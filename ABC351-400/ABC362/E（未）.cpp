#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define range(i, s, e) for (ll i = (s); i <= (ll)(e); i++)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)


template<class T>   // こう書くと、どんな型の集合(vector)が来ても対応できる
void combination(const vector<T>& data, int comb_size, bool (*callback)(const vector<T>&)) {
    vector<int> table(comb_size);  // dataから選択した要素の番号を記録するテーブル
    int iTable = 0;    // tableを指すインデックス（組合せ要素の幾つめに注目しているか）
    int index_of_selectable_data = 0;
 
    while (0 <= iTable) {
 
//cout << "Start of while (index_of_selectable_data=" << index_of_selectable_data << ")\n";
 
        // 次のループが1回まわるたびに、table要素がひとつずつセットされる
        for (int iData = index_of_selectable_data; iData < data.size(); ++iData) {
 
//cout << "  Enter for loop (iData=" << iData << ",iTable=" << iTable;
 
            table[iTable++] = iData;
 
//cout << "->" << iTable << ")";
//for (int k=0; k<comb_size; k++) cout << ' ' << table[k];
//cout << endl;
 
            if (iTable == comb_size) {  // 組み合わせの数だけ要素を選択したら、
                vector<T> comb(comb_size);  // そのサイズのvectorに、
                for (int j=0; j<comb_size; j++) comb[j] = data[table[j]];  // 各要素をセットして、
                if (callback(comb)) return;  // コールバック関数を呼ぶ。処理指示されたら戻る
                break;   // forループを抜けて次の組み合わせを探索
            }
 
        }
        if (--iTable < 0) break;
//cout << "  Exit for loop (iTable=" << iTable << ')' << endl;
        index_of_selectable_data = table[iTable] + 1;
    }
}

ll ans;

bool my_callback(const vector<ll>& comb) {
    //cout << "    CALLBACK: ";
    ll n = comb.size();
    ll d = comb[1] - comb[0];
    range(i,2,n-1) if (comb[i] - comb[i-1] != d) return false;
    ans++;

    cout << ans << " " ;
    rep(i,n) cout << comb[i] << " ";
    cout << endl;

    return false;
}

int main()
{
    ll N; cin >>N;
    vector<ll> A(N); rep(i,N) cin >>A[i];
    sort(all(A));
    cout << N << " ";
    if (2 <= N) cout << N*(N-1)/2 << " ";
    if (N == 2) { cout << endl; return 0; }
    // Nは3以上
    range(k,3,N) {
        ans = 0;
        combination(A, k, my_callback);
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}
