#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string reverse_words_in_a_string(string& input, char delimiter)
{
    string output;
    vector<string> tokens;
    stringstream ss(input);
    string token;

    while (getline(ss, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    if (tokens.empty()) {
        return output;
    }

    output = tokens[tokens.size() - 1];
    for (int i = tokens.size() - 2; i >= 0; --i) {
        output += delimiter;
        output += tokens[i];
    }
    
    return output;
}

int main()
{
    string input1 = "hello,   world!";
    cout << reverse_words_in_a_string(input1, ' ') << endl;

    string input2 = "bashful doc dopey grumpy happy sleepy sneezy";
    cout << reverse_words_in_a_string(input2, ' ') << endl;
}