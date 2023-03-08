// exceed.cpp -- exceeding some integer limits
#include <iostream>
#include <climits>
#define ZERO 0

int main()
{
    using namespace std;
    short short_max = SHRT_MAX;
    short short_min = SHRT_MIN;
    cout << "short_max: " << short_max << endl;
    cout << "short_min: " << short_min << endl;

    short_max = short_max + 1;
    short_min = short_min + 1;

    cout << "short_max plus one: " << short_max << endl;
    cout << "short_min plus one: " << short_min << endl;

    unsigned short unsigned_short_max = USHRT_MAX;
    unsigned short unsigned_short_min = ZERO;
    cout << "unsigned_short_max: " << unsigned_short_max << endl;
    cout << "unsigned_short_min: " << unsigned_short_min << endl;

    unsigned_short_max = unsigned_short_max - 1;
    unsigned_short_min = unsigned_short_min - 1;

    cout << "short_max minus one: " << unsigned_short_max << endl;
    cout << "short_min minus one: " << unsigned_short_min << endl;
    return 0;
}