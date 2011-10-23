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
	char getOrderItemSeatID() const; //return Order Seat ID M.O. B.2.c S.X.-B.2b
	int getOrderItemID() const; //return Order ID M.O. B.2.c S.X.-B.2b  LC - B.2a
	int getOrderItemMenuItemID() const; //return Order Item Menu ID M.O. B.2.c S.X.-B.2b  LC - B.2a
	int getOrderItemProdQty() const; //return Order Item Menu Quantity ID M.O. B.2.c S.X.-B.2b  LC - B.2a

private:
   //constants  

   // private data
	char seat_id;
	int order_id;
	int menu_item_id;
	int prod_qty;
};


#endif //ORDER_ITEM_H_
