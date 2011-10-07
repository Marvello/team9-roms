//Author : M.O.-A.1

#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#include <string>

using namespace std;
 
struct Instructions {
public:
	// constructors
	Instructions(string n);

   // utility functions
	string display() const;
	
private:
	string instructions;
};


#endif //INSTRUCTION_H_
