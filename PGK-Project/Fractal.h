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
	virtual int GetTransformationSize();
	///empty function has to be filled
	virtual void SetTransformationSize(int n) = 0;
protected:
	int iterations;
	wxSize bitmap; //bitmap size on which it has to be drawn
	int transformationSize; //size of transformations needed in fractal
};

