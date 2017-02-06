#include "operation.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
#define MAXNUM 10
#define MAXLEVEL 3

//private
char Operation::newsymbol(int upper)
{
	int c;
	char x;
	switch (c=newnum(1,upper))
	{
		case 1:x='+';break;
		case 2:x='-';break;
		case 3:x='*';break;
		case 4:x='/';break;
		default:x='0';break;
	}
	return x;
}

int Operation::newnum(int randmin,int randmax)
{
	srand(static_cast<unsigned> (time(NULL)));
	int x;
	x=(static_cast<int> (rand()));
	if (x!=0) x=x%(randmax+1-randmin);
	return (x+randmin);
}

int Operation::set()
{
	int flag,x; 
	if (symbol=='0') 
	{
		prep=NULL;next=NULL;priority=3;
		flag=newnum(0,1);
		if (flag==0)// int
		{
			num=new Fraction(newnum(0,MAXNUM),1);
		}
		else // proper fraction
		{
			x=newnum(1,MAXNUM-1);
			num=new Fraction(x,newnum(x+1,MAXNUM));
		}
	}
	else 
	{
		switch (symbol)
		{
			case '+':priority=1;break;
			case '-':priority=1;break;
			case '*':priority=2;break;
			case '/':priority=2;break;
		}
	}
	return 0;
}//set other variable based on symbol

//public
Operation::Operation() :prep(NULL),next(NULL),symbol('0'),priority(3),num(NULL)
{
	
}
//default constructor

Operation::Operation(int model,int f):prep(NULL),next(NULL),symbol('0'),priority(3),num(NULL)
//f==1 means root of the tree  f==2 means the second level of the tree and so on
//Model 1 means it can only be a operator, not a number.
//Model 3 means it can only be a number
{
	int c;
	if (model==1) { symbol=newsymbol(4);set();}
	else if (model==0) {symbol=newsymbol(6);set();} //4-6 means '0' . change 6 to change the chance of '0'
	else {symbol='0';set();}
	if (f==1)// make sure the equation has 3 number
	{
		if ((c=newnum(0,1))==0)
		{		
			prep=new Operation(1,2);  
			next=new Operation(0,2);		
		}
		else 
		{
			prep=new Operation(0,2);
			next=new Operation(1,2);		
		}
	}
	else if (f<MAXLEVEL)// make sure the equation has MAXLEVEL number most.
	{
		prep=new Operation(0,f+1);
		next=new Operation(0,f+1);
	}
	else if (f==MAXLEVEL)
	{
		prep=new Operation(3,f+1);
		next=new Operation(3,f+1);
	}

}


Operation::~Operation()
{
	if (prep!=NULL) delete(prep);
	if (next!=NULL) delete(next);
	if (num!=NULL) delete(num);
}


int Operation::print(int lastpri)
{

}


