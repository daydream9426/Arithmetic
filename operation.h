#ifndef OPERATION_H_
#define OPERATION_H_

#include "fraction.h"

class Operation{
private:
	Operation *prep;
	Operation *next;
	char symbol;
	int priority;
	Fraction *num;

	char newsymbol(int upper);
	int set();
	int newnum(int min,int max);// random min-10

public:
	Operation();
	Operation(int model,int f);//init construct: f==1 means root of the tree  f==2 means the second level of the tree
	//Model 1 means it can only be a operator, not a number.
	~Operation();
	int print(int lastpri);//last priority   Traversal tree,print the equation and calculate the answer
	
};

#endif
