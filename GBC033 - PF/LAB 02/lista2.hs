-- EXERCÍCIO 1
xor1 :: Bool -> Bool -> Bool
xor1 a b = (a || b) && not(a && b)

xor2 :: Bool -> Bool -> Bool
xor2 a b = a /= b 

xor3 :: Bool -> Bool -> Bool
xor3 a b = if a /= b then True else False

xor4 :: Bool -> Bool -> Bool
xor4 a b
  | a == b = False
  | a /= b = True 


-- EXERCÍCIO 2
numeven :: Int -> Bool
numeven x = if mod x 2 == 0 then True else False


-- EXERCÍCIO 3
numodd :: Int -> Bool
numodd x = if not(numeven x) then True else False


-- EXERCÍCIO 4
maior :: Int -> Int -> Int 
maior a b
   | a > b = a 
   | a < b = b 
   | otherwise = a 

menor :: Int -> Int -> Int 
menor a b
   | a > b = b 
   | a < b = a 
   | otherwise = a


-- EXERCÍCIO 5
areacirc :: Float -> Float
areacirc d = pi * r^2
   where
   r = d/2


-- EXERCÍCIO 6
numraizes :: Int -> Int -> Int -> Int 
numraizes a b c
   | delta > 0 = 2
   | delta == 0 = 1
   | delta < 0 = 0
   
   where
   delta = (b^2) - (4 * a * c)
