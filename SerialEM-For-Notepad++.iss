; -- SerialEM-For-Notpad++.iss --
; Install SerialEM language support for Notepad++

#define SERIALEM4NPP_VERSION "0.3.5.5"
#define SERIALEM4NPP_UUID "{61aba454-af81-4469-8770-f1859da5026b}"

[Setup]
AppName=SerialEM for Notepad++
UninstallDisplayName=SerialEM for Notepad++
AppID={{#SERIALEM4NPP_UUID}
AppVersion={#SERIALEM4NPP_VERSION}
AppCopyright=Copyright (C) 2016 Daniel Caujolle-Bert, BioEM Lab.
AppPublisher=BioEM Lab.
AppPublisherURL=https://c-cina.unibas.ch/bioem/
AppComments=SerialEM for Notepad++ {#SERIALEM4NPP_VERSION} x86
;AppUpdatesURL=http://www.example.com/updates.html
;AppContact=My Company Customer Support
LicenseFile=LICENSE.txt
WizardImageFile="Logos\BioEM-Lab-Vertical.bmp"
WizardSmallImageFile="Logos\SerialEM4NPP-Icon55_58.bmp"
SetupIconFile="Logos\SerialEM4NPP-Icon64.ico"
OutputBaseFilename=SerialEM4NPP-{#SERIALEM4NPP_VERSION}-x86
DefaultDirName={pf}\SerialEM4NPP
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
;;;;;ArchitecturesInstallIn64BitMode=x64
; Note: We don't set ProcessorsAllowed because we want this
; installation to run on all architectures (including Itanium,
; since it's capable of running 32-bit code too).

[Files]
; Place all x86 files here, first one should be marked 'solidbreak'
Source: "UserLanguages\DeepBlack\SerialEM_Lang.xml"; DestDir: "{app}\DeepBlack"; DestName: "SerialEM_Lang.xml"; Check: not Is64BitInstallMode; Flags: solidbreak
Source: "UserLanguages\Default\SerialEM_Lang.xml"; DestDir: "{app}\Default"; DestName: "SerialEM_Lang.xml"; Check: not Is64BitInstallMode; Flags: solidbreak
Source: "Notepad++\plugins\APIs\SerialEM.xml"; DestDir: "{pf}\Notepad++\plugins\APIs"; DestName: "SerialEM.xml"; Check: not Is64BitInstallMode; Flags: solidbreak
; Place all common files here, first one should be marked 'solidbreak'
Source: "LICENSE.txt"; DestDir: "{app}"; Flags: solidbreak

[Icons]
Name: "{group}\Uninstall SerialEM For Notepad++ {#SERIALEM4NPP_VERSION}"; Filename: "{uninstallexe}"
Name: "{group}\License"; Filename: "{app}\LICENSE.txt"

[Run]
;// User selected... these files are shown for launch after everything is done
;Filename: {app}\README.TXT; Description: View the README file; Flags: postinstall shellexec skipifsilent

[Code]
// Some constants decl.
const
    RegKey = 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\' + '{#SERIALEM4NPP_UUID}' + '_is1';
    SerialEM4NPPVersion = '{#SERIALEM4NPP_VERSION}';

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
            
            if (CompareVersion(oldVersion, SerialEM4NPPVersion) <> 0) then
                begin
                    //MsgBox('Uninstall version ' + oldVersion + ' of Serial for Notepad++', mbInformation, MB_OK);    

                    RegQueryStringValue(HKEY_LOCAL_MACHINE, RegKey, 'UninstallString', uninstaller);
                    ShellExec('runas', uninstaller, '/SILENT', '', SW_HIDE, ewWaitUntilTerminated, ErrorCode);
                    Result := True;
                    
                end
            else
                begin
                
                    MsgBox('Version ' + oldVersion + ' of Serial for Notepad++ is already installed.'+#13#10+'This installer will exit.', mbInformation, MB_OK);    
                    Result := False;
                    
                end;
        end
    else
        begin
            //MsgBox('No uninstall of Serial for Notepad++', mbInformation, MB_OK);    
            Result := True;
        end;
end;
