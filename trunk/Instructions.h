//Author : M.O.-A.1

#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#include <string>

using namespace std;
 
struct Instructions {
public:
	// constructors
	Instructions(string n); //Instruction Constructor M.O. A.1

   // utility functions
	string display() const; //Return string consist of instrution informationM.O. A.1
	
private:
	string instructions; //Variable contain instruction M.O. A.1
};


#endif //INSTRUCTION_H_
