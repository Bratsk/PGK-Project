///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"

#include <wx/filedlg.h>

#include "TransformationSetup.h"
#include "Fractal.h"
///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxSize(-1, -1), wxDefaultSize);

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* panelSizer;
	panelSizer = new wxBoxSizer(wxVERTICAL);

	drawPanel = new wxPanel(this, wxID_DRAWPANEL, wxDefaultPosition, wxSize(300, 400), wxTAB_TRAVERSAL);
	panelSizer->Add(drawPanel, 1, wxEXPAND | wxALL, 5);


	mainSizer->Add(panelSizer, 1, wxEXPAND, 5);

	wxBoxSizer* controlSizer;
	controlSizer = new wxBoxSizer(wxVERTICAL);

	readFileButton = new wxButton(this, wxID_READFILE, wxT("Read File"), wxDefaultPosition, wxDefaultSize, 0);
	controlSizer->Add(readFileButton, 0, wxALL, 5);

	animateFractalButton = new wxButton(this, wxID_ANY, wxT("Animate"), wxDefaultPosition, wxDefaultSize, 0);
	controlSizer->Add(animateFractalButton, 0, wxALL, 5);


	mainSizer->Add(controlSizer, 0, wxALIGN_LEFT | wxALL, 5);


	this->SetSizer(mainSizer);
	this->Layout();
	mainTimer.SetOwner(this, wxID_ANY);

	this->Centre(wxBOTH);

	// Connect Events
	readFileButton->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(MainFrame::readFileButtonOnLeftUp), NULL, this);
	animateFractalButton->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(MainFrame::animateFractalButtonOnLeftUp), NULL, this);
}

MainFrame::~MainFrame()
{
}

void MainFrame::AdjustFrameSize(const wxSize bitmapSize)
{
	wxSize frameSize = this->GetSize();
	wxSize panelSize = drawPanel->GetSize();
	//set frame size to bitmap size
	this->SetSize(bitmapSize);
	//expand x direction
	while (panelSize.x < bitmapSize.x)
	{
		frameSize = this->GetSize();
		frameSize.x++;
		this->SetSize(frameSize);
		panelSize = this->GetSize();
		panelSize.x++;
		this->SetSize(panelSize);
	}
	//expand y direction
	while (panelSize.y < bitmapSize.y)
	{
		frameSize = this->GetSize();
		frameSize.y++;
		this->SetSize(frameSize);
		panelSize = this->GetSize();
		panelSize.y++;
		this->SetSize(panelSize);
	}
}

void MainFrame::readFileButtonOnLeftUp(wxMouseEvent& event) 
{
	wxFileDialog openFileDialog(this, _("Open text file"), "", "",
			"text files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (openFileDialog.ShowModal() == wxID_CANCEL)
		return;     // the user changed idea... 
					//open filestream with selected path
	TransformationSetup fractalSetup(openFileDialog.GetPath(), drawPanel);
	//adjust size of frame
	this->AdjustFrameSize(fractalSetup.GetBitmapSize());
	Fractal ** fractal = fractalSetup.GetFractal();
	int fractalSize = fractalSetup.GetFractalSize();

	for (int i = 0; i < fractalSize; i++)
	{
		wxString name = "";
		name << i + 1 << ".bmp";
		fractal[i]->GenerateBitmap(name, drawPanel);
	}
}

void MainFrame::animateFractalButtonOnLeftUp(wxMouseEvent & event)
{
	event.Skip();
	return;
}
