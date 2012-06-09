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

    return 0;
}
