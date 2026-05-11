#pragma once
#include <iostream>
#include "_str.h"

using namespace std;

class Str
{
private:
    _str* p;

    void detach()
    {
        if (p->ref > 1)
        {
            p->ref--;

            int len = strlen(p->s);
            char* ns = new char[len + 1];

            for (int i = 0; i <= len; i++)
            {
                ns[i] = p->s[i];
            }

            p = new _str(ns);
            delete[] ns;
        }
    }

public:
    Str(const char* s)
    {
        p = new _str(s);
    }

    Str(const Str& other)
    {
        p = other.p;
        p->ref++;
    }

    ~Str()
    {
        p->ref--;

        if (p->ref == 0)
        {
            delete p;
        }
    }

    Str& operator=(const Str& other)
    {
        if (this == &other)
            return *this;

        p->ref--;

        if (p->ref == 0)
            delete p;

        p = other.p;
        p->ref++;

        return *this;
    }

    Str& operator+=(const Str& other)
    {
        detach();

        int len1 = strlen(p->s);
        int len2 = strlen(other.p->s);

        char* ns = new char[len1 + len2 + 1];

        for (int i = 0; i < len1; i++)
        {
            ns[i] = p->s[i];
        }

        for (int i = 0; i < len2; i++)
        {
            ns[len1 + i] = other.p->s[i];
        }

        ns[len1 + len2] = 0;

        delete p;

        p = new _str(ns);

        delete[] ns;

        return *this;
    }

    operator const char*() const
    {
        return p->s;
    }

    int find(const char* t, int off) const
    {
        int n = strlen(p->s);
        int m = strlen(t);

        if (m == 0)
            return off <= n ? off : -1;

        for (int i = off; i <= n - m; i++)
        {
            int j = 0;

            while (j < m && p->s[i + j] == t[j])
            {
                j++;
            }

            if (j == m)
                return i;
        }

        return -1;
    }
};