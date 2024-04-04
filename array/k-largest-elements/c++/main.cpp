#include <iostream>
#include <set>
#include <vector>

using namespace std;

void print_k_largest_elements(const vector<int> &input, int k)
{
    set<int, greater<int>> s(input.begin(), input.end());

    auto i = s.begin();

    while (k > 0) {
        cout << *i << " ";
        ++i;    
        --k;
    }
    
    cout << endl;
}


int main()
{
    vector<int> input{ 1, 23, 12, 9, 30, 2, 50 };
    print_k_largest_elements(input, 3);
}