//Author :  M.O. B.3a S.X.-B.2b

#include "Order.h"

int Order::getOrdID() const // //Return Order ID M.O. B.3a  S.X.-B.2b  LC - B.2a
{
	return order_id;
}

int Order::getOrdServerID() const // //Return Order Server ID M.O. B.3a  S.X.-B.2b
{
	return server_id;
}

int Order::getOrdTableID() const // //Return Order Table ID M.O. B.3a  S.X.-B.2b  LC - B.2a
{
	return table_id;
}

Date Order::getOrdDate() const // //Return Order Date M.O. B.3a  S.X.-B.2b
{
	return order_date;
}

Time Order::getOrdTime() const // //Return Order Time M.O. B.3a  S.X.-B.2b
{
	return order_time;
}
