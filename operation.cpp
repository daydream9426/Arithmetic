#include "Operation.h"
#include <time.h>
#include <stdio.h>
#define MAXNUM 10
//public 
Operation::Operation() :prep(NULL),next(NULL),symbol("0"),priority(3),nume(0),deno(1)
{
	int flag;
	symbol=newsymbol();
	if (symbol=='0') 
	{
		prep=NULL;next=NUll;priority=3;
		flag=newnum(0,1);
		if (flag==0)// int
		{
			nume=newnum(0,MAXNUM);
			deno=1;
		}
		else // double
		{
			nume=newnum(1,MAXNUM-1);
			deno=newnum(nume,MAXNUM);
		}
	}
	else 
	{
		prep=new Operation;
		next=new Operation;
		switch (symbol)
		{
			case '+':priority=1;break;
			case '-':priority=1;break;
			case '*':priority=2;break;
			case '/':priority=2;break;
		}
	}
}//default init
Operation::Operation(int f) 
{
	int c;
	nume=0;deno=1;
	switch (c=random(1,4))
	{
		case 1:symbol='+';break;
		case 2:symbol='-';break;
		case 3:symbol='*';break;
		case 4:symbol='/';break;
	}
	prep=new Operation;
	next=new Operation;
	switch (symbol)
	{
		case '+':priority=1;break;
		case '-':priority=1;break;
		case '*':priority=2;break;
		case '/':priority=2;break;
	}
}
//default init


Operation::~Operation()
{
	if (prep!=NULL) delete(prep);
	if (next!=NULL) delete(next);
}


int Operation::print(int lastpri)
{

}

//private
char Operation::newsymbol()
{
	int c;
	char x;
	switch (c=random(1,6))// 4-6 :'0' can change "6" to change the chance of '0' 
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
	srand(static_cast<unsigned> time(NULL));
	int x;
	x=static_cast<int> ((rand())/(randmax+1-randmin));
	return (x+randmin);
}

int Operation::plus()
{

}

int Operation::minus()
{

}

int Operation::multi()
{

}

int Operation::divide()
{

}

int Operation::simplify()
{

}

