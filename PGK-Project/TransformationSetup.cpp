#include "TransformationSetup.h"
#include "Fractal2D.h"

/*
[rozmiar x bitmap],[rozmiar y bitmap],[ile iteracji],[typ:0 – 2D, 1 - 3D] 
[x_obserwatora][y_obserwatora][z_obserwatora] 
[ile fraktali bedziemy animowac min.2] 
[ilosc przeksztalcen dla pierwszego fraktala] 
[przeksztalcenie 1] 
.....
[przeksztalcenie n]
[ile klatek animacji do kolejnego fraktala] 
[ilosc przeksztalcen dla drugiego fraktala] 
[przeksztalcenie 1] 
.....
[przeksztalcenie n]
*/
TransformationSetup::TransformationSetup(wxString filepath, wxPanel * panel) :
	//open file stream and text input stream
	input_stream(filepath),
	input_text_stream(input_stream),
	//set all data to zero
	bitmapSize(0, 0),
	drawPanel(panel),
	iterations(0),
	fractalDimension(d2D),
	viewerPos(0, 0, 0),
	fractalSize(0),
	transformationBitmapFrames(nullptr),
	fractal(nullptr)
{
	ReadData();
}


TransformationSetup::~TransformationSetup()
{
	if (fractal != nullptr)
	{
		for (int i = 0; i < fractalSize; i++)
			delete fractal[i];
		delete[] fractal;
	}
	delete[] transformationBitmapFrames;
}

bool TransformationSetup::ReadData()
{
	// read header of file
	int dimension;
	input_text_stream.SetStringSeparators(" ,");
	input_text_stream
		>> bitmapSize.x 
		>> bitmapSize.y
		>> iterations
		>> dimension;
	fractalDimension = dimension == 0 ? d2D : d3D;
	// read viewer position
	input_text_stream
		>> viewerPos.x >> viewerPos.y >> viewerPos.z;
	input_text_stream
		>> fractalSize;


	// ALLOCATE MEMORY for all fractals in file
	fractal = new Fractal*[fractalSize];
	for (int i = 0; i < fractalSize; i++)
		fractal[i] = nullptr;
	// ALLOCATE MEMORY for transformationBitmapFrames
	transformationBitmapFrames = new int[fractalSize - 1];


	
	/// TEST BEGIN	-> to delete
	//iterations = 10000;
	/// TEST END	-> to delete

	// read fractal data
	// fts contians the number how many transformations the fractal contains
	int fts; //Fractal Transformation Size

	// read first fractal separately
	input_text_stream >> fts;
	fractal[0] = new Fractal2D(iterations, bitmapSize, fts);
	for (int i = 0; i < fts; i++)
		fractal[0]->AddTransformation(input_text_stream, i);

	// read all next fractal data
	for(int j = 1; j < fractalSize; j++)
	{
		input_text_stream
			>> transformationBitmapFrames[j - 1]
			>> fts;
		fractal[j] = new Fractal2D(iterations, bitmapSize, fts);
		for (int i = 0; i < fts; i++)
			fractal[j]->AddTransformation(input_text_stream, i);
	}
	return true;
}


wxSize TransformationSetup::GetBitmapSize()
{
	return bitmapSize;
}

Fractal ** TransformationSetup::GetFractal()
{
	return fractal;
}

int TransformationSetup::GetFractalSize()
{
	return fractalSize;
}


