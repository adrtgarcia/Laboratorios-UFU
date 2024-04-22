-- exercício 1
addPares :: [(Int, Int)] -> [Int]
addPares [(x, y)] = [x + y]
addPares ((x, y) : lista) = x + y : addPares lista


-- exercício 2
toUpper :: [Char] -> [Char]
toUpper [] = []
toUpper (x : str)
    | x >= 'a' && x <= 'z' = toEnum (fromEnum x - 32) : toUpper str
    | otherwise = x : toUpper str 

strToUpper :: [Char] -> ([Char], [Char])
strToUpper str = (str, toUpper str)


-- exercício 3
buscaPosicao :: Int -> [Int] -> Int
buscaPosicao _ [] = error "elemento nao encontrado."
buscaPosicao x (y : lista)
    | x == y = 1
    | otherwise = 1 + buscaPosicao x lista

buscaMaior :: [Int] -> Int
buscaMaior [] = error "lista vazia."
buscaMaior [x] = x
buscaMaior (x : lista) = max x (buscaMaior lista)

maior :: [Int] -> (Int, Int)
maior lista = let m = buscaMaior lista
                  pos = buscaPosicao m lista
              in (m, pos)


-- exercício 4
removeElem :: Int -> [a] -> [a]
removeElem _ [] = error "lista vazia."
removeElem pos lista
    | pos < 1 || pos > length lista = error "posicao invalida."
    | otherwise = let (antes, _:depois) = splitAt (pos - 1) lista
                  in antes ++ depois


-- exercício 5
type NomeAluno = String 
type MediaNota = Int 
type Aluno = (NomeAluno, MediaNota)

type Turma = [Aluno]

aprovados :: Turma -> Int -> [NomeAluno]
aprovados lista notaCorte = [nome | (nome, nota) <- lista, nota > notaCorte]
