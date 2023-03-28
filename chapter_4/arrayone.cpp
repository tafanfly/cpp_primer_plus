#include <iostream>

int main()
{
    using namespace std;
    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 6;

    int yamsconst[3] = {20, 30, 5};
    cout << "Total ymas = " << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs "
         << yamsconst[1] << " cents per yam.\n";

    int total = yams[0] * yamsconst[0] + yams[1] * yamsconst[1];
    total = total + yams[2] * yamsconst[2];
    cout << "The total yam expense is " << total << " cents." << endl;

    cout << "\nSize of yams array = " << sizeof(yams)
         << " bytes.\n";
    cout << "Size of one element = " << sizeof(yams[0])
         << " bytes.\n";

    return 0;
}