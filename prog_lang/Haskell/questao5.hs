mdc :: Integer -> Integer -> Integer
mdc a b
    | mod a b == 0 = b
    | mod b a == 0 = a
    | (a > b) = mdc b (mod a b)
    | (b > a) = mdc a (mod b a)

mmc :: Integer -> Integer -> Integer
mmc a b | a == 0 = 0
        | b == 0 = 0
        | a == b = a
        | otherwise = div (a * b) (mdc a b)

main = do
    print $ mmc 3 5