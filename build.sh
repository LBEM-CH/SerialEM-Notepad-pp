#!/bin/bash

VERSION=0.99.2
ZIPFILE=SerialEM_for_Notepad++_v$VERSION.zip

rm -rf build
rm -f $ZIPFILE

mkdir -p build/Program\ Files\ \(x86\)/Notepad++/plugins/APIs

cat ./Notepad++/plugins/APIs/SerialEM.xml | sed -e 's/@VERSION@/'$VERSION'/' > build/Program\ Files\ \(x86\)/Notepad++/plugins/APIs/SerialEM.xml

cp -r ./UserLanguages build
cp gpl-2.0.txt build

cat > build/README.txt <<EOF
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
