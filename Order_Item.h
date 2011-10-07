#ifndef ORDER_ITEM_H_
#define ORDER_ITEM_H_

#include <string>
using namespace std;


struct Order_Item {
public:
	// constructors
	Order_Item () {}

   // utility functions
	string display() const;

private:
   //constants  

   // private data
	int seat_id;
	int order_id;
	int menu_item_id;
	int prod_qty;
};


#endif //ORDER_ITEM_H_