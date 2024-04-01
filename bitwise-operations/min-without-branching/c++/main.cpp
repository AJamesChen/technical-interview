#include <iostream>

using namespace std;

static int min_bitwise(int a, int b)
{
    long _a {a};
    long _b {b};

    _a -= _b;
    _a &= _a >> (sizeof(long) * 8 - 1);

    return (int) (_a + _b);
}

int main()
{
    cout << "min(-1, -2):" << min_bitwise(-1, -2) << endl;
    cout << "min(-2, -1):" << min_bitwise(-2, -1) << endl;
    cout << "min(5, 2):" << min(5, 2) << endl;
    cout << "min(2, 5):" << min(2, 5) << endl;
    cout << "min(5, 0):" << min(5, 0) << endl;
    cout << "min(0, 5):" << min(0, 5) << endl;
    cout << "min(-5, 0):" << min(-5, 0) << endl;
    cout << "min(0, -5):" << min(0, -5) << endl;
}