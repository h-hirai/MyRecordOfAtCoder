module Main where

import Control.Monad (replicateM_)

count :: String -> [Int]
count s = count' 0 $ zip s $ tail s
  where
    count' n [] = [n]
    count' n (('A','C'):rest) = n:count' (n+1) rest
    count' n (_:rest) = n:count' n rest

main :: IO ()
main = do
  [_, q] <- map read . words <$> getLine -- skip n
  s <- getLine
  let acc = count s
  replicateM_ q $ do
    [l, r] <- map read . words <$> getLine
    print $ acc!!(r-1) - acc!!(l-1)
