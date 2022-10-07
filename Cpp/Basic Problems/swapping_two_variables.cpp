#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    cout << "Before swaping a = " << a << " , b = " << b << endl;
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "After swaping a = " << a << " , b = " << b << endl;
    return 0;
}
