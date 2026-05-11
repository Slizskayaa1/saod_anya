#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

unsigned RLEDeflate(const unsigned char *src, unsigned len, unsigned char *dst)
{
    unsigned i = 0, j = 0;

    while (i < len)
    {
        unsigned char current = src[i];
        unsigned count = 1;

        while (i + count < len && src[i + count] == current && count < 255)
            count++;

        if (count > 3)
        {
            dst[j++] = 0;
            dst[j++] = (unsigned char)count;
            dst[j++] = current;
        }
        else
        {
            for (unsigned k = 0; k < count; k++)
                dst[j++] = current;
        }

        i += count;
    }

    return j;
}

unsigned RLEInflate(const unsigned char *src, unsigned len, unsigned char *dst)
{
    unsigned i = 0, j = 0;

    while (i < len)
    {
        if (src[i] == 0)
        {
            unsigned count = src[i + 1];
            unsigned char value = src[i + 2];

            for (unsigned k = 0; k < count; k++)
                dst[j++] = value;

            i += 3;
        }
        else
        {
            dst[j++] = src[i++];
        }
    }

    return j;
}

unsigned Size(const unsigned char *src, int len)
{
    unsigned size = 0;

    for (int i = 0; i < len; i++)
    {
        if (src[i] == 0)
        {
            i++;
            size += src[i];
            i++;
        }
        else
        {
            size++;
        }
    }

    return size;
}

extern unsigned COBS_encode(const unsigned char*, unsigned, unsigned char*);
extern unsigned COBS_decode(const unsigned char*, unsigned, unsigned char*);

int main()
{
    ifstream fin("data.exe", ios::binary);

    if (!fin)
        return 0;

    vector<unsigned char> input((istreambuf_iterator<char>(fin)),
                                 istreambuf_iterator<char>());

    fin.close();

    unsigned char *cobs = new unsigned char[input.size() * 2];
    unsigned char *rle  = new unsigned char[input.size() * 2];
    unsigned char *out  = new unsigned char[input.size() * 2];

    unsigned cobsSize = COBS_encode(input.data(), input.size(), cobs);
    unsigned rleSize = RLEDeflate(cobs, cobsSize, rle);

    unsigned predicted = Size(rle, rleSize);

    unsigned decodedCobs = RLEInflate(rle, rleSize, out);
    unsigned finalSize = COBS_decode(out, decodedCobs, out);

    ofstream fout("output.bin", ios::binary);
    fout.write((char*)out, finalSize);
    fout.close();

    delete[] cobs;
    delete[] rle;
    delete[] out;

    return 0;
}