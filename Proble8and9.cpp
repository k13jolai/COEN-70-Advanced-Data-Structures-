//Problem 8 and 9
//Coen 70

#include <iostream>
#include <math.h>


class quadratic{
public:
	quadratic();
	void set_coefficients(double x, double y, double z);
	void get_a() const;
	void get_b() const;
	void get_c() const;
	void evaluate(int p);

	friend quadratic operator+(const quadratic& q1, const quadratic&2);
	friend quadratic operator*(double r, const quadratic& q);

private:
	double a;
	double b;
	double c;
	int realroots;

};

quadratic::quadratic() : a(0.0), b(0.0), c(0.0), realroots(0) {}

void quadratic::set_coefficients(double x, double  y, double z){
	a=x;
	b=y;
	z=c;
	
}

void quadratic::get_a() cost{
cout << "Coefficient A is" << a << "\n";
}


void quadratic::get_b() const{
cout << "Coefficient B is" << b << "\n";
}


void quadratic::get_c() const{
cout << "Coefficient C is" << c << "\n";
}

void quadratic::evaluate(int p){
double result;
result=(a*a*p)+(b*p)+c;

cout << "The value of this quadratic expression is" << result  << "\n";
