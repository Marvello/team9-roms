//Author : M.O.-A.1

#include "Instructions.h"
#include <iostream>

Instructions::Instructions (string n) //Instruction Constructor
{
	instructions = n;
}

string Instructions::display() const //Display the instruction
{
	return instructions;
}