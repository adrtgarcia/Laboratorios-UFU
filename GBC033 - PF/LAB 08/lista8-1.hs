import Data.Char

-- exercício 1
primeiros :: [(a, b)] -> [a]
primeiros lista = map fst lista

maiusculas :: String -> String 
maiusculas str = map toUpper str 

dobros :: Num a => [a] -> [a]
dobros lista = map (*2) lista


-- exercício 2
pares :: [Int] -> [Int]
pares lista = filter even lista

alfa :: String -> String 
alfa str = filter isAlpha str 

rmChar :: Char -> String -> String 
rmChar c str = filter (/= c) str 


-- exercício 3
produto :: Num a => [a] -> a
produto lista = foldr (*) 1 lista 

eLogico :: [Bool] -> Bool 
eLogico lista = foldr (&&) True lista

concatena :: [String] -> String 
concatena lista = foldr (++) "" lista
