#ifndef CC_INPUT_BUFFER
#define CC_INPUT_BUFFER

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

// class to hold size of frame such as video frame
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
        VideoInputBuffer();
        VideoInputBuffer(int height, int width);
        void capture();
        cv::Mat get();

        // TEMP - just for testing; will be deleted later
        void show(){
            cv::Mat currentFrame(cv::Size(frameSize.height, frameSize.width), -1);
            currentFrame = get();
            cv:: imshow ("test get", currentFrame);
            cv::waitKey();
        }
};

#endif