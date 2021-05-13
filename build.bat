set env=%1

if %env% == "local" GOTO :LOCALBUILD

:BUILD
cmake -B ${{github.workspace}}/build -DCMAKE_BUILD_TYPE=${{env.BUILD_TYPE}}
cmake --build ${{github.workspace}}/build --config ${{env.BUILD_TYPE}}

GOTO :END

:LOCALBUILD
set BUILD_DIR=cmake_tests
if exist %BUILD_DIR% rmdir /s /Q %BUILD_DIR%
mkdir %BUILD_DIR%
cd %BUILD_DIR%

call cmake -G "Visual Studio 15 2017" -A x64 -T host=x64 ..\..\cursorControl
call cmake --build .
call cmake --install . --config Debug --prefix C:\Users\Asus\Desktop\cursorControl

GOTO :END


:END