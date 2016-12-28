#include "TransformationSetup.h"


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
TransformationSetup::TransformationSetup(wxString filepath) :
	//open file stream and text input stream
	input_stream(filepath),
	input_text_stream(input_stream),
	//set all data to zero
	bitmap(0, 0),
	iterations(0),
	fractalDimension(d2D),
	viewerPos(0, 0, 0),
	fractalNumber(0),
	transformationBitmapFrames(0)
{

}


TransformationSetup::~TransformationSetup()
{
}

bool TransformationSetup::ReadData()
{
	//read header of file
	char separator;
	int dimension;
	input_text_stream
		>> bitmap.x >> separator
		>> bitmap.y >> separator
		>> iterations >> separator
		>> dimension;
	fractalDimension = dimension == 0 ? d2D : d3D;
	//read viewer position
	input_text_stream
		>> viewerPos.x >> viewerPos.y >> viewerPos.z;
	input_text_stream
		>> fractalNumber;
	//read fractal data
	return true;
}
