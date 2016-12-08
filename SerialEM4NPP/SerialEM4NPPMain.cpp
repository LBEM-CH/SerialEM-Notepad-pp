/***************************************************************
 * Name:      SerialEM4NPPMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Daniel Caujolle-Bert (daniel.caujolle-bert@unibas.ch)
 * Created:   2016-12-01
 * Copyright: Daniel Caujolle-Bert (https://c-cina.unibas.ch/bioem/)
 * License:
 **************************************************************/

#include "SerialEM4NPPMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(SerialEM4NPPFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)
#include <wx/log.h>


//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(SerialEM4NPPFrame)
const long SerialEM4NPPFrame::ID_TEXTCTRL1 = wxNewId();
const long SerialEM4NPPFrame::ID_BUTTON1 = wxNewId();
const long SerialEM4NPPFrame::ID_BUTTON2 = wxNewId();
const long SerialEM4NPPFrame::ID_BITMAPBUTTON1 = wxNewId();
const long SerialEM4NPPFrame::ID_BITMAPBUTTON2 = wxNewId();
const long SerialEM4NPPFrame::ID_BITMAPBUTTON4 = wxNewId();
const long SerialEM4NPPFrame::ID_TREECTRL2 = wxNewId();
const long SerialEM4NPPFrame::ID_PANEL4 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL2 = wxNewId();
const long SerialEM4NPPFrame::ID_BITMAPBUTTON3 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL3 = wxNewId();
const long SerialEM4NPPFrame::ID_CHECKBOX1 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL5 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL6 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL7 = wxNewId();
const long SerialEM4NPPFrame::ID_STATICTEXT2 = wxNewId();
const long SerialEM4NPPFrame::ID_STATICTEXT1 = wxNewId();
const long SerialEM4NPPFrame::ID_PANEL5 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL4 = wxNewId();
const long SerialEM4NPPFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long SerialEM4NPPFrame::ID_SPLITTERWINDOW1 = wxNewId();
const long SerialEM4NPPFrame::ID_PANEL2 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL8 = wxNewId();
const long SerialEM4NPPFrame::ID_BUTTON3 = wxNewId();
const long SerialEM4NPPFrame::ID_BUTTON4 = wxNewId();
const long SerialEM4NPPFrame::ID_TREECTRL1 = wxNewId();
const long SerialEM4NPPFrame::ID_PANEL6 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL9 = wxNewId();
const long SerialEM4NPPFrame::ID_BITMAPBUTTON6 = wxNewId();
const long SerialEM4NPPFrame::ID_CHECKBOX6 = wxNewId();
const long SerialEM4NPPFrame::ID_CHECKBOX5 = wxNewId();
const long SerialEM4NPPFrame::ID_CHECKBOX7 = wxNewId();
const long SerialEM4NPPFrame::ID_CHECKBOX8 = wxNewId();
const long SerialEM4NPPFrame::ID_CHECKBOX10 = wxNewId();
const long SerialEM4NPPFrame::ID_CHECKBOX11 = wxNewId();
const long SerialEM4NPPFrame::ID_CHECKBOX9 = wxNewId();
const long SerialEM4NPPFrame::ID_CHECKBOX12 = wxNewId();
const long SerialEM4NPPFrame::ID_CHECKBOX2 = wxNewId();
const long SerialEM4NPPFrame::ID_CHECKBOX3 = wxNewId();
const long SerialEM4NPPFrame::ID_CHECKBOX4 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL10 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL13 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL16 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL17 = wxNewId();
const long SerialEM4NPPFrame::ID_PANEL7 = wxNewId();
const long SerialEM4NPPFrame::ID_PANEL8 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL11 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL12 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL15 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL14 = wxNewId();
const long SerialEM4NPPFrame::ID_SCROLLEDWINDOW2 = wxNewId();
const long SerialEM4NPPFrame::ID_SPLITTERWINDOW2 = wxNewId();
const long SerialEM4NPPFrame::ID_PANEL3 = wxNewId();
const long SerialEM4NPPFrame::ID_TEXTCTRL18 = wxNewId();
const long SerialEM4NPPFrame::ID_BITMAPBUTTON7 = wxNewId();
const long SerialEM4NPPFrame::ID_BITMAPBUTTON8 = wxNewId();
const long SerialEM4NPPFrame::ID_BITMAPBUTTON5 = wxNewId();
const long SerialEM4NPPFrame::ID_BITMAPBUTTON9 = wxNewId();
const long SerialEM4NPPFrame::ID_HTMLWINDOW1 = wxNewId();
const long SerialEM4NPPFrame::ID_PANEL9 = wxNewId();
const long SerialEM4NPPFrame::ID_AUINOTEBOOK1 = wxNewId();
const long SerialEM4NPPFrame::ID_PANEL1 = wxNewId();
const long SerialEM4NPPFrame::idMenuQuit = wxNewId();
const long SerialEM4NPPFrame::idMenuAbout = wxNewId();
const long SerialEM4NPPFrame::ID_STATUSBAR1 = wxNewId();
//*)
const long SerialEM4NPPFrame::ID_CTXMENU_COPY = wxNewId();
const long SerialEM4NPPFrame::ID_CTXMENU_SELECTALL = wxNewId();
const long SerialEM4NPPFrame::ID_CTXMENU_PASTE = wxNewId();

BEGIN_EVENT_TABLE(SerialEM4NPPFrame,wxFrame)
    //(*EventTable(SerialEM4NPPFrame)
    //*)
END_EVENT_TABLE()

static size_t di = 0;

void debug(const char *str)
{
    wxString s = wxEmptyString;

    for (size_t i = 0; i < di; i++)
        s << wxT(" ");

    s << str;

    wxLogStatus(s);
}
void debug(const wxString &str)
{
    debug((const char *)str.c_str());
}

void debugEnter(const char *str)
{
    di += 4;
    debug(str);
}
void debugEnter(const wxString &str)
{
    debugEnter((const char *)str.c_str());
}
void debugLeave(const char *str)
{
    debug(str);
    di -= 4;
}
void debugLeave(const wxString &str)
{
    debugLeave((const char *)str.c_str());
}


