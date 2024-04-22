-- exercício 01

{-
    A) (toUpper . head) ["maria", "jose", "silva"] -- tipo char, valor 'M'
    B) (not . odd . lenght) "felicidade" -- tipo bool, valor True
    C) (isLetter . head . head . reverse) ["maria", "silva", "pereira"] -- tipo bool, valor True
    D) (even . (\x -> x * 2 + 3) . (\x -> div x 2) . snd) (9 + 4, 9 - 4) -- tipo bool, valor False
-}


-- exercício 02
-- \(nome, peso, altura) ->  peso / (altura^2)


-- exercício 03
-- filter (\x -> mod x 3 == 0) lista


-- exercício 04
composta f g = h 
        where h x = f (g x)

-- a) composta \f g -> f . g
-- b) composta :: (b -> c) -> (a -> b) -> a -> c
-- c) (composta even length) "linguagens modernas"


-- exercício 05
{-
    A) ('c':)
        tipo = Char -> [Char]
        lambda = (\x -> 'c' : x) 
    B) (:"fim")
        tipo = Char -> [Char]
        lambda = (\x -> x:"fim")
    C) (==2)
        tipo = Eq a => a -> Bool
        lambda = (\x -> x == 2)
    D) (++"\n")
        tipo = [Char] -> [Char]
        lambda = (\x -> x ++ "\n")
    E) (^3)
        tipo = Num a => a -> a
        lambda = (\x -> x^3)
    F) (3^)
        tipo = Num a => a -> a
        lambda = (\x -> 3^x)
    G) (‘elem’ "AEIOU")
        tipo = Char -> Bool
        lambda = (\x -> elem x "AEIOU")
-}


-- exercício 06
{-
    let pares = [(1,8),(2,5),(0,1),(4,4),(3,2)]
        h = sum . map (\(x,y) -> x*y-1) . filter (\(x,_) -> even x)
    in h pares
-}
