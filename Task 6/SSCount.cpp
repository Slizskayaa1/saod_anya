#include <iostream>
#include <string>
#include "PF.h"

using namespace std;

unsigned SimpleSSCount(const char* s)
{
    string str(s);
    string arr[10000];

    int cnt = 0;

    for (int len = 1; len <= (int)str.size(); len++)
    {
        for (int i = 0; i + len <= (int)str.size(); i++)
        {
            string sub = str.substr(i, len);

            bool found = false;

            for (int j = 0; j < cnt; j++)
            {
                if (arr[j].size() == sub.size())
                {
                    bool ok = true;

                    for (int k = 0; k < (int)sub.size(); k++)
                    {
                        if (arr[j][k] != sub[k])
                        {
                            ok = false;
                            break;
                        }
                    }

                    if (ok)
                    {
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
            {
                arr[cnt] = sub;
                cnt++;
            }
        }
    }

    return cnt;
}

unsigned SSCount(const char* s)
{
    string str(s);
    unsigned total = 0;

    for (int i = 0; i < (int)str.size(); i++)
    {
        string t = str.substr(i);

        PF pf(t.c_str());

        int pMax = 0;

        for (int j = 0; j < (int)t.size(); j++)
        {
            int v = pf[j];
            if (v > pMax) pMax = v;
        }

        total += (t.size() - pMax);
    }

    return total;
}

int main()
{
    string s = "ababa";

    cout << SimpleSSCount(s.c_str()) << endl;
    cout << SSCount(s.c_str()) << endl;

    return 0;
}