#include "opencv2/opencv.hpp"
#include <cv.h>
#include <highgui.h>

#include <iostream>

#include "SignalTimer.cpp"

using namespace cv;
using namespace std;

class ImageMain
{
        private:
                VideoCapture *camera;
                Mat frame;
        public:
                ImageMain()
                {
                        camera= new VideoCapture(0);
                        
                        if(!camera->isOpened())
                                return -1;
                        namedWindow("Camera",WINDOW_AUTOSIZE);
                }
                
                void framecapture()
                {
                        for(;;)
                        {
                                camera >> frame;
                        }
                }
};

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    Mat frame;
    namedWindow("edges",WINDOW_AUTOSIZE);
    for(;;)
    {
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, CV_BGR2GRAY);
        //GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        //Canny(edges, edges, 0, 30, 3);
        threshold(edges,edges,128,225,THRESH_BINARY);
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;
    }
    
    imshow("edges",frame);
    
    waitKey(0);
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
