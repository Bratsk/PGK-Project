#include "Fractal.h"




Fractal::Fractal(int iter, wxSize bitmp, int nTrans) :
	iterations(iter),
	bitmap(bitmp),
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


