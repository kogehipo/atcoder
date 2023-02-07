#include <bits/stdc++.h>
using namespace std;

// nの約数を全て配列に入れて返す
vector<long long> divisors(long long n) {
    vector<long long> res;
    for (long long i=1; i*i<=n; ++i) {
        if (n%i == 0) {
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());  // 昇順
    return res;
}

int main()
{
    vector<long long> v;
    v = divisors(96);
    for (auto i : v) cout << i << ' ';
    cout << endl;
}