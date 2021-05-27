# build script for cursorControl package

# update and upgrade packages
sudo apt-get -y update
sudo apt-get -y upgrade

# Remove any existing versions of x264
# sudo apt-get remove x264 libx264-dev

# Install OS Libraries

# Install Dependencies
# sudo apt-get -y install build-essential checkinstall cmake pkg-config yasm gfortran git
# sudo apt-get -y install libjpeg8-dev libjasper-dev libpng12-dev
# Used for Ubuntu 16.04
# sudo apt-get -y install libtiff5-dev
# sudo apt-get -y install libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev
# sudo apt-get -y install libxine2-dev libv4l-dev
# sudo apt-get -y install libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev
# sudo apt-get -y install libqt4-dev libgtk2.0-dev libtbb-dev
# sudo apt-get -y install libatlas-base-dev
# sudo apt-get -y install libfaac-dev libmp3lame-dev libtheora-dev
# sudo apt-get -y install libvorbis-dev libxvidcore-dev
# sudo apt-get -y install libopencore-amrnb-dev libopencore-amrwb-dev
# sudo apt-get -y install x264 v4l-utils

# Install Optional Dependencies
# sudo apt-get -y install libprotobuf-dev protobuf-compiler
# sudo apt-get -y install libgoogle-glog-dev libgflags-dev
# sudo apt-get -y install libgphoto2-dev libeigen3-dev libhdf5-dev doxygen

# download OpenCV from Github
mkdir -p third-party && cd third-party
git clone https://github.com/opencv/opencv.git
cd opencv
git checkout 4.5.1
cd ..

# download opencv_contrib from Github
git clone https://github.com/opencv/opencv_contrib.git
cd opencv_contrib
git checkout 4.5.1
cd ..

# compile and Install OpenCV with contrib
# create build directory inside opencv directory
cd opencv
mkdir -p build
cd build

# run CMake with the following options
cmake -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D INSTALL_C_EXAMPLES=ON \
      -D INSTALL_PYTHON_EXAMPLES=ON \
      -D WITH_TBB=ON \
      -D WITH_V4L=ON \
      -D WITH_QT=ON \
      -D WITH_OPENGL=ON \
      -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
      -D BUILD_EXAMPLES=ON ..

# compile and install
make -j4
sudo make install
sudo sh -c 'echo "/usr/local/lib" >> /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig

# configure cmake for project build
cmake -B ${{github.workspace}}/build -DCMAKE_BUILD_TYPE=${{env.BUILD_TYPE}}

# build the project
cmake --build ${{github.workspace}}/build --config ${{env.BUILD_TYPE}}

# 
cmake --install ${{github.workspace}}/build --config ${{env.BUILD_TYPE}} --prefix ${{github.workspace}}/build/artifact