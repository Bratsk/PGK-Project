#include "Fractal2D.h"
#include <wx/image.h>

#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <random>



Fractal2D::Fractal2D(int iter, wxSize bitmp, int nTrans) : 
	Fractal(iter, bitmp, nTrans),
	transformation(new AffineTransformation2D[Fractal::transformationSize])
{
}


Fractal2D::~Fractal2D()
{
	delete[] transformation;
}

void Fractal2D::AddTransformation(wxTextInputStream & fstr, int i)
{
	//set all values in affine transformation
	fstr >> transformation[i].a
		>> transformation[i].b
		>> transformation[i].c
		>> transformation[i].d
		>> transformation[i].e
		>> transformation[i].f;
	//set propability of stransformation
	transformation[i].probability = 1. / transformationSize;
}

void Fractal2D::GenerateBitmap(wxString filename, wxPanel * drawPanel)
{
	wxImage fractalImage(bitmapSize);
	wxClientDC * cDC;
	cDC = new wxClientDC(drawPanel);
	wxBufferedDC * bDC;
	bDC = new wxBufferedDC(cDC);
	bDC->Clear();
	//bDC->SetBackground(wxBrush(wxColor(255, 255, 255)));
	bDC->SetPen(wxPen(wxColor(0, 0, 0)));
	int strechFactor = bitmapSize.x < bitmapSize.y ? bitmapSize.x : bitmapSize.y;
	wxCoord x = 0,  y  = 0;
	double x1 = 0., y1 = 0.;
	double x2 = 0., y2 = 0.;
	int t; // transformation index which is currently used
	// ALLOCATE threshold array with threshold values between 0 and 1
	double * threshold = new double[transformationSize + 2]; 
	threshold[0] = 0.0;
	for (int i = 1; i < transformationSize + 1; i++)
	{
		threshold[i] = transformation[i - 1].probability + threshold[i - 1];
	}
	threshold[transformationSize + 1] = 1.;
	//generate uniform distributed random number
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 1);
	double rand; // random number
	for (int i = 0; i < iterations; i++)
	{
		//generate number
		rand = dis(gen);
		//choosing transformation
		for (int j = 0; j < transformationSize + 1; j++)
		{
			if (threshold[j] <= rand && rand < threshold[j + 1])
			{
				t = j;
				break;
			}
		}
		x2 = transformation[t].a * x1 + transformation[t].b * y1 + transformation[t].e;
		y2 = transformation[t].c * x1 + transformation[t].d * y1 + transformation[t].f;
		x1 = x2;
		y1 = y2;
		x = static_cast<wxCoord>(x1 * strechFactor);
		y = static_cast<wxCoord>(y1 * strechFactor);
		bDC->DrawPoint(x, y);
	}
	wxBitmap fractalBitmap = bDC->GetAsBitmap();
	fractalImage = fractalBitmap.ConvertToImage();
	//save image
	fractalImage.SaveFile(filename, wxBITMAP_TYPE_BMP);
	// DELETE memory
	delete[] threshold;
	delete bDC;
	delete cDC;
}

void Fractal2D::SetTransformationSize(int n)
{
	///has to be filled
}
