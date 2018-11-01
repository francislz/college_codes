produtoInterval :: Integer -> Integer -> Integer
produtoInterval a b
        | a == b = b
        | otherwise = a * produtoInterval (a + 1) b

main = do
    print $ produtoInterval 1 4