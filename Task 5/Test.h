#pragma once
#include <iostream>
#include <typeinfo>

using namespace std;

class Test
{
public:
    Test();
    Test(const Test& other);
    virtual ~Test();

    static int nCount;
};

void foo(Test t);

class Child : public Test
{
private:
    int* data;

public:
    Child();
    ~Child();
};

class Aggregate
{
private:
    Test obj;

public:
    Aggregate();
    ~Aggregate();
};

template <typename T>
class AggregateT
{
private:
    T value;

public:
    AggregateT()
    {
        cout << "AggregateT constructor for type: " << typeid(T).name() << endl;
    }

    ~AggregateT()
    {
        cout << "AggregateT destructor for type: " << typeid(T).name() << endl;
    }
};