# AtCoder Grand Contest 025

2018-06-03参加。Aしか解けず。後日BをRustとHaskellでやってみたがWAとTLE。

[提出一覧](https://beta.atcoder.jp/contests/agc025/submissions/me)

## A. Digits Sum

[問題ページ](https://beta.atcoder.jp/contests/agc025/tasks/agc025_a)

ほとんど自明。注意すべきケースも例示されてるので問題ない。

## RGB Coloring

[問題ページ](https://beta.atcoder.jp/contests/agc025/tasks/agc025_b)

色の点数が与えられたとき、N個のブロックをRGBいずれかに塗って、合計がちょうどK点となる組み合わせはいくつあるか。競プロではよくあるらしい、巨大な数になる解答を998244353の剰余で答えさせる問題。この数は30bitの素数で、こういった問題ではこれが素数であることが重要っぽい。

RがA点、BがB点、GがA+B点なので、各ブロックをRGBいずれかに塗るのではなく、RBいずれか、または両方塗ると読み替えることができ、K=a*A+b*Bなるa,bをaまたはbの全探索で得られる。あとはΣ(Comb(N,a)*Comb(N,b))を求めればよい、らしい。

素数pを法をする剰余の組み合わせの数は、蟻本に載っていて、これをRustで実装したつもりだけどWA。じゃあいっそBigIntが使える言語でやってみたらいいんじゃね、とHaskellでやってみたけど、世の中そんなにあまくなくTLE。
