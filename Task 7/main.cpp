#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    size_t prevCap = v.capacity();

    cout << v.size() << " " << v.capacity() << endl;

    for (int i = 0; i < 32; i++)
    {
        v.push_back(1);

        if (v.capacity() != prevCap)
        {
            cout << v.size() << " " << v.capacity() << endl;
            prevCap = v.capacity();
        }
    }

    return 0;
}