// should try 0x501 below instead of 0x500 if we run into error
#define _WIN32_WINNT 0x500

#include "cursorControl.h"
#include "Controller\Controller.h"
#include "InputBuffer\InputBuffer.h"
#include "EventProcessor\EventProcessor.h"
#include "FaceDetector\FaceDetector.h"
#include "opencv2\core\mat.hpp"
#include "opencv2\core\types.hpp"

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("%s Version %d.%d.%d\n", argv[0], cursorControl_VERSION_MAJOR, cursorControl_VERSION_MINOR, cursorControl_VERSION_PATCH);
		printf("Usage: %s Number", argv[0]);
		return 1;
	}

	VideoInputBuffer videoInputBuffer;
	videoInputBuffer.capture();
	cv::Mat frame = videoInputBuffer.get();

	CVCascadeFaceDetector faceDetector;
	// cv::Rect face = faceDetector.detect(frame);
	cv::Rect face = faceDetector.detect(1, frame);
	if(face.empty()){
		printf("[ERROR][cursorControl] face detector returned empty rectangle\n");
	}

	cv::Mat faceTemplate(frame, face);

	MouseMover mouseMover;
	
	MouseMoverEventChannel mouseMoverEventChannel;
	mouseMoverEventChannel.attach(mouseMover);
	
	MouseMoverEventGenerator mouseMoverEventGenerator(faceTemplate);
	mouseMoverEventGenerator.setInputBuffer(&videoInputBuffer);
	mouseMoverEventGenerator.setEventChannel(&mouseMoverEventChannel);

	videoInputBuffer.capture();
	mouseMoverEventGenerator.run();

	// MouseMover mouseMover;
	// Position position(65535, 123);
	// mouseMover.setState(StateNames::mouse_position, ControllerStateValue<Position>(position));
	// mouseMover.execute();

	MouseClicker mouseClicker;
	MouseClickerEventChannel mouseClickerEventChannel;
	mouseClickerEventChannel.attach(mouseClicker);

	MouseClickerEventGenerator mouseClickerEventGenerator;
	mouseClickerEventGenerator.setInputBuffer(&videoInputBuffer);
	mouseClickerEventGenerator.setEventChannel(&mouseClickerEventChannel);
	
	videoInputBuffer.capture();
	mouseClickerEventGenerator.run();

	// MouseClicker mouseClicker;
	// ClickStates clickState = ClickStates::Right;
	// mouseClicker.setState(StateNames::mouse_click_state, ControllerStateValue<ClickStates>(clickState));
	// mouseClicker.execute();

	// VideoInputBuffer videoInput;
	// videoInput.capture();
	// videoInput.show();
}