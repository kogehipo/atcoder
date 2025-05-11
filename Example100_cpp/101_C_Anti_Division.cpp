#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFF;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define cin_from(fname) ifstream ifs(fname); cin.rdbuf(ifs.rdbuf());
#define cout_to(fname) ofstream ofs(fname); cout.rdbuf(ofs.rdbuf());

// https://atcoder.jp/contests/abc131/tasks/abc131_c

int main()
{
  ll A, B;
  ll C, D;
  cin >> A >> B >> C >> D;
 
  // A以上で最小の、Cで割り切れる数
  ll min_by_C = ((A+C-1)/C)*C;
  // B以下で最大の、Cで割り切れる数
  ll max_by_C = (B/C)*C;
  // その個数
  ll nC = (max_by_C - min_by_C) / C +1;
 
  // A以上で最小の、Dで割り切れる数
  ll min_by_D = ((A+D-1)/D)*D;
  // B以下で最大の、Dで割り切れる数
  ll max_by_D = (B/D)*D;
  // その個数
  ll nD = (max_by_D - min_by_D) / D +1;
  
  //ll CD = C*D;  // こうじゃなくて最小公倍数が必要
  ll CD = lcm(C,D);
  // A以上で最小の、CDで割り切れる数
  ll min_by_CD = ((A+CD-1)/CD)*CD;
  // B以下で最大の、CDで割り切れる数
  ll max_by_CD = (B/CD)*CD;
  // その個数
  ll nCD = (max_by_CD - min_by_CD) / CD +1;

  ll ans = B-A+1 - nD - nC + nCD;

  //cout << B-A+1 << ' ' << nC << ' '  << nD << ' '  << nCD << endl;
  cout << ans << endl;    
    
  return 0;
}
