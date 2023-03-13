// limits.cpp
#include<iostream>
#include<climits>

int main()
{
    using namespace std;
    char n_char = CHAR_MAX;
    short n_short = SHRT_MAX;
    int n_int = INT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    // sizeof operator yields size of type or of variable
    cout << "char is " << sizeof(char) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl;
    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "char: " << n_char << endl;
    cout << "char: " << CHAR_MAX << endl;
    cout << "short: " << n_short << endl;
    cout << "int: " << n_int << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl;
    cout << endl;

    return 0;
}