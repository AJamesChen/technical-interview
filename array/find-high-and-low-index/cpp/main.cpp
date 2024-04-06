#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void print_array(const vector<int> &input)
{
    copy(input.begin(), input.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

int find_high_low_index(vector<int> &input, int val, int &low, int &high)
{
    auto [low_it, high_it] = equal_range(input.begin(), input.end(), val);

    low = low_it - input.begin();
    high = high_it - input.begin();

    if (low_it == input.end() || *low_it != val) {
        return -1;
    }

    return 0;
}

void print_result(vector<int> &input, int val, int ret, int low, int high)
{
    print_array(input);
    if (ret == -1) {
        cout << "Cannot find " << val << endl;
    } else {
        cout << "find " << val << " betwen low: " << low << " high: " << high << endl;
    }
}

int main()
{
    vector<int> input{ 1, 2, 2, 2, 3, 3, 3, 4, 6, 6 };
    int low;
    int high;
    int ret;
    int val = -1;
    ret = find_high_low_index(input, val, low, high);
    print_result(input, val, ret, low, high);

    val = 1;
    ret = find_high_low_index(input, val, low, high);
    print_result(input, val, ret, low, high);

    val = 2;
    ret = find_high_low_index(input, val, low, high);
    print_result(input, val, ret, low, high);

    val = 4;
    ret = find_high_low_index(input, val, low, high);
    print_result(input, val, ret, low, high);

    val = 6;
    ret = find_high_low_index(input, val, low, high);
    print_result(input, val, ret, low, high);

    val = 10;
    ret = find_high_low_index(input, val, low, high);
    print_result(input, val, ret, low, high);
}