#ifndef ORDER_ITEM_H_
#define ORDER_ITEM_H_

#include <string>
using namespace std;


struct Order_Item {
public:
	// constructors
	Order_Item (char sid, int oid, int miid, int pq)	//L.C., A2
	{
		seat_id=sid;
		order_id=oid;
		menu_item_id=miid;
		prod_qty=pq;
	}

   // utility functions
	string display() const;

private:
   //constants  

   // private data
	char seat_id;
	int order_id;
	int menu_item_id;
	int prod_qty;
};


#endif //ORDER_ITEM_H_