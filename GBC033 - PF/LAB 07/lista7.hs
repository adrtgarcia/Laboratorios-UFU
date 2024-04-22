-- exercício 1
numOf :: Char -> String -> Int
numOf c str = length (filter (== c) str)

ellen :: [String] -> [Int]
ellen lista = map length lista

ssp :: [Int] -> Int 
ssp lista = sum (map (^2) (filter (> 0) lista))
