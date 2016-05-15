#include <iostream>

#include "TrafficSignal.cpp"
#include "TrafficSignalChanger.cpp"

using namespace std;

class TrafficJunction
{
        private:
                int number_lanes, flag, signaltime; //number of lanes in the junction
                TrafficSignal *signal[10];//signals for each lane
                TrafficSignalChanger *compare;
                ImageProcessing *image;
                
        
        public:
                //default constractor
                TrafficJunction()
                {
                        number_lanes=4;
                        compare = new TrafficSignalChanger();
                        flag=0;
                        this->signal_creation();
                }
                
                //paramaterized constructor (user input)
                TrafficJunction(int number)
                {
                        number_lanes=number;
                        if(number < 4)
                        {
                                flag=1;
                        }
                        else
                                flag=0;
                        compare = new TrafficSignalChanger();
                        this->signal_creation();
                }
                
                //displaying the number of lanes
                void Display();
                //creating the signals for each lane
                void signal_creation();
                //getting the histogram value from each lane
                void gethistovalue();
  
};

void TrafficJunction::Display()
{
        cout << number_lanes;
}

void TrafficJunction::signal_creation()
{
        for(int i=0;i<number_lanes;i++)
        {
                signal[i]=new TrafficSignal();
        }       
}


void TrafficJunction::gethistovalue()
{
        while(1)
        {
                for(int i=0;i<number_lanes;i++)
                {
                        int a,b,c;
                        a=i;
                        b=(i+1)%number_lanes;
                        c=(i+2)%number_lanes;
                
                        compare->histovalue[0]=signal[a]->callimage();
                        compare->histovalue[1]=signal[b]->callimage();
                        compare->histovalue[2]=signal[c]->callimage();
                        
                        compare->signalcomparison(i,c);
                        signaltime = compare->getsignaltime();
                        cout << "The Signal time is:" << signaltime << endl;
                        signal[i]->settimer(signaltime);
                        signal[i]->startsignal();
                }
         }
}
