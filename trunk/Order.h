/*
	The directives starting with # below ensures that this file is read by the compiler only once
	even if it is #included several times. It is call an "include guard"
*/
#ifndef ORDER_H_
#define ORDER_H_

//#include <string>

//other types
#include "Date.h"				//L.C., A2, defines Date type
#include "Time.h"				//L.C., A2, defines Time type

using namespace std;

struct Order {
public:
	//data
	
	// constructors
	Order (int oid, int sid, int tid, Date od, Time ot) { //L.C., A2, Order constructor
	order_id=oid;
	server_id=sid;
	table_id=tid;
	order_date=od;
	order_time=ot;
	};

   // utility functions
	string display() const;
	int getOrdID() const; // //Return Order ID M.O. B.3a  S.X.-B.2b  LC - B.2a
	int getOrdServerID() const; // //Return Order Server ID M.O. B.3a  S.X.-B.2b
	int getOrdTableID() const; // //Return Order Table ID M.O. B.3a  S.X.-B.2b  LC - B.2a
	Date getOrdDate() const; // //Return Order Date M.O. B.3a  S.X.-B.2b
	Time getOrdTime() const; // //Return Order Time M.O. B.3a  S.X.-B.2b

private:
   //constants

   // private data
	int order_id;
	int server_id;
	int table_id;
	Date order_date;	//L.C., A2
	Time order_time;  //L.C., A2
};


#endif //ORDER_H_