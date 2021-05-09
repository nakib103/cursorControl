#ifndef MOUSE_CONTROLLER
#define MOUSE_CONTROLLER

#include <utility>
#include <windows.h>
#include <string>

enum clickStates {
        None, 
        Right, 
        Left
};

class Position{
    public:
        int x;
        int y;
};

// base event processor class for mouse events
class MouseController {
    Position position;   
    clickStates clickState;

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

        clickStates getClickState(){
            return clickState;
        }

        void setClickState(clickStates state){
            clickState = state;
        }

        virtual void execute() = 0;
};

// event processor class for mouse movement event
class MouseMover : public MouseController {
    public:
        void execute(){
            // get mouse position
            Position position = getPosition();

            // create an mouse input event
            INPUT Input = {0};
            Input.type = INPUT_MOUSE;
            Input.mi.dwFlags = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
            
            // move mouse cursor
            Input.mi.dx = LONG(position.x);
            Input.mi.dy = LONG(position.y);
            SendInput(1,&Input,sizeof(INPUT));
        
            // set input event to zero - TODO delete INPUT
            ZeroMemory(&Input,sizeof(INPUT));
        }
};

// event processor class for mouse click event
class MouseClicker : public MouseController {
    public:
        void execute(){
            // get click state
            clickStates clickState = getClickState();
            // create and mouse input event
            INPUT Input = {0};
            Input.type = INPUT_MOUSE;

            if(clickState == Right){
                // hold down mouse right button
                Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
                SendInput(1,&Input,sizeof(INPUT));

                // release mouse right button
                Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
                SendInput(1,&Input,sizeof(INPUT));
            }
            else if(clickState == Left){
                // hold down mouse left button
                Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                SendInput(1,&Input,sizeof(INPUT));

                // release mouse left button 
                Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
                SendInput(1,&Input,sizeof(INPUT));
            }
            else{
                printf("[DEBUG][Controller:mousectl] MouseClicker - No actionable click state");
            }

            // set input event to zero - TODO delete INPUT
            ZeroMemory(&Input,sizeof(INPUT));
        }
};

#endif