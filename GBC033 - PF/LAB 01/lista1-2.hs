subtrai :: Float -> Float -> Float
subtrai x y = x - y

areacirc :: Float -> Float
areacirc r = pi * (r**2)

difareacirc :: Float -> Float -> Float
difareacirc c1 c2 = subtrai (areacirc c1) (areacirc c2)

logica :: Bool -> Bool -> Bool
logica p q = (p || q) && not (p && q)
