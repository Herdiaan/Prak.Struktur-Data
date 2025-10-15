#include <iostream>
#include "mahasiswa.h"
#include "mahasiswa.CPP"
using namespace std;

int main()
{
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata - rata = " << rata2(mhs);
    return 0;
}