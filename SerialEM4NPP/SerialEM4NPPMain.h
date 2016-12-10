/***************************************************************
 * Name:      SerialEM4NPPMain.h
 * Purpose:   Defines Application Frame
 * Author:    Daniel Caujolle-Bert (daniel.caujolle-bert@unibas.ch)
 * Created:   2016-12-01
 * Copyright: Daniel Caujolle-Bert (https://c-cina.unibas.ch/bioem/)
 * License:
 **************************************************************/

#ifndef SERIALEM4NPPMAIN_H
#define SERIALEM4NPPMAIN_H

//(*Headers(SerialEM4NPPFrame)
#include <wx/scrolwin.h>
#include <wx/treectrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/splitter.h>
#include <wx/aui/aui.h>
#include <wx/colordlg.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/html/htmlwin.h>
#include <wx/statusbr.h>
//*)

//#include <wx/app.h>
#include <wx/msgdlg.h>
#include <wx/progdlg.h>
#include <wx/xml/xml.h>
#include <wx/textdlg.h>
#include <wx/filename.h>
#include <wx/dir.h>
#include <wx/log.h>
#include <wx/textfile.h>
#include <wx/url.h>
#include <wx/clipbrd.h>
#include <wx/tokenzr.h>

#include <vector>

#include "SerialEM4NPPApp.h"
#include "version.h"

class SerialEM4NPPFrame;

enum sTreeItemType
{
    ITEM_TYPE_UNDEF,
    ITEM_TYPE_COMMENT,
    ITEM_TYPE_ENVIRONMENT,
    ITEM_TYPE_FUNCTION,
    ITEM_TYPE_LANG_USERLANG,
    ITEM_TYPE_LANG_SETTINGS,
    ITEM_TYPE_LANG_KEYWORDS,
    ITEM_TYPE_LANG_WORDSTYLE,
};

class sTreeItemData: public wxTreeItemData
{
    public:
        sTreeItemData() : wxTreeItemData(), m_type(ITEM_TYPE_UNDEF), m_hasChanged(false)
        {
        }

        sTreeItemData(sTreeItemType type) : wxTreeItemData(), m_type(type), m_hasChanged(false)
        {
        }

        sTreeItemType GetType()
        {
            return m_type;
        }


        void Changed(bool v = true)
        {
            m_hasChanged = v;
        }

        bool HasChanged()
        {
            return m_hasChanged;
        }

    private:
        sTreeItemType                   m_type;
        bool                            m_hasChanged;
};

class sTreeItemFunctionData: public sTreeItemData
{
    public:
        sTreeItemFunctionData() : sTreeItemData(ITEM_TYPE_FUNCTION)
        {

        }

        void SetFunctionName(const wxString &str)
        {
            m_functionName = str;
        }

        wxString GetFunctionName() const
        {
            return m_functionName;
        }

        void ClearFunctionParameter()
        {
            m_functionParams.Clear();
        }

        void AddFunctionParameter(const wxString &str)
        {
            m_functionParams.Add(str + wxT("\n"));
        }

        wxArrayString GetFunctionParameters() const
        {
            return m_functionParams;
        }

        void SetFunctionDescription(const wxString &str)
        {
            m_functionDescr = str;

            // Original \n+\t\t\t has been replaced
            // by 4 spaces by XML parser
            m_functionDescr.Replace(wxT("    "), wxT("\n"), true);

        }

        wxString GetFunctionDescription() const
        {
            return m_functionDescr;
        }

    private:
        wxString                        m_functionName;
        wxArrayString                   m_functionParams;
        wxString                        m_functionDescr;
};

class sTreeItemCommentData: public sTreeItemData
{
    public:
        sTreeItemCommentData() : sTreeItemData(ITEM_TYPE_COMMENT)
        {

        }

        void SetComment(const wxString &str)
        {
            m_comment = str;
        }

        wxString GetComment() const
        {
            return m_comment;
        }

    private:
        wxString                        m_comment;
};

class sTreeItemEnvironmentData: public sTreeItemData
{
    public:
        sTreeItemEnvironmentData() : sTreeItemData(ITEM_TYPE_ENVIRONMENT)
        {

        }

        void SetIgnoreCase(bool v)
        {
            m_ignore = v;
        }
        bool GetIgnoreCase()
        {
            return m_ignore;
        }

        void SetStartFunc(const wxString &str)
        {
            m_start = str;
        }
        wxString GetStartFunc() const
        {
            return m_start;
        }

        void SetStopFunc(const wxString &str)
        {
            m_stop = str;
        }
        wxString GetStopFunc() const
        {
            return m_stop;
        }

        void SetParamSeparator(const wxString &str)
        {
            m_sep = str;
        }
        wxString GetParamSeparator() const
        {
            return m_sep;
        }

