#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define all(a) begin(a), end(a)

// . 通路
// # 磁石
// @ 磁石隣接

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    // 磁石に隣接するマスを@にする
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') {
                if (0 < i   && S[i-1][j] == '.') S[i-1][j] = '@';
                if (i < H-1 && S[i+1][j] == '.') S[i+1][j] = '@';
                if (0 < j   && S[i][j-1] == '.') S[i][j-1] = '@';
                if (j < W-1 && S[i][j+1] == '.') S[i][j+1] = '@';
            }
        }
    }
    //rep(i, H) {
    //    cout << S[i] << endl;
    //}

    // 通路'.'について連結成分を求める
    dsu d(H*W);
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '.') {
                //if (0 < i   && S[i-1][j] == '.') d.merge(i*W+j, (i-1)*W+j); // 冗長
                if (i < H-1 && S[i+1][j] == '.') d.merge(i*W+j, (i+1)*W+j);
                //if (0 < j   && S[i][j-1] == '.') d.merge(i*W+j, i*W+j-1); // 冗長
                if (j < W-1 && S[i][j+1] == '.') d.merge(i*W+j, i*W+j+1);
            }
        }
    }

/*
    // こう書くとTLEする
    map<int, int> G; // 連結成分のleader, その連結成分のサイズ
    int N = d.groups().size(); // 連結成分の数
    rep(i, N) {
        int l = d.leader(d.groups()[i][0]);
        if (S[l/W][l%W] != '.') continue; // 連結成分が1マスだけのものは除外
        G[l] = d.size(l);
    }
*/
    map<int, int> G; // 連結成分のleader, その連結成分のサイズ
    for (auto& g : d.groups()) {
        int l = d.leader(g[0]);
        if (S[l/W][l%W] != '.') continue; // 連結成分が1マスだけのものは除外
        G[l] = g.size();
    }
    //for (const auto& g : G) cout << g.first << ":" << g.second << endl;
    //cout << "--" << endl;

    // @の数を、隣接する連結成分に足す
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] != '@') continue;
            set<int> st; // 連結成分に+1足すべき
            if (0 < i   && S[i-1][j] == '.') st.insert(d.leader((i-1)*W+j));
            if (i < H-1 && S[i+1][j] == '.') st.insert(d.leader((i+1)*W+j));
            if (0 < j   && S[i][j-1] == '.') st.insert(d.leader(i*W+j-1));
            if (j < W-1 && S[i][j+1] == '.') st.insert(d.leader(i*W+j+1));
            for (const auto& l : st) G[l]++;
        }
    }
    //for (const auto& g : G) cout << g.first << ":" << g.second << endl;

    int ans = 1;  // 通路が1マスもない場合=最小値
    for (const auto& g : G) ans = max(ans, g.second);
    cout << ans << endl;
    return 0;
}
