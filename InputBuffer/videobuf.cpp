#ifndef CC_VIDEO_INPUT_BUFFER
#define CC_VIDEO_INPUT_BUFFER

#include "InputBuffer.h"

VideoInputBuffer::VideoInputBuffer(){
    frameSize.height = 320;
    frameSize.width = 240;
}

VideoInputBuffer::VideoInputBuffer(int height, int width){
    frameSize.height = height;
    frameSize.width = width;
}

void VideoInputBuffer::capture(){
    cv::VideoCapture capture;

    // open webcam to capture a frame
    capture.open (0);
    if (!capture.isOpened ()) { 
        printf ("[ERROR][InputBuffer:videobuf] VideoInputBUffer - could not open camera\n"); 
        if (cv::waitKey (0) >= 0) return;
    }
    
    // capture a frame
    capture.read (frame);
    capture.release();
    if (frame.empty ()) {
        printf ("[ERROR][InputBuffer:videobuf] VideoInputBUffer - failed tp capture frame\n");
        return; 
    }

    // resizing and mirroring the frame to reduce calculation and faster application
    cv::resize (frame, frame, cv::Size(frameSize.height, frameSize.width), 0, 0, cv::INTER_CUBIC);
    cv::flip (frame, frame, 1);

    // insert the captured frame into buffer
    frameBuffer.push(frame);
}

cv::Mat VideoInputBuffer::get(){
    cv::Mat currentFrame(cv::Size(frameSize.height, frameSize.width), -1);
    if(!frameBuffer.empty()){
        currentFrame = frameBuffer.front();
        frameBuffer.pop();
    }
    return currentFrame;
}

#endif