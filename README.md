AtCoder参加記録

[プロフィールページ](https://beta.atcoder.jp/users/hhirai)

## [AtCoder Grand Contest 023](AGC023)

### A. Zero-Sum Ranges

与えられた数列について、空でない連続する部分列であって、その総和が0になるものの個数を求める。

累積和で求める。累積和を計算していって、ある値になったあとでふたたび同じ値になったとすると、その間の総和は0である。累積和を求めた後、それをソートして、同じ値がいくつあるか数えればよい。

## [AtCoder Beginner Contest 096](ABC096)

### C. Grid Repainting 2

1×2の縦または横でしか描画できない筆を用いて、指定の作画ができるか判定せよという問題。

全画素について走査し、ある画素が描画対象画素であったとき、その上下左右に隣接する画素いずれかも描画対象であったとき、その画素は描画可能。そうでない画素がひとつでもあれば描画不可能。

### D. Five, Five Everywhere

条件を満たす長さNの数列を求める。条件は、どの異なる5つの要素を選択してもその合計は合成数となる、すべて互いに相異なる、素数、というもの。

「5で割った剰余が1になる数」5つの和はかならず5の倍数になり、そのような5555以下の素数は55を優に超えるだけ存在する。

## [AtCoder Beginner Contest 097](ABC097)

この回は4問ともRustでも書いてみている。

### B. Exponential

与えられる正整数X以下で最大のべき乗数を求める。

i∈2,3,...√X となるすべてのiについて、j∈i^2,i^3,...(j≦X)となるすべてのjを求め、その中の最大値を答えとする。

### C. K-th Substring

与えられた文字列sのsubstringを辞書順に並べたときにK番目にくるものはなにになるか。ただし、重複分は数えないものとする。

まず部分文字列の辞書を作成する。ここでKが問題の制限で5以下なので、6文字以上の長さの部分文字列は考慮しなくていい。C++ の std::set<std::string> を range-based for で順にアクセスすればそのまま辞書順に出てくるので、そのままK番目の要素を答えとすればよい。Rust の BTreeSet も同様。

### D. Equals

1からNまでの数を並べ替えた順列pと、入れ替えてもよいインデックスの組が複数与えられる。順列に対し入れ替え操作を繰り返し、なるべく昇順になるよう並べ替える。順列中、位置と数値が一致する数を最大でいくつにできるか。

UnionFindTreeを使って解く問題。与えられる組によって、インデックスをグループ化できる。順列のi番目にある数P[i]であるとき、iとP[i]が同じグループであれば、P[i]はiの位置からP[i]の位置に移動できる。そのようなiとP[i]の組み合わせの数が答えになる。

## [AtCoder Grand Contest 024](AGC024)

### A. Fairness

A, B, Cに対してK回操作を繰り返した後でA-Bを求める。

実際に何回か分の操作をシミュレーションしてみると、Kが奇数のとき答えは`B-A`、偶数のときは`A-B`になることがわかる。

### B. Backfront

選択ソート (のようななにか) に必要な操作回数を求める。

ソート済みの部分については操作が必要ないので、与えられた数列の中からソート済みの部分で最長のものを見つける。

ソート済み列の長さを求めるには、長さ N+1 の 0 で初期化された配列 A を用意し、P_i が入力されるたびに A[P_i] に A[P_i-1]+1 を入れればよい。

### C. Sequence Growing Easy

与えられた数列を、決められた操作の繰り返しで作成できるかを判定し、可能な場合の最小操作回数を求める。

作成できる数列は、0から1ずつ階段状に増加する列か、それを上書きしたものになる。

## [AtCoder Beginner Contest 098](ABC098)

### A. Add Sub Mul

```
std::max({a+b, a-b, a*b})
```

### B. Cut and Count

文字列を2つに分割する。ここで、前半と後半両方に含まれる文字の種類が最大になるようにしたとき、その種類はいくつか。

そのままやる。文字列の長さは最大でも100なので間に合う。

### C. Attention

N人のひとが整列していて、各々は東または西を向いている。任意のひとりを選び、全員がそのひとりを見るように向きを変える。そのひとりを、向きを変える人数が最小になるように選んだとき、向きを変えるのは何人になるか。

西から順に西向きの人数、東から順に東向きの人数の累積和を求め、それからひとりの選び方について全探索を行う。

### D. Xor Sum 2

与えられた数列の部分列のうち、部分列のすべての要素の排他的論理和(Xor)と総和(Sum)が等しくなる部分列はいくつあるか。

数列のXorとSumが等しくなるのは、各bitで見たとき1が立ってる要素がひとつしかないときである。ある数列がその条件を満たすとき、その部分列もすべてXorとSumが等しくなる。

しゃくとり法で解く。

あるときあらためて書き直してみたらACになってしまったという感じだったので、悩んでたWAのデバッグがまだできていない。

## [AtCoder Grand Contest 025](AGC025)

### RGB Coloring

色の点数が与えられたとき、N個のブロックをRGBいずれかに塗って、合計がちょうどK点となる組み合わせはいくつあるか。競プロではよくあるらしい、巨大な数になる解答を998244353の剰余で答えさせる問題。

## [AtCoder Beginner Contest 099](ABC099)

### C. Strange Bank

両替問題。黙って DP で解けとちょくだい先生がついっとしてたのでそのようにした。

### D. Good Grid

与えられた格子模様を、条件を満たすように描き替えるコストを求める問題。

条件を満たす模様は結局3色の縞模様となるので、初期状態を3グループに分け、各グループを同色に塗りつぶすコストを全通り試す。このグループ分けのところで各色の数を集計しておかないと計算量が間に合わなくなるらしい。

## [AtCoder Beginner Contest 100](ABC100)

### B. Ringo's Favorite Numbers

`N×100^D`なんだけど、問題文でも強調されているように「100 で **ちょうど** D 回割りきれる」N番目の数なので、N=100のときだけ`(N+1)×100^D`としなければいけない。まんまとひっかかった。

### C. *3 or /2

与えられた数列に、決められた操作を行う。操作が行えなくなるまでの最大の回数を求める。

要するに、数列の素因数の中から2の個数の合計を求める問題になる。

### D. Patisserie ABC

各要素は3種の値`(x,y,z)`を持ち、それぞれは符号付きの値である。N個の要素からM個の要素を選ぶとき、xの合計の絶対値、yの合計の絶対値、zの合計の絶対値の和が最大になるように選んだときの、その値を求める問題。

(x,y,z) について、(x + y + z)順、(x + y + -z)順、(x + -y + z)順……のように、要素を8通りにソートしておき、それぞれからM個の合計を求めればよい。

## [AtCoder Beginner Contest 101](ABC101)

### C. Minimization

与えられた数列に、決められた操作をほどこし目的の数列に変換する。このときの最小の回数を求める問題。

ここで操作一回で最小化できる項の数は`K-1`、最小化する項の数は、最初から最小の1を除き`N-1`、よって`ceil((N-1)/(K-1))`が答え。

### D. Snuke Numbers

条件によって定められる数列を列挙する問題。

ある程度の法則性が見受けられるものの、完全な法則を見つけることはできないので、「ある程度の法則性」で候補を絞ったあとで、条件でさらに絞り込むという解き方をする。


## [AtCoder Beginner Contest 102](ABC102)

### C. Linear Approximation

適当な定数bを選ぶことで、与えられた数列に対する、与えられた関数の値を最小化する問題。

平均値を求めればいいのかと思っていたら、中央値だった。なんでそうなのかはまだピンときてない。

### D. Equal Cut

与えられた数列を、それぞれの総和がなるべく近くなるよう4つの部分列に分割する問題。

真ん中の分割がすんでいるものと仮定して、数列の全部分について、左2つの部分列の総和が一番近くなる左の分割点を、尺取法でさがす。右についても同様にする。

逆イテレータを使用してみた。

## [SoundHound Inc. Programming Contest 2018](SoundHound2018)

### C. Ordinary Beauty

各要素が1以上n以下の整数である長さmの数列を考える。全通りの数列の点数を求め、それらの平均(期待値?)を出力する問題。

自分にとって初めての浮動小数点数を扱う問題。

## [AtCoder Grand Contest 026](AGC026)

### A. Colorful Slimes 2

与えられた数列を変更して、同じ数が連続しないようにするには、最小で何回変更すればいいか。

入力値を読んでいって、連続した値があったら答えを+1、ただし、+1した直後(連続の3つめ)は除外。

### B. rng_10s

在庫管理問題。初期在庫(A)、販売数/日(B)、仕入れ基準(C)、入荷数(D)が与えられて、在庫切れが起こらないか判定する。

在庫量が、C<在庫<Bという状況にならないかどうかを判定する。在庫量は`A-nB+mD`(n,mは任意の自然数)という式で表せ、この値は`a+m*g`(`a=A%B`,`g=gcd(B,D)`)と表せる。ここから`C<a+m*g<B`という不等式が導けるので、ここから判定条件を得られる。

## [AtCoder Beginner Contest 103](ABC103)

### B. String Rotation

文字列S,Tが与えられて、片方をローテーションさせて一致させられるかという問題。実際にやってみればいい。

### C. Modulo Summation

各項が、与えられる数列要素を法とした、引数の剰余であり、それらの総和が値となる関数の、最大値を求める。(`f(m) = (m mod a_1) + (m mod a_2) + ... + (m mod a_N)`)

引数を1ずつ増加させたときの各項の値を観察すると、各項は1ずつ増加していき a-1 で1周する。m=lcm(A)-1のとき、全項が a_n-1 となり、これが f(m) の最大値である。よって答えはΣ(a_n-1)。

### D. Islands War

(1)-(2)-(3)-...-(N) のような一列のリンクがあり、M個の組 (a_m, b_m) が与えられる。すべての組の連絡をなくすようにリンクを切断するには、最少いくつのリンクを切断すればよいか。

(n)-(n+1) 間のリンクをnとしたとき、a <= n < b であるようなすべての組は、n のリンクを切断することで連絡をなくすことができるので、M個の組をa_mについてソートして頭からなめていき、aがそこまでbの最小値を上回ったところで切断するべきリンク数をインクリメントして、また走査を繰り返す。

## [SoundHound Inc. Programming Contest 2018 本戦](SoundHound2018_Final)

### A. Feel the Beat

範囲 [C, D) を与えられて、そのなかに決められた条件を満たす数はいくつあるかという問題。
条件は、数を 2^n (n=0,1,2...) で割った時に [140, 170) になるかどうかというもの。

140, 170 のほうを、増やしていく。[C, D) に収まる分を答えに加算していく。

### B. Neutralize

符号あり整数の列Bを与えられる。連続するK個以上の任意の部分列を何度でもすべて0にできる。総和を最大になるように操作したときの総和を求める。

## [Mujin Programming Challenge 2018](Mujin2018)

### B. セキュリティ

初期値と、1ずつの増減をあらわす`+`、`-`からなる文字列が与えられて、0になる瞬間があるかどうかを問う問題。

### C. 右折

通過可能なグリッドと障害物グリッドからなるの地図が与えられる。
1以上進み、右に方向転換して、また1以上進む。可能なコースはいくつあるか。

各グリッド、上下左右4つについて、進行可能スペースの数を記録しておく。方向転換地点に着目し、全グリッドについて進行可能スペースの組み合わせを加算していく。

## [AtCoder Beginner Contest 104](ABC104)

### C. All Green

100、200、……とランクわけされたスコアを最少いくつ獲得すれば合計が目標に達するか、という問題。ただし、ランクごとに獲得できる最大数と、そのランクを全て獲得したときのボーナススコアが設定されているので、高いスコアから順番に取ればいいというだけの話ではない。

### D. We Love ABC

文字列中に、ABC となる部分列 (順序が保たれていれば連続でなくてもよい) がいくつあるかを ABC 数とする。与えられた文字列中 `?` をワイルドカードとして、生成できる文字列の ABC 数の合計を求める問題。答えは `10^9 + 7` を法とする剰余で求める。


# 共通する注意点など

## C++ での注意点、使えるライブラリなど

### `std::max`、`std::min`

最大値、最小値は `std::max`、`std::min` で求められる。`#include <algorithm>` が必要。

比較対象が2つのときはそのまま使う。

```
ans = std::min(ans, cost);
```

3つ以上あるときは、`initializer_list`でくくってやるとまとめて比較できる。

```
std::cout << std::max({a+b, a-b, a*b}) << std::endl;
```

### 逆順のループ

`size_t`のような符号なし型をループ変数に使うと、0未満の値にならないせいでうっかり無限ループになったりする。しょぼいミスだがわりとやりがち。

逆イテレータはABC102で使ってみたが、順イテレータと演算するときに変換する必要があり (`base()`で変換する)、このとき1つずれたりするのでなにかと面倒。

```
std::vector<int> v = {0, 1, 2, 3, 4, 5};

for (auto i=v.crbegin(); i!=v.crend(); i++) {
  std::cout << *i << ' ' << *(i.base()) << std::endl;
}
```

```
5 -1902163756
4 5
3 4
2 3
1 2
0 1
```

単純な逆ループには、上記の符号なしループ変数の問題もあり、いいかもしれない。

### 各型が取りうる最大値

`std::numeric_limits<T>::max()`で具体的な値を得られる。

```
#include <limits>
#include <iostream>

int main() {
  std::cout << std::numeric_limits<long>::max() << std::endl;
  std::cout << std::numeric_limits<unsigned long>::max() << std::endl;
  return 0;
}
```

### ソート済みvectorに対する二分探索を行うライブラリ

### 浮動小数点数の表示精度

## 言語によらないアルゴリズムの考え方など

### 累積和を求めるとき0を含めるか含めないか

### しゃくとり法の書き方
