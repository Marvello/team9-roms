//Author : M.O.-A.1

#include "Instructions.h"
#include <iostream>

Instructions::Instructions (string n) //Instruction Constructor M.O. A.1
{
	instructions = n;
}

string Instructions::display() const //Display the instruction M.O. A.1
{
	return instructions;
}
