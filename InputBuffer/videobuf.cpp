#ifndef VIDEO_INPUT_BUFFER
#define VIDEO_INPUT_BUFFER

#include "opencv2\core\mat.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"

#include <queue>

// class for input buffer interface
class InputBuffer{
    public:
        virtual void capture() = 0;
        // TODO - how to make get function as interface
        // template <typename input> input get() = 0;
};

// class to hold size of video frame
class FrameSize{
    public:
        int height;
        int width;
};

// class for video input buffer
class VideoInputBuffer : public InputBuffer {
    cv::Mat frame;
    std::queue<cv::Mat> frameBuffer;
    FrameSize frameSize;

    public:
        VideoInputBuffer(int height, int width){
            frameSize.height = height;
            frameSize.width = width;
        }

        void capture(){
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
        
        cv::Mat get(){
            cv::Mat currentFrame(cv::Size(frameSize.height, frameSize.width), -1);
            if(!frameBuffer.empty()){
                currentFrame = frameBuffer.front();
                frameBuffer.pop();
            }
            return currentFrame;
        }
};

#endif