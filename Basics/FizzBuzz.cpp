// FizzBuzz問題
// 1から100までの数をプリントするプログラムを書け。
// ただし3の倍数のときは数の代わりに「Fizz」と，
// 5の倍数のときは「Buzz」とプリントし，
// 3と5両方の倍数の場合には「FizzBuzz」とプリントすること。

#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

#define ANS 2


#if ANS == 1
int main()
{
    rep(i, 1, 101) {
             if (! (i % 15)) cout << "FizzBuzz" << endl;
        else if (! (i %  5)) cout << "Buzz" << endl;
        else if (! (i %  3)) cout << "Fizz" << endl;
        else                 cout << i << endl;
    }
    return 0;
}
#endif


#if ANS == 2
int main()
{
    int f = 2, b = 4, fb = 14;
    rep(i, 1, 101) {
             if (! fb) { cout << "FizzBuzz" << endl; f=2; b=4; fb=14;}
        else if (!  f) { cout << "Fizz"     << endl; f=2; b--; fb--; }
        else if (!  b) { cout << "Buzz"     << endl; f--; b=4; fb--; }
        else           { cout << i << endl; f--; b--; fb--; }
    }
    return 0;
}
#endif


#if ANS == 3
int main()
{
    printf("1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n11\nFizz\n13\n14\nFizzBuzz\n16\n17\nFizz\n19\nBuzz\nFizz\n22\n23\nFizz\nBuzz\n26\nFizz\n28\n29\nFizzBuzz\n31\n32\nFizz\n34\nBuzz\nFizz\n37\n38\nFizz\nBuzz\n41\nFizz\n43\n44\nFizzBuzz\n46\n47\nFizz\n49\nBuzz\nFizz\n52\n53\nFizz\nBuzz\n56\nFizz\n58\n59\nFizzBuzz\n61\n62\nFizz\n64\nBuzz\nFizz\n67\n68\nFizz\nBuzz\n71\nFizz\n73\n74\nFizzBuzz\n76\n77\nFizz\n79\nBuzz\nFizz\n82\n83\nFizz\nBuzz\n86\nFizz\n88\n89\nFizzBuzz\n91\n92\nFizz\n94\nBuzz\nFizz\n97\n98\nFizz\nBuzz\n");
    return 0;
}
#endif
