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

void print_k_closest_numbers(vector<int> &input, size_t k, int x)
{
    cout << "Print " << k << " closest numberss to " << x << " in " << endl;
    print_array(input);

    if (k == 0) {
        cout << "Invalid input k: " << k << endl;
        return;
    }

    if (input.size() == 0) {
        cout << "empty input array" << endl;
        return;
    }

    sort(input.begin(), input.end());

    if (k > input.size()) {
        cout << "k: " << k;
        cout << " is greater than array size: " << input.size() << endl;
        cout << "print all elements" << endl;
        print_array(input);
        return;
    }

    int left = 0;
    int right = input.size() - 1;
    // int min_abs = input[right] - input[left];
    int min_pos = left;

    if (input[left] >= x) {
        for (int i = 0; i < (int)(k - 1); ++i) {
            cout << input[i] << ", ";
        }
        cout << input[k - 1] << endl;
        return;
    }

    if (input[right] <= x) {
        for (int i = (int)(k - 1); i > 0; --i) {
            cout << input[i] << ", ";
        }
        cout << input[0] << endl;
        return;
    }

    int min_abs = abs(input[left] - x);
    
    while (left < right) {
        int mid = (left + right) / 2;
        if (abs(input[mid] - x) == 0) {
            min_pos = mid;
            break;
        }

        if (abs(input[mid] - x) < abs(input[left] - x)) {
            left = mid + 1;
        } else if (abs(input[mid] - x) < abs(input[right] - x)) {
            right = mid - 1;
        }

        if (min_abs > abs(input[mid] - x)) {
            min_abs = abs(input[mid] - x);
            min_pos = mid;
        }

        if (min_abs > abs(input[left] - x)) {
            min_abs = abs(input[left] - x);
            min_pos = left;
        }

        if (min_abs > abs(input[right] - x)) {
            min_abs = abs(input[right] - x);
            min_pos = right;
        }
    }

    cout << "minimum pos: " << min_pos << endl;
    size_t count = 1;
    left = min_pos;
    right = min_pos;
    while (count < k) {
        if (left > 0 && abs(input[left - 1] - x) <= abs(input[right + 1] - x)) {
            left -= 1;
            ++count;
        } 
        
        if (right < (int)(input.size() - 1) && abs(input[left - 1] - x) >= abs(input[right + 1] - x)) {
            right += 1;
            ++count;
        }

        if (right == (int)(input.size() - 1)) {
            left -= 1;
            ++count;
        }

        if (left == 0) {
            right += 1;
            ++count;
        }
    }

    for (int i = left; i < right; ++i) {
        cout << input[i] << ", ";
    }
    cout << input[right] << "\n" << endl;
}


int main()
{
    vector<int> input{ 1, 23, 12, 9, 30, 2, 50, -1, -20, -13 };
    sort(input.begin(), input.end());
    print_k_closest_numbers(input, 0, 5);
    print_k_closest_numbers(input, 2, 20);
    print_k_closest_numbers(input, 10, 3);
    print_k_closest_numbers(input, 3, 10);
    print_k_closest_numbers(input, 5, 9);
}