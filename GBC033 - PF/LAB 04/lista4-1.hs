-- exercício 1
fatduplo :: Int -> Int 
fatduplo x
    | x == 1 = 1
    | x == 2 = 2
    | otherwise = fatduplo(x - 2) * x 


-- exercício 2
quociente :: Int -> Int -> Int 
quociente a b
    | a < b = 0
    | otherwise = 1 + quociente((a - b) b) 

resto :: Int -> Int -> Int 
resto a b 
    | a < b = a 
    | otherwise = resto((a - b) b)


-- exercício 3
pot :: Int -> Int -> Int 
pot a b
    | a == 0 = 0
    | b == 0 = 1
    | otherwise = a * pot(a (b - 1))


-- exercício 4
nand1 :: Bool -> Bool -> Bool
nand1 p q = if (p == True) && (q == True) then False
            else True 

nand2 :: Bool -> Bool -> Bool
nand2 p q
    | (p == True) && (q == True) = False
    | otherwise = True

nand3 :: Bool -> Bool -> Bool
nand3 True True = False
nand3 _ _ = True
