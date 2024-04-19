#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct P {  // 人の情報をまとめた構造体
    int id;
    int omote;
    int ura;
};

bool fcomp(const struct P &a, const struct P &b) {
    // 勝率を降順で比較する
    // a.omote/(a.omote+a.ura) > b.omote/(b.omote+b.ura) なら a < b
    // 割り算を使わないように、比較式を次のように変形する
    // a.omote*(b.omote+b.ura) > b.omote*(a.omote+a.ura) なら a < b
    ll A = (ll)a.omote*(b.omote+b.ura);
    ll B = (ll)b.omote*(a.omote+a.ura);
    if (A != B) return A > B;

    // 勝率が同じなら、idの昇順
    return a.id < b.id;
}

int main()
{
    int N;
    cin >> N;
    vector<struct P> P(N);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        P[i].id = i+1;
        P[i].omote = a;
        P[i].ura = b;
    }
    sort(P.begin(), P.end(), fcomp);
    rep(i, N) cout << P[i].id << ' ';
    cout << endl;
    return 0;
}


/*
int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<pair<long double,int>> C(N);
    rep(i, N) C[i] = make_pair((long double)A[i]/(A[i]+B[i]), i+1);
    sort(rall(C));

    vector<int> x;
    rep(i, N) {
        if (i==0) {
            x.push_back(C[i].second);
            continue;
        }
        else if (C[i].first == C[i-1].first) {
            x.push_back(C[i].second);
            if (i == N-1) {
                sort(all(x));
                rep(j, x.size()) cout << x[j] << ' ';
                cout << endl;
                return 0;
            }
            continue;
        }
        else {
            sort(all(x));
            rep(j, x.size()) cout << x[j] << ' ';
            x.clear();
            x.push_back(C[i].second);
            if (i == N-1) {
                cout << C[i].second << endl;
                return 0;
            }
        }
    }
    return 0;
}
*/
