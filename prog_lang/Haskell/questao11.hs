raizInteira :: Integer -> Integer -> Integer
raizInteira a n
    | (n*n) > a = (n - 1)
    | otherwise = raizInteira a (n + 1)

raizQ :: Integer -> Integer
raizQ a = raizInteira a 1

main = do
    print $ raizQ 20