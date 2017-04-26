/***************************************************************
 * Name:      SerialEM4NPPApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Daniel Caujolle-Bert (daniel.caujolle-bert@unibas.ch)
 * Created:   2016-12-01
 * Copyright: Daniel Caujolle-Bert (https://c-cina.unibas.ch/bioem/)
 * License:
 **************************************************************/

#include "SerialEM4NPPApp.h"

//(*AppHeaders
#include "SerialEM4NPPMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SerialEM4NPPApp);

bool SerialEM4NPPApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	SerialEM4NPPFrame* Frame = new SerialEM4NPPFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
