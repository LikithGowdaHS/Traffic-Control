#include <iostream>
#include "SignalTimer.cpp"

using namespace std;

class TrafficSignal
{
        private:
                int light;
                unsigned long signal_time;
                SignalTimer time; 
        public:
                TrafficSignal()
                {
                        light=0;
                        signal_time=60;
                        cout << "Signal created" << endl;
                }
                
                void settimer(unsigned long t);
                bool startsignal();
  
};

void TrafficSignal::settimer(unsigned long t)
{
        signal_time=t;
}

bool TrafficSignal::startsignal()
{
        time.start();
        while(true)
        {
                if(time.elapsedTime() >= signal_time)
                        return true;
                //else
                        //cout << "Still running" << endl;
        }
}
