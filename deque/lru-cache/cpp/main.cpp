#include <algorithm>
#include <iostream>
#include <iterator>
#include <deque>
#include <string>

using namespace std;

const int MAX_CACHE_SIZE = 5;

void print_cache(const deque<int>& cache)
{
    copy(cache.begin(), cache.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

void lru_cache(deque<int>& cache, int val)
{
    if (cache.size() >= MAX_CACHE_SIZE) {
        cache.pop_front();
    }

    cache.push_back(val);
    print_cache(cache);
}

int main()
{
    deque<int> cache;
    
    for (auto i = 0; i < 10; ++i) {
        lru_cache(cache, i);
    }
}