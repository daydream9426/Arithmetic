#include "fraction.h"
#include <iostream>

Fraction::Fraction():nume(0),deno(1)
{

}
Fraction::Fraction(int nu,int de):nume(nu),deno(de)
{
	simplify();
}
Fraction::~Fraction()
{

}

int Fraction::print()
{
	if (deno==1) std::cout<<nume;
	else std::cout<<nume<<"/"<<deno;
	return 0;
}

//private of Fraction

int Fraction::plus()
{

}

int Fraction::minus()
{

}

int Fraction::multi()
{

}

int Fraction::divide()
{

}

int Fraction::simplify()
{
	int x,y,temp;
	if (nume==0) return 0;
	if (nume>=deno) {x=nume;y=deno;}
	else {x=deno;y=nume;}
	while (x%y!=0)
	{
		temp=x%y;
		x=y;
		y=temp;
	}//find the GCD between nume and demo
	if (y!=1)
	{
		nume/=y;
		deno/=y;
	}
	return 0;
}

