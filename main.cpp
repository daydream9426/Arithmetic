#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "operation.h"
#include "fraction.h"
using namespace std;

int main(void)
{
	srand((unsigned) (time(NULL)));
	Operation *a;
	for (int i=0;i<30;i++)
	{
		a=new Operation();
		a->print();
		cout<<"= ";
		(a->getans()).print();
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


