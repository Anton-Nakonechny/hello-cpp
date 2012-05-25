#include <iostream>

#ifndef _DATE_H_
#define _DATE_H_
namespace C
{

class A
{
	int int_a;
public:
	A& operator+(int b);
	A();
	inline friend std::ostream& operator<<(std::ostream& out,const A& a)
	{
		out << a.int_a;
		return out;
	}
};

}//namespace C
#endif
