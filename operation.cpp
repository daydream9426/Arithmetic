#include "Operation.h"
#include <time.h>
#include <stdio.h>

int random(int max)
{
	srand((unsigned)time(NULL));
	double x;
	x=(rand())/(max+1);
	return x;
}

//public 

Operation::Operation() :prep(NULL),next(NULL),symbol("0"),priority(0),deno(0),nume(0),ans(0)
{

}//default init


Operation::~Operation()
{

}

Operation* Operation::newop()
{

}

int Operation::print(int lastpri)
{

}

//private
char Operation::newsymbol()
{

}

int Operation::newnum()
{

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

