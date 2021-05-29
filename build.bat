:: build script for cursorControl package

set env=%1

if %env% == local GOTO :LOCALBUILD

:BUILD

:: check if dependent commands are available
where tar.exe >nul 2>nul
if not ERRORLEVEL 0 (
    @echo tar.exe not found in path, please install it ..
    exit /b %ERRORLEVEL%
)
where msbuild.exe >nul 2>nul
if not ERRORLEVEL 0 (
    @echo msbuild.exe not found in path, please install it ..
    exit /b %ERRORLEVEL%
)
where git.exe >nul 2>nul
if not ERRORLEVEL 0 (
    @echo git.exe not found in path, please install it ..
    exit /b %ERRORLEVEL%
)
where curl.exe >nul 2>nul
if not ERRORLEVEL 0 (
    @echo curl.exe not found in path, please install it ..
    exit /b %ERRORLEVEL%
)

:: create third_party directory
if not exist "third_party" (
    mkdir third_party
)

:: build opencv
cd third_party
if not exist "opencv" (
    @echo "no opencv directory found, installing opencv .."
    git clone https://github.com/opencv/opencv.git
    cd opencv
    git checkout 4.5.1

    if not exist "build" ( 
        mkdir build
    )
    cd build

    cmake -D CMAKE_BUILD_TYPE=RELEASE \
      -D INSTALL_CREATE_DISTRIB=ON \
      -D BUILD_SHARED_LIBS=ON \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D BUILD_LIST=core,imgproc,objdetect,highgui,videoio \
      -D WITH_TBB=ON \
      -D WITH_V4L=ON \
      -D WITH_QT=OFF \
    ::   -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
      -D WITH_OPENGL=ON  ..

    msbuild OpenCV.sln

    cd ..
    cd ..
) else (
    @echo opencv directory found, assuming opencv installed ..
)

:: build boost
curl -L https://boostorg.jfrog.io/artifactory/main/release/1.76.0/source/boost_1_76_0.tar.gz --output boost_1_76_0.tar.gz --silent
tar -xzf boost_1_76_0.tar.gz

cd ..

:: build cursorcontrol

set BUILD_DIR=build
if exist %BUILD_DIR% rmdir /s /Q %BUILD_DIR%
mkdir %BUILD_DIR%

call cmake -B %BUILD_DIR%  -G "Visual Studio 15 2017" -A x64 -T host=x64 ..\..\cursorControl
call cmake --build %BUILD_DIR%

set INSTALL_DIR=install
if exist %INSTALL_DIR% rmdir /s /Q %INSTALL_DIR%
mkdir %INSTALL_DIR%
call cmake --install %BUILD_DIR% --config Debug --prefix %INSTALL_DIR%

:: build finished
@echo build finished ..
GOTO :eof

:LOCALBUILD

set BUILD_DIR=cmake_tests
if exist %BUILD_DIR% rmdir /s /Q %BUILD_DIR%
mkdir %BUILD_DIR%

call cmake -B %BUILD_DIR%  -G "Visual Studio 15 2017" -A x64 -T host=x64 ..\..\cursorControl
call cmake --build %BUILD_DIR%
call cmake --install %BUILD_DIR% --config Debug --prefix C:\Users\Asus\Desktop\cursorControl