#pragma once

#include <fstream>

#include <wx/gdicmn.h>
#include <wx/wfstream.h> // input stream file
#include <wx/txtstrm.h> // text stream file

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
	TransformationSetup(wxString filepath);
	~TransformationSetup();

	bool ReadData();

protected:
	wxFileInputStream input_stream;
	wxTextInputStream input_text_stream; //input text file for the animation
	wxSize bitmap; // size of bitmap for the fractal
	int iterations; // how many points should the fractal contain
	dimension fractalDimension; // visual dimension of fractal
	Position viewerPos; // position of viewer (3D only)
	int fractalNumber; // how many fractals should be drawn
	int transformationBitmapFrames; // how manz frames should be drawn between the fractals
};

