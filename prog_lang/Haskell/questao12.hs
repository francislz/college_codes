list1 = [1,2, 3]
list2 = [4, 5, 6]

concatenar :: [Integer] -> [Integer] -> [Integer]
concatenar (x:xs) l2 
    | (xs == []) = (x:l2)
    | otherwise = concatenar xs (x:l2)

concatenarList :: [Integer] -> [Integer] -> [Integer]
concatenarList lista1 lista2 = concatenar (reverse lista1) lista2

main = do
    print $ concatenarList list1 list2