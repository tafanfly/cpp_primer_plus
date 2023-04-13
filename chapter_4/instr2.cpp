#include <iostream>

int main()
{
    using namespace std;
    const int ArSize = 6;
    char name[ArSize];
    char friut[ArSize];

    cout << "Enter your name:\n";
    cin.getline(name, ArSize);
    cout << "Enter your favorite friut:\n";
    cin.getline(friut, ArSize);
    cout << "I have some delicious " << friut;
    cout << " for you, " << name << ".\n";
    return 0;
}