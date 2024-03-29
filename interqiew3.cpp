#include <iostream>

class A
{
public:
    A(int n = 2) : m_i(n) { }

    ~A() { std::cout<< m_i; }

protected:
    int m_i;
};

class B
    : public A
{
public:
    B(int n) : m_x(m_i + 1) , m_a(n) { }

public:
    ~B()
    {
        std::cout << m_i;
        --m_i;
    }

private:
    A m_x;
    A m_a;
};

int main()
{
    { B b(5); }

    std::cout << std::endl;

    return 0;
}
