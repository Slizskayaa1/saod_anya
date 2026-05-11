#pragma once
#include <string.h>

class _str
{
public:
    char* s;
    int ref;

    _str(const char* src)
    {
        ref = 1;

        int len = strlen(src);
        s = new char[len + 1];

        for (int i = 0; i <= len; i++)
        {
            s[i] = src[i];
        }
    }

    ~_str()
    {
        delete[] s;
    }
};