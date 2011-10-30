#ifndef TIME_H_
#define TIME_H_

//Header written by Laura Caflisch for A2
#include <iostream>
using namespace std;
class Time {
public:
	//constructors
	Time(){}
	Time(int hh, int minn)
	{
		h=hh;
		min=minn;
	}
	
	int getHour() const
	{
		return h;
	}
	int getMinute() const
	{
		return min;
	}

	//int display() const;
    
private:
    int   h;
    int   min;
};
#endif

