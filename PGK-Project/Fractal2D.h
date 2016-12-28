#pragma once
#include "Fractal.h"

struct AffineTransformation2D
{
	double a, b, e, c, d, f;
	double percentage;
};

class Fractal2D :
	public Fractal
{
public:
	Fractal2D(int iter, wxSize bitmp, int nTrans);
	~Fractal2D();
protected:
	// Inherited via Fractal
	virtual void AddTransformation(wxTextInputStream & fstr, int i) override;
private:
	AffineTransformation2D * transformation;
};

