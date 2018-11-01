fatoriaD :: Integer -> Integer
fatoriaD n | n == 1 = 1
        | n == 2 = 2
        |otherwise = n * fatoriaD (n - 2)

main = do
    print $ fatoriaD 8
    print $ fatoriaD 7