set VSWHERE="%ProgramFiles(x86)%/Microsoft Visual Studio/Installer/vswhere.exe"
for /f "usebackq tokens=*" %i in (`%VSWHERE% -latest -products * -requires Microsoft.Component.MSBuild -property installationPath`) do (
    set InstallDir=%i
) 
"%InstallDir%/VC/Auxiliary/Build/vcvars64".bat
"devenv.exe" C:\Users\aborjas22\Desktop\EX01_32\source\AddTwo.asm /debugexe C:\Users\aborjas22\Desktop\EX01_32/bin/main.exe
