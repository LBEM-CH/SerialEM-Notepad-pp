/// -----------------------------------------------------------------------------///
/// \file SerialEM4NPPApp.cpp
///
/// \copyright Copyright (c) 2016-2019 Daniel Caujolle-Bert <daniel.caujolle-bert@unibas.ch>
/// \brief SerialEM for Notepad++ Tool
/// \author Daniel Caujolle-Bert <daniel.caujolle-bert@unibas.ch>
///
/// \license
/// All rights reserved. This program and the accompanying materials
/// are made available under the terms of the GNU Public License v2.0
/// which accompanies this distribution, and is available at
/// http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
///
/// This file is part of Zuul.
///
/// This program is free software; you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation; either version 2 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License along
/// with this program; if not, write to the Free Software Foundation, Inc.,
/// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
///
///
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
