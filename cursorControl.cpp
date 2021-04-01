// should try 0x501 below instead of 0x500 if we run into error
#define _WIN32_WINNT 0x500

#include <Controller/mousectl.h>

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	MouseController mouseController;

	mouseController.setPosition();
	Position pos;
	pos = mouseController.getPosition();
	cout << pos.x << " " << pos.y << endl;
}