#pragma once

#include <fstream>

#include <wx/gdicmn.h>
#include <wx/wfstream.h> // input stream file
#include <wx/txtstrm.h> // text stream file
#include <wx/panel.h>

#include "Fractal2D.h"

/*
	dimension enumeration indicates which dimension the fractal has
*/
enum dimension
{
	d2D = 0,
	d3D = 1
};

/*
	point of viewer in 3 dimensional space
*/
struct Position
{
	Position(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {}
	double x;
	double y;
	double z;
};

/*
	Transformation class is the main class which handles the reading of the data 
	file which sets up the animation
	the main tasks are
	- opening and reading the file
	- setup of the needed Fractal object
	- creating bitmaps with the transformation between the fractals
 */
class TransformationSetup
{
public:
	/* Constructor
		Set up the file given with filepath and the panel where fractal has to be drawn
		Opens the text file to read*/
	TransformationSetup(wxString filepath, wxPanel * panel);
	~TransformationSetup();
	/*
		Reads data from file and initalises variables needed for the transformation
	*/
	bool ReadData();
	/* Get bitmap size of all fractals */
	wxSize GetBitmapSize();
	/* Get fractal data read from file */
	Fractal** GetFractal();
	/* Get amout ouf fractals stored in file */
	int GetFractalSize();
protected:
	wxFileInputStream input_stream;
	wxTextInputStream input_text_stream; //input text file for the animation
	wxSize bitmapSize; // size of bitmap for the fractal
	wxPanel * drawPanel;
	int iterations; // how many points should the fractal contain
	dimension fractalDimension; // visual dimension of fractal
	Position viewerPos; // position of viewer (3D only)
	int fractalSize; // how many fractals should be drawn
	int * transformationBitmapFrames; // how manz frames should be drawn between the fractals
	Fractal ** fractal;
};

