#include <iostream>

int main()
{
    using namespace std;
    char dog[3] = {'a', 'b', 'c'};
    char cat[3] = {'f', 'e', '\0'};
    cout << "dog is " << dog << endl;
    cout << "cat is " << cat << endl;

    char size = 'S';
    // char newSize = "S";
    cout << "size is " << size << endl;
    // cout << "newSize is " << newSize << endl;

    cout << "hello," " world." << endl;
    cout << "hello, world." << endl;
    cout << "hello,"
    " world." << endl;

    return 0;
}