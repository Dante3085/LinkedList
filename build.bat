
@ECHO OFF

set build_type=%1

:: Normal Build
IF [%build_type%]==[] (
    ECHO NORMAL BUILD...
    ECHO BUILDING LINKED-LIST PROJECT
    cl /Fe: main.exe /EHsc /std:c++17 main.cpp
    ECHO FINISHED BUILDING
)

:: Build and run
IF [%build_type%]==[-bar] (
    ECHO BUILD AND RUN...
    ECHO BUILDING LINKED-LIST PROJECT
    cl /Fe: main.exe /EHsc /std:c++17 main.cpp
    ECHO FINISHED BUILDING
    ECHO RUNNING PROGRAM
    .\main.exe
)

:: Build with debug info
IF [%build_type%]==[-debug] (
    ECHO BUILD WITH DEBUG INFO...
    ECHO BUILDING LINKED-LIST PROJECT
    cl /Fe: main.exe /EHsc /Zi /std:c++17 main.cpp
    ECHO FINISHED BUILDING
)