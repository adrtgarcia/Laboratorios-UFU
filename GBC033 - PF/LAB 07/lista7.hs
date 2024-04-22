-- exercício 1
data Forma = Circulo Float | Retangulo Float Float | Triangulo Float Float

verificaCirculo :: Forma -> Bool
verificaCirculo (Circulo _) = True 
verificaCirculo _ = False 

calculaArea :: Forma -> Float 
calculaArea (Circulo raio) = pi * raio * raio
calculaArea (Retangulo base altura) = base * altura 
calculaArea (Triangulo base altura) = base * altura / 2

-- tipos Circulo: Float -> Forma
--       Retângulo: Float -> Float -> Forma
--       Triângulo: Float -> Float -> Forma


-- exercício 2
{-
    A) Num a => a -> a    
    B) (Ord a, Num a) => a -> Bool
    C) Floating a => a -> a -> a
-}
-- exercício 3
{-
    A) [[a]]
    B) Num a => [[a]]
    C) (Fractional a, Fractional b, Fractional c) => (a, b, c)
    D) (Num a, Fractional b) => [(a, b)]
    E) (Foldable t, Num a) => ([String], t a -> a, [Char])
    F) Foldable t => [t Int -> Int]
-}

-- exercício 4
type CoordA = (Double, Double)
data CoordB = CorrdB Double Double 

somaCoordA :: CoordA -> CoordA -> CoordA
somaCoordA (xa, ya) (xb, yb) = (xa + xb, ya + yb)

somaCoordB :: CoordB -> CoordB -> CoordB
somaCoordB (CoordB xa, ya) (CoordB xb, yb) = CoordB (xa + xb) (ya + yb)
