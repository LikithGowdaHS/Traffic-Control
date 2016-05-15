#include <iostream>


#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

class ImageProcessing {
        private:
                Mat frame, frame_grey;
                Mat base, base_grey;
                
                MatND hist_base;
                MatND hist_frame;
                
                double comparedvalue;
                int x,y;
                
        public:
                ImageProcessing()
                {
                        cout << "HERE" <<endl;
                        base=imread("/home/likith/Desktop/Project/2016-05-04-133248.jpg",1);
                        if(base.empty())
                                cout << "error";
                        else
                        {
                                cvtColor( base, base_grey, COLOR_BGR2GRAY );
                                this->medianfilter(0);
                                this->histogramcomputing(0);
                        }
                        
                }
                
                ImageProcessing(int i)
                {
                        cout << "HERE in signal " << i <<endl;
                        base=imread("/home/likith/Desktop/Project/traffic0.png",1);
                        if(base.empty())
                                cout << "error";
                        else
                        {
                                cvtColor( base, base_grey, COLOR_BGR2GRAY );
                                this->medianfilter(0);
                                this->histogramcomputing(0);
                        }
                        frame=imread("/home/likith/Desktop/Project/traffic100.png",1);
                        if(frame.empty())
                                cout << "error";
                        else
                        {
                                cvtColor( frame, frame_grey, COLOR_BGR2GRAY );
                                this->medianfilter(1);
                        }
                }

                double framecapture();
                void medianfilter(int flag);
                double histogramcomputing(int flag);
                double histogramcomparing();
};

void ImageProcessing::medianfilter(int flag)
{
    if(!flag)
    {
        uchar * data = base_grey.data;
        vector<int> values;
        for (auto int index = 0; index < (base_grey.rows*base_grey.cols); index++)
        {
                for (size_t i = 0; i < 7; i++) // 13 is the element to get the median from...
                {
                        values.push_back(data[index + i]);

                }
                std::sort(values.begin(), values.end());

                base_grey.data[index] = values[6]; // 6 is the median  of 13 plus the index number (0-6) ...
                values.clear();
        }
        //imshow("testbase", base_grey);
    }
    else
    {
        cout << "In Filter";
        uchar * data = frame_grey.data;
        vector<int> values;
        for (auto int index = 0; index < (frame_grey.rows*frame_grey.cols); index++)
        {
                for (size_t i = 0; i < 7; i++) // 13 is the element to get the median from...
                {
                        values.push_back(data[index + i]);

                }
                std::sort(values.begin(), values.end());

                frame_grey.data[index] = values[6]; // 6 is the median  of 13 plus the index number (0-6) ...
                values.clear();
        }
        //imshow("testframe", frame_grey);
    }
    //waitKey(0);
}

double ImageProcessing::framecapture()
{
                       
                        VideoCapture camera(0);           
                        for(;;)
                        {
                                                
                                                camera.read(frame);//get a new frame from camera
                                                if(frame.empty())
                                                        cout << "Camera error";
                                                else
                                                {
                                                        
                                                        cvtColor( frame, frame_grey, COLOR_BGR2GRAY );
                                                        this->medianfilter(1);
                                                        imwrite("image.jpg",frame_grey);
                                                        double value = this->histogramcomputing(1);
                                                        return value;
                                                }
                        }
                        
}

double ImageProcessing::histogramcomputing(int flag)
{
        int histSize =256;
        float range[]={0,255};
        const float* ranges[] = {range};


    /// Histograms

    /// Calculate the histograms for the gray images
    if(!flag)
    {
        calcHist( &base_grey, 1,0, Mat(), hist_base, 1, &histSize, ranges, true, false );
        normalize( hist_base, hist_base, 0, hist_base.rows, NORM_MINMAX, -1, Mat() );
        printf( "HISTOGRAM COMPUTING IS DONE For Reference image \n" );
    }
    else
    {
        calcHist( &frame_grey, 1,0, Mat(), hist_frame, 1,&histSize, ranges, true, false );
        normalize( hist_base, hist_base, 0,hist_frame.rows, NORM_MINMAX, -1, Mat() );
        printf( "HISTOGRAM COMPUTING IS DONE for current image \n" );
    }

    if(flag)
    {
        comparedvalue=this->histogramcomparing();
        return comparedvalue;
    }
    return 0;
}

double ImageProcessing::histogramcomparing()
{
        double base_test1 = compareHist( hist_base, hist_frame, 3);
        printf( "Base-Test(1):%f\n",base_test1);
        return base_test1;
}
