#include <iostream>

#include "TrafficJunction.cpp"

using namespace std;

int main(int argc, char **argv)
{
        //object pointer
        TrafficJunction *junction;
        
        //user input for number of lanes
        cout << "Enter the number of lanes in the junction" <<endl;
        int number=0;
        cin >> number;
        
        //checking for a valid input
        if(number)
        {
                junction = new TrafficJunction(number);
        }
        else
        {
                junction = new TrafficJunction();
        }
        junction->set_time();
        return 0;
}
