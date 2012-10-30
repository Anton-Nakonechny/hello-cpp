#include <iostream>

class A
{
public:
    explicit A(int n = 0) : m_n(n) { }

    A(const A& a)
        : m_n(a.m_n)
    {
        ++m_copy_ctor_calls;
        std::cout << "&";
    }

public:
    static int m_copy_ctor_calls;

private:
    int m_n;
};

int A::m_copy_ctor_calls = 0;

A f(const A& a) { std::cout << "f";return a; }

A g(const A a) { std::cout << "g";return a; }

class B
{
private:
	int b_int;
public:
	B(int b):b_int(b)
	{}
	friend int operator+(const B &b, const int);
	friend std::ostream& operator<<(std::ostream & out, const B& b);
};
std::ostream& operator<<(std::ostream & out, const B& b)
{
	return out<<b.b_int;
}
int operator+(const B &b, const int a)
{
	return a+b.b_int;
}
int main()
{
    A a;
    A b = a, c(a);
    std::cout << A::m_copy_ctor_calls;

    b = g(c);
    std::cout << A::m_copy_ctor_calls;

    A& d = a;
    std::cout << "d";
    d = f(c);
    std::cout << A::m_copy_ctor_calls << std::endl;

    B i = 5;

    std::cout<<i+4<<std::endl;

    return 0;
}
