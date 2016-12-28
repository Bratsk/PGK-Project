///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"

#include <wx/filedlg.h>


#include "TransformationSetup.h"
///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxSize(300, 150), wxDefaultSize);

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* panelSizer;
	panelSizer = new wxBoxSizer(wxVERTICAL);

	drawPanel = new wxPanel(this, wxID_DRAWPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	panelSizer->Add(drawPanel, 1, wxEXPAND | wxALL, 5);


	mainSizer->Add(panelSizer, 1, wxEXPAND, 5);

	wxBoxSizer* controlSizer;
	controlSizer = new wxBoxSizer(wxVERTICAL);

	readFileButton = new wxButton(this, wxID_READFILE, wxT("Read File"), wxDefaultPosition, wxDefaultSize, 0);
	controlSizer->Add(readFileButton, 0, wxALL, 5);


	mainSizer->Add(controlSizer, 0, wxALIGN_LEFT | wxALL, 5);


	this->SetSizer(mainSizer);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	readFileButton->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(MainFrame::readFileButtonOnLeftUp), NULL, this);
}

MainFrame::~MainFrame()
{
}

void MainFrame::readFileButtonOnLeftUp(wxMouseEvent& event) 
{ 
	wxFileDialog openFileDialog(this, _("Open text file"), "", "",
			"text files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (openFileDialog.ShowModal() == wxID_CANCEL)
		return;     // the user changed idea... 
					//open filestream with selected path
	TransformationSetup(openFileDialog.GetPath());
}

