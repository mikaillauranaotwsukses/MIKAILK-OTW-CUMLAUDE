#include <iostream>

using namespace std;

int main() {
    //Pakai temp untuk menyimpan variabel a sebelum dibalik
    int a = 30, b = 20, temp;

    cout << endl << "Sebelum Dibalik:" << endl;
    cout << "a=" << a << " b=" << b << endl;

    int *p = &a;
    int *q = &b;

    temp = *p;
    *p = *q;
    *q = temp;

    cout << endl << "Setelah Dibalik:" << endl;
    cout << "a=" << a << " b=" << b << endl;

    return 0;
}
