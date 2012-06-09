#include <iostream>

#ifndef _DATE_H_
#define _DATE_H_
namespace Chrono
{
class Date{

   int d,m,y;
protected:
   virtual ~Date()	{std::cout<<"Date-destuctor "<<this<<std::endl;}

public:

   //...
   Date& add_year(int n = 1); // add n years
   Date& add_month(int n); // add n months
   Date& add_day(int n); // add n days

 	Date():
	   d(1), m(1), y(1970)
		{std::cout<<"Date-constuctor "<<this<<std::endl;}

   inline bool leapyear(int y) {
   	return static_cast<bool>(y % 100)
   			? !static_cast<bool>(y % 4)
   			: !static_cast<bool>(y % 400);
   }
	inline friend std::ostream& operator<<(std::ostream& out,const Date& d)
	{
		out<<d.d<<"-"<<d.m<<"-"<<d.y;
		return out;
	}

	Date(const Date &date)
	{
		this->d = date.d;
		this->y = date.y;
		this->m = date.m;
		std::cout<<"Copy-constructor of Date "<<this<<std::endl;
	}

};


class A:public Date
{
	mutable int int_a;
public:
	inline	A& operator+=(int b)
		{
			int_a += b;
			return *this;
		}
	A();
	A(const A & a)
	{
		this->int_a = a.int_a;
		std::cout<<"Copy-constructor of A "<<this<<std::endl;
	}
	inline void const_inc (int a) const
		{int_a +=a;}
	~A()
	{std::cout<<"A-destuctor "<<this<<std::endl;}
	A(const Date &d);
	inline friend std::ostream& operator<<(std::ostream& out,const A& a)
	{
		out << "(int_a = " << a.int_a << ")";
		return out;
	}
};
inline const A operator+(const A& a, const int b)
{
	std::cout<<"A::operator+"<<std::endl;
	A a2=a;
	std::cout<<"A::operator+ after a2"<<std::endl;
	a2 += b;
	return a2;
}

class Bimpl
{
	int int_b;
	public:
	Bimpl()
	{std::cout<<"B-impl-constuctor "<<this<<std::endl;}
	~Bimpl()
	{std::cout<<"B-impl-destuctor "<<this<<std::endl;}
};
class B:public A
{
	int int_b;
	Bimpl impl;
	public:
	B()
	{std::cout<<"B-constuctor "<<this<<std::endl;}
	B(int b)
	{int_b = b;
	std::cout<<"B-constuctor "<<this<<std::endl;}
	~B()
	{std::cout<<"B-destuctor "<<this<<std::endl;}
};
}//namespace C
#endif
