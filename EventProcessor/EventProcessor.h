#ifndef CC_EVENT_PROCESSOR
#define CC_EVENT_PROCESSOR

#include "Controller\Controller.h"

#include <vector>

// base class for event channel
class EventChannel{
    std::vector<MouseController> controllers;

    public:
        virtual void getState() = 0;
        virtual void setState() = 0;
        virtual void attach() = 0;
        virtual void notify() = 0;
};

#endif