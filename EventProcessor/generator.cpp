#ifndef CC_EVENT_GENERATOR
#define CC_EVENT_GENERATOR

#include "EventProcessor.h"
#include "channel.cpp"

void MouseMoverEventGenerator::run(){
    // get input from video input buffer
    VideoInputBuffer* videoInputBuffer = getInputBuffer();
    cv::Mat input = videoInputBuffer->get();

    // check if input is empty
    if(input.empty()){
        printf("[ERROR][EventProcessor:generator] run - input is empty\n");
        return;
    }

    // create an controller event 
    Event<Position> event;
    Position position(123, 65535);
    event.setStateName(StateNames::mouse_position);
    event.setStateValue(ControllerStateValue<Position>(position));

    // push the event to event channel
    EventChannel<MouseMover, Position>* eventChannel = getEventChannel();
    eventChannel->pushEvent(event);

    // notify the controllers
    eventChannel->notify();
}

void MouseClickerEventGenerator::run(){
    // get input from video input buffer
    VideoInputBuffer* videoInputBuffer = getInputBuffer();
    cv::Mat input = videoInputBuffer->get();

    // check if input is empty
    if(input.empty()){
        printf("[ERROR][EventProcessor:generator] run - input is empty\n");
        return;
    }

    // create an controller event 
    Event<ClickStates> event;
    event.setStateName(StateNames::mouse_click_state);
    event.setStateValue(ControllerStateValue<ClickStates>(ClickStates::Right));

    // push the event to event channel
    EventChannel<MouseClicker, ClickStates>* eventChannel = getEventChannel();
    eventChannel->pushEvent(event);

    // notify the controllers
    eventChannel->notify();
}

#endif