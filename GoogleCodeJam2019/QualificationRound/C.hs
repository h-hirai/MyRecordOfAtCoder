{-# Language ScopedTypeVariables #-}

module Main where

import Control.Monad
import Data.List
import Data.Maybe
import Text.Printf

decode :: [Integer] -> String
decode ps = let dict = zip (sort $ nub ps) ['A'..] in
  map (\p -> fromJust $ lookup p dict) ps

unweave :: Integer -> [Integer] -> [Integer]
unweave n [] = [n]
unweave n (l:ls) = n:unweave (l `div` n) ls

testcase :: [Integer] -> String
testcase ls = let len = length $ fst $ span (uncurry (==)) $ zip ls (tail ls)
                  (f, b) = splitAt len ls
                  n:m:_ = b
                  g = gcd n m
                  g' = n `div` g
                  f' = reverse $ tail $ unweave g' $ reverse f
                  b' = unweave g' b in
  decode (f' ++ b')

main :: IO ()
main = do
  numCases :: Int <- readLn
  forM_ [1..numCases] $ \caseNum -> do
    _ <- getLine -- skip N and L
    ls <- map read . words <$> getLine
    printf "Case #%d: %s\n" caseNum $ testcase ls
