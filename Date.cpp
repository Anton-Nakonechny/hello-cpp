#include "Date.h"

class Date{

   int d,m,y;
   public:

   //...
   Date& add_year(int n); // add n years
   Date& add_month(int n); // add n months
   Date& add_day(int n); // add n days
   Date();
   public:
   inline bool leapyear(int y) {
   	return static_cast<bool>(y % 100)
   			? !static_cast<bool>(y % 4)
   			: !static_cast<bool>(y % 400);
   }
};

Date::Date()
{
	d = 1;
	m = 1;
	y = 1970;
}

Date& Date::add_year(int n) {
   if (d==29 && m==2 && !leapyear(y+n)) {
      // beware of February 29
      d=1;
      m=3;
    }
   y += n;
   return *this;
};

namespace C
{

	A& A::operator+(int b)
	{
		int_a += b;
		return *this;
	}
	A::A()
	{int_a = 0;}



}//namespace C
