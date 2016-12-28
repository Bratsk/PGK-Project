#pragma once

#include <wx/gdicmn.h>
#include <wx/txtstrm.h> // text stream file

class Fractal
{
public:
	Fractal(int iter, wxSize bitmp, int nTrans);
	virtual ~Fractal();

	virtual void AddTransformation(wxTextInputStream & fstr, int i) = 0;
protected:
	int iterations;
	wxSize bitmap; //bitmap size on which it has to be drawn
	int nTransf; //number of transformations needed in fractal
};

