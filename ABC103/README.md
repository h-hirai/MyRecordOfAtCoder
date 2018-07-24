# AtCoder Beginner Contest 103

2018-07-21参加。なんかジャッジシステムがトラぶってたらしいけど、自分の回答には影響なかった。初めて時間内に全問ACできた。

[提出一覧](https://beta.atcoder.jp/contests/abc103/submissions/me)

## A. Task Scheduling Problem

[問題ページ](https://beta.atcoder.jp/contests/abc103/tasks/abc103_a)

3つの数字を与えられて、|A_j-A_i|+|A_k-A_j|が最小になるi,j,kの順序を求めよ、という問題。ソートして上記を計算すればいいと思ってそうしたけど、それって結局max-minだった。

全通り計算しちゃってもいい。

## B. String Rotation

[問題ページ](https://beta.atcoder.jp/contests/abc103/tasks/abc103_b)

文字列S,Tが与えられて、片方をローテーションさせて一致させられるかという問題。実際にやってみればいい。

ローテーションの方法は、自分が書いたように、

```
auto R = S.substr(i, S.length()) + S.substr(0, i);
```

でもいいし、解説のように、

```
S = S.back() + S.substr(0, S.size()-1);
```

でもいい。

## C. Modulo Summation

[問題ページ](https://beta.atcoder.jp/contests/abc103/tasks/abc103_c)

各項が、与えられる数列要素を法とした、引数の剰余であり、それらの総和が値となる関数の、最大値を求める。(`f(m) = (m mod a_1) + (m mod a_2) + ... + (m mod a_N)`)

引数を1ずつ増加させたときの各項の値を観察すると、各項は1ずつ増加していき a-1 で1周する。m=lcm(A)-1のとき、全項が a_n-1 となり、これが f(m) の最大値である。よって答えはΣ(a_n-1)。

## D. Islands War

[問題ページ](https://beta.atcoder.jp/contests/abc103/tasks/abc103_d)

(1)-(2)-(3)-...-(N) のような一列のリンクがあり、M個の組 (a_m, b_m) が与えられる。すべての組の連絡をなくすようにリンクを切断するには、最少いくつのリンクを切断すればよいか。

(1)-(2) 間のリンクを1、(2)-(3) 間のリンクを2のように、(n)-(n+1) 間のリンクをnとしたとき、a <= n < b であるようなすべての組は、n のリンクを切断することで連絡をなくすことができるので、M個の組をa_mについてソートして頭からなめていき、aがそこまでbの最小値を上回ったところで切断するべきリンク数をインクリメントして、また走査を繰り返す。

ひとつのリンクの切断で連絡をなくすことができる組のグループ分け、という問題なので、前に見た UnionFindTree がらみの問題かなと最初は思ったけど、そんなものまで考える必要なかった。
