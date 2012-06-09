#include "Date.h"

namespace Chrono
{

Date& Date::add_year(int n) {
   if (d==29 && m==2 && !leapyear(y+n)) {
      // beware of February 29
      d=1;
      m=3;
   }
   y += n;
   return *this;
};


	A::A()
	{int_a = 0;std::cout<<"A-constuctor "<<this<<std::endl;}

}//namespace C
