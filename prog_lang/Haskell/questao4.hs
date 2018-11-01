somaIntervalo :: Integer -> Integer -> Integer
somaIntervalo x y
    | x == y = x
    | (x < y) = x + somaIntervalo (x + 1) y
    | otherwise = y + somaIntervalo x (y + 1)

somaExcluindo a b = somaIntervalo (a - 1) (b - 1)
main = do
    print $ somaIntervalo 4 7
    print $ somaExcluindo 4 7
