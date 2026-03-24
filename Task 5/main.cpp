#include <iostream>
#include "Test.h"

using namespace std;

int main()
{
    Child c;
    Aggregate a;

    AggregateT<Test> t1;
    AggregateT<Child> t2;

    foo(c);

    return 0;
}