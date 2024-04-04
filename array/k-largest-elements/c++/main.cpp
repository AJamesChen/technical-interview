#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

void print_k_largest_elements(const vector<int> &input, int k)
{
    cout << "Print " << k << " largest elements in " << endl;
    copy(input.begin(), input.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    if (k < 0) {
        cerr << "Invalid input k: " << k << "\n" << endl;
        return;
    }

    if (k > (int)input.size()) {
        cout << "k: " << k;
        k = input.size();
        cout << " is greater than array size: " << input.size() << endl;
        cout << "print all elements" << endl;
    }

    set<int, greater<int>> s(input.begin(), input.end());

    auto i = s.begin();

    while (k > 0) {
        cout << *i << " ";
        ++i;    
        --k;
    }
    
    cout << "\n" << endl;
}


int main()
{
    vector<int> input{ 1, 23, 12, 9, 30, 2, 50 };
    print_k_largest_elements(input, -1);
    print_k_largest_elements(input, 20);
    print_k_largest_elements(input, 3);
}