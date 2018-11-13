# AtCoder Beginner Contest 098

2018-05-26参加。C問題までAC。D問題は解説読んでもWAがとれずテストケースが出るまで待つかと放置してた。2018-07-20にAC。

[提出一覧](https://beta.atcoder.jp/contests/abc098/submissions/me)

## A. Add Sub Mul

[問題ページ](https://beta.atcoder.jp/contests/abc098/tasks/abc098_a)

```
std::max({a+b, a-b, a*b})
```

## B. Cut and Count

[問題ページ](https://beta.atcoder.jp/contests/abc098/tasks/abc098_b)

文字列を2つに分割する。ここで、前半と後半両方に含まれる文字の種類が最大になるようにしたとき、その種類はいくつか。

そのままやる。文字列の長さは最大でも100なので間に合う。

最初に文字列に含まれる文字種の集合を作って、それについて数える、という書き方をしたが、文字種も`a-z`しかないのだからこれも全通りやっちゃってかまわなかった。

## C. Attention

[問題ページ](https://beta.atcoder.jp/contests/abc098/tasks/arc098_a)

N人のひとが整列していて、各々は東または西を向いている。任意のひとりを選び、全員がそのひとりを見るように向きを変える。そのひとりを、向きを変える人数が最小になるように選んだとき、向きを変えるのは何人になるか。

西から順に西向きの人数、東から順に東向きの人数の累積和を求め、それからひとりの選び方について全探索を行う。

## D. Xor Sum 2

[問題ページ](https://beta.atcoder.jp/contests/abc098/tasks/arc098_b)

与えられた数列の部分列のうち、部分列のすべての要素の排他的論理和(Xor)と総和(Sum)が等しくなる部分列はいくつあるか。

数列のXorとSumが等しくなるのは、各bitで見たとき1が立ってる要素がひとつしかないときである。ある数列がその条件を満たすとき、その部分列もすべてXorとSumが等しくなる。

しゃくとり法で解く。部分列の左のインデックスをl、右をrとする。

- XorとSumを計算しながらrを増やしていく。
  - `l==r`のときは当然一致する。
  - `l+n==r`で`Xor==Sum`であったとすると、条件を満たす部分列の両端は`(l,l+n)`のほか`(l+1,l+n)`,`(l+2,l+n)`,...,`(l+n,l+n)`の部分列も条件を満たすので`r-l+1`を求める答えに加算する (このときrがl+n未満の例はすでに加算済みなので考えない) 。
- やがてXorとSumが一致しなくなるので、今度はXorとSumを逆算しながらlを増やしていく。
- ふたたび一致するようになったらrを増やす処理に戻る。

最初は累積和を求めてから総あたりする方法でやったがTLE。解説を読んでしゃくとり法でやる方法を Rust で書いてみたが WA がとれず。2018-07-20にあらためてC++で書いてみたらあっさりACになった。WAのデバッグができていない。