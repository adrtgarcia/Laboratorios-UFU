-- exercício 1
numOf :: Char -> String -> Int
numOf c str = length (filter (== c) str)

ellen :: [String] -> [Int]
ellen lista = map length lista

ssp :: [Int] -> Int 
ssp lista = foldr (+) 0 (map (^2) (filter (> 0) lista))


-- exercício 2
separa :: String -> (String, String)
separa str = ((filter isAlpha str), (filter isDigit str))


-- exercício 3
const :: p1 -> p2 -> p3
const x y = x

swap :: (b, a) -> (a, b)
swap (x, y) = (y, x)

apply :: (t1 -> t2) -> t1 -> t2
apply f x = f x 

flip :: (t1 -> t2 -> t3) -> t2 -> t1 -> t3
flip f x y = f y x


-- exercício 4
data ShopItem = ShopItem String Float Float -- nome, qnt, preco/un

valorItem :: ShopItem -> Float
valorItem (ShopItem _ qnt preco) = qnt * preco

valorCompra :: [ShopItem] -> Float
valorCompra [] = 0 
valorCompra lista = foldr somaItens 0 lista
                    where somaItens item acc = valorItem item + acc
