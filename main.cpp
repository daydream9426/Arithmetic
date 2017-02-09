#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include "operation.h"
#include "fraction.h"
using namespace std;

int main(void)
{
	srand((unsigned) (time(NULL)));
	Operation *a;
	int opwid=0,answid=0,maxopwid=60;
	for (int i=0;i<30;i++)
	{
		a=new Operation();
		opwid=a->print();
		
		cout<<" = ";
		answid=(a->getans()).print();
		cout<<setw(maxopwid-opwid-answid-3)<<"your answer is  "<<0;
		//50 is only an example.Calculate the maxopwid while running.
		//3 is the length of " = "
		cout<<endl;
		
		delete a;
	}
	Fraction b(2,1);
	Fraction c(3,1);
	Fraction d(4,2);
	cout<<endl;
	cout<<(c==b)<<endl;
	cout<<(d==b)<<endl;
	cout<<(c==d)<<endl;
	
	return 0;
}


