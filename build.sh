#!/bin/bash

VERSION=0.99.0
ZIPFILE=SerialEM_for_Notepad++_v$VERSION.zip

rm -rf build
rm -f $ZIPFILE

mkdir -p build/Program\ Files\ \(x86\)/Notepad++/plugins/APIs

cat ./Notepad++/plugins/APIs/SerialEM.xml | sed -e 's/@VERSION@/0.99.x/g' > build/Program\ Files\ \(x86\)/Notepad++/plugins/APIs/SerialEM.xml

cp -r ./UserLanguages build


cat > build/README.txt <<EOF
Installation:
------------

   1) Install Notepad++ (6.9.2 at the moment)
   2) Copy Program\ Files\ \(x86\)/Notepad++/plugins/APIs/SerialEM.xml to C:\Program\ Files\ \(x86\)/Notepad++/plugins/APIs/SerialEM.xml (Administrator rights required)
   3) Start Notepad++, select "Define your language..." from "Language" menu. Click "Import..." button and select one the SerialEM_Lang.xml in the UserLanguages, according to your color scheme (Default for with background, or DeepBlack for black background)
   4) Close and reopen Notepad++, SerialEM language can be selected at the bottom of the "Language" menu.



Usage:
----

To automatically select SerialEM language, just give ".sem" file extension of your macro files.
The autocompletion is case sensitive, all macro commands start with a upper case except repval* and argVal*. ReportedValue* are kept with first upper case letter to match SerialEM's documentation.

To get macro's syntax help popup, just press the question mark after the macro command, like:

     LongOperation ?
   or
     LongOperation?

Enjoy.
---
Daniel 
EOF


(cd build && echo "SerialEM language completion and syntax colorization v$VERSION." | zip -vr9 -z ../$ZIPFILE .)
