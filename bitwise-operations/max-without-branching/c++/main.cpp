#include <iostream>

using namespace std;

static int max_bitwise(int a, int b)
{
    long _a {a};
    long _b {b};

    _a -= _b;
    _a &= (~_a) >> (sizeof(long) * 8 - 1);

    return (int) (_a + _b);
}

int main()
{
    cout << "max(-1, -2):" << max_bitwise(-1, -2) << endl;
    cout << "max(-2, -1):" << max_bitwise(-2, -1) << endl;
    cout << "max(5, 2):" << max(5, 2) << endl;
    cout << "max(2, 5):" << max(2, 5) << endl;
    cout << "max(5, 0):" << max(5, 0) << endl;
    cout << "max(0, 5):" << max(0, 5) << endl;
    cout << "max(-5, 0):" << max(-5, 0) << endl;
    cout << "max(0, -5):" << max(0, -5) << endl;
}