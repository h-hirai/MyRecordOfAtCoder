# AtCoder Beginner Contest 099

2018-06-10開催。不参加。昼から飲んでて酔い醒まし〜とかゆって寝過ごした。

[提出一覧](https://beta.atcoder.jp/contests/abc099/submissions/me)

A、Bは省略。

## C. Strange Bank

[問題ページ](https://beta.atcoder.jp/contests/abc099/tasks/abc099_c)

両替問題。黙って DP で解けとちょくだい先生がついっとしてたのでそのようにした。

そうでない解法が解説に載ってるけど、分からないので試してない。

## D. Good Grid

[問題ページ](https://beta.atcoder.jp/contests/abc099/tasks/abc099_d)

与えられた格子模様を、条件を満たすように描き替えるコストを求める問題。

条件を満たす模様は結局3色の縞模様となるので、初期状態を3グループに分け、各グループを同色に塗りつぶすコストを全通り試す。このグループ分けのところで各色の数を集計しておかないと計算量が間に合わなくなるらしい。
