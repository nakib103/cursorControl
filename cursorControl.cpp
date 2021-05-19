// should try 0x501 below instead of 0x500 if we run into error
#define _WIN32_WINNT 0x500

#include "cursorControl.h"
#include "Controller\Controller.h"
#include "InputBuffer\InputBuffer.h"

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("%s Version %d.%d\n", argv[0], cursorControl_VERSION_MAJOR, cursorControl_VERSION_MINOR);
		printf("Usage: %s Number", argv[0]);
		return 1;
	}
	
	// MouseMover mouseMover;
	// mouseMover.setPosition();
	// Position pos;
	// pos = mouseMover.getPosition();
	// cout << pos.x << " " << pos.y << endl;

	MouseClicker mouseClicker;
	ClickStates clickState = ClickStates::Right;
	mouseClicker.setState(StateNames::mouse_click_state, ControllerStateValue<ClickStates>(clickState));
	mouseClicker.execute();

	VideoInputBuffer videoInput;
	videoInput.capture();
	// cv::Mat frame = videoInput.get();
	// std::cout << frame.dims << std::endl;
	// std::cout << frame.rows << " " << frame.cols << std::endl;
	videoInput.show();
}