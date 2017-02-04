#ifndef OPERATION_H_
#define OPERATION_H_

class Operation{
private:
	Operation *prep;
	Operation *next;
	char symbol;
	int priority;
	int nume;// numerator
	int deno;// denominator
	

	char newsymbol();
	int newnum(int min,int max);// random min-10

	int plus();
	int minus();
	int multi();//multiply
	int divide();

	int simplify();// simplify 
public:
	Operation();
	Operation(int f);//init construct: f==1 means root of the tree  
	~Operation();
	int print(int lastpri);//last priority   Traversal tree,print the equation and calculate the answer

}

#endif