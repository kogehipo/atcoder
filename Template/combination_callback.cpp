#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

// 再帰を使わずに組み合わせを作成する（コールバック関数付き）
// https://maku77.github.io/cpp/number/combination.html

//   ①②③④ から、組合せ ○○○ を選び出す。
//   ①②③
//   ①② ④
//   ① ③④
//    ②③④

// (引数1)元データ（vector型の参照）
// (引数2)組み合わせの要素数
// (引数3)各組み合わせを処理するコールバック関数

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
//rep(k,0,comb_size) cout << ' ' << table[k];
//cout << endl;

            if (iTable == comb_size) {  // 組み合わせの数だけ要素を選択したら、
                vector<T> comb(comb_size);  // そのサイズのvectorに、
                rep(j, 0, comb_size) comb[j] = data[table[j]];  // 各要素をセットして、
                if (callback(comb)) return;  // コールバック関数を呼ぶ。処理指示されたら戻る
                break;   // forループを抜けて次の組み合わせを探索
            }

        }
        if (--iTable < 0) break;
//cout << "  Exit for loop (iTable=" << iTable << ')' << endl;
        index_of_selectable_data = table[iTable] + 1;
    }
}


///////////////// How to use


// 戻り値： true=処理停止、false=処理継続
bool my_callback(const vector<int>& comb) {
    cout << "    CALLBACK: ";
    int n = comb.size();
    for (int i=0; i<n; ++i)
        cout << comb[i] << " ";
    cout << endl;
    return false;
}

int main() {
    vector<int> vals;
    vals.push_back(10);
    vals.push_back(20);
    vals.push_back(30);
    vals.push_back(40);

    // (1)元データ（vector型）
    // (2)組み合わせの要素数
    // (3)各組み合わせを処理するコールバック関数
    combination(vals, 3, my_callback);
}
