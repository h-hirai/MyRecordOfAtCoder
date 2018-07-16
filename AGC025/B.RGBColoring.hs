import Data.List (foldl')

p = 998244353

-- http://haskell.g.hatena.ne.jp/hyuki/20060612/combination
-- c n k = n^>k `div` k^>k
--   where
--     n^>k = foldr (*) 1 [n-k+1..n]

c n k = foldl' (\r (n, d) -> r * n `div` d) 1 $ zip [n,n-1..] [1..k]

d n r b = (c n r `mod` p) * (c n b `mod` p)

e n a b k nr =
  if k >= a * nr && (k - a * nr) `mod` b == 0 then
    let nb = (k - a * nr) `div` b in d n nr nb `mod` p
  else
    0

solv n a b k =
  foldl' (\r nr -> (r + e n a b k nr) `mod` p) 0 [0..n-1]

parseInput :: String -> [Integer]
parseInput = map read . words

main :: IO ()
main = do
  [n, a, b, k] <- return . parseInput =<< getContents
  putStrLn $ show $ solv n a b k
