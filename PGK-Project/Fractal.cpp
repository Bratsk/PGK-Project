#include "Fractal.h"




Fractal::Fractal(int iter, wxSize bitmp, int nTrans) :
	iterations(iter),
	bitmapSize(bitmp),
	transformationSize(nTrans)
{

}

Fractal::~Fractal()
{
}

int Fractal::GetTransformationSize()
{
	return transformationSize;
}


