#!/bin/bash

VERSION=0.99.3
ZIPFILE=SerialEM_for_Notepad++_v$VERSION.zip

rm -rf build
rm -f $ZIPFILE

mkdir -p build/Program\ Files\ \(x86\)/Notepad++/plugins/APIs

cat ./Notepad++/plugins/APIs/SerialEM.xml | sed -e 's/@VERSION@/'$VERSION'/' > build/Program\ Files\ \(x86\)/Notepad++/plugins/APIs/SerialEM.xml

cp -r ./UserLanguages build
cp gpl-2.0.txt build

cat > build/README.txt <<EOF
License:
-------
  Copyright (c) 2016 Daniel Caujolle-Bert <daniel.caujolle-bert@unibas.ch>, C-CINA <https://c-cina.unibas.ch>, BioEM Lab <https://c-cina.unibas.ch/bioem>

  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.
  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.



Installation:
------------

   1) Install Notepad++ (6.9.2 at the moment)
   2) Copy "Program Files (x86)/Notepad++/plugins/APIs/SerialEM.xml" to "C:\Program Files (x86)/Notepad++/plugins/APIs/SerialEM.xml" (Administrator rights required)
   3) Start Notepad++, select "Define your language..." from "Language" menu..
      Click "Import..." button and select one of the SerialEM_Lang.xml files in the "UserLanguages" sub-directories, according to 
      your color scheme: "Default" for white background, "DeepBlack" for black one)
   4) Restart Notepad++, SerialEM language can now be selected at the bottom of the "Language" menu.
      - If you want to have both imported, you have to rename at least one of the "SerialEM" entries, right after imports (like SerialEM Light, SerialEM Dark, ...).



Usage:
----

To automatically select SerialEM language, just give ".sem" file extension of your macro files.
The autocompletion is case sensitive: all macro commands start with an upper case character, except "repval*" and "argVal*". 
Also, "ReportedValue*" are kept with first upper case character to match SerialEM's documentation.

To get macro's syntax popup, just press the question mark after the macro name, e.g.:

  LongOperation ?
or
  LongOperation?

Enjoy.
---
Daniel 
EOF


(cd build && echo "SerialEM language completion and syntax colorization v$VERSION." | zip -vr9 -z ../$ZIPFILE .)
