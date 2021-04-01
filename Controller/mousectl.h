#ifndef MOUSE_CONTROLLER
#define MOUSE_CONTROLLER

#include <utility>
#include <windows.h>

class Position{
    public:
        int x;
        int y;
};

class MouseController {
    Position position;   

    public:
        Position getPosition(){
            return position;
        }

        void setPosition(){
            POINT cursorPos;
            GetCursorPos(&cursorPos);

            // xPos = (xPos / 1365.0) * frameRes_width;
            // yPos = (yPos / 767.0) * frameRes_height;
            position.x = cursorPos.x;
            position.y = cursorPos.y;
        }

        /*void moveToPosition (int toX, int toY)
        {
            // modify for the 65535 (as float) way we talk to the screen...
            double dx = toX*(65535.0f / frameRes_width);
            double dy = toY*(65535.0f / frameRes_height);
            
            // movement stuff
            INPUT Input = {0};
            Input.type = INPUT_MOUSE;
            Input.mi.dwFlags = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
            //Input.mi.dwFlags = MOUSEEVENTF_MOVE;
            Input.mi.dx = LONG(dx);
            Input.mi.dy = LONG(dy);
            SendInput(1,&Input,sizeof(INPUT));
        }

        void rightClick ()
        {
            INPUT Input = {0};
            
            // right down
            Input.type = INPUT_MOUSE;
            Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
            SendInput(1,&Input,sizeof(INPUT));
            
            // right up
            ZeroMemory(&Input,sizeof(INPUT));
            Input.type = INPUT_MOUSE;
            Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
            SendInput(1,&Input,sizeof(INPUT));
        }

        void leftClick ()
        {
            INPUT Input = {0};
            
            // left down
            Input.type = INPUT_MOUSE;
            Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1,&Input,sizeof(INPUT));
            
            // left up
            ::ZeroMemory(&Input,sizeof(INPUT));
            Input.type = INPUT_MOUSE;
            Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1,&Input,sizeof(INPUT));
        }*/
};

#endif