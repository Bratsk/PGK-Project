#pragma once
#include "Fractal.h"

/* AffineTransfomration2D describes one transformation needed to draw the fractal 
	all transformation percentages has to sum to 1*/
struct AffineTransformation2D
{
	double a, b, e, c, d, f;
	double probability;
};

/*
	fractal2D defines the 2D fractal.
	with ADDTransformation all transformations are added
	with Draw a bitmap is returned which can be drawn on the wxPanel
*/
class Fractal2D :
	public Fractal
{
public:
	Fractal2D(int iter, wxSize bitmp, int nTrans);
	~Fractal2D();
	/* Adding new Transformation to Fractal
		@param fstr text stream from which the parameters are read from
		@param i index in which the transformation should be written to
	*/
	virtual void AddTransformation(wxTextInputStream & fstr, int i) override;
	/* Generate simple bitmap file visualising the fractal */
	virtual void GenerateBitmap(wxString filename, wxPanel * drawPanel) override;
private:
	AffineTransformation2D * transformation;



	// Inherited via Fractal
	virtual void SetTransformationSize(int n) override;

};

