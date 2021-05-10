#ifndef VIDEO_INPUT_BUFFER
#define VIDEO_INPUT_BUFFER

#include "opencv2/core/core.hpp"
#include "opencv2/video.hpp"

#include <queue>

// class for input buffer interface
template <typename input>;
class InputBuffer{
    public:
        virtual void capture() = 0;
        virtual input get() = 0;
};

// class to hold size of video frame
class FrameSize{
    int height;
    int width;
};

// class for video input buffer
class VideoInputBuffer : public InputBuffer {
    Mat frame;
    std::queue<Mat> frameBuffer;
    FrameSize frameSize;

    public:
        VideoInputBuffer(int height, int width){
            frameSize.height = height;
            frameSize.width = width;
        }

        void capture(){
            VideoCapture capture;

            // open webcam to capture a frame
            capture.open (0);
            if (!capture.isOpened ()) { 
                printf ("[ERROR][InputBuffer:videobuf] VideoInputBUffer - could not open camera\n"); 
                if (waitKey (0) >= 0) return -1;
            }
            
            // capture a frame
            capture.read (frame);
            capture.release();
            if (frame.empty ()) {
                printf ("[ERROR][InputBuffer:videobuf] VideoInputBUffer - failed tp capture frame\n");
                return; 
            }

            // resizing and mirroring the frame to reduce calculation and faster application
            resize (frame, frame, Size(frameSize.height, frameSize,width), 0, 0, INTER_CUBIC);
            flip (frame, frame, 1);

            // insert the captured frame into buffer
            frameBuf.push(frame);
        }

        Mat get(){
            if(!frameBuf.empty())
                return frameBuf.pop();
            else{
                Mat empty(frameSize.height, frameSize.width, -1);
                return empty;
            } 
        }
};

#endif