import Data.Char

-- exercício 1
converte :: Char -> (Char, Char, Int)
converte c = if ord c >= 97 && ord c <= 122 then (c, (toUpper c), (ord c))
             else (c, (toLower c), ord c)


-- exercício 2
equacao :: (Float, Float, Float) -> (Float, Float)
equacao (a, b, c)
        | delta > 0 = (x1, x2)
        | delta == 0 = (x1, x1)
        | otherwise = error ("raízes imaginárias")
        where delta = b*b - 4*a*c
              x1 = (-b + sqrt delta) / 2*a 
              x2 = (-b - sqrt delta) / 2*a


-- exercício 3
type Nome = String
type Idade = Float 
type Sexo = Char
type Pessoa = (Nome, Idade, Sexo)

pessoa1 :: Float -> Pessoa 
pessoa1 1 = ("maria", 20, 'f')
pessoa1 2 = ("joão", 25, 'm')

pessoa2 :: Float -> Pessoa 
pessoa2 indice 
    | indice == 1 = ("maria", 20, 'f')
    | indice == 2 = ("joão", 25, 'm')

idpessoa :: Pessoa -> Float
idpessoa (_, idade, _) = idade 

somaid :: Float -> Float
somaid i
   | i == 1 = pessoa1 1 
   | i > 1 = somaid (i - 1) + idpessoa (pessoa1 i)

mediaid :: Float -> Float 
mediaid x = (somaid x) / x
