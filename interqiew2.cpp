#include <iostream>
#include <vector>

class A
{
public:
    A(int n = 0) : m_n(n) { }

public:
    virtual int value() const { return m_n; }
    virtual ~A() { }

protected:
    int m_n;
};

class B
    : public A
{
public:
    B(int n = 0) : A(n) { }

public:
    virtual int value() const { return m_n + 1; }
};

int main()
{
    const A a(1);
    const B b(3);
    const A *x[2] = { &a, &b };
    typedef std::vector<A> V;
    V y;
    y.push_back(a);
    y.push_back(b);
    V::const_iterator i = y.begin();

    std::cout << x[0]->value() << x[1]->value()
              << i->value() << (i + 1)->value() << std::endl;

    return 0;
}
