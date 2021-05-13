// should try 0x501 below instead of 0x500 if we run into error
#define _WIN32_WINNT 0x500

#include "cursorControl.h"
#include "Controller\mousectl.cpp"
#include "InputBuffer\videobuf.cpp"

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("%s Version %d.%d\n", argv[0], cursorControl_VERSION_MAJOR, cursorControl_VERSION_MINOR);
		printf("Usage: %s Number", argv[0]);
		return 1;
	}
	
	MouseClicker mouseClicker;

	// mouseClicker.setPosition();
	// Position pos;
	// pos = mouseClicker.getPosition();
	// cout << pos.x << " " << pos.y << endl;

	mouseClicker.setClickState(Right);
	mouseClicker.execute();
}