    private:
        bool                            m_ignore;
        wxString                        m_start;
        wxString                        m_stop;
        wxString                        m_sep;
};

// Language
class sTreeItemLangUserlangData: public sTreeItemData
{
    public:
        sTreeItemLangUserlangData() : sTreeItemData(ITEM_TYPE_LANG_USERLANG)
        {

        }

        void SetName(const wxString &str)
        {
            m_name = str;
        }
        wxString GetName() const
        {
            return m_name;
        }

        void SetExt(const wxString &str)
        {
            m_ext = str;
        }
        wxString GetExt() const
        {
            return m_ext;
        }

        void SetUdlVersion(const wxString &str)
        {
            m_udlVersion = str;
        }
        wxString GetUdlVersion() const
        {
            return m_udlVersion;
        }

    private:
        wxString                        m_name;
        wxString                        m_ext;
        wxString                        m_udlVersion;
};

class sTreeItemLangSettingsData: public sTreeItemData
{
    public:
        sTreeItemLangSettingsData() : sTreeItemData(ITEM_TYPE_LANG_SETTINGS)
        {

        }

        void SetCaseIgnored(bool v)
        {
            m_caseIgnored = v;
        }
        bool GetCaseIgnored()
        {
            return m_caseIgnored;
        }

        void SetAllowFoldOfComments(bool v)
        {
            m_allowFoldOfComments = v;
        }
        bool GetAllowFoldOfComments()
        {
            return m_allowFoldOfComments;
        }

        void SetFoldCompact(bool v)
        {
            m_foldCompact = v;
        }
        bool GetFoldCompact()
        {
            return m_foldCompact;
        }

        void SetForcePureLC(const wxString &str)
        {
            m_forcePureLC = str;
        }
        wxString GetForcePureLC() const
        {
            return m_forcePureLC;
        }

        void SetDecimalSeparator(const wxString &str)
        {
            m_decimalSeparator = str;
        }
        wxString GetDecimalSeparator() const
        {
            return m_decimalSeparator;
        }

        void SetKeywords(size_t i, bool v)
        {
            if ((i >= 0) && (i < sizeof(m_Keywords) / sizeof(m_Keywords[0])))
                m_Keywords[i] = v;
        }
        bool GetKeywords(size_t i)
        {
            if ((i >= 0) && (i < sizeof(m_Keywords) / sizeof(m_Keywords[0])))
                return m_Keywords[i];

            return false;
        }

    private:
        bool                            m_caseIgnored;
        bool                            m_allowFoldOfComments;
        bool                            m_foldCompact;
        wxString                        m_forcePureLC;
        wxString                        m_decimalSeparator;
        bool                            m_Keywords[8];

};

class sTreeItemLangKeywordsData: public sTreeItemData
{
    public:
        sTreeItemLangKeywordsData() : sTreeItemData(ITEM_TYPE_LANG_KEYWORDS)
        {

        }

        void SetName(const wxString &str)
        {
            m_name = str;
        }
        wxString GetName() const
        {
            return m_name;
        }

        void SetText(const wxString &str)
        {
            m_text = str;
            m_text.Replace(wxT("\n"), wxT(" "), true);

            while (m_text.Find(wxT("  ")) != wxNOT_FOUND)
                m_text.Replace(wxT("  "), wxT(" "), true);
        }
        wxString GetText() const
        {
            return m_text;
        }

    private:
        wxString                        m_name;
        wxString                        m_text;
};

class sTreeItemLangWordstyleData: public sTreeItemData
{
    public:
        sTreeItemLangWordstyleData() : sTreeItemData(ITEM_TYPE_LANG_WORDSTYLE)
        {

        }

        void SetName(const wxString &str)
        {
            m_name = str;
        }
        wxString GetName() const
        {
            return m_name;
        }

        void SetFgColor(const wxString &str)
        {
            m_fgColor = str;
        }
        wxString GetFgColor() const
        {
            return m_fgColor;
        }
        void SetBgColor(const wxString &str)
        {
            m_bgColor = str;
        }
        wxString GetBgColor() const
        {
            return m_bgColor;
        }
        void SetFontName(const wxString &str)
        {
            m_fontName = str;
        }
        wxString GetFontName() const
        {
            return m_fontName;
        }
        void SetFontStyle(const wxString &str)
        {
            m_fontStyle = str;
        }
        wxString GetFontStyle() const
        {
            return m_fontStyle;
        }
        void SetFontSize(const wxString &str)
        {
            m_fontSize = str;
        }
        wxString GetFontSize() const
        {
            return m_fontSize;
        }
        void SetNesting(const wxString &str)
        {
            m_nesting = str;
        }
        wxString GetNesting() const
        {
            return m_nesting;
        }

    private:
        wxString                        m_name;
        wxString                        m_fgColor;
        wxString                        m_bgColor;
        wxString                        m_fontName;
        wxString                        m_fontStyle;
        wxString                        m_fontSize;
        wxString                        m_nesting;
};