SerialEM4NPPFrame::SerialEM4NPPFrame(wxWindow* parent,wxWindowID id) : m_progress(NULL), m_apiLoaded(false), m_langLoaded(false)
{
#if 0
    wxLogWindow *logger = new wxLogWindow(this, _("Logging Window"));
    wxLog::SetActiveTarget(logger);
    wxLogStatus(wxT("Started"));
#endif

    //(*Initialize(SerialEM4NPPFrame)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer29;
    wxBoxSizer* BoxSizer19;
    wxBoxSizer* BoxSizer15;
    wxBoxSizer* BoxSizer20;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer7;
    wxStaticBoxSizer* StaticBoxSizer12;
    wxBoxSizer* BoxSizer39;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer21;
    wxStaticBoxSizer* StaticBoxSizer21;
    wxStaticBoxSizer* StaticBoxSizer15;
    wxMenuItem* MenuItem2;
    wxBoxSizer* BoxSizer13;
    wxStaticBoxSizer* StaticBoxSizer14;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxBoxSizer* BoxSizer36;
    wxMenuItem* MenuItem1;
    wxStaticBoxSizer* StaticBoxSizer16;
    wxBoxSizer* BoxSizer37;
    wxBoxSizer* BoxSizer23;
    wxStaticBoxSizer* StaticBoxSizer9;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer11;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer16;
    wxStaticBoxSizer* StaticBoxSizer7;
    wxBoxSizer* BoxSizer18;
    wxBoxSizer* BoxSizer30;
    wxBoxSizer* BoxSizer12;
    wxBoxSizer* BoxSizer28;
    wxStaticBoxSizer* StaticBoxSizer17;
    wxStaticBoxSizer* StaticBoxSizer13;
    wxStaticBoxSizer* StaticBoxSizer10;
    wxBoxSizer* BoxSizer38;
    wxBoxSizer* BoxSizer14;
    wxStaticBoxSizer* StaticBoxSizer8;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxBoxSizer* BoxSizer27;
    wxBoxSizer* BoxSizer31;
    wxStaticBoxSizer* StaticBoxSizer20;
    wxBoxSizer* BoxSizer17;
    wxBoxSizer* BoxSizer24;
    wxBoxSizer* BoxSizer26;
    wxBoxSizer* BoxSizer32;
    wxStaticBoxSizer* StaticBoxSizer11;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer9;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer34;
    wxBoxSizer* BoxSizer33;
    wxBoxSizer* BoxSizer22;
    wxBoxSizer* BoxSizer35;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxBoxSizer* BoxSizer25;
    wxStaticBoxSizer* StaticBoxSizer18;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1290,700));
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    m_notebook = new wxAuiNotebook(Panel1, ID_AUINOTEBOOK1, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TAB_FIXED_WIDTH);
    Panel2 = new wxPanel(m_notebook, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer9 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("  Source file  "));
    m_wtextInput = new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticBoxSizer1->Add(m_wtextInput, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wbtnLoad = new wxButton(Panel2, ID_BUTTON1, _("Load"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer1->Add(m_wbtnLoad, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wbtnSave = new wxButton(Panel2, ID_BUTTON2, _("Save As..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    m_wbtnSave->Disable();
    StaticBoxSizer1->Add(m_wbtnSave, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    SplitterWindow1 = new wxSplitterWindow(Panel2, ID_SPLITTERWINDOW1, wxDefaultPosition, wxSize(348,364), wxSP_3DSASH|wxSP_3DBORDER, _T("ID_SPLITTERWINDOW1"));
    SplitterWindow1->SetMinSize(wxSize(250,250));
    SplitterWindow1->SetMinimumPaneSize(250);
    SplitterWindow1->SetSashGravity(0);
    Panel4 = new wxPanel(SplitterWindow1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer11 = new wxBoxSizer(wxVERTICAL);
    BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer12->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wbtnItemAdd = new wxBitmapButton(Panel4, ID_BITMAPBUTTON1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NEW")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    m_wbtnItemAdd->Disable();
    m_wbtnItemAdd->SetToolTip(_("Add entry AFTER selection"));
    BoxSizer12->Add(m_wbtnItemAdd, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wbtnItemDel = new wxBitmapButton(Panel4, ID_BITMAPBUTTON2, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_DELETE")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    m_wbtnItemDel->Disable();
    m_wbtnItemDel->SetToolTip(_("Delete selection"));
    BoxSizer12->Add(m_wbtnItemDel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wbtnExportFunctionNames = new wxBitmapButton(Panel4, ID_BITMAPBUTTON4, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_INFORMATION")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    m_wbtnExportFunctionNames->Disable();
    m_wbtnExportFunctionNames->SetToolTip(_("Export function name list to file"));
    BoxSizer12->Add(m_wbtnExportFunctionNames, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer11->Add(BoxSizer12, 0, wxALL|wxEXPAND, 5);
    m_wtree = new wxTreeCtrl(Panel4, ID_TREECTRL2, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL2"));
    BoxSizer11->Add(m_wtree, 1, wxEXPAND, 0);
    BoxSizer10->Add(BoxSizer11, 1, wxALL|wxEXPAND, 5);
    Panel4->SetSizer(BoxSizer10);
    BoxSizer10->Fit(Panel4);
    BoxSizer10->SetSizeHints(Panel4);
    m_scrolledWindow = new wxScrolledWindow(SplitterWindow1, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, m_scrolledWindow, _("  Name  "));
    m_wtextFunctionName = new wxTextCtrl(m_scrolledWindow, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    m_wtextFunctionName->SetMinSize(wxSize(300,-1));
    StaticBoxSizer2->Add(m_wtextFunctionName, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer13->Add(StaticBoxSizer2, 0, wxALL, 5);
    BoxSizer13->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wbtmBtnSave = new wxBitmapButton(m_scrolledWindow, ID_BITMAPBUTTON3, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_SAVE")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BoxSizer13->Add(m_wbtmBtnSave, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(BoxSizer13, 0, wxALL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, m_scrolledWindow, _("  Arguments  "));
    m_wtextFunctionArgs = new wxTextCtrl(m_scrolledWindow, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    m_wtextFunctionArgs->SetMinSize(wxSize(200,100));
    StaticBoxSizer3->Add(m_wtextFunctionArgs, 1, wxALL|wxEXPAND, 5);
    BoxSizer6->Add(StaticBoxSizer3, 0, wxALL, 5);
    m_wsizerEnv = new wxStaticBoxSizer(wxVERTICAL, m_scrolledWindow, _("  Env  "));
    m_wcheckEnvCase = new wxCheckBox(m_scrolledWindow, ID_CHECKBOX1, _("Ignore Case"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    m_wcheckEnvCase->SetValue(false);
    m_wsizerEnv->Add(m_wcheckEnvCase, 0, wxALL|wxEXPAND, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, m_scrolledWindow, _("  Start  "));
    StaticBoxSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wtextEnvStart = new wxTextCtrl(m_scrolledWindow, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    m_wtextEnvStart->SetMaxLength(1);
    m_wtextEnvStart->SetMinSize(wxSize(40,-1));
    StaticBoxSizer7->Add(m_wtextEnvStart, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer7->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(StaticBoxSizer7, 0, wxALL, 5);
    StaticBoxSizer8 = new wxStaticBoxSizer(wxHORIZONTAL, m_scrolledWindow, _("  Stop  "));
    StaticBoxSizer8->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wtextEnvStop = new wxTextCtrl(m_scrolledWindow, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    m_wtextEnvStop->SetMaxLength(1);
    m_wtextEnvStop->SetMinSize(wxSize(40,-1));
    StaticBoxSizer8->Add(m_wtextEnvStop, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer8->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(StaticBoxSizer8, 0, wxALL, 5);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, m_scrolledWindow, _("  Sep  "));
    StaticBoxSizer6->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wtextEnvSep = new wxTextCtrl(m_scrolledWindow, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    m_wtextEnvSep->SetMaxLength(1);
    m_wtextEnvSep->SetMinSize(wxSize(40,-1));
    StaticBoxSizer6->Add(m_wtextEnvSep, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer6->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(StaticBoxSizer6, 0, wxALL, 5);
    m_wsizerEnv->Add(BoxSizer7, 0, wxALL|wxEXPAND, 0);
    BoxSizer6->Add(m_wsizerEnv, 0, wxALL, 5);
    BoxSizer5->Add(BoxSizer6, 0, wxALL, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, m_scrolledWindow, _("  Description  "));
    BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer15 = new wxBoxSizer(wxVERTICAL);
    Panel5 = new wxPanel(m_scrolledWindow, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    Panel5->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
    BoxSizer16 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(Panel5, ID_STATICTEXT2, _("0         1         2         3         4         5         6         7         8         9"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
    if ( !StaticText2Font.Ok() ) StaticText2Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText2->SetFont(StaticText2Font);
    BoxSizer16->Add(StaticText2, 0, wxLEFT|wxRIGHT|wxEXPAND, 5);
    StaticText1 = new wxStaticText(Panel5, ID_STATICTEXT1, _("0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
    if ( !StaticText1Font.Ok() ) StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer16->Add(StaticText1, 0, wxLEFT|wxRIGHT|wxEXPAND, 5);
    Panel5->SetSizer(BoxSizer16);
    BoxSizer16->Fit(Panel5);
    BoxSizer16->SetSizeHints(Panel5);
    BoxSizer15->Add(Panel5, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND, 0);
    m_wtextFunctionDescription = new wxTextCtrl(m_scrolledWindow, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    wxFont m_wtextFunctionDescriptionFont = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
    if ( !m_wtextFunctionDescriptionFont.Ok() ) m_wtextFunctionDescriptionFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_wtextFunctionDescription->SetFont(m_wtextFunctionDescriptionFont);
    BoxSizer15->Add(m_wtextFunctionDescription, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    BoxSizer14->Add(BoxSizer15, 1, wxALL|wxEXPAND, 0);
    StaticBoxSizer4->Add(BoxSizer14, 1, wxALL|wxEXPAND, 5);
    BoxSizer5->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
    BoxSizer4->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
    m_scrolledWindow->SetSizer(BoxSizer4);
    BoxSizer4->Fit(m_scrolledWindow);
    BoxSizer4->SetSizeHints(m_scrolledWindow);
    SplitterWindow1->SplitVertically(Panel4, m_scrolledWindow);
    SplitterWindow1->SetSashPosition(250);
    BoxSizer3->Add(SplitterWindow1, 1, wxALL|wxEXPAND, 5);
    BoxSizer9->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    BoxSizer8->Add(BoxSizer9, 1, wxALL|wxEXPAND, 5);
    Panel2->SetSizer(BoxSizer8);
    BoxSizer8->Fit(Panel2);
    BoxSizer8->SetSizeHints(Panel2);
    Panel3 = new wxPanel(m_notebook, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer18 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("  Source file  "));
    m_wtextInputLang = new wxTextCtrl(Panel3, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    StaticBoxSizer5->Add(m_wtextInputLang, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wbtnLoadLang = new wxButton(Panel3, ID_BUTTON3, _("Load"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBoxSizer5->Add(m_wbtnLoadLang, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wbtnSaveLang = new wxButton(Panel3, ID_BUTTON4, _("Save As..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    m_wbtnSaveLang->Disable();
    StaticBoxSizer5->Add(m_wbtnSaveLang, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer18->Add(StaticBoxSizer5, 0, wxALL|wxEXPAND, 5);
    BoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
    SplitterWindow2 = new wxSplitterWindow(Panel3, ID_SPLITTERWINDOW2, wxDefaultPosition, wxSize(348,364), wxSP_3DSASH|wxSP_3DBORDER, _T("ID_SPLITTERWINDOW2"));
    SplitterWindow2->SetMinSize(wxSize(250,250));
    SplitterWindow2->SetMinimumPaneSize(250);
    SplitterWindow2->SetSashGravity(0);
    Panel6 = new wxPanel(SplitterWindow2, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    BoxSizer21 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer22 = new wxBoxSizer(wxVERTICAL);
    BoxSizer23 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer23->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer22->Add(BoxSizer23, 0, wxALL|wxEXPAND, 0);
    m_wtreeLang = new wxTreeCtrl(Panel6, ID_TREECTRL1, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
    BoxSizer22->Add(m_wtreeLang, 1, wxEXPAND, 0);
    BoxSizer21->Add(BoxSizer22, 1, wxALL|wxEXPAND, 5);
    Panel6->SetSizer(BoxSizer21);
    BoxSizer21->Fit(Panel6);
    BoxSizer21->SetSizeHints(Panel6);
    ScrolledWindow1 = new wxScrolledWindow(SplitterWindow2, ID_SCROLLEDWINDOW2, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW2"));
    BoxSizer24 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer25 = new wxBoxSizer(wxVERTICAL);
    BoxSizer26 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer35 = new wxBoxSizer(wxVERTICAL);
    BoxSizer36 = new wxBoxSizer(wxHORIZONTAL);
    m_wsizerNameLang = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  Name  "));
    m_wtextTextLang = new wxTextCtrl(ScrolledWindow1, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    m_wtextTextLang->SetMinSize(wxSize(300,-1));
    m_wsizerNameLang->Add(m_wtextTextLang, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer36->Add(m_wsizerNameLang, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5);
    BoxSizer36->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton4 = new wxBitmapButton(ScrolledWindow1, ID_BITMAPBUTTON6, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_SAVE")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    BoxSizer36->Add(BitmapButton4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer35->Add(BoxSizer36, 1, wxALL|wxEXPAND, 0);
    m_wsizerPrefixLang = new wxStaticBoxSizer(wxVERTICAL, ScrolledWindow1, _("  Prefix  "));
    BoxSizer33 = new wxBoxSizer(wxHORIZONTAL);
    m_wcheckKeywords1 = new wxCheckBox(ScrolledWindow1, ID_CHECKBOX6, _("Keywords1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    m_wcheckKeywords1->SetValue(false);
    BoxSizer33->Add(m_wcheckKeywords1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wcheckKeywords2 = new wxCheckBox(ScrolledWindow1, ID_CHECKBOX5, _("Keywords2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    m_wcheckKeywords2->SetValue(false);
    BoxSizer33->Add(m_wcheckKeywords2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wcheckKeywords3 = new wxCheckBox(ScrolledWindow1, ID_CHECKBOX7, _("Keywords3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX7"));
    m_wcheckKeywords3->SetValue(false);
    BoxSizer33->Add(m_wcheckKeywords3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wcheckKeywords4 = new wxCheckBox(ScrolledWindow1, ID_CHECKBOX8, _("Keywords4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX8"));
    m_wcheckKeywords4->SetValue(false);
    BoxSizer33->Add(m_wcheckKeywords4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wsizerPrefixLang->Add(BoxSizer33, 0, wxALL|wxEXPAND, 0);
    BoxSizer34 = new wxBoxSizer(wxHORIZONTAL);
    m_wcheckKeywords5 = new wxCheckBox(ScrolledWindow1, ID_CHECKBOX10, _("Keywords5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX10"));
    m_wcheckKeywords5->SetValue(false);
    BoxSizer34->Add(m_wcheckKeywords5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wcheckKeywords6 = new wxCheckBox(ScrolledWindow1, ID_CHECKBOX11, _("Keywords6"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX11"));
    m_wcheckKeywords6->SetValue(false);
    BoxSizer34->Add(m_wcheckKeywords6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wcheckKeywords7 = new wxCheckBox(ScrolledWindow1, ID_CHECKBOX9, _("Keywords7"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX9"));
    m_wcheckKeywords7->SetValue(false);
    BoxSizer34->Add(m_wcheckKeywords7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wcheckKeywords8 = new wxCheckBox(ScrolledWindow1, ID_CHECKBOX12, _("Keywords8"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX12"));
    m_wcheckKeywords8->SetValue(false);
    BoxSizer34->Add(m_wcheckKeywords8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wsizerPrefixLang->Add(BoxSizer34, 0, wxALL|wxEXPAND, 0);
    BoxSizer35->Add(m_wsizerPrefixLang, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND, 5);
    BoxSizer26->Add(BoxSizer35, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wsizerSettingsLang = new wxStaticBoxSizer(wxVERTICAL, ScrolledWindow1, _("  Settings  "));
    StaticBoxSizer14 = new wxStaticBoxSizer(wxVERTICAL, ScrolledWindow1, _(" Global  "));
    BoxSizer31 = new wxBoxSizer(wxHORIZONTAL);
    m_wcheckCaseIgnored = new wxCheckBox(ScrolledWindow1, ID_CHECKBOX2, _("caseIgnored"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    m_wcheckCaseIgnored->SetValue(false);
    BoxSizer31->Add(m_wcheckCaseIgnored, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wcheckAllowFoldOfComments = new wxCheckBox(ScrolledWindow1, ID_CHECKBOX3, _("allowFoldOfComments"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    m_wcheckAllowFoldOfComments->SetValue(false);
    BoxSizer31->Add(m_wcheckAllowFoldOfComments, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wcheckFoldCompact = new wxCheckBox(ScrolledWindow1, ID_CHECKBOX4, _("foldCompact"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    m_wcheckFoldCompact->SetValue(false);
    BoxSizer31->Add(m_wcheckFoldCompact, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer14->Add(BoxSizer31, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer32 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer20 = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  forcePureLC  "));
    m_wtextForcePureLC = new wxTextCtrl(ScrolledWindow1, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    StaticBoxSizer20->Add(m_wtextForcePureLC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer32->Add(StaticBoxSizer20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer21 = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  decimalSeparator  "));
    m_wtextDecimalSeparator = new wxTextCtrl(ScrolledWindow1, ID_TEXTCTRL13, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    StaticBoxSizer21->Add(m_wtextDecimalSeparator, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer32->Add(StaticBoxSizer21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer14->Add(BoxSizer32, 0, wxALL|wxEXPAND, 0);
    m_wsizerSettingsLang->Add(StaticBoxSizer14, 0, wxALL|wxEXPAND, 0);
    BoxSizer26->Add(m_wsizerSettingsLang, 0, wxALL|wxEXPAND, 5);
    BoxSizer25->Add(BoxSizer26, 0, wxALL, 0);
    BoxSizer27 = new wxBoxSizer(wxHORIZONTAL);
    m_wsizerUserLang = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  User Lang  "));
    StaticBoxSizer11 = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  Name  "));
    m_wtextUserLangName = new wxTextCtrl(ScrolledWindow1, ID_TEXTCTRL16, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    StaticBoxSizer11->Add(m_wtextUserLangName, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wsizerUserLang->Add(StaticBoxSizer11, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer9 = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  Ext  "));
    m_wtextUserLangExt = new wxTextCtrl(ScrolledWindow1, ID_TEXTCTRL17, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    m_wtextUserLangExt->SetMinSize(wxSize(50,-1));
    StaticBoxSizer9->Add(m_wtextUserLangExt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wsizerUserLang->Add(StaticBoxSizer9, 0, wxALL|wxEXPAND, 5);
    BoxSizer27->Add(m_wsizerUserLang, 1, wxALL, 5);
    BoxSizer27->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wsizerWordsStyleLang = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  Words Style  "));
    BoxSizer28 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer12 = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  fgColor  "));
    StaticBoxSizer12->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wpanelFgColor = new wxPanel(ScrolledWindow1, ID_PANEL7, wxDefaultPosition, wxDefaultSize, wxRAISED_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    m_wpanelFgColor->SetMinSize(wxSize(25,25));
    StaticBoxSizer12->Add(m_wpanelFgColor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer12->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer28->Add(StaticBoxSizer12, 0, wxALL, 5);
    StaticBoxSizer13 = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  bgColor"));
    StaticBoxSizer13->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wpanelBgColor = new wxPanel(ScrolledWindow1, ID_PANEL8, wxDefaultPosition, wxDefaultSize, wxRAISED_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    m_wpanelBgColor->SetMinSize(wxSize(25,25));
    StaticBoxSizer13->Add(m_wpanelBgColor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer13->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer28->Add(StaticBoxSizer13, 0, wxALL, 5);
    m_wsizerWordsStyleLang->Add(BoxSizer28, 0, wxALL, 0);
    BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer16 = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  Font Name  "));
    m_wtextFontName = new wxTextCtrl(ScrolledWindow1, ID_TEXTCTRL11, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    m_wtextFontName->SetMinSize(wxSize(80,-1));
    StaticBoxSizer16->Add(m_wtextFontName, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer19->Add(StaticBoxSizer16, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer17 = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  Font Style  "));
    m_wtextFontStyle = new wxTextCtrl(ScrolledWindow1, ID_TEXTCTRL12, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    m_wtextFontStyle->SetMinSize(wxSize(80,-1));
    StaticBoxSizer17->Add(m_wtextFontStyle, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer19->Add(StaticBoxSizer17, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer18 = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  Font Size  "));
    m_wtextFontSize = new wxTextCtrl(ScrolledWindow1, ID_TEXTCTRL15, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    m_wtextFontSize->SetMinSize(wxSize(80,-1));
    StaticBoxSizer18->Add(m_wtextFontSize, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer19->Add(StaticBoxSizer18, 0, wxALL, 5);
    m_wsizerWordsStyleLang->Add(BoxSizer19, 0, wxALL, 0);
    BoxSizer27->Add(m_wsizerWordsStyleLang, 0, wxALL, 5);
    BoxSizer25->Add(BoxSizer27, 0, wxALL|wxEXPAND, 0);
    m_wsizerContentLang = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("  Content  "));
    BoxSizer29 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer30 = new wxBoxSizer(wxVERTICAL);
    m_wtextContentLang = new wxTextCtrl(ScrolledWindow1, ID_TEXTCTRL14, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    wxFont m_wtextContentLangFont = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
    if ( !m_wtextContentLangFont.Ok() ) m_wtextContentLangFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_wtextContentLang->SetFont(m_wtextContentLangFont);
    BoxSizer30->Add(m_wtextContentLang, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 0);
    BoxSizer29->Add(BoxSizer30, 1, wxALL|wxEXPAND, 5);
    m_wsizerContentLang->Add(BoxSizer29, 1, wxALL|wxEXPAND, 0);
    BoxSizer25->Add(m_wsizerContentLang, 1, wxALL|wxEXPAND, 5);
    BoxSizer24->Add(BoxSizer25, 0, wxALL|wxEXPAND, 0);
    ScrolledWindow1->SetSizer(BoxSizer24);
    BoxSizer24->Fit(ScrolledWindow1);
    BoxSizer24->SetSizeHints(ScrolledWindow1);
    SplitterWindow2->SplitVertically(Panel6, ScrolledWindow1);
    SplitterWindow2->SetSashPosition(250);
    BoxSizer20->Add(SplitterWindow2, 1, wxALL|wxEXPAND, 5);
    BoxSizer18->Add(BoxSizer20, 1, wxALL|wxEXPAND, 0);
    BoxSizer17->Add(BoxSizer18, 1, wxALL|wxEXPAND, 0);
    Panel3->SetSizer(BoxSizer17);
    BoxSizer17->Fit(Panel3);
    BoxSizer17->SetSizeHints(Panel3);
    m_panel7 = new wxPanel(m_notebook, ID_PANEL9, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    BoxSizer37 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer38 = new wxBoxSizer(wxVERTICAL);
    BoxSizer39 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer10 = new wxStaticBoxSizer(wxHORIZONTAL, m_panel7, wxEmptyString);
    m_wtextBetaURL = new wxTextCtrl(m_panel7, ID_TEXTCTRL18, _("http://bio3d.colorado.edu/SerialEM/hlp/html/macro_commands.htm"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    StaticBoxSizer10->Add(m_wtextBetaURL, 1, wxALL|wxEXPAND, 5);
    m_wbtnHomeBetaHtml = new wxBitmapButton(m_panel7, ID_BITMAPBUTTON7, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_WARNING")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
    m_wbtnHomeBetaHtml->SetToolTip(_("Load beta commands"));
    StaticBoxSizer10->Add(m_wbtnHomeBetaHtml, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wbtnHomeStableHtml = new wxBitmapButton(m_panel7, ID_BITMAPBUTTON8, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_INFORMATION")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON8"));
    m_wbtnHomeStableHtml->SetToolTip(_("Load stable commands"));
    StaticBoxSizer10->Add(m_wbtnHomeStableHtml, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_wbtnReloadHtml = new wxBitmapButton(m_panel7, ID_BITMAPBUTTON5, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_UNDO")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
    m_wbtnReloadHtml->SetToolTip(_("Reload current page"));
    StaticBoxSizer10->Add(m_wbtnReloadHtml, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer39->Add(StaticBoxSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer39->Add(0,0,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer15 = new wxStaticBoxSizer(wxHORIZONTAL, m_panel7, wxEmptyString);
    m_wbtnHtmlSave = new wxBitmapButton(m_panel7, ID_BITMAPBUTTON9, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_SAVE_AS")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON9"));
    m_wbtnHtmlSave->SetToolTip(_("Save pqge context to text file"));
    StaticBoxSizer15->Add(m_wbtnHtmlSave, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer39->Add(StaticBoxSizer15, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer38->Add(BoxSizer39, 0, wxALL|wxEXPAND, 5);
    m_whtmlWindowBeta = new wxHtmlWindow(m_panel7, ID_HTMLWINDOW1, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO|wxSUNKEN_BORDER, _T("ID_HTMLWINDOW1"));
    m_whtmlWindowBeta->SetBorders(5);
    BoxSizer38->Add(m_whtmlWindowBeta, 1, wxALL|wxEXPAND, 5);
    BoxSizer37->Add(BoxSizer38, 1, wxALL|wxEXPAND, 5);
    m_panel7->SetSizer(BoxSizer37);
    BoxSizer37->Fit(m_panel7);
    BoxSizer37->SetSizeHints(m_panel7);
    m_notebook->AddPage(Panel2, _("Plugin"));
    m_notebook->AddPage(Panel3, _("Language"));
    m_notebook->AddPage(m_panel7, _("Online Commands"));
    BoxSizer2->Add(m_notebook, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    m_wfileDialog = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    m_wcolourDialog = new wxColourDialog(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnLoadClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnSaveClick);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::Onm_wbtnItemAddClick);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::Onm_wbtnItemDelClick);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::Onm_wbtnExportFunctionNamesClick);
    Connect(ID_TREECTRL2,wxEVT_COMMAND_TREE_BEGIN_DRAG,(wxObjectEventFunction)&SerialEM4NPPFrame::OnTreeBeginDrag);
    Connect(ID_TREECTRL2,wxEVT_COMMAND_TREE_END_DRAG,(wxObjectEventFunction)&SerialEM4NPPFrame::OnTreeEndDrag);
    Connect(ID_TREECTRL2,wxEVT_COMMAND_TREE_SEL_CHANGED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnSelectionChanged);
    Connect(ID_TREECTRL2,wxEVT_COMMAND_TREE_SEL_CHANGING,(wxObjectEventFunction)&SerialEM4NPPFrame::OnSelectionChanging);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputText);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnBitmapButton1Click);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputText);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnEnvCaseClick);
    Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputText);
    Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputText);
    Connect(ID_TEXTCTRL7,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputText);
    Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputText);
    Connect(ID_SPLITTERWINDOW1,wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnSplitterWindow1SashPosChanged);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnLoadLangClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnSaveLangClick);
    Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_SEL_CHANGED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnSelectionChanged);
    Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_SEL_CHANGING,(wxObjectEventFunction)&SerialEM4NPPFrame::OnSelectionChanging);
    Connect(ID_TEXTCTRL9,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputTextLang);
    Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnBitmapButton4Click);
    Connect(ID_CHECKBOX6,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnCheckLangClick);
    Connect(ID_CHECKBOX5,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnCheckLangClick);
    Connect(ID_CHECKBOX7,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnCheckLangClick);
    Connect(ID_CHECKBOX8,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnCheckLangClick);
    Connect(ID_CHECKBOX10,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnCheckLangClick);
    Connect(ID_CHECKBOX11,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnCheckLangClick);
    Connect(ID_CHECKBOX9,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnCheckLangClick);
    Connect(ID_CHECKBOX12,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnCheckLangClick);
    Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnCheckLangClick);
    Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnCheckLangClick);
    Connect(ID_CHECKBOX4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnCheckLangClick);
    Connect(ID_TEXTCTRL10,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputTextLang);
    Connect(ID_TEXTCTRL13,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputTextLang);
    Connect(ID_TEXTCTRL16,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputTextLang);
    Connect(ID_TEXTCTRL17,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputTextLang);
    m_wpanelFgColor->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&SerialEM4NPPFrame::OnPanelColorClick,0,this);
    m_wpanelBgColor->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&SerialEM4NPPFrame::OnPanelColorClick,0,this);
    Connect(ID_TEXTCTRL11,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputTextLang);
    Connect(ID_TEXTCTRL12,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputTextLang);
    Connect(ID_TEXTCTRL15,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputTextLang);
    Connect(ID_TEXTCTRL14,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnInputTextLang);
    Connect(ID_SPLITTERWINDOW2,wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnSplitterWindow1SashPosChanged);
    Connect(ID_TEXTCTRL18,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&SerialEM4NPPFrame::Onm_wtextBetaURLTextEnter);
    Connect(ID_BITMAPBUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::Onm_whomeBetaHtmlClick);
    Connect(ID_BITMAPBUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::Onm_whomeStableHtmlClick);
    Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnHtmlReloadClick);
    Connect(ID_BITMAPBUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnHtmlSaveClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SerialEM4NPPFrame::OnAbout);
    //*)

    m_whtmlWindowBeta->GetHTMLWindow()->Connect(wxEVT_RIGHT_DOWN, (wxObjectEventFunction)&SerialEM4NPPFrame::OnPanel7RightDown, 0, this);

    m_whtmlCtxMenu = new wxMenu();
    m_whtmlCtxMenu->Append(ID_CTXMENU_COPY, wxT("Copy"));
    m_whtmlCtxMenu->Append(ID_CTXMENU_PASTE, wxT("Paste"));
    m_whtmlCtxMenu->AppendSeparator();
    m_whtmlCtxMenu->Append(ID_CTXMENU_SELECTALL, wxT("Select All"));

    Connect(ID_CTXMENU_COPY, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&SerialEM4NPPFrame::OnHtmlCopy);
    Connect(ID_CTXMENU_PASTE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&SerialEM4NPPFrame::OnHtmlPaste);
    Connect(ID_CTXMENU_SELECTALL, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&SerialEM4NPPFrame::OnHtmlSelectAll);

    SetIcon(wxICON(MAINICON));
    SetTitle(wxGetApp().GetAppName() + wxT(" ")
             + wxString::FromAscii(AutoVersion::FULLVERSION_STRING)
             + wxString::FromAscii(AutoVersion::STATUS_SHORT));

    m_scrolledWindow->SetScrollRate(-1, 5);

    _enableSizerChilds(m_wsizerEnv, false);

    _enableSizerChilds(m_wsizerNameLang, false);
    _enableSizerChilds(m_wsizerPrefixLang, false);
    _enableSizerChilds(m_wsizerSettingsLang, false);
    _enableSizerChilds(m_wsizerUserLang, false);
    _enableSizerChilds(m_wsizerWordsStyleLang, false);
    _enableSizerChilds(m_wsizerContentLang, false);



    wxSize s = GetSize();
    SetMinSize(s);
    Fit();
}

SerialEM4NPPFrame::~SerialEM4NPPFrame()
{
    //(*Destroy(SerialEM4NPPFrame)
    //*)
}

void SerialEM4NPPFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SerialEM4NPPFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void SerialEM4NPPFrame::_enableSizerChilds(wxSizer *sizer, bool enable)
{
    wxSizerItemList           &items = sizer->GetChildren();
    wxSizerItemList::iterator  it = items.begin();

    while(it != items.end())
    {
        if ((*it)->IsWindow())
        {
            wxWindow *o = (*it)->GetWindow();

            o->Enable(enable);
        }
        else if ((*it)->IsSizer())
        {
            wxSizer *s = (*it)->GetSizer();

            _enableSizerChilds(s, enable);
        }

        it++;
    }
}

void SerialEM4NPPFrame::_parseAttributes(wxXmlNode *node, sTreeItemData *data)
{
    wxXmlAttribute *attr = node->GetAttributes();

    if (attr && data)
    {
        sTreeItemType type = data->GetType();
        wxString nodeName = node->GetName();

        //debugEnter(wxT("Enter Attributes for: ") + node->GetName());

        do
        {
            wxString name = attr->GetName();
            wxString value = attr->GetValue();

            if (m_progress)
                m_progress->Pulse();

            switch (type)
            {
                //
                // API
                //
                case ITEM_TYPE_COMMENT:
                    // NOOP
                    break;

                case ITEM_TYPE_ENVIRONMENT:
                    {
                        sTreeItemEnvironmentData *d = (sTreeItemEnvironmentData *)data;

                        if (name.CmpNoCase(wxT("ignoreCase")) == 0)
                            d->SetIgnoreCase((value.CmpNoCase(wxT("yes")) == 0) ? true : false);
                        else if (name.CmpNoCase(wxT("startFunc")) == 0)
                            d->SetStartFunc(value);
                        else if (name.CmpNoCase(wxT("stopFunc")) == 0)
                            d->SetStopFunc(value);
                        else if (name.CmpNoCase(wxT("paramSeparator")) == 0)
                            d->SetParamSeparator(value);
                    }
                    break;

                case ITEM_TYPE_FUNCTION:
                    {
                        sTreeItemFunctionData *d = (sTreeItemFunctionData *)data;

                        if (nodeName.CmpNoCase(wxT("KeyWord")) == 0)
                        {
                            if (name.CmpNoCase(wxT("name")) == 0)
                                d->SetFunctionName(value);
                        }
                        else if (nodeName.CmpNoCase(wxT("Overload")) == 0)
                        {
                            if (name.CmpNoCase(wxT("descr")) == 0)
                                d->SetFunctionDescription(value);
                        }
                        else if (nodeName.CmpNoCase(wxT("Param")) == 0)
                        {
                            if (name.CmpNoCase(wxT("name")) == 0)
                                d->AddFunctionParameter(value);
                        }
                    }
                    break;

                //
                // Language
                //
                case ITEM_TYPE_LANG_USERLANG:
                    {
                        sTreeItemLangUserlangData *d = (sTreeItemLangUserlangData *)data;

                        if (name.CmpNoCase(wxT("name")) == 0)
                            d->SetName(value);
                        else if (name.CmpNoCase(wxT("ext")) == 0)
                            d->SetExt(value);
                        else if (name.CmpNoCase(wxT("udlVersion")) == 0)
                            d->SetUdlVersion(value);
                    }
                    break;

                case ITEM_TYPE_LANG_SETTINGS:
                    {
                        sTreeItemLangSettingsData *d = (sTreeItemLangSettingsData *)data;

                        if (name.CmpNoCase(wxT("caseIgnored")) == 0)
                            d->SetCaseIgnored((value.CmpNoCase(wxT("yes")) == 0) ? true : false);
                        else if (name.CmpNoCase(wxT("allowFoldOfComments")) == 0)
                            d->SetAllowFoldOfComments((value.CmpNoCase(wxT("yes")) == 0) ? true : false);
                        else if (name.CmpNoCase(wxT("foldCompact")) == 0)
                            d->SetFoldCompact((value.CmpNoCase(wxT("yes")) == 0) ? true : false);
                        else if (name.CmpNoCase(wxT("forcePureLC")) == 0)
                            d->SetForcePureLC(value);
                        else if (name.CmpNoCase(wxT("decimalSeparator")) == 0)
                            d->SetDecimalSeparator(value);

                        // Keywords{1..8}
                        for (size_t i = 0; i < 8; i++)
                        {
                            wxString str = wxString::Format(wxT("Keywords%zu"), i + 1);

                            if (name.CmpNoCase(str) == 0)
                            {
                                d->SetKeywords(i, (value.CmpNoCase(wxT("yes")) == 0) ? true : false);
                                break;
                            }
                        }
                    }
                    break;

                case ITEM_TYPE_LANG_KEYWORDS:
                    {
                        sTreeItemLangKeywordsData *d = (sTreeItemLangKeywordsData *)data;

                        if (name.CmpNoCase(wxT("name")) == 0)
                            d->SetName(value);
                    }
                    break;

                case ITEM_TYPE_LANG_WORDSTYLE:
                    {
                        sTreeItemLangWordstyleData *d = (sTreeItemLangWordstyleData *)data;

                        if (name.CmpNoCase(wxT("name")) == 0)
                            d->SetName(value);
                        else if (name.CmpNoCase(wxT("fgColor")) == 0)
                            d->SetFgColor(value);
                        else if (name.CmpNoCase(wxT("bgColor")) == 0)
                            d->SetBgColor(value);
                        else if (name.CmpNoCase(wxT("fontName")) == 0)
                            d->SetFontName(value);
                        else if (name.CmpNoCase(wxT("fontStyle")) == 0)
                            d->SetFontStyle(value);
                        else if (name.CmpNoCase(wxT("fontSize")) == 0)
                            d->SetFontSize(value);
                        else if (name.CmpNoCase(wxT("nesting")) == 0)
                            d->SetNesting(value);
                    }
                    break;


                case ITEM_TYPE_UNDEF:
                    // NOOP
                    break;
            }


            //debug(wxT("Attr: ") + attr->GetName() + wxT(", Value: ") + attr->GetValue());
        } while((attr = attr->GetNext()));


        //debugLeave(wxT("Leave Attributes for: ") + node->GetName());
    }

}

void SerialEM4NPPFrame::_traverseXmlNodes(wxTreeCtrl *tree, wxTreeItemId rootID, wxXmlNode *node)
{
    bool appendItem = false;
    static sTreeItemData *data = NULL;

    //debugEnter(wxT("Enter >> ") + node->GetName());

    wxXmlNode *n = node->GetChildren();

    if (m_progress)
        m_progress->Pulse();

    if (node->GetName().CmpNoCase(wxT("Environment")) == 0)
    {
        data = (sTreeItemData *)new sTreeItemEnvironmentData();

        appendItem = true;
    }
    else if (node->GetName().CmpNoCase(wxT("KeyWord")) == 0)
    {
        data = (sTreeItemData *)new sTreeItemFunctionData();

        appendItem = true;
    }
    else if (node->GetName().CmpNoCase(wxT("UserLang")) == 0)
    {
        data = (sTreeItemData *)new sTreeItemLangUserlangData();

        appendItem = true;
    }
    else if (node->GetName().CmpNoCase(wxT("Settings")) == 0)
    {
        data = (sTreeItemData *)new sTreeItemLangSettingsData();

        appendItem = true;
    }
    else if (node->GetName().CmpNoCase(wxT("Keywords")) == 0)
    {
        data = (sTreeItemData *)new sTreeItemLangKeywordsData();

        appendItem = true;
    }
    else if (node->GetName().CmpNoCase(wxT("WordsStyle")) == 0)
    {
        data = (sTreeItemData *)new sTreeItemLangWordstyleData();

        appendItem = true;
    }
#warning FIXME
    else if ((tree == m_wtree) && (node->GetContent() != wxEmptyString))
    {
        data = (sTreeItemData *)new sTreeItemCommentData();
        ((sTreeItemCommentData *)data)->SetComment(node->GetContent());

        appendItem = true;
    }
    else if (data && ((tree == m_wtreeLang) && (node->GetContent() != wxEmptyString)))
    {
        ((sTreeItemLangKeywordsData *)data)->SetText(node->GetContent());
    }

    //debug(wxT("Content: ") + node->GetContent());

    _parseAttributes(node, data);

    if (appendItem)
    {
        wxString name = wxEmptyString;

        switch (data->GetType())
        {
            //
            // API
            //
            case ITEM_TYPE_COMMENT:
                name = wxT("Comment");
                break;
            case ITEM_TYPE_ENVIRONMENT:
                name = wxT("Environment");
                break;

            case ITEM_TYPE_FUNCTION:
                name = ((sTreeItemFunctionData *)data)->GetFunctionName();
                break;

            //
            // Language
            //
            case ITEM_TYPE_LANG_USERLANG:
                name = wxT("UserLang");
                break;

            case ITEM_TYPE_LANG_SETTINGS:
                name = wxT("Settings");
                break;

            case ITEM_TYPE_LANG_KEYWORDS:
                name = ((sTreeItemLangKeywordsData *)data)->GetName();
                break;

            case ITEM_TYPE_LANG_WORDSTYLE:
                name = ((sTreeItemLangWordstyleData *)data)->GetName();
                break;

            case ITEM_TYPE_UNDEF:
                break;
        }

        wxTreeItemId id = tree->AppendItem(rootID, name);
        tree->SetItemData(id, data);
    }

    if (n)
    {
        do
        {
            //debug("Iterate");
            _traverseXmlNodes(tree, rootID, n);
        } while((n = n->GetNext()));
    }

    //debugLeave(wxT("Leave << ") + node->GetName());
}

void SerialEM4NPPFrame::_fillXmlFromTree(wxXmlDocument *doc, wxTreeCtrl *tree)
{
    wxXmlNode *AutoComplete = NULL;
    wxXmlNode *UserLang = NULL;
    wxXmlNode *Settings = NULL;

    wxXmlNode *KeywordLists = NULL;
    wxXmlNode *Styles = NULL;

    // <<NotepadPlus>
    wxXmlNode *xroot = new wxXmlNode(NULL, wxXML_ELEMENT_NODE, "NotepadPlus");
    doc->SetRoot(xroot);

    // Only for API file
    if (tree == m_wtree)
    {
        // <AutoComplete language="SEM">
        AutoComplete = new wxXmlNode(xroot, wxXML_ELEMENT_NODE, "AutoComplete");
        AutoComplete->AddAttribute("language", "SEM");
    }
    else
    {
        UserLang = new wxXmlNode(xroot, wxXML_ELEMENT_NODE, "UserLang");
        Styles = new wxXmlNode(UserLang, wxXML_ELEMENT_NODE, "Styles");
        KeywordLists = new wxXmlNode(UserLang, wxXML_ELEMENT_NODE, "KeywordLists");
        Settings = new wxXmlNode(UserLang, wxXML_ELEMENT_NODE, "Settings");
    }

    //
    // wxXML document save node backwards, handle this here
    //
    std::vector<wxTreeItemId>   ids;
    wxTreeItemId                root = tree->GetRootItem();
    wxTreeItemIdValue           cookie;
    wxTreeItemId                id = tree->GetFirstChild(root, cookie);

    do
    {
        if (id.IsOk())
            ids.push_back(id);

    } while ((id = tree->GetNextChild(id, cookie)) && id.IsOk());

    std::vector<wxTreeItemId>::reverse_iterator it = ids.rbegin();

    while (it != ids.rend())
    {
        sTreeItemData *data = (sTreeItemData *) tree->GetItemData((*it));

        switch (data->GetType())
        {
            //
            // API
            //
            case ITEM_TYPE_COMMENT:
                {
                    sTreeItemCommentData *d = (sTreeItemCommentData *)data;

                    wxXmlNode *n = new wxXmlNode(NULL, wxXML_COMMENT_NODE, wxEmptyString);

                    n->SetContent(d->GetComment());

                    //wxXmlNode *prolog = doc->GetDocumentNode()->GetChildren();
                    //prolog->SetContent(d->GetComment());
                    doc->AppendToProlog(n);

//                    wxXmlNode *n = new wxXmlNode(NULL, wxXML_ELEMENT_NODE, wxEmptyString);//doc->GetDocumentNode();

//                    wxXmlNode *n = doc->GetDocumentNode();
//
//                    n->SetContent(d->GetComment());

                    //doc->SetDocumentNode(n);

                }
                break;

            case ITEM_TYPE_ENVIRONMENT:
                {
                    sTreeItemEnvironmentData *d = (sTreeItemEnvironmentData *)data;

                    wxXmlNode *Environment = new wxXmlNode(AutoComplete, wxXML_ELEMENT_NODE, "Environment");

                    Environment->AddAttribute("ignoreCase", d->GetIgnoreCase() ? "yes" : "no");
                    Environment->AddAttribute("startFunc", d->GetStartFunc());
                    Environment->AddAttribute("stopFunc", d->GetStopFunc());
                    Environment->AddAttribute("paramSeparator", d->GetParamSeparator());
                }
                break;

            case ITEM_TYPE_FUNCTION:
                {
                    sTreeItemFunctionData *d = (sTreeItemFunctionData *)data;

                    wxXmlNode *KeyWord = new wxXmlNode(AutoComplete, wxXML_ELEMENT_NODE, "KeyWord");

                    KeyWord->AddAttribute("name", d->GetFunctionName());
                    KeyWord->AddAttribute("func", "yes");


                    wxXmlNode *Overload = new wxXmlNode(KeyWord, wxXML_ELEMENT_NODE, "Overload");

                    Overload->AddAttribute("retVal", "");
                    Overload->AddAttribute("descr", d->GetFunctionDescription().Trim());

                    wxArrayString ar = d->GetFunctionParameters();
                    wxString s;
                    size_t cnt = ar.GetCount();

                    if (cnt > 0)
                    {
                        for (wxInt32 i = wxInt32(cnt) - 1; i >= 0; i--)
                        {
                            wxString s = ar.Item(i).Trim();

                            if (s != wxEmptyString)
                            {
                                wxXmlNode *Param = new wxXmlNode(Overload, wxXML_ELEMENT_NODE, "Param");

                                Param->AddAttribute("name", ar.Item(i).Trim());
                            }
                        }
                    }
                }
                break;

            //
            // Language
            //
            case ITEM_TYPE_LANG_USERLANG:
                {
                    sTreeItemLangUserlangData *d = (sTreeItemLangUserlangData *)data;

                    UserLang->AddAttribute("name", d->GetName());
                    UserLang->AddAttribute("ext", d->GetExt());
                    UserLang->AddAttribute("udlVersion", d->GetUdlVersion());
                }
                break;

            case ITEM_TYPE_LANG_SETTINGS:
                {
                    sTreeItemLangSettingsData *d = (sTreeItemLangSettingsData *)data;

                    wxXmlNode *Prefix = new wxXmlNode(Settings, wxXML_ELEMENT_NODE, "Prefix");
                    wxXmlNode *Global = new wxXmlNode(Settings, wxXML_ELEMENT_NODE, "Global");

                    Global->AddAttribute("caseIgnored", d->GetCaseIgnored() ? "yes" : "no");
                    Global->AddAttribute("allowFoldOfComments", d->GetAllowFoldOfComments() ? "yes" : "no");
                    Global->AddAttribute("foldCompact", d->GetFoldCompact() ? "yes" : "no");
                    Global->AddAttribute("forcePureLC", d->GetForcePureLC());
                    Global->AddAttribute("decimalSeparator", d->GetDecimalSeparator());

                    Prefix->AddAttribute("Keywords1", d->GetKeywords(0) ? "yes" : "no");
                    Prefix->AddAttribute("Keywords2", d->GetKeywords(1) ? "yes" : "no");
                    Prefix->AddAttribute("Keywords3", d->GetKeywords(2) ? "yes" : "no");
                    Prefix->AddAttribute("Keywords4", d->GetKeywords(3) ? "yes" : "no");
                    Prefix->AddAttribute("Keywords5", d->GetKeywords(4) ? "yes" : "no");
                    Prefix->AddAttribute("Keywords6", d->GetKeywords(5) ? "yes" : "no");
                    Prefix->AddAttribute("Keywords7", d->GetKeywords(6) ? "yes" : "no");
                    Prefix->AddAttribute("Keywords8", d->GetKeywords(7) ? "yes" : "no");
                }
                break;

            case ITEM_TYPE_LANG_KEYWORDS:
                {
                    sTreeItemLangKeywordsData *d = (sTreeItemLangKeywordsData *)data;

                    wxXmlNode *Keywords = new wxXmlNode(KeywordLists, wxXML_ELEMENT_NODE, "Keywords");
                    Keywords->AddAttribute("name", d->GetName());

                    wxXmlNode *text = new wxXmlNode(Keywords, wxXML_TEXT_NODE, wxEmptyString);
                    text->SetContent(d->GetText());
                }
                break;

            case ITEM_TYPE_LANG_WORDSTYLE:
                {
                    sTreeItemLangWordstyleData *d = (sTreeItemLangWordstyleData *)data;

                    wxXmlNode *WordsStyle = new wxXmlNode(Styles, wxXML_ELEMENT_NODE, "WordsStyle");
                    WordsStyle->AddAttribute("name", d->GetName());
                    WordsStyle->AddAttribute("fgColor", d->GetFgColor());
                    WordsStyle->AddAttribute("bgColor", d->GetBgColor());
                    WordsStyle->AddAttribute("fontName", d->GetFontName());
                    WordsStyle->AddAttribute("fontStyle", d->GetFontStyle());

                    wxString fontSize = d->GetFontSize();

                    if (fontSize != wxEmptyString)
                        WordsStyle->AddAttribute("fontSize", fontSize);

                    WordsStyle->AddAttribute("nesting", d->GetNesting());
                }
                break;

            case ITEM_TYPE_UNDEF:
                break;
        }

        it++;

    }
}

void SerialEM4NPPFrame::_parse(wxXmlDocument *doc)
{
    wxProgressDialog dialog(wxT("Parsing XML"), wxT("Please wait..."));
    wxTreeItemId id;
    //wxXmlNode      *root = m_xmlDoc.GetRoot();

    dialog.Show();
    m_progress = &dialog;

    if (m_wtree->GetCount())
        m_wtree->DeleteAllItems();

    m_notebook->SetPageText(0, wxT("Plugin"));

    id = m_wtree->AddRoot(wxT("Root"));

    _traverseXmlNodes(m_wtree, id, doc->GetDocumentNode());//->GetChildren());

    m_wtree->ExpandAll();

    m_progress = NULL;
}

void SerialEM4NPPFrame::_parseLang(wxXmlDocument *doc)
{
    wxProgressDialog dialog(wxT("Parsing XML"), wxT("Please wait..."));
    wxTreeItemId id;

    dialog.Show();
    m_progress = &dialog;

    if (m_wtreeLang->GetCount())
        m_wtreeLang->DeleteAllItems();

    m_notebook->SetPageText(1, wxT("Language"));

    id = m_wtreeLang->AddRoot(wxT("Root"));

    _traverseXmlNodes(m_wtreeLang, id, doc->GetDocumentNode());

    m_wtreeLang->ExpandAll();

    m_progress = NULL;
}

void SerialEM4NPPFrame::OnLoadClick(wxCommandEvent& event)
{
    m_wfileDialog->SetWildcard(wxT("XML files (*.xml)|*.xml|All types (*.*)|*.*"));
    m_wfileDialog->SetPath(wxT("SerialEM.xml"));

    if (m_wfileDialog->ShowModal() == wxID_OK)
    {
        wxXmlDocument   doc;
        wxString        file = m_wfileDialog->GetPath();

        m_wtextInput->SetValue(file);

        m_apiLoaded = false;

        if (doc.Load(file))
        {
            if (doc.GetRoot()->GetName() != wxT("NotepadPlus"))
                wxMessageBox(wxT("Unable to get root"), wxT("Error"));
            else
            {
                //debug(wxT("Encoding: ") + m_xmlDoc.GetFileEncoding());

                _parse(&doc);

                m_apiLoaded = true;
            }
        }
        else
        {

        }
    }

    m_wbtnSave->Enable(m_apiLoaded);
    m_wbtnExportFunctionNames->Enable(m_apiLoaded);
}

void SerialEM4NPPFrame::_storeItem(wxTreeCtrl *tree, wxTreeItemId id)
{
    sTreeItemData *data = id.IsOk() ? (sTreeItemData *)tree->GetItemData(id) : NULL;

    if (data)
    {
        switch (data->GetType())
        {
            //
            // API
            //
            case ITEM_TYPE_COMMENT:
                {
                    sTreeItemCommentData *d = (sTreeItemCommentData *)data;

                    d->SetComment(m_wtextFunctionDescription->GetValue());
                    d->Changed(false);
                }
                break;

            case ITEM_TYPE_ENVIRONMENT:
                {
                    sTreeItemEnvironmentData *d = (sTreeItemEnvironmentData *)data;

                    d->SetIgnoreCase(m_wcheckEnvCase->GetValue());
                    d->SetStartFunc(m_wtextEnvStart->GetValue());
                    d->SetStopFunc(m_wtextEnvStop->GetValue());
                    d->SetParamSeparator(m_wtextEnvSep->GetValue());
                    d->Changed(false);
                }
                break;

            case ITEM_TYPE_FUNCTION:
                {
                    sTreeItemFunctionData *d = (sTreeItemFunctionData *)data;

                    d->SetFunctionName(m_wtextFunctionName->GetValue());

                    m_wtree->SetItemText(id, d->GetFunctionName());

                    d->ClearFunctionParameter();
                    for (int i = 0; i < m_wtextFunctionArgs->GetNumberOfLines(); i++)
                        d->AddFunctionParameter(m_wtextFunctionArgs->GetLineText(i));

                    d->SetFunctionDescription(m_wtextFunctionDescription->GetValue());
                    d->Changed(false);
                }
                break;

            //
            // Language
            //
            case ITEM_TYPE_LANG_USERLANG:
                {
                    sTreeItemLangUserlangData *d = (sTreeItemLangUserlangData *)data;

                    d->SetName(m_wtextUserLangName->GetValue());
                    d->SetExt(m_wtextUserLangExt->GetValue());
                    d->Changed(false);
                }
                break;

            case ITEM_TYPE_LANG_SETTINGS:
                {
                    sTreeItemLangSettingsData *d = (sTreeItemLangSettingsData *)data;

                    d->SetCaseIgnored(m_wcheckCaseIgnored->GetValue());
                    d->SetAllowFoldOfComments(m_wcheckAllowFoldOfComments->GetValue());
                    d->SetFoldCompact(m_wcheckFoldCompact->GetValue());
                    d->SetForcePureLC(m_wtextForcePureLC->GetValue());
                    d->SetDecimalSeparator(m_wtextDecimalSeparator->GetValue());

                    d->SetKeywords(0, m_wcheckKeywords1->GetValue());
                    d->SetKeywords(1, m_wcheckKeywords2->GetValue());
                    d->SetKeywords(2, m_wcheckKeywords3->GetValue());
                    d->SetKeywords(3, m_wcheckKeywords4->GetValue());
                    d->SetKeywords(4, m_wcheckKeywords5->GetValue());
                    d->SetKeywords(5, m_wcheckKeywords6->GetValue());
                    d->SetKeywords(6, m_wcheckKeywords7->GetValue());
                    d->SetKeywords(7, m_wcheckKeywords8->GetValue());
                    d->Changed(false);
                }
                break;

            case ITEM_TYPE_LANG_KEYWORDS:
                {
                    sTreeItemLangKeywordsData *d = (sTreeItemLangKeywordsData *)data;

                    d->SetName(m_wtextTextLang->GetValue());
                    d->SetText(m_wtextContentLang->GetValue());
                    d->Changed(false);
                }
                break;

            case ITEM_TYPE_LANG_WORDSTYLE:
                {
                    sTreeItemLangWordstyleData *d = (sTreeItemLangWordstyleData *)data;

                    d->SetName(m_wtextTextLang->GetValue());

                    d->SetFgColor(m_wpanelFgColor->GetBackgroundColour().GetAsString(wxC2S_HTML_SYNTAX));
                    d->SetBgColor(m_wpanelBgColor->GetBackgroundColour().GetAsString(wxC2S_HTML_SYNTAX));

                    d->SetFontName(m_wtextFontName->GetValue());
                    d->SetFontStyle(m_wtextFontStyle->GetValue());
                    d->SetFontSize(m_wtextFontSize->GetValue());
                    d->Changed(false);
                }
                break;

            case ITEM_TYPE_UNDEF:
                break;
        }
    }
}

void SerialEM4NPPFrame::OnSelectionChanged(wxTreeEvent& event)
{
    wxTreeItemId id = event.GetItem();
    wxTreeCtrl *tree = wxDynamicCast(event.GetEventObject(), wxTreeCtrl);
    sTreeItemData *data = (sTreeItemData *)tree->GetItemData(id);


    if (data)
    {
        switch (data->GetType())
        {
            //
            // API
            //
            case ITEM_TYPE_COMMENT:
                {
                    sTreeItemCommentData *d = (sTreeItemCommentData *)data;

                    m_wbtnItemAdd->Enable(false);
                    m_wbtnItemDel->Enable(false);
                    //m_wbtnExportFunctionNames->Enable(false);

                    m_wcheckEnvCase->SetValue(false);
                    m_wtextEnvStart->ChangeValue(wxEmptyString);
                    m_wtextEnvStop->ChangeValue(wxEmptyString);
                    m_wtextEnvSep->ChangeValue(wxEmptyString);
                    _enableSizerChilds(m_wsizerEnv, false);

                    m_wtextFunctionName->Enable(false);
                    m_wtextFunctionName->ChangeValue(wxEmptyString);

                    m_wtextFunctionArgs->Enable(false);
                    m_wtextFunctionArgs->ChangeValue(wxEmptyString);

                    m_wtextFunctionDescription->Enable(true);
                    m_wtextFunctionDescription->ChangeValue(wxEmptyString);

                    m_wtextFunctionDescription->ChangeValue(d->GetComment());
                }
                break;

            case ITEM_TYPE_ENVIRONMENT:
                {
                    sTreeItemEnvironmentData *d = (sTreeItemEnvironmentData *)data;

                    m_wbtnItemAdd->Enable(false);
                    m_wbtnItemDel->Enable(false);
                    //m_wbtnExportFunctionNames->Enable(false);

                    _enableSizerChilds(m_wsizerEnv, true);

                    m_wtextFunctionName->Enable(false);
                    m_wtextFunctionName->ChangeValue(wxEmptyString);

                    m_wtextFunctionArgs->Enable(false);
                    m_wtextFunctionArgs->ChangeValue(wxEmptyString);

                    m_wtextFunctionDescription->Enable(false);
                    m_wtextFunctionDescription->ChangeValue(wxEmptyString);

                    m_wcheckEnvCase->SetValue(d->GetIgnoreCase());
                    m_wtextEnvStart->ChangeValue(d->GetStartFunc());
                    m_wtextEnvStop->ChangeValue(d->GetStopFunc());
                    m_wtextEnvSep->ChangeValue(d->GetParamSeparator());
                }
                break;

            case ITEM_TYPE_FUNCTION:
                {
                    sTreeItemFunctionData *d = (sTreeItemFunctionData *)data;

                    m_wbtnItemAdd->Enable(true);
                    m_wbtnItemDel->Enable(true);
                    //m_wbtnExportFunctionNames->Enable(true);

                    m_wcheckEnvCase->SetValue(false);
                    m_wtextEnvStart->ChangeValue(wxEmptyString);
                    m_wtextEnvStop->ChangeValue(wxEmptyString);
                    m_wtextEnvSep->ChangeValue(wxEmptyString);
                    _enableSizerChilds(m_wsizerEnv, false);

                    m_wtextFunctionName->Enable(true);
                    m_wtextFunctionName->ChangeValue(wxEmptyString);

                    m_wtextFunctionArgs->Enable(true);
                    m_wtextFunctionArgs->ChangeValue(wxEmptyString);

                    m_wtextFunctionDescription->Enable(true);
                    m_wtextFunctionDescription->ChangeValue(wxEmptyString);

                    m_wtextFunctionName->ChangeValue(d->GetFunctionName());

                    wxArrayString ar = d->GetFunctionParameters();
                    wxString s;

                    for (size_t i = 0; i < ar.GetCount(); i++)
                        s << ar.Item(i);// << wxT("\n");

                    m_wtextFunctionArgs->ChangeValue(s);

                    m_wtextFunctionDescription->ChangeValue(d->GetFunctionDescription());
                }
                break;

            //
            // Language
            //
            case ITEM_TYPE_LANG_USERLANG:
                {
                    sTreeItemLangUserlangData *d = (sTreeItemLangUserlangData *)data;

                    _enableSizerChilds(m_wsizerNameLang, false);
                    _enableSizerChilds(m_wsizerPrefixLang, false);
                    _enableSizerChilds(m_wsizerSettingsLang, false);
                    _enableSizerChilds(m_wsizerUserLang, true);
                    _enableSizerChilds(m_wsizerWordsStyleLang, false);
                    _enableSizerChilds(m_wsizerContentLang, false);

                    // Clear
                    m_wtextTextLang->ChangeValue(wxEmptyString);

                    m_wcheckKeywords1->SetValue(false);
                    m_wcheckKeywords2->SetValue(false);
                    m_wcheckKeywords3->SetValue(false);
                    m_wcheckKeywords4->SetValue(false);
                    m_wcheckKeywords5->SetValue(false);
                    m_wcheckKeywords6->SetValue(false);
                    m_wcheckKeywords7->SetValue(false);
                    m_wcheckKeywords8->SetValue(false);

                    m_wcheckCaseIgnored->SetValue(false);
                    m_wcheckAllowFoldOfComments->SetValue(false);
                    m_wcheckAllowFoldOfComments->SetValue(false);

                    m_wtextForcePureLC->ChangeValue(wxEmptyString);
                    m_wtextDecimalSeparator->ChangeValue(wxEmptyString);

                    m_wtextUserLangName->ChangeValue(wxEmptyString);
                    m_wtextUserLangExt->ChangeValue(wxEmptyString);

                    m_wpanelFgColor->SetBackgroundColour(wxNullColour);
                    m_wpanelFgColor->ClearBackground();
                    m_wpanelBgColor->SetBackgroundColour(wxNullColour);
                    m_wpanelBgColor->ClearBackground();

                    m_wtextFontName->ChangeValue(wxEmptyString);
                    m_wtextFontStyle->ChangeValue(wxEmptyString);
                    m_wtextFontSize->ChangeValue(wxEmptyString);

                    m_wtextContentLang->ChangeValue(wxEmptyString);


                    m_wtextUserLangName->ChangeValue(d->GetName());
                    m_wtextUserLangExt->ChangeValue(d->GetExt());
                }
                break;

            case ITEM_TYPE_LANG_SETTINGS:
                {
                    sTreeItemLangSettingsData *d = (sTreeItemLangSettingsData *)data;

                    _enableSizerChilds(m_wsizerNameLang, false);
                    _enableSizerChilds(m_wsizerPrefixLang, true);
                    _enableSizerChilds(m_wsizerSettingsLang, true);
                    _enableSizerChilds(m_wsizerUserLang, false);
                    _enableSizerChilds(m_wsizerWordsStyleLang, false);
                    _enableSizerChilds(m_wsizerContentLang, false);

                    // Clear
                    m_wtextTextLang->ChangeValue(wxEmptyString);

                    m_wcheckKeywords1->SetValue(false);
                    m_wcheckKeywords2->SetValue(false);
                    m_wcheckKeywords3->SetValue(false);
                    m_wcheckKeywords4->SetValue(false);
                    m_wcheckKeywords5->SetValue(false);
                    m_wcheckKeywords6->SetValue(false);
                    m_wcheckKeywords7->SetValue(false);
                    m_wcheckKeywords8->SetValue(false);

                    m_wcheckCaseIgnored->SetValue(false);
                    m_wcheckAllowFoldOfComments->SetValue(false);
                    m_wcheckAllowFoldOfComments->SetValue(false);

                    m_wtextForcePureLC->ChangeValue(wxEmptyString);
                    m_wtextDecimalSeparator->ChangeValue(wxEmptyString);

                    m_wtextUserLangName->ChangeValue(wxEmptyString);
                    m_wtextUserLangExt->ChangeValue(wxEmptyString);

                    m_wpanelFgColor->SetBackgroundColour(wxNullColour);
                    m_wpanelFgColor->ClearBackground();
                    m_wpanelBgColor->SetBackgroundColour(wxNullColour);
                    m_wpanelBgColor->ClearBackground();

                    m_wtextFontName->ChangeValue(wxEmptyString);
                    m_wtextFontStyle->ChangeValue(wxEmptyString);
                    m_wtextFontSize->ChangeValue(wxEmptyString);

                    m_wtextContentLang->ChangeValue(wxEmptyString);


                    //
                    //
                    m_wcheckCaseIgnored->SetValue(d->GetCaseIgnored());
                    m_wcheckAllowFoldOfComments->SetValue(d->GetAllowFoldOfComments());
                    m_wcheckFoldCompact->SetValue(d->GetFoldCompact());
                    m_wtextForcePureLC->ChangeValue(d->GetForcePureLC());
                    m_wtextDecimalSeparator->ChangeValue(d->GetDecimalSeparator());

                    m_wcheckKeywords1->SetValue(d->GetKeywords(0));
                    m_wcheckKeywords2->SetValue(d->GetKeywords(1));
                    m_wcheckKeywords3->SetValue(d->GetKeywords(2));
                    m_wcheckKeywords4->SetValue(d->GetKeywords(3));
                    m_wcheckKeywords5->SetValue(d->GetKeywords(4));
                    m_wcheckKeywords6->SetValue(d->GetKeywords(5));
                    m_wcheckKeywords7->SetValue(d->GetKeywords(6));
                    m_wcheckKeywords8->SetValue(d->GetKeywords(7));

                }
                break;

            case ITEM_TYPE_LANG_KEYWORDS:
                {
                    sTreeItemLangKeywordsData *d = (sTreeItemLangKeywordsData *)data;

                    _enableSizerChilds(m_wsizerNameLang, true);
                    _enableSizerChilds(m_wsizerPrefixLang, false);
                    _enableSizerChilds(m_wsizerSettingsLang, false);
                    _enableSizerChilds(m_wsizerUserLang, false);
                    _enableSizerChilds(m_wsizerWordsStyleLang, false);
                    _enableSizerChilds(m_wsizerContentLang, true);

                    // Clear
                    m_wtextTextLang->ChangeValue(wxEmptyString);

                    m_wcheckKeywords1->SetValue(false);
                    m_wcheckKeywords2->SetValue(false);
                    m_wcheckKeywords3->SetValue(false);
                    m_wcheckKeywords4->SetValue(false);
                    m_wcheckKeywords5->SetValue(false);
                    m_wcheckKeywords6->SetValue(false);
                    m_wcheckKeywords7->SetValue(false);
                    m_wcheckKeywords8->SetValue(false);

                    m_wcheckCaseIgnored->SetValue(false);
                    m_wcheckAllowFoldOfComments->SetValue(false);
                    m_wcheckAllowFoldOfComments->SetValue(false);

                    m_wtextForcePureLC->ChangeValue(wxEmptyString);
                    m_wtextDecimalSeparator->ChangeValue(wxEmptyString);

                    m_wtextUserLangName->ChangeValue(wxEmptyString);
                    m_wtextUserLangExt->ChangeValue(wxEmptyString);

                    m_wpanelFgColor->SetBackgroundColour(wxNullColour);
                    m_wpanelFgColor->ClearBackground();
                    m_wpanelBgColor->SetBackgroundColour(wxNullColour);
                    m_wpanelBgColor->ClearBackground();

                    m_wtextFontName->ChangeValue(wxEmptyString);
                    m_wtextFontStyle->ChangeValue(wxEmptyString);
                    m_wtextFontSize->ChangeValue(wxEmptyString);

                    m_wtextContentLang->ChangeValue(wxEmptyString);


                    //
                    //
                    m_wtextTextLang->ChangeValue(d->GetName());
                    m_wtextContentLang->ChangeValue(d->GetText());
                }
                break;

            case ITEM_TYPE_LANG_WORDSTYLE:
                {
                    sTreeItemLangWordstyleData *d = (sTreeItemLangWordstyleData *)data;

                    _enableSizerChilds(m_wsizerNameLang, true);
                    _enableSizerChilds(m_wsizerPrefixLang, false);
                    _enableSizerChilds(m_wsizerSettingsLang, false);
                    _enableSizerChilds(m_wsizerUserLang, false);
                    _enableSizerChilds(m_wsizerWordsStyleLang, true);
                    _enableSizerChilds(m_wsizerContentLang, false);

                    // Clear
                    m_wtextTextLang->ChangeValue(wxEmptyString);

                    m_wcheckKeywords1->SetValue(false);
                    m_wcheckKeywords2->SetValue(false);
                    m_wcheckKeywords3->SetValue(false);
                    m_wcheckKeywords4->SetValue(false);
                    m_wcheckKeywords5->SetValue(false);
                    m_wcheckKeywords6->SetValue(false);
                    m_wcheckKeywords7->SetValue(false);
                    m_wcheckKeywords8->SetValue(false);

                    m_wcheckCaseIgnored->SetValue(false);
                    m_wcheckAllowFoldOfComments->SetValue(false);
                    m_wcheckAllowFoldOfComments->SetValue(false);

                    m_wtextForcePureLC->ChangeValue(wxEmptyString);
                    m_wtextDecimalSeparator->ChangeValue(wxEmptyString);

                    m_wtextUserLangName->ChangeValue(wxEmptyString);
                    m_wtextUserLangExt->ChangeValue(wxEmptyString);

                    m_wpanelFgColor->SetBackgroundColour(wxNullColour);
                    m_wpanelFgColor->ClearBackground();
                    m_wpanelBgColor->SetBackgroundColour(wxNullColour);
                    m_wpanelBgColor->ClearBackground();

                    m_wtextFontName->ChangeValue(wxEmptyString);
                    m_wtextFontStyle->ChangeValue(wxEmptyString);
                    m_wtextFontSize->ChangeValue(wxEmptyString);

                    m_wtextContentLang->ChangeValue(wxEmptyString);


                    //
                    //
                    m_wtextTextLang->ChangeValue(d->GetName());
                    wxColor fgcolor(wxT("#") + d->GetFgColor());
                    m_wpanelFgColor->SetBackgroundColour(fgcolor);
                    m_wpanelFgColor->ClearBackground();
                    wxColor bgcolor(wxT("#") + d->GetBgColor());
                    m_wpanelBgColor->SetBackgroundColour(bgcolor);
                    m_wpanelBgColor->ClearBackground();
                    m_wtextFontName->ChangeValue(d->GetFontName());
                    m_wtextFontStyle->ChangeValue(d->GetFontStyle());
                    m_wtextFontSize->ChangeValue(d->GetFontSize());
                }
                break;


            case ITEM_TYPE_UNDEF:
                break;
        }
    }

}

void SerialEM4NPPFrame::OnSelectionChanging(wxTreeEvent& event)
{
    wxTreeCtrl *tree = wxDynamicCast(event.GetEventObject(), wxTreeCtrl);
    wxTreeItemId id = tree->GetSelection();
    sTreeItemData *data = id.IsOk() ? (sTreeItemData *)tree->GetItemData(id) : NULL;

    if (data)
    {
        if (data->HasChanged())
        {
            wxMessageDialog dialog(this, wxT("Save the item changes ?"), wxT("Warning"), wxYES_NO|wxCANCEL|wxYES_DEFAULT|wxICON_WARNING);
            int ret;

            ret = dialog.ShowModal();

            switch (ret)
            {
                case wxID_YES:
                    _storeItem(tree, id);
                    break;

                case wxID_NO:
                    event.Skip();
                    break;

                case wxID_CANCEL:
                    event.Veto();
                    break;
            }

        }
    }
}

void SerialEM4NPPFrame::OnInputText(wxCommandEvent& event)
{
    wxTreeItemId id = m_wtree->GetSelection();
    sTreeItemData *data = id.IsOk() ? (sTreeItemData *)m_wtree->GetItemData(id) : NULL;

    if (data)
    {
        data->Changed();
        m_notebook->SetPageText(0, wxT("Plugin*"));
        //m_wbtnSave->Enable();
    }

    event.Skip();
}

void SerialEM4NPPFrame::OnEnvCaseClick(wxCommandEvent& event)
{
    wxTreeItemId id = m_wtree->GetSelection();
    sTreeItemData *data = id.IsOk() ? (sTreeItemData *)m_wtree->GetItemData(id) : NULL;

    if (data)
    {
        data->Changed();
        m_notebook->SetPageText(0, wxT("Plugin*"));
        //m_wbtnSave->Enable();
    }

    event.Skip();
}

void SerialEM4NPPFrame::OnSaveClick(wxCommandEvent& event)
{
    m_wfileDialog->SetWildcard(wxT("XML files (*.xml)|*.xml|All types (*.*)|*.*"));
    m_wfileDialog->SetPath(wxT("SerialEM-new.xml"));

    wxTreeItemId id = m_wtree->GetSelection();

    if (id.IsOk())
        _storeItem(m_wtree, id);

    if (m_wfileDialog->ShowModal() == wxID_OK)
    {
        wxString file = m_wfileDialog->GetPath();

        if (wxFileName::Exists(file))
        {
            if (wxMessageBox(wxT("The destination file '") + file + wxT("' exists.\nDo you want to ovewrite ?"),
                             wxT("Warning"), wxYES_NO|wxNO_DEFAULT|wxICON_WARNING) != wxYES)
            {
                return;
            }
        }

        wxXmlDocument doc;//(file, wxT("Windows-1252"));

        _fillXmlFromTree(&doc, m_wtree);

        doc.SetFileEncoding(wxT("Windows-1252"));

        if (! doc.Save(file, 4))
        {
            wxMessageBox(wxT("Unable to save '") + file + wxT("': ") + wxSysErrorMsg(wxSysErrorCode()), wxT("Error"), wxOK|wxICON_ERROR);
        }
        else
        {
            m_notebook->SetPageText(0, wxT("Plugin"));

            // Clear all change states
            wxTreeItemId                root = m_wtree->GetRootItem();
            wxTreeItemIdValue           cookie;
            wxTreeItemId                id = m_wtree->GetFirstChild(root, cookie);

            do
            {
                if (id.IsOk())
                {
                    sTreeItemData *data = (sTreeItemData *)m_wtree->GetItemData(id);

                    data->Changed(false);
                }

            } while ((id = m_wtree->GetNextChild(id, cookie)) && id.IsOk());


            //m_wbtnSave->Enable(false);
        }
    }
    event.Skip();
}

void SerialEM4NPPFrame::OnTreeBeginDrag(wxTreeEvent& event)
{
    wxTreeCtrl *tree = wxDynamicCast(event.GetEventObject(), wxTreeCtrl);
//    wxTreeCtrl *tree = (wxTreeCtrl *)event.GetEventObject();

    if (event.GetItem() != tree->GetRootItem())
    {
        m_draggedItem = event.GetItem();
        event.Allow();
    }
}

void SerialEM4NPPFrame::OnTreeEndDrag(wxTreeEvent& event)
{
    wxTreeCtrl *tree = wxDynamicCast(event.GetEventObject(), wxTreeCtrl);
//    wxTreeCtrl *tree = (wxTreeCtrl *)event.GetEventObject();
    wxTreeItemId itemSrc  = m_draggedItem;
    wxTreeItemId itemDest = event.GetItem();

    m_draggedItem = (wxTreeItemId) 0L;

    if (! itemDest.IsOk())
    {
        wxMessageBox(wxT("OnTreeEndDrag(): can't drop here"), wxT("Error"));
        return;
    }

    wxTreeItemId id = tree->InsertItem(tree->GetRootItem(), itemDest,
                                          tree->GetItemText(itemSrc), -1, -1, tree->GetItemData(itemSrc));

    // Remove item data ref, otherwise it will be deleted
    tree->SetItemData(itemSrc, NULL);
    tree->Delete(itemSrc);

    tree->SelectItem(id);

    event.Skip();
}

void SerialEM4NPPFrame::Onm_wbtnItemAddClick(wxCommandEvent& event)
{
    wxTreeItemId idSel = m_wtree->GetSelection();
    sTreeItemData *data = idSel.IsOk() ? (sTreeItemData *)m_wtree->GetItemData(idSel) : NULL;

    if (idSel.IsOk() && data && (data->GetType() == ITEM_TYPE_FUNCTION))
    {
        wxTextEntryDialog dialog(this, wxT("Enter the keyword"));

        if (dialog.ShowModal() == wxID_OK)
        {
            sTreeItemFunctionData *data = new sTreeItemFunctionData();
            data->SetFunctionName(dialog.GetValue());

            wxTreeItemId id = m_wtree->InsertItem(m_wtree->GetRootItem(), idSel, data->GetFunctionName(), -1, -1, (wxTreeItemData *)data);
            m_wtree->SelectItem(id, true);
        }
    }

    event.Skip();
}

void SerialEM4NPPFrame::Onm_wbtnItemDelClick(wxCommandEvent& event)
{
    wxTreeItemId idSel = m_wtree->GetSelection();
    sTreeItemData *data = idSel.IsOk() ? (sTreeItemData *)m_wtree->GetItemData(idSel) : NULL;

    if (idSel.IsOk() && data && (data->GetType() == ITEM_TYPE_FUNCTION))
    {
        if (wxMessageBox(wxT("Do you really want to delete '")
                         + ((sTreeItemFunctionData *)data)->GetFunctionName()
                         + wxT("' entry ?"), wxT("Warning"), wxYES_NO|wxNO_DEFAULT|wxICON_WARNING) == wxYES)
        {
            wxTreeItemId id = m_wtree->GetPrevSibling(idSel);
            m_wtree->Delete(idSel);

            m_wtree->SelectItem(id, true);
        }
    }

    event.Skip();
}

void SerialEM4NPPFrame::OnSplitterWindow1SashPosChanged(wxSplitterEvent& event)
{
//    int i = SplitterWindow1->GetSashPosition();
}

void SerialEM4NPPFrame::OnBitmapButton1Click(wxCommandEvent& event)
{
    wxTreeItemId id = m_wtree->GetSelection();

    if (id.IsOk())
    {
        _storeItem(m_wtree, id);
        m_wtree->SelectItem(id, true);
    }

    event.Skip();
}

void SerialEM4NPPFrame::OnLoadLangClick(wxCommandEvent& event)
{
    m_wfileDialog->SetWildcard(wxT("XML files (*.xml)|*.xml|All types (*.*)|*.*"));
    m_wfileDialog->SetPath(wxT("SerialEM_Lang.xml"));

    if (m_wfileDialog->ShowModal() == wxID_OK)
    {
        wxXmlDocument   doc;
        wxString        file = m_wfileDialog->GetPath();

        m_wtextInputLang->SetValue(file);

        m_langLoaded = false;

        if (doc.Load(file))
        {
            if (doc.GetRoot()->GetName() != wxT("NotepadPlus"))
                wxMessageBox(wxT("Unable to get root"), wxT("Error"));
            else
            {
                //debug(wxT("Encoding: ") + m_xmlDoc.GetFileEncoding());

                _parseLang(&doc);

                m_langLoaded = true;
            }
        }
        else
        {

        }
    }

    m_wbtnSaveLang->Enable(m_langLoaded);
}

void SerialEM4NPPFrame::OnPanelColorClick(wxMouseEvent& event)
{
    wxPanel *panel = wxDynamicCast(event.GetEventObject(), wxPanel);

    if (m_wcolourDialog->ShowModal() == wxID_OK)
    {
        wxTreeItemId id = m_wtreeLang->GetSelection();
        sTreeItemData *data = id.IsOk() ? (sTreeItemData *)m_wtreeLang->GetItemData(id) : NULL;

        if (data)
        {
            data->Changed();
            m_notebook->SetPageText(1, wxT("Language*"));
        }

        wxColor color = m_wcolourDialog->GetColourData().GetColour();

        panel->SetBackgroundColour(color);
        panel->ClearBackground();
    }


    event.Skip();
}

void SerialEM4NPPFrame::OnBitmapButton4Click(wxCommandEvent& event)
{
    wxTreeItemId id = m_wtreeLang->GetSelection();

    if (id.IsOk())
    {
        _storeItem(m_wtree, id);
        m_wtreeLang->SelectItem(id, true);
    }

    event.Skip();
}

void SerialEM4NPPFrame::Onm_wbtnExportFunctionNamesClick(wxCommandEvent& event)
{
    wxLogNull noLog; // Shut up please ;-)

    m_wfileDialog->SetWildcard(wxT("Text files (*.txt)|*.txt|All types (*.*)|*.*"));
    m_wfileDialog->SetPath(wxT("SerialEM_Commands.txt"));

    if (m_wfileDialog->ShowModal() == wxID_OK)
    {
        wxString filename = m_wfileDialog->GetPath();
        wxTextFile file(filename);

        // The file already exists, ask to overwrite
        if (wxFileName::Exists(filename))
        {
            wxFileName fn(filename);

            if (wxMessageBox(wxT("The file ") + fn.GetFullName() + wxT(" already exists, do you want to override it ?"),
                             wxT("Warning"), wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION) == wxNO)
            {
                return;
            }
        }

        // Try to reopen file
        if (! file.Open())
        {
            // File did not exist, create it.
            if (!file.Create())
            {
                wxMessageBox(wxT("Failed to Create() '") + filename + wxT("': ") + wxSysErrorMsg(wxSysErrorCode()), wxT("Error"), wxOK|wxICON_ERROR);
                return;
            }

            if (! file.Open())
                wxMessageBox(wxT("Failed to Open() '") + filename + wxT("': ") + wxSysErrorMsg(wxSysErrorCode()), wxT("Error"), wxOK|wxICON_ERROR);
        }

        // Ensure file is open now
        if (! file.IsOpened())
        {
            wxMessageBox(wxT("File not opened:  ") + filename, wxT("Error"), wxOK|wxICON_ERROR);

            return;
        }

        // Erase file content (in memory)
        file.Clear();

        // Settings TAG
//        file.AddLine(wxT("SerialEMSettings"));


        // Build file
        wxTreeItemId                root = m_wtree->GetRootItem();
        wxTreeItemIdValue           cookie;
        wxTreeItemId                id = m_wtree->GetFirstChild(root, cookie);

        do
        {
            if (id.IsOk())
            {
                sTreeItemData *data = (sTreeItemData *)m_wtree->GetItemData(id);

                switch (data->GetType())
                {
                    case ITEM_TYPE_FUNCTION:
                        {
                            sTreeItemFunctionData *d = (sTreeItemFunctionData *)data;

                            file.AddLine(d->GetFunctionName());
                        }
                        break;

                    case ITEM_TYPE_ENVIRONMENT:
                    case ITEM_TYPE_COMMENT:
                    case ITEM_TYPE_LANG_USERLANG:
                    case ITEM_TYPE_LANG_SETTINGS:
                    case ITEM_TYPE_LANG_KEYWORDS:
                    case ITEM_TYPE_LANG_WORDSTYLE:
                    case ITEM_TYPE_UNDEF:
                        break;
                }
            }

        } while ((id = m_wtree->GetNextChild(id, cookie)) && id.IsOk());

        // Dude! something's wrong in wonderland...
        if (! file.Write())
        {
            wxMessageBox(wxT("Unable to save ") + file.GetName() + wxT(": ") + wxSysErrorMsg(wxSysErrorCode()),  wxT("Error"), wxOK|wxICON_ERROR);
            return;
        }

        if (! file.Close())
        {
            wxMessageBox(wxT("Unable to save ") + file.GetName() + wxT(": ") + wxSysErrorMsg(wxSysErrorCode()),  wxT("Error"), wxOK|wxICON_ERROR);
        }


    }
}

void SerialEM4NPPFrame::OnInputTextLang(wxCommandEvent& event)
{
    wxTreeItemId id = m_wtreeLang->GetSelection();
    sTreeItemData *data = id.IsOk() ? (sTreeItemData *)m_wtreeLang->GetItemData(id) : NULL;

    if (data)
    {
        data->Changed();
        m_notebook->SetPageText(1, wxT("Language*"));
    }

    event.Skip();
}

void SerialEM4NPPFrame::OnCheckLangClick(wxCommandEvent& event)
{
    wxTreeItemId id = m_wtreeLang->GetSelection();
    sTreeItemData *data = id.IsOk() ? (sTreeItemData *)m_wtreeLang->GetItemData(id) : NULL;

    if (data)
    {
        data->Changed();
        m_notebook->SetPageText(1, wxT("Language*"));
    }

    event.Skip();
}

void SerialEM4NPPFrame::OnSaveLangClick(wxCommandEvent& event)
{
    m_wfileDialog->SetWildcard(wxT("XML files (*.xml)|*.xml|All types (*.*)|*.*"));
    m_wfileDialog->SetPath(wxT("SerialEM_Lang-new.xml"));


    wxTreeItemId id = m_wtreeLang->GetSelection();

    if (id.IsOk())
        _storeItem(m_wtreeLang, id);

    if (m_wfileDialog->ShowModal() == wxID_OK)
    {
        wxString file = m_wfileDialog->GetPath();

        if (wxFileName::Exists(file))
        {
            if (wxMessageBox(wxT("The destination file '") + file + wxT("' exists.\nDo you want to ovewrite ?"),
                             wxT("Warning"), wxYES_NO|wxNO_DEFAULT|wxICON_WARNING) != wxYES)
            {
                return;
            }
        }

        wxXmlDocument doc;

        _fillXmlFromTree(&doc, m_wtreeLang);

        doc.SetFileEncoding(wxT("Windows-1252"));

        if (! doc.Save(file, 4))
        {
            wxMessageBox(wxT("Unable to save '") + file + wxT("': ") + wxSysErrorMsg(wxSysErrorCode()), wxT("Error"), wxOK|wxICON_ERROR);
        }
        else
        {
            m_notebook->SetPageText(1, wxT("Language"));

            // Clear all change states
            wxTreeItemId                root = m_wtreeLang->GetRootItem();
            wxTreeItemIdValue           cookie;
            wxTreeItemId                id = m_wtreeLang->GetFirstChild(root, cookie);

            do
            {
                if (id.IsOk())
                {
                    sTreeItemData *data = (sTreeItemData *)m_wtreeLang->GetItemData(id);

                    data->Changed(false);
                }

            } while ((id = m_wtreeLang->GetNextChild(id, cookie)) && id.IsOk());

        }
    }
    event.Skip();
}

void SerialEM4NPPFrame::OnHtmlReloadClick(wxCommandEvent& event)
{
    wxProgressDialog dialog(wxT("Loading page..."), wxT("Please wait..."));

    dialog.Show();

    wxString uri = m_wtextBetaURL->GetValue();

    dialog.Pulse();

    //if it isn't a full url, try appending http:// to it
    if(wxURI(uri).IsReference())
        uri = wxString(wxT("http://")) + uri;

    dialog.Pulse();

    wxURL *url = new wxURL(uri);


    dialog.Pulse();

    wxInputStream *in_stream;

    dialog.Pulse();

    in_stream = url->GetInputStream();

    dialog.Pulse();

    size_t FileSize = in_stream->GetSize();

    dialog.Pulse();

    char *buffer = new char [FileSize];

    dialog.Pulse();

    in_stream->ReadAll(buffer, FileSize);

    dialog.Pulse();

    wxString content = buffer;

    m_whtmlWindowBeta->SetPage(content);

    dialog.Pulse();

    delete buffer;
    delete url;

    event.Skip();
}

void SerialEM4NPPFrame::Onm_whomeBetaHtmlClick(wxCommandEvent& event)
{
    // Beta URL
    m_wtextBetaURL->ChangeValue(wxT("http://bio3d.colorado.edu/SerialEM/hlp/html/macro_commands.htm"));

    wxCommandEvent evt;
    OnHtmlReloadClick(evt);

    event.Skip();
}

void SerialEM4NPPFrame::Onm_whomeStableHtmlClick(wxCommandEvent& event)
{
    // Stable URL
    m_wtextBetaURL->ChangeValue(wxT("http://bio3d.colorado.edu/SerialEM/stableHlp/html/macro_commands.htm"));

    wxCommandEvent evt;
    OnHtmlReloadClick(evt);

    event.Skip();
}

void SerialEM4NPPFrame::OnHtmlSaveClick(wxCommandEvent& event)
{    wxLogNull noLog; // Shut up please ;-)

    m_wfileDialog->SetWildcard(wxT("Text files (*.txt)|*.txt|All types (*.*)|*.*"));
    m_wfileDialog->SetPath(wxT("Content.txt"));

    if (m_wfileDialog->ShowModal() == wxID_OK)
    {
        wxString filename = m_wfileDialog->GetPath();
        wxTextFile file(filename);

        // The file already exists, ask to overwrite
        if (wxFileName::Exists(filename))
        {
            wxFileName fn(filename);

            if (wxMessageBox(wxT("The file ") + fn.GetFullName() + wxT(" already exists, do you want to override it ?"),
                             wxT("Warning"), wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION) == wxNO)
            {
                return;
            }
        }

        // Try to reopen file
        if (! file.Open())
        {
            // File did not exist, create it.
            if (!file.Create())
            {
                wxMessageBox(wxT("Failed to Create() '") + filename + wxT("': ") + wxSysErrorMsg(wxSysErrorCode()), wxT("Error"), wxOK|wxICON_ERROR);
                return;
            }

            if (! file.Open())
                wxMessageBox(wxT("Failed to Open() '") + filename + wxT("': ") + wxSysErrorMsg(wxSysErrorCode()), wxT("Error"), wxOK|wxICON_ERROR);
        }

        // Ensure file is open now
        if (! file.IsOpened())
        {
            wxMessageBox(wxT("File not opened:  ") + filename, wxT("Error"), wxOK|wxICON_ERROR);

            return;
        }

        // Erase file content (in memory)
        file.Clear();

        file.AddLine(m_whtmlWindowBeta->ToText());

        // Dude! something's wrong in wonderland...
        if (! file.Write())
        {
            wxMessageBox(wxT("Unable to save ") + file.GetName() + wxT(": ") + wxSysErrorMsg(wxSysErrorCode()),  wxT("Error"), wxOK|wxICON_ERROR);
            return;
        }

        if (! file.Close())
        {
            wxMessageBox(wxT("Unable to save ") + file.GetName() + wxT(": ") + wxSysErrorMsg(wxSysErrorCode()),  wxT("Error"), wxOK|wxICON_ERROR);
        }

    }

    event.Skip();
}

void SerialEM4NPPFrame::Onm_wtextBetaURLTextEnter(wxCommandEvent& event)
{
    wxCommandEvent evt;
    OnHtmlReloadClick(evt);

    event.Skip();
}

void SerialEM4NPPFrame::OnPanel7RightDown(wxMouseEvent& event)
{
    wxString str = m_whtmlWindowBeta->SelectionToText();

    m_whtmlCtxMenu->Enable(ID_CTXMENU_COPY, str != wxEmptyString);
    m_whtmlCtxMenu->Enable(ID_CTXMENU_PASTE, false);

    PopupMenu(m_whtmlCtxMenu);

    event.Skip();
}

void SerialEM4NPPFrame::OnHtmlCopy(wxCommandEvent& event)
{
    wxString str = m_whtmlWindowBeta->SelectionToText();

    if (wxTheClipboard->Open())
    {
        // Data objects are held by the clipboard,
        // so do not delete them in the app.
        wxTheClipboard->SetData(new wxTextDataObject(str));
        wxTheClipboard->Close();
    }

    event.Skip();
}

void SerialEM4NPPFrame::OnHtmlSelectAll(wxCommandEvent& event)
{
    m_whtmlWindowBeta->SelectAll();

    event.Skip();
}

void SerialEM4NPPFrame::OnHtmlPaste(wxCommandEvent& event)
{
    event.Skip();
}

