#include <iostream>

#include "TrafficSignal.cpp"

using namespace std;

class TrafficJunction
{
        private:
                int number_lanes; //number of lanes in the junction
                TrafficSignal *signal[10];//signals for each lane
        
        public:
                //default constractor
                TrafficJunction()
                {
                        number_lanes=4;
                        this->signal_creation();
                }
                
                //paramaterized constructor (user input)
                TrafficJunction(int number)
                {
                        number_lanes=number;
                        this->signal_creation();
                }
                
                //displaying the number of lanes
                void Display();//line 38
                //creating the signals for each lane
                void signal_creation();//line 43
                //setting time to the signals and running it in round robin way
                void set_time();
                
  
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

void TrafficJunction::set_time()
{
        for(int i=0;i<number_lanes;i++)
        {
                signal[i]->settimer(5);
                cout << "Running signal: " << i << endl;
                while(true)
                {
                        if(signal[i]->startsignal())
                                break;
                        
                }
        }
}