class SerialEM4NPPFrame: public wxFrame
{
    public:
        SerialEM4NPPFrame(wxWindow* parent, wxWindowID id = -1);
        virtual ~SerialEM4NPPFrame();

    private:

        //(*Handlers(SerialEM4NPPFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnLoadClick(wxCommandEvent& event);
        void OnSelectionChanged(wxTreeEvent& event);
        void OnInputText(wxCommandEvent& event);
        void OnEnvCaseClick(wxCommandEvent& event);
        void OnSaveClick(wxCommandEvent& event);
        void OnTreeBeginDrag(wxTreeEvent& event);
        void OnTreeEndDrag(wxTreeEvent& event);
        void Onm_wbtnItemAddClick(wxCommandEvent& event);
        void Onm_wbtnItemDelClick(wxCommandEvent& event);
        void OnSplitterWindow1SashPosChanged(wxSplitterEvent& event);
        void OnSelectionChanging(wxTreeEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnLoadLangClick(wxCommandEvent& event);
        void OnPanelColorClick(wxMouseEvent& event);
        void OnBitmapButton4Click(wxCommandEvent& event);
        void Onm_wbtnExportFunctionNamesClick(wxCommandEvent& event);
        void OnInputTextLang(wxCommandEvent& event);
        void OnCheckLangClick(wxCommandEvent& event);
        void OnSaveLangClick(wxCommandEvent& event);
        void Onm_whomeBetaHtmlClick(wxCommandEvent& event);
        void Onm_whomeStableHtmlClick(wxCommandEvent& event);
        void Onm_wtextBetaURLTextEnter(wxCommandEvent& event);
        void OnPanel7RightDown(wxMouseEvent& event);
        void OnHtmlReloadClick(wxCommandEvent& event);
        void OnHtmlSaveClick(wxCommandEvent& event);
        void Onm_wbtnMissingKeywordsClick(wxCommandEvent& event);
        void Onm_wbtnSortContentClick(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        //*)

        void                            OnHtmlCopy(wxCommandEvent &);
        void                            OnHtmlSelectAll(wxCommandEvent &);
        void                            OnHtmlPaste(wxCommandEvent &);

        void                            _dataHasChanged(wxTreeCtrl *);
        bool                            _isDataHasChanged();

        void                            _enableSizerChilds(wxSizer *, bool);

        void                            _parseAttributes(wxXmlNode *, sTreeItemData *);
        void                            _traverseXmlNodes(wxTreeCtrl *, wxTreeItemId, wxXmlNode *);

        void                            _storeItem(wxTreeCtrl *, wxTreeItemId);
        void                            _parse(wxXmlDocument *);
        void                            _parseLang(wxXmlDocument *);

        void                            _fillXmlFromTree(wxXmlDocument *, wxTreeCtrl *);

        //(*Identifiers(SerialEM4NPPFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON4;
        static const long ID_TREECTRL2;
        static const long ID_PANEL4;
        static const long ID_TEXTCTRL2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_TEXTCTRL3;
        static const long ID_CHECKBOX1;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long ID_TEXTCTRL7;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT1;
        static const long ID_PANEL5;
        static const long ID_TEXTCTRL4;
        static const long ID_SCROLLEDWINDOW1;
        static const long ID_SPLITTERWINDOW1;
        static const long ID_PANEL2;
        static const long ID_TEXTCTRL8;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_TREECTRL1;
        static const long ID_PANEL6;
        static const long ID_TEXTCTRL9;
        static const long ID_BITMAPBUTTON6;
        static const long ID_CHECKBOX6;
        static const long ID_CHECKBOX5;
        static const long ID_CHECKBOX7;
        static const long ID_CHECKBOX8;
        static const long ID_CHECKBOX10;
        static const long ID_CHECKBOX11;
        static const long ID_CHECKBOX9;
        static const long ID_CHECKBOX12;
        static const long ID_CHECKBOX2;
        static const long ID_CHECKBOX3;
        static const long ID_CHECKBOX4;
        static const long ID_TEXTCTRL10;
        static const long ID_TEXTCTRL13;
        static const long ID_TEXTCTRL16;
        static const long ID_TEXTCTRL17;
        static const long ID_PANEL7;
        static const long ID_PANEL8;
        static const long ID_TEXTCTRL11;
        static const long ID_TEXTCTRL12;
        static const long ID_TEXTCTRL15;
        static const long ID_TEXTCTRL14;
        static const long ID_BITMAPBUTTON10;
        static const long ID_SCROLLEDWINDOW2;
        static const long ID_SPLITTERWINDOW2;
        static const long ID_PANEL3;
        static const long ID_TEXTCTRL18;
        static const long ID_BITMAPBUTTON7;
        static const long ID_BITMAPBUTTON8;
        static const long ID_BITMAPBUTTON5;
        static const long ID_BITMAPBUTTON9;
        static const long ID_HTMLWINDOW1;
        static const long ID_PANEL9;
        static const long ID_AUINOTEBOOK1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)
        static const long ID_CTXMENU_COPY;
        static const long ID_CTXMENU_SELECTALL;
        static const long ID_CTXMENU_PASTE;

        //(*Declarations(SerialEM4NPPFrame)
        wxTextCtrl* m_wtextEnvStop;
        wxTreeCtrl* m_wtree;
        wxPanel* m_panel7;
        wxButton* m_wbtnSave;
        wxTextCtrl* m_wtextForcePureLC;
        wxPanel* Panel5;
        wxTextCtrl* m_wtextTextLang;
        wxButton* m_wbtnSaveLang;
        wxTextCtrl* m_wtextDecimalSeparator;
        wxButton* m_wbtnLoadLang;
        wxTextCtrl* m_wtextUserLangExt;
        wxStaticBoxSizer* m_wsizerEnv;
        wxPanel* m_wpanelBgColor;
        wxTextCtrl* m_wtextEnvStart;
        wxStaticText* StaticText2;
        wxPanel* Panel4;
        wxScrolledWindow* ScrolledWindow1;
        wxSplitterWindow* SplitterWindow2;
        wxTextCtrl* m_wtextInput;
        wxCheckBox* m_wcheckKeywords8;
        wxColourDialog* m_wcolourDialog;
        wxBitmapButton* m_wbtmBtnSave;
        wxCheckBox* m_wcheckKeywords3;
        wxStaticBoxSizer* m_wsizerPrefixLang;
        wxPanel* Panel1;
        wxTextCtrl* m_wtextEnvSep;
        wxBitmapButton* m_wbtnExportFunctionNames;
        wxCheckBox* m_wcheckKeywords4;
        wxStaticText* StaticText1;
        wxCheckBox* m_wcheckKeywords7;
        wxTextCtrl* m_wtextFunctionDescription;
        wxCheckBox* m_wcheckKeywords6;
        wxButton* m_wbtnMissingKeywords;
        wxBitmapButton* m_wbtnItemAdd;
        wxPanel* Panel6;
        wxPanel* Panel3;
        wxTextCtrl* m_wtextInputLang;
        wxTextCtrl* m_wtextFontStyle;
        wxScrolledWindow* m_scrolledWindow;
        wxCheckBox* m_wcheckAllowFoldOfComments;
        wxTextCtrl* m_wtextFontSize;
        wxStaticBoxSizer* m_wsizerContentLang;
        wxBitmapButton* m_wbtnHtmlSave;
        wxTextCtrl* m_wtextFontName;
        wxTextCtrl* m_wtextFunctionArgs;
        wxStatusBar* StatusBar1;
        wxCheckBox* m_wcheckKeywords1;
        wxBitmapButton* m_wbtnHomeBetaHtml;
        wxPanel* m_wpanelFgColor;
        wxTextCtrl* m_wtextFunctionName;
        wxBitmapButton* BitmapButton4;
        wxStaticBoxSizer* m_wsizerWordsStyleLang;
        wxBitmapButton* m_wbtnReloadHtml;
        wxCheckBox* m_wcheckEnvCase;
        wxBitmapButton* m_wbtnHomeStableHtml;
        wxButton* m_wbtnLoad;
        wxPanel* Panel2;
        wxTextCtrl* m_wtextBetaURL;
        wxTreeCtrl* m_wtreeLang;
        wxFileDialog* m_wfileDialog;
        wxStaticBoxSizer* m_wsizerNameLang;
        wxCheckBox* m_wcheckKeywords5;
        wxSplitterWindow* SplitterWindow1;
        wxCheckBox* m_wcheckFoldCompact;
        wxStaticBoxSizer* m_wsizerUserLang;
        wxStaticBoxSizer* m_wsizerSettingsLang;
        wxCheckBox* m_wcheckKeywords2;
        wxTextCtrl* m_wtextContentLang;
        wxAuiNotebook* m_notebook;
        wxCheckBox* m_wcheckCaseIgnored;
        wxTextCtrl* m_wtextUserLangName;
        wxBitmapButton* m_wbtnSortContent;
        wxBitmapButton* m_wbtnItemDel;
        wxHtmlWindow* m_whtmlWindowBeta;
        //*)

        wxProgressDialog               *m_progress;
        bool                            m_apiLoaded;
        bool                            m_apiChanged;
        bool                            m_langLoaded;
        bool                            m_langChanged;
        wxTreeItemId                    m_draggedItem;

        wxMenu                         *m_whtmlCtxMenu;

        DECLARE_EVENT_TABLE()
};

#endif // SERIALEM4NPPMAIN_H
