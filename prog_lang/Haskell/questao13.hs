removeEspacos :: String -> String -> Char -> String
removeEspacos (s:ss) l2 c
    | ss == [] = (s:l2)
    | ((s == ' ') && (c == ' ')) = removeEspacos ss l2 ' '
    | s == ' ' = removeEspacos ss (s:l2) s
    | otherwise = removeEspacos ss (s:l2) 'a'

processa :: String -> String
processa texto = removeEspacos (reverse texto) [] 't'

main = do
    print $ "Remove  os  espacos"
    print $ processa "Remove  os  espacos"