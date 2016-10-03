#!/bin/bash

function backup()
{
    echo Arg: $1


    if test -f $1; then
	echo Backing up $1
	stamp=`date +%d-%m-%y_%H-%M-%S`
	mv $1 `basename $1 .html`-$stamp.html
    fi
	
}


function diffing()
{
    echo Diffing stable-$1-commands.html beta-$2-commands.html to $1-to-$2-diff.diff
    diff -uw stable-$1-commands.html beta-$2-commands.html > $1-to-$2-diff.diff
}



# Beta
read -p "Beta version ?: " bversion
echo Version: $bversion
backup beta-$bversion-commands.html
wget http://bio3d.colorado.edu/SerialEM/hlp/html/macro_commands.htm -O beta-$bversion-commands.html


read -p "Stable version ?: " sversion
echo Version: $sversion
backup stable-$sversion-commands.html
wget http://bio3d.colorado.edu/SerialEM/stableHlp/html/macro_commands.htm -O stable-$sversion-commands.html


diffing $sversion $bversion
