--returns the firsts elements that are the same as n
firstsSameTo :: Eq a =>  a ->  [a] -> [a]
firstsSameTo n xs = takeWhile (==n) xs
