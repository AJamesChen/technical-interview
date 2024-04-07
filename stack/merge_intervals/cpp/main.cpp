#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>
#include <string>

using namespace std;

void print_array(string message, const vector<pair<int, int>>& input)
{
    cout << message << ": " << endl;
    for (auto i: input) {
        cout << "[ " << i.first << ", " << i.second << " ]";
    }
    cout << endl;
}

int merge_interval(vector<pair<int, int>> &output, vector<pair<int, int>> &input)
{
    output.clear();
    print_array("input", input);
    sort(input.begin(), input.end(), [](auto a, auto b) { return a.first > b.first; });
    
    pair<int, int> p1 = input.back();
    input.pop_back();

    while (input.size() > 0) {
        pair<int, int> p2 = input.back();
 
        if (p1.second >= p2.first || p1.second >= p2.second) {
            input.pop_back();
            input.push_back(make_pair(p1.first, max(p1.second, p2.second)));
        } else {
            output.push_back(make_pair(p1.first, p1.second));
        }

        p1 = input.back();
        input.pop_back();
    }

    output.push_back(make_pair(p1.first, p1.second));

    return 0;
}

int main()
{
    vector<pair<int, int>> input{
        make_pair(1, 3),
        make_pair(2, 6),
        make_pair(8, 10),
        make_pair(15,18)
    };
    vector<pair<int, int>> output;
    merge_interval(output, input);
    print_array("output", output);

    vector<pair<int, int>> input1{
        make_pair(1, 4),
        make_pair(2, 5),
        make_pair(3, 6)
    };
    merge_interval(output, input1);
    print_array("output", output);

    vector<pair<int, int>> input2{
        make_pair(1, 2),
        make_pair(3, 4),
        make_pair(5, 6)
    };
    merge_interval(output, input2);
    print_array("output", output);

    vector<pair<int, int>> input3{
        make_pair(1, 2)
    };
    merge_interval(output, input3);
    print_array("output", output);

    vector<pair<int, int>> input4{
        make_pair(1, 10),
        make_pair(2, 5),
    };
    merge_interval(output, input4);
    print_array("output", output);
}