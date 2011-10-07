/*
	The directives starting with # below ensures that this file is read by the compiler only once
	even if it is #included several times. It is call an "include guard"
*/
#ifndef ORDER_H_
#define ORDER_H_

//other types
//#include "Date.h"				//uncomment once you have added the type definition
//#include "Time.h"				//uncomment once you have added the type definition
#include <string>
using namespace std;

struct Order {
public:
	//data

	// constructors
	Order () {}

   // utility functions
	string display() const;
private:
   //constants

   // private data
	int order_id;
	int server_id;
	int table_id;
	//Date order_date;	//uncomment once you have added the type definition
	//Time order_time;  //uncomment once you have added the type definition
};


#endif //ORDER_H_