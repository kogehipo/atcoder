// 問題 https://atcoder.jp/contests/abc122/tasks/abc122_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string N;
    cin >> N;

    int max_count = 0;
    int count = 0;
    int end = N.length();

    for (int i=0; i<end; i++) {
        switch (N.at(i)) {
            case 'A':
            case 'C':
            case 'G':
            case 'T':
                count++;
                break;
            default:
                if (max_count < count) max_count = count;
                count=0;
                break;
        }
        if (max_count < count) max_count = count;
    }

    cout << max_count << endl;
    return 0;
}
