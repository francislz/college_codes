mdc :: Integer -> Integer -> Integer
mdc a b
    | mod a b == 0 = b
    | mod b a == 0 = a
    | (a > b) = mdc b (mod a b)
    | (b > a) = mdc a (mod b a)

main = do
    print $ mdc 20 30