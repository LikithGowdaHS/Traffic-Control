#include <iostream>

#include "SignalTimer.cpp"
#include "ImageProcessing.cpp"

using namespace std;

class TrafficSignal
{
        private:
                int light;
                unsigned long signal_time;
                SignalTimer time;
                ImageProcessing  Image;
        public:
                TrafficSignal()
                {
                        cout << "Inside Signal Constructor"<<endl;
                        light=0;
                        signal_time=10;
                        cout << "Signal created" << endl;
                }
                
                void settimer(unsigned long t);
                bool startsignal();
                double callimage();
  
};

void TrafficSignal::settimer(unsigned long t)
{
        signal_time=t;
}

bool TrafficSignal::startsignal()
{
        time.start();
        //Image.framecapture();
        while(true)
        {
                if(time.elapsedTime() >= signal_time)
                        return true;
                //else
                  //      Image.framecapture();
        }
}

double TrafficSignal::callimage()
{
        //double value=Image.histogramcomputing(1);
        double value=Image.framecapture();
        return value;
}
