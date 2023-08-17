@echo off
::setlocal

if "%~1" == "compile" (
    goto Compile
) else (
    tools\premake5.exe %1
)
goto Done

:: Compile solution without running the Visual Studio
:Compile

:: Setup the solution if not setup already
if not "%~2" == "" (
    tools\premake5.exe %2
)

:: Find the path to vswhere or exit
set VsWhere="%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
echo VsWhere path:
echo "    %VsWhere%"
if not exist %VsWhere% (
    echo vswhere tool not found. You might need to install or update Visual Studio.
    ::echo $('%VsWhere% -latest -products * -property installationPath')
    exit /b 1
)

:: Use vswhere to find the latest Visual Studio installation path
for /f "tokens=* delims=" %%i in ('%VsWhere% -latest -products * -property installationPath') do (
    set VSInstallPath=%%i
    echo Visual Studio installation path:
    echo "    %VSInstallPath%"
)
if not exist "%VSInstallPath%" (
    echo Visual Studio installation not found.
    exit /b 1
)

:: Determine the path to VsDevCmd.bat
set VsDevCmdPath=%VSInstallPath%\Common7\Tools\VsDevCmd.bat
echo VsDevCmdPath path:
echo "    %VsDevCmdPath%"
if not exist "%VsDevCmdPath%" (
    echo VsDevCmd.bat not found.
    exit /b 1
)

:: Prepare the command line so you can run Visual Studio tools
call "%VsDevCmdPath%"

:: Compile the solution using the found MSBuild
set solutionFile="CodeSnippets.sln"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 %solutionFile%

:: Check for compilation errors
if errorlevel 1 (
    echo Build failed.
    exit /b 1
) else (
    echo Build succeeded.
    exit /b 0
)

goto Done

:Unused
:: Use vswhere to find the latest MSBuild path or exit
for /f "tokens=*" %%i in ('%VsWhere% -latest -products * -requires Microsoft.Component.MSBuild -find MSBuild\**\Bin\MSBuild.exe') do (
    set MSBuildPath="%%i"
)
if not defined MSBuildPath (
    echo MSBuild not found.
    exit /b 1
)
:: Compile the solution using the found MSBuild
set solutionFile="CodeSnippets.sln"
!MSBuildPath! /t:Build /p:Configuration=Debug /p:Platform=x64 %solutionFile%

:: Done section
:Done
    echo Done.
    ::endlocal