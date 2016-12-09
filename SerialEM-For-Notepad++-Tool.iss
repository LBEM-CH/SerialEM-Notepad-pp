; -- SerialEM-For-Notpad++-Tool.iss --
; Install SerialEM language support Tool for Notepad++

#define SERIALEM4NPPTOOL_VERSION "0.99.3.0"
#define SERIALEM4NPPTOOL_UUID "{dc46f650-bdd3-4ea8-a0e1-4be3e2cd30ec}"

[Setup]
AppName=SerialEM for Notepad++ Tool
UninstallDisplayName=SerialEM for Notepad++ Tool
AppID={{#SERIALEM4NPPTOOL_UUID}
AppVersion={#SERIALEM4NPPTOOL_VERSION}
AppCopyright=Copyright (C) 2016 Daniel Caujolle-Bert, BioEM Lab.
AppPublisher=BioEM Lab.
AppPublisherURL=https://c-cina.unibas.ch/bioem/
AppComments=SerialEM for Notepad++ Tool {#SERIALEM4NPPTOOL_VERSION} {code:Architecture}
;AppUpdatesURL=http://www.example.com/updates.html
;AppContact=My Company Customer Support
LicenseFile=LICENSE.txt
WizardImageFile="Logos\BioEM-Lab-Vertical.bmp"
WizardSmallImageFile="Logos\SerialEM4NPP-Icon55_58.bmp"
SetupIconFile="Logos\SerialEM4NPP-Icon64.ico"
OutputBaseFilename=SerialEM4NPP-Tool-{#SERIALEM4NPPTOOL_VERSION}-x64
DefaultDirName={pf}\SerialEM for Notepad++
DefaultGroupName=SerialEM For Notepad++
UninstallDisplayIcon={uninstallexe}
Compression=lzma2
SolidCompression=yes
CloseApplications=yes
WindowVisible=no
;OutputDir=userdocs:Inno Setup Examples Output
; "ArchitecturesInstallIn64BitMode=x64" requests that the install be
; done in "64-bit mode" on x64, meaning it should use the native
; 64-bit Program Files directory and the 64-bit view of the registry.
; On all other architectures it will install in "32-bit mode".
ArchitecturesInstallIn64BitMode=x64
; Note: We don't set ProcessorsAllowed because we want this
; installation to run on all architectures (including Itanium,
; since it's capable of running 32-bit code too).

[Files]
; Place all x86 files here, first one should be marked 'solidbreak'
Source: "SerialEM4NPP\bin\Release\SerialEM4NPP.exe"; DestDir: "{app}"; DestName: "SerialEM4NPP.exe"; Check: Is64BitInstallMode
Source: "SerialEM4NPP\releaselibs_x64\*.dll"; DestDir: "{app}"; Check: Is64BitInstallMode
; Place all common files here, first one should be marked 'solidbreak'
Source: "LICENSE.txt"; DestDir: "{app}"; DestName: "Tool-LICENSE.txt"; Check: Is64BitInstallMode

[Icons]
Name: "{group}\SerialEM for Notepad++ Tool"; Filename: "{app}\SerialEM4NPP.exe"
Name: "{group}\Uninstall SerialEM for Notepad++ Tool"; Filename: "{uninstallexe}"
Name: "{group}\Tool's License"; Filename: "{app}\Tool-LICENSE.txt"

[Run]
;// User selected... these files are shown for launch after everything is done
;Filename: {app}\README.TXT; Description: View the README file; Flags: postinstall shellexec skipifsilent
Filename: "{app}\SerialEM4NPP.exe"; Description: Start SerialEM for Notepad++ Tool; Flags: postinstall nowait skipifsilent unchecked

[Code]
// Some constants decl.
const
    RegKey = 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\' + '{#SERIALEM4NPPTOOL_UUID}' + '_is1';
    SerialEM4NPPTOOLVersion = '{#SERIALEM4NPPTOOL_VERSION}';

// Returns architecture string
function Architecture(str: String): String;
var
    S: String;
begin
    case ProcessorArchitecture of
        paX86:
            S := 'x86';
        paX64:
            S := 'x64';
        paIA64:
            S := 'Itanium';
    else
        S := 'Unrecognized';
    end;

  Result := S;
end;
    
// Stupid strcmp
function CompareVersion(str1, str2: String): Integer;
var
    temp1, temp2: String;

    
begin
    temp1 := str1;
    temp2 := str2;
    Result := CompareText(temp1, temp2);
end;

// It will uninstall different version than the current one, and exists the
// installer if identical version is already installed
function InitializeSetup(): Boolean;
var
    oldVersion: String;
    uninstaller: String;
    ErrorCode: Integer;
    
begin

  if RegKeyExists(HKEY_LOCAL_MACHINE, RegKey) then
      begin
      
          RegQueryStringValue(HKEY_LOCAL_MACHINE, RegKey, 'DisplayVersion', oldVersion);
          
          if (CompareVersion(oldVersion, SerialEM4NPPTOOLVersion) <> 0) then
              begin
                  //MsgBox('Uninstall version ' + oldVersion + ' of SerialEM for Notepad++ Tool', mbInformation, MB_OK);    

                  RegQueryStringValue(HKEY_LOCAL_MACHINE, RegKey, 'UninstallString', uninstaller);
                  ShellExec('runas', uninstaller, '/SILENT', '', SW_HIDE, ewWaitUntilTerminated, ErrorCode);
                  Result := True;
                  
              end
          else
              begin
              
                  MsgBox('Version ' + oldVersion + ' of SerialEM for Notepad++ Tool is already installed.'+#13#10+'This installer will exit.', mbInformation, MB_OK);    
                  Result := False;
                  
              end;
      end
  else
      begin
          //MsgBox('No uninstall of SerialEM for Notepad++ Tool', mbInformation, MB_OK);    
          Result := True;
      end;
end;
