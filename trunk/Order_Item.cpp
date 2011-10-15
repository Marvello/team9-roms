//Author :M.O. B.2.c S.X.-B.2b

#include "Order_Item.h"

char Order_Item::getOrderItemSeatID() const	//return Order Seat ID M.O. B.2.c S.X.-B.2b
{
	return (seat_id);
}

int Order_Item::getOrderItemID() const		//return Order ID M.O. B.2.c S.X.-B.2b
{
	return (order_id);
}

int Order_Item::getOrderItemMenuItemID() const		//return Order Item Menu ID M.O. B.2.c S.X.-B.2b
{
	return (menu_item_id);
}

int Order_Item::getOrderItemProdQty() const		//return Order Item Menu Quantity ID M.O. B.2.c S.X.-B.2b
{
	return (prod_qty);
}