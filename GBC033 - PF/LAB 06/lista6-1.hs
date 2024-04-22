-- exercício 1
{- 
    ['a', 'b', 'c'] -- lista de char (string)
    ('a', 'b', 'c') -- tupla
    [(False, '0'), (True, '1')] -- lista
    ([False, True], ['0','1']) -- tupla
    [tail, init, reverse] -- inválido
-}


-- exercício 2
    second xs = head (tail xs) -- retorna o segundo elemento da lista
    pair x y = (x, y) -- retorna uma tupla com os elementos
    palindrome xs = reverse xs == xs -- verifica se a string é palíndromo


-- exercício 3
ultimo1 :: [Int] -> Int 
ultimo1 lista = head (reverse lista)

ultimo2 :: [Int] -> Int 
ultimo2 lista = lista !! (lenght lista - 1)  

ultimo3 :: [Int] -> Int 
ultimo3 lista = head (drop (lenght lista - 1) lista)


-- exercício 4
type Aluno = (Int, [Char], Double)
type Curso = [Aluno]

getNota :: Aluno -> Double
getNota (_, _, nota) = nota

getNome :: Aluno -> [Char]
getNome (_, nome, _) = nome

maiorNota :: Curso -> [Char]
maiorNota [a] = getNome a
maiorNota (a1 : a2 : t)
    | getNota a1 > getNota a2 = maiorNota (a1 : t)
    | otherwise = maiorNota (a2 : t)

insereAluno :: Aluno -> Curso -> Curso 
insereAluno a [] = [a]
insereAluno a (h : t) = 
    if elem a (h : t) then (h : t)
        else [a] ++ (h : t)
