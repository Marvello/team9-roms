//Header written by Laura Caflisch for A2
#ifndef DATE_H_
#define DATE_H_
#include <iostream>

class Date {
public:

	Date(){}

	Date(int yy, int mm, int dd)
	{
		y=yy;
		m=mm;
		d=dd;
	}
	
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	//string display() const;
    
private:
    int   y;
    int   m;
    int   d;
};
#endif
