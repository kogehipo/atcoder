#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N; cin >> N;
    int sum = 0;
    vector<int> A(N); rep(i, N) { cin >> A[i]; sum += A[i]; }
    if (sum%N != 0) {
        cout << -1 << endl;
        return 0;
    }
    int ave = sum/N;
//cout << "ave=" << ave << endl;
    int ans = 0;
    int l = 0, r = 0;
    while(l < N) {
        if (A[l] == ave) {
            l++;
            r = l;
            continue;
        }
        int local_sum = A[l];
        int local_ave = A[l];
        int local_cnt = 1;
        r++;
        while (local_ave != ave) {
            ans++;
            local_sum += A[r];
            local_cnt++;
            local_ave = local_sum/local_cnt;
            if (local_sum%local_cnt != 0) local_ave = -1; 
//cout << ans << " l=" << l << " r=" << r << " local_sum=" << local_sum << " local_ave=" << local_ave << " #=" << local_cnt << endl;
            r++;
            if (r >= N) break;
        }
        l = r;
    }
    cout << ans << endl;
    return 0;
}
