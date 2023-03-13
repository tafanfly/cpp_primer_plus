// hexotc.cpp -- shows hex and otc
#include<iostream>

int main()
{
    using namespace std;
    int decimal_int = 42;
    int hexadecimal_int = 0x42;
    int octal_int = 042;

    cout << "decimal_int 42 is (dec)" << decimal_int << endl;
    cout << "hexadecimal_int 0x42 is (dec)" << hexadecimal_int << endl;
    cout << "octal_int 042 is (dec)" << octal_int << endl;

    cout << endl;
    cout << "decimal_int 42 is (dec)" << decimal_int << endl;
    cout << hex;
    cout << "hexadecimal_int 0x42 is (hex)" << hexadecimal_int << endl;
    cout << oct;
    cout << "octal_int 042 is (oct)" << octal_int << endl;
    return 0;
}