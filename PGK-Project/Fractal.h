#pragma once

#include <wx/gdicmn.h>
#include <wx/txtstrm.h> // text stream file
#include <wx/panel.h>

class Fractal
{
public:
	Fractal(int iter, wxSize bitmp, int nTrans);
	virtual ~Fractal();

	virtual void AddTransformation(wxTextInputStream & fstr, int i) = 0;
	virtual void GenerateBitmap(wxString filename, wxPanel * drawPanel) = 0;
	/* returns current number of transformations stored in fractal*/
	virtual int GetTransformationSize();
	/* adds transformations to fractal with 0 probability and 0 parameters 
	in affine transformation
	 */
	virtual void SetTransformationSize(int n) = 0;
protected:
	int iterations; // number of transformations needed in fractal
	wxSize bitmapSize; //bitmap size on which it has to be drawn
	int transformationSize; //number of transformations needed in fractal
};

