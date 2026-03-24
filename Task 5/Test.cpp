#include "Test.h"

int Test::nCount = 0;

Test::Test()
{
    nCount++;
    cout << "Created element, ammount: " << nCount << endl;
}

Test::Test(const Test& other)
{
    nCount++;
    cout << "Copy constructor, amount: " << nCount << endl;
}

Test::~Test()
{
    nCount--;
    cout << "Delete element, ammount: " << nCount << endl;
}

void foo(Test t)
{
    cout << "foo is running" << endl;
}

Child::Child() : Test()
{
    data = new int(0);
    cout << "Child constructor" << endl;
}

Child::~Child()
{
    delete data;
    cout << "Child destructor" << endl;
}

Aggregate::Aggregate()
{
    cout << "Aggregate constructor" << endl;
}

Aggregate::~Aggregate()
{
    cout << "Aggregate destructor" << endl;
}