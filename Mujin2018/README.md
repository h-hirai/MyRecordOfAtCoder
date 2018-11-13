# Mujin Programming Challenge 2018

2018-08-04参加。Not Rated。なんとかCまでは解けたけど、そこまで。

[提出一覧](https://beta.atcoder.jp/contests/mujin-pc-2018/submissions/me)

A は省略。

## B. セキュリティ

[問題ページ](https://beta.atcoder.jp/contests/mujin-pc-2018/tasks/mujin_pc_2018_b)

初期値と、1ずつの増減をあらわす`+`、`-`からなる文字列が与えられて、0になる瞬間があるかどうかを問う問題。

初期値が0の場合、という場合が例示されていたのでループ内、増減手前で検査するように書いたら、最後に0になるケースでWAになった。

## C. 右折

[問題ページ](https://beta.atcoder.jp/contests/mujin-pc-2018/tasks/mujin_pc_2018_c)

通過可能なグリッドと障害物グリッドからなるの地図が与えられる。
1以上進み、右に方向転換して、また1以上進む。可能なコースはいくつあるか。

各グリッド、上下左右4つについて、進行可能スペースの数を記録しておく。方向転換地点に着目し、全グリッドについて進行可能スペースの組み合わせを加算していく。

というのが、解説の模範解答。自分では、始点から順に追って計算していくやり方でやって、想定通りにTLEになったのでメモ化するようにしたら通った。解説見た後になってみると無理やりすぎる。