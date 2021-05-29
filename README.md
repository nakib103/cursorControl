# cursorControl: Powering the Disabled

![Build Status](https://github.com/nakib103/cursorControl/actions/workflows/cmake.yml/badge.svg)
[![Slack join](https://img.shields.io/badge/slack-join-green)](https://join.slack.com/t/cursorcontrolgroup/shared_invite/zt-qwzhxi4m-iNh3UmEdWQGDRcINwEd4EQ)

The goal of cursorControl is to enable a disabled person to use the technology the same way a non-disabled person would do. 

## Design Concept
cursorControl is an event-driven application and designed to be modular so that more functionalities can be added to it with greater flexibility. There are basically three parts of the system - 
- Input buffers
- Event processors
- Controllers

For example, to enable a disabled person who have not voluntary movement under the neck to control a mouse cursor we will use a video input buffer, a mouse mover event processor, and a mouse movement controller. Video input buffer stores the input from input device (webcam), the mouse mover event processor processes the frames and set the mouse contollers state to desired cursor location, and finally the mouse controller moves the cursor. 


## Installation
##### In Windows
For build and install run the following command:

```batch
call build.bat
```
##### In Linux
For build and install run the following command:

```sh
bash build.bat
```

##### Installation Directory
The installed application can be found in the **install** directory under source directory.

```sh
+-- cursorControl
!   +-- install
!   !   +-- bin
!   !   !   +-- cursorControl.exe
!   !   +-- include
!   !   +-- lib
```

##### Tested Environment
In Windows
![tests](https://img.shields.io/badge/test-1-yellow)
|MSbulid|Cmake|OpenCV|Boost|
|:---:|:---:|:---:|:--:|
|15.9.21.664|3.10|4.5.1|1.76.0|
In Linux
![tests](https://img.shields.io/badge/test-none-red)
### 
## Usage
Checking version
```batch
cursorControl.exe
```
Running the application
```batch
cursorControl.exe <anything>
```
## Contributing
Want to contribute? Great!
## License

GNU Public License v3