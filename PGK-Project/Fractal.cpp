#include "Fractal.h"




Fractal::Fractal(int iter, wxSize bitmp, int nTrans) :
	iterations(iter),
	bitmap(bitmp),
	nTransf(nTrans)
{
}

Fractal::~Fractal()
{
}

void Fractal::AddTransformation(wxTextInputStream & fstr, int i)
{

}
