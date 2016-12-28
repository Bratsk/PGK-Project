#include "Fractal2D.h"



Fractal2D::Fractal2D(int iter, wxSize bitmp, int nTrans) : 
	Fractal(iter, bitmp, nTrans),
	transformation(new AffineTransformation2D[Fractal::nTransf])
{
}


Fractal2D::~Fractal2D()
{
	delete[] transformation;
}

void Fractal2D::AddTransformation(wxTextInputStream & fstr, int i)
{
	fstr >> transformation[i].a
		>> transformation[i].b
		>> transformation[i].e
		>> transformation[i].c
		>> transformation[i].d
		>> transformation[i].f;
}
