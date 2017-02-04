#ifndef OPERATION_H_
#define OPERATION_H_

int random(int max);// random number 0-max

class Operation{
private:
	Operation *prep;
	Operation *next;
	char symbol;
	int priority;
	int deno;// denominator
	int nume;// numerator

	char newsymbol();
	int newnum();

	int plus();
	int minus();
	int multi();//multiply
	int divide();

	int simplify();// simplify 
public:
	Operation();
	~Operation();
	Operation* newop; //last priority
	int print(int lastpri);//Traversal tree,print the equation and calculate the answer

}

#endif