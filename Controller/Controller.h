#ifndef CC_CONTROLLER
#define CC_CONTROLLER

#include <utility>
#include <string>
#include <map>

// enum for mouse click states
enum class ClickStates{ None, Right, Left };

// class to hold position such as mouse cursor
class Position{
    public:
        int x;
        int y;
        Position() { x = -1; y = -1; }
};

// enum for controller state
enum class StateNames{
    mouse_position,
    mouse_click_state
};

// Base class for controller state
class ControllerState{
    public:
        // template <typename StateValue> void value(StateValue* stateValue){ stateValue = NULL; };
};

// class to create controller state
template <typename StateValue>
class ControllerStateValue : public ControllerState{
    StateValue stateValue;
    public:
        ControllerStateValue(StateValue value) : stateValue(value) {};
        StateValue value() { return stateValue; };
};

// base class for contorller
class Controller {
    std::map<StateNames, ControllerState*> states;
    public:
        void setState(StateNames stateName, ControllerState* stateValue){ states[stateName] = stateValue; }
        ControllerState* getState(StateNames name){ return states[name]; }
        virtual void execute() = 0;
};
// class Controller {
//     public:
//         virtual void execute() = 0;
// };

// base class for mouse event processor
class MouseController : public Controller {
    public:
        MouseController();
        virtual void execute() = 0;
};
// base class for mouse event processor
// class MouseController : public Controller {
//     Position position;   
//     ClickStates clickState;

//     public:
//         Position getPosition(){ return position; }
//         void setPosition();
//         ClickStates getClickState(){ return clickState; }
//         void setClickState(ClickStates state){ clickState = state; }
//         virtual void execute() = 0;
// };

// class for mouse movement event processor 
class MouseMover : public MouseController {
    public:
        void execute();
};

// class for mouse click event processor 
class MouseClicker : public MouseController {
    public:
        void execute();
};

#endif