#pragma once
#include <cstring> 

class Str {
    char* m_pszText;
public:
    Str()
    {
        m_pszText = new char[1] {0};
    }

    Str(const char* p)
    {
        if (p) {
            m_pszText = new char[strlen(p) + 1];
            strcpy(m_pszText, p);  
        }
        else
            m_pszText = new char[1] {0};
    }

    Str(const Str& s) 
    {
        m_pszText = new char[strlen(s.m_pszText) + 1];
        strcpy(m_pszText, s.m_pszText);  
    }

    const Str& operator = (const Str& s) 
    {
        if (&s == this) return *this;
        delete[] m_pszText;    
        m_pszText = new char[strlen(s.m_pszText) + 1];
        strcpy(m_pszText, s.m_pszText);  
        return *this;
    }

    Str& operator +=(const char* sz) {
        int lng = strlen(m_pszText);
        int szLen = strlen(sz);
        
        char* temp = new char[lng + szLen + 1];
        
        strcpy(temp, m_pszText);  
        strcat(temp, sz);  
        
        delete[] m_pszText;
        m_pszText = temp;
        
        return *this;
    }

    Str operator +(const char *sz) const
    {
        Str res = *this;
        
        res += sz;
        
        return res;
    }

    ~Str() { delete[] m_pszText; }

    operator const char* ()const { return m_pszText; }
};