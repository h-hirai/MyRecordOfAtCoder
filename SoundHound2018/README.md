# SoundHound Inc. Programming Contest 2018

2018-07-07参加、5問中A、BのみAC。Cは終了後、たなこふ先生の解説を見てからAC。D、Eは未着手。

[提出一覧](https://beta.atcoder.jp/contests/soundhound2018-summer-qual/submissions/me)

A、Bは書くだけなので省略。

## C. Ordinary Beauty

[問題ページ](https://beta.atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_c)

各要素が1以上n以下の整数である長さmの数列を考える。全通りの数列の点数を求め、それらの平均(期待値?)を出力する問題。

初めての浮動小数点数を扱う問題。

* 隣り合う要素の差が +d になる場合が`n-d`、-d になる場合が`n-d`で合わせて`2*(n-d)`、数列の長さが2のとき、組み合わせの総数は`n*n`なので答えは`2*(n-d)/(n*n)`になる。
* あとはmについての漸化式を求めて〜とかぐにょぐにょやってたが、結局上記に`(m-1)`をかけるだけでいい。
* また`d==0`の場合は`1*(n-d)/(n*n)`(つまり`1/n`か)になることを忘れてはいけないのだが、忘れてた。
* 浮動小数点数を扱う問題は初めてだった。問題には正解とする出力の精度も指定してある。`std::cout`デフォルトの出力精度では足りなくなるテストケースもきっちり用意されていて、一回WAになった。
