//Author : S.X.-A.3

#ifndef DESCRIPTION_H_
#define DESCRIPTION_H_

#include <string>
using namespace std;

struct Description{
public:
	//constructor
	Description(string descr);

	//utility function
	string display() const;

private:
	//constant

	//private data
	string description;
};

#endif //DESCRIPTION_H_
