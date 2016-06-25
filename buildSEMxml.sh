#/bin/bash

INPUT="serialem.api.SORTED2.txt"
OUTPUT="SerialEM.xml"
KEYWORD="SerialEM-Keyword.txt"

function header()
{
    cat >> $OUTPUT << EOF
<?xml version="1.0" encoding="Windows-1252" ?>
<NotepadPlus>
     <AutoComplete language="SEM">
          <Environment ignoreCase="yes" startFunc="?" stopFunc="" paramSeparator=" " />
EOF
}

function footer()
{
    cat >> $OUTPUT <<EOF
     </AutoComplete>
</NotepadPlus>
EOF
}

function entry()
{
    funcName=$1
    ## Get rid of " char in help string
    funcHelp=`echo ${@:2} | tr \" \'`
    

    echo "Adding <$funcName> function to XML file..."
    
    cat >> $OUTPUT <<EOF
          <KeyWord name="$funcName" func="yes">
              <Overload retVal="" descr="$funcHelp" >
                   <Param name="int pouet" />
              </Overload>
          </KeyWord>

EOF
}

function entrySimple()
{
    funcName=$1
    funcHelp=${@:2}

    echo "Adding <$funcName> function to XML file..."
    
    cat >> $OUTPUT <<EOF
          <KeyWord name="$funcName" />

EOF
}


rm -f $OUTPUT

header

while read l; do
    keyword=`echo $l | cut -f 1 -d' '`
    text=`echo $l | cut -f 2- -d' '`

    entry $keyword $text
    
    #echo -e "\t\t<KeyWord name=\"$keyword\" func=\"yes\">"
    #echo -e "\t\t\t<Overload retVal=\"none\" descr=\"$text\" >"
    #echo -e "\t\t\t\t<Param name=\"int pouet\" />"
    #echo -e "\t\t\t</Overload>"
    #echo -e "\t\t</KeyWord>"

    echo -n "$keyword " >> $KEYWORD
##    echo $keyword \"$text\"
    
done < $INPUT

footer
