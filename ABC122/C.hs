module Main where

import Data.Array.IArray
import Control.Monad (replicateM_)

count :: Int -> String -> Array Int Int
count n s = array (1, n) $ zip [1..n] $ count' 0 $ zip s (tail s)
  where
    count' n [] = [n]
    count' n (('A','C'):rest) = n:count' (n+1) rest
    count' n (_:rest) = n:count' n rest

main :: IO ()
main = do
  [n, q] <- map read . words <$> getLine
  s <- getLine
  let acc = count n s
  replicateM_ q $ do
    [l, r] <- map read . words <$> getLine
    print $ acc!r - acc!l
