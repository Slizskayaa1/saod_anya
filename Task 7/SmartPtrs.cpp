#include <iostream>
#include <memory>
#include "Test.h"

using namespace std;

shared_ptr<Test> foo()
{
    shared_ptr<Test> p(new Test());

    p->Val = 42;

    return p;
}

Test* goo()
{
    Test* p = new Test();

    p->Val = 42;

    return p;
}

int main()
{
    {
        shared_ptr<Test> p = foo();

        cout << p->Val << endl;
    }

    cout << "after block" << endl;

    {
        shared_ptr<Test> t;

        t = foo();

        cout << t->Val << endl;
    }

    cout << "---- goo ----" << endl;

    Test* r = goo();

    cout << r->Val << endl;

    delete r;

    return 0;
}