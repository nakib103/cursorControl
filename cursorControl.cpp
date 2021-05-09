// should try 0x501 below instead of 0x500 if we run into error
#define _WIN32_WINNT 0x500

#include <mousectl.h>

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	MouseClicker mouseClicker;

	// mouseClicker.setPosition();
	// Position pos;
	// pos = mouseClicker.getPosition();
	// cout << pos.x << " " << pos.y << endl;

	mouseClicker.setClickState(Right);
	mouseClicker.execute();
}