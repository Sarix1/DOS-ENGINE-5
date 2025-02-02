@echo off
setlocal enabledelayedexpansion

:: Variables
set SRC_DIR=src
set OBJ_DIR=obj
set BUILD_DIR=build
set LOG_DIR=logs
set COMPILER=wcc386
set LINKER=wlink
set EXECUTABLE=game.exe
set COMPILER_FLAGS=-bt=dos -mf -za99 -zc -ot
set OBJECT_FILES=

:: Create necessary directories
if not exist %OBJ_DIR% mkdir %OBJ_DIR%
if not exist %LOG_DIR% mkdir %LOG_DIR%
if not exist %BUILD_DIR% mkdir %BUILD_DIR%

:: Clear directories
del /Q %OBJ_DIR%\*.*
del /Q %LOG_DIR%\*.*
:: del /Q %BUILD_DIR%\*.*

:: Compile each .c file in the source directory
echo Compiling source files...
for %%f in (%SRC_DIR%\*.c) do (
    echo Compiling %%f...
    "%COMPILER%" "%%f" %COMPILER_FLAGS% -fo=%OBJ_DIR%\%%~nf.obj -fr=%LOG_DIR%\%%~nf.err
    if errorlevel 1 (
        echo Error compiling %%f. Check %LOG_DIR%\%%~nf.err for details.
        goto end
    )
    set OBJECT_FILES=!OBJECT_FILES! %OBJ_DIR%\%%~nf.obj
)

:: Create a response file for wlink
echo Linking object files...
set RESPONSE_FILE=%OBJ_DIR%\linker_response.txt
del /Q %RESPONSE_FILE%
for %%f in (%SRC_DIR%\*.c) do (
    echo file %OBJ_DIR%\%%~nf.obj >> %RESPONSE_FILE%
)
echo name %BUILD_DIR%\%EXECUTABLE% >> %RESPONSE_FILE%
echo system dos4g >> %RESPONSE_FILE%

:: Use the response file to link the executable
"%LINKER%" @%RESPONSE_FILE% 2>> %LOG_DIR%\linking.err
if errorlevel 1 (
    echo Error during linking. Check %LOG_DIR%\linking.err for details.
    goto end
)

:: Build successful
echo Build completed successfully.
echo Executable is located at %BUILD_DIR%\%EXECUTABLE%

:end
pause >nul
exit /b
