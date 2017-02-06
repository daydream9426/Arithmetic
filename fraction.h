#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction{
private:
	int nume;// numerator
	int deno;// denominator

	int plus();
	int minus();
	int multi();//multiply
	int divide();

	int simplify();// simplify the fraction
public:
	Fraction();
	Fraction(int nu,int de);
	~Fraction();
	int print();
};

#endif
