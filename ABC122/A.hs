{-# Language ScopedTypeVariables #-}

import Data.Maybe (fromJust)
import Debug.Trace

pair = zip "ACGT" "TGCA"

main = do
  b <- head <$> getLine
  putStrLn $ (:"\n") $ fromJust $ lookup b pair
