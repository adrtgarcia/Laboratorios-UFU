-- exercício 1
imprimeNVezes :: Int -> IO()
imprimeNVezes = do putStrLn "digite um número: "
                   n <- readLn :: IO Float 
                   putStrLn "digite uma frase: "
                   frase <- readLn :: IO String
                   putStrLn imprime(n frase)

imprime :: Int -> String -> String
imprime n frase
    | n == 0 = "impressão finalizada"
    | otherwise = imprime(n-1 frase)


-- exercício 2
eLogico1 :: Bool -> Bool -> Bool
eLogico1 p q
    | (p == True) && (q == True) = True 
    | otherwise = False


-- exercício 3
eLogico2 :: Bool -> Bool -> Bool
eLogico2 p q
    | (p == True) = q
    | (p == False) =  False


-- exercício 4
comb :: Int -> Int -> Int
comb n k
    | k == 1 = n
    | k == n = 1 
    | otherwise = comb((n - 1) (k - 1)) + comb((n - 1) k)
