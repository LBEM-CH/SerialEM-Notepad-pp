#!/bin/bash

VERSION=0.99.0
ZIPFILE=SerialEM_for_Notepad++_v$VERSION.zip

rm -rf build
rm -f $ZIPFILE

mkdir -p build/Program\ Files\ \(x86\)/Notepad++/plugins/APIs

cat ./Notepad++/plugins/APIs/SerialEM.xml | sed -e 's/@VERSION@/0.99.x/g' > build/Program\ Files\ \(x86\)/Notepad++/plugins/APIs/SerialEM.xml

cp -r ./UserLanguages build

(cd build && echo "SerialEM language completion and syntax colorization v$VERSION." | zip -vr9 -z ../$ZIPFILE .)
