#include <iostream>
#include <time.h>

using namespace std;

class SignalTimer {
	private:
		unsigned long begTime;
	public:
	        SignalTimer()
	        {
	        }
	        
		void start()
		{
			begTime = clock();
		}

		unsigned long elapsedTime()
		{
			return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
		}

		bool isTimeout(unsigned long seconds)
		{
			return seconds >= elapsedTime();
		}
};
