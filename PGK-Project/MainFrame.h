///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once


#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_MAINFRAME 1000
#define wxID_DRAWPANEL 1001
#define wxID_READFILE 1002

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
private:

protected:
	wxPanel* drawPanel;
	wxButton* readFileButton;

	// Virtual event handlers, overide them in your derived class
	virtual void readFileButtonOnLeftUp(wxMouseEvent& event);


public:

	MainFrame(wxWindow* parent, wxWindowID id = wxID_MAINFRAME, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(861, 529), long style = wxDEFAULT_FRAME_STYLE | wxICONIZE | wxMINIMIZE | wxRESIZE_BORDER | wxSYSTEM_MENU | wxTAB_TRAVERSAL);

	~MainFrame();
private:
};