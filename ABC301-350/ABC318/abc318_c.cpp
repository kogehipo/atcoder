#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, s, e) for (int i = (s); i <= (int)(e); i++)
#define mod(a,b) ((a)%(b)<0 ? (a)%(b)+abs(b) : (a)%(b))
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

int main()
{
    ll days, bookSize, bookPrice;
    cin >> days >> bookSize >> bookPrice;
    vector<ll> dayFare(days);
    rep(i, days) cin >> dayFare[i];
    sort(rall(dayFare));  // 日毎の運賃を降順にソート
    ll bookDay = bookPrice / bookSize;  // 回数券の1日あたりの値段

    ll ans = 0;  // 費用合計
    ll i = 0;  // 処理した日

    // 回数券のほうが確実に安い
    while(1) {
        if (i + bookSize -1 < days && 
            bookDay <= dayFare[i+bookSize-1]) {
            ans += bookPrice;
            i += bookSize;
        } else {
            break;
        }
    }
    //cout << "(1) "<< ans << endl;

    // 次のbookSize日間の運賃合計
    ll subTotal = 0;
    range(j, i, i+bookSize-1) {
        if (days <= j) break;
        subTotal += dayFare[j];
    }
    ans += min(subTotal, bookPrice);
    i += bookSize;
    //cout << "(2) "<< ans << endl;

    // 1日券のほうが安い
    range(j, i, days-1) {
        ans += dayFare[j];
    }

    cout << ans << endl;
    return 0;
}
