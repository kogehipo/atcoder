#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> P(N);
    rep(n, N) {
        P[n].first = n+1;
        P[n].second = 0;
    }
    int head = 0;
    rep(i, Q) {
        int q;
        cin >> q;
        if (q == 2) {
            int p;
            cin >> p;
            int j = head+p-1;
            if (N <= j) j -= N;
            cout << P[j].first << ' ' << P[j].second << endl;
            continue;
        }
/*
        else if (q == 3) {
            int i=head;
            while(1) {
                cout << "- " << (i) << P[i].first << ' ' << P[i].second << " -\n";
                i++;
                if (N<=i) i-=N;
                if (i == head) break;
            }
        }
*/
        int neck = head;
        head--;
        if (head < 0) head += N;
        P[head] = P[neck];
        char c;
        cin >> c;
        switch (c) {
            case 'L': P[head].first--; break;
            case 'R': P[head].first++; break;
            case 'D': P[head].second--; break;
            case 'U': P[head].second++; break;
        }
    }
    return 0;
}
