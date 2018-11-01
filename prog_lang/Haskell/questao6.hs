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

--Verifica padroes
-- teste :: Integer -> String
-- teste 1 = "Vai se foder"
-- teste x = "NADA"

l1 = [1.. 3]
mmcLista :: [Integer] -> Integer

soma :: [Integer] -> Integer
soma [] = 0
soma (x:xs) = x + soma xs

--(x:xs) -- x -> indicado a head da lista e xs a cauda isso pode ser usado de forma recursiva
main = do
    print $ soma l1
    --print $ l1 !! 3 --retorna o 4 elemento
    --print $ head l1 -- cabeca da lista 1
    --print $ tail l1 -- calda da lista 1
    --print $ last l1 --print ultimo elemento
    --print $ elem 4 l1 -- verifica se o num 4 esta na lista
    --print $ length l1 -- print o tamanho da lista
    --print $ null l1 -- vertifica se a lista e nula
    --print $ reverse l1 -- print o inverso
    --print $ take 3 l1 -- retorna os 3 primeiros elementos
    --print $ drop 2 l1 -- retira os 2 primeiros e imprime o resto
    --print $ minimum l1 -- imprime o minimo
    --print $ maximum l1 -- imprime o maximo
    --print $ sum l1 -- imprime a soma da l1
    --print $ product l1 -- imprime o produto de todos os elementos da lista