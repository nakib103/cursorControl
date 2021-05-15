set env=%1

if %env% == local GOTO :LOCALBUILD

:BUILD
cmake -B ${{github.workspace}}/build -DCMAKE_BUILD_TYPE=${{env.BUILD_TYPE}}
cmake --build ${{github.workspace}}/build --config ${{env.BUILD_TYPE}}

GOTO :eof

:LOCALBUILD
set BUILD_DIR=cmake_tests
if exist %BUILD_DIR% rmdir /s /Q %BUILD_DIR%
mkdir %BUILD_DIR%

call cmake -B %BUILD_DIR%  -G "Visual Studio 15 2017" -A x64 -T host=x64 ..\..\cursorControl
call cmake --build %BUILD_DIR%
call cmake --install %BUILD_DIR% --config Debug --prefix C:\Users\Asus\Desktop\cursorControl