//Author : S.X.-A.3

#include "Description.h"
#include <iostream>

//Description constructor
Description::Description (string d)
{
	description = d;
}

//Display the description of menu
string Description::display() const
{
	return description;
}