#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "Date.h"

using namespace std;
using namespace Chrono;

int main()
{
	A c_a,c_a2;
	A &ref_a = c_a;
	cout<<&c_a<<endl<<&ref_a<<endl;
	//Date *date = dynamic_cast<Date *>(& c_a);
	/*c_a.add_year(5);
	Date *date = new Date(c_a+7);
	date->add_year(1);
	A *a_from_date =  static_cast<A *>(date);
	cout<<"Hello cpp!"<<endl<<c_a<<endl<<*date<<endl;
	if (a_from_date)
		cout<<"A from_date cast to date "<<*(Date *)a_from_date<<endl<<*a_from_date<<endl<<endl;
	else
		cout<<endl;

	B b(5);
	B b2 = b;*/
//	execv("/home/x0169011/bin/hello.sh", NULL);
//	cout<<"Returned back from shell";
	return 0;
}
