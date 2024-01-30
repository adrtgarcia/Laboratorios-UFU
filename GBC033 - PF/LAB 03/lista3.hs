-- EXERCÍCIO 1

palindromo :: IO()
palindromo = do
                putStrLn "digite uma frase: "
                frase <- getLine
                if reverse frase == frase 
                    then putStrLn "é palíndromo"
                    else putStrLn "não é palíndromo"


-- EXERCÍCIO 2

produto :: IO()
produto = do
        putStrLn "digite o primeiro número: "
        num1 <- readLn :: IO Float
        putStrLn "digite o segundo número: "
        num2 <- readLn :: IO Float
        putStrLn "digite o terceiro número: "
        num3 <- readLn :: IO Float
        putStr "o produto é: "
        putStrLn (show(num1 * num2 * num3))


-- EXERCÍCIO 3

celsius :: Double -> Double
celsius f = 5/9 * (f - 32)

temperatura :: IO ()
temperatura = do 
                putStrLn "digite a temperatura em fahrenheit: "
                tempf <- readLn :: IO Double
                let tempc = celsius (tempf)
                putStr "temperatura em fahrenheit: "
                putStrLn (show tempf)
                putStr "temperatura em celsius: "
                putStrLn (show tempc)


-- EXERCÍCIO 4

media :: IO ()
media = do 
            putStrLn "digite a nota 1: "
            n1 <- readLn :: IO Float
            putStrLn "digite a nota 2: "
            n2 <- readLn :: IO Float
            putStrLn "digite a nota 3: "
            n3 <- readLn :: IO Float
            let m = (n1 + n2 + n3)/3
            putStrLn ("a média é " ++ show(m))
            putStrLn ("situação: " ++ calculamedia (m))

calculamedia :: Float -> String
calculamedia m
    | m < 3 = "reprovado"
    | m > 7 = "aprovado"
    | otherwise = "exame especial"


-- EXERCÍCIO 5

classeeleitoral :: IO ()
classeeleitoral = do 
                    putStrLn "digite a idade: "
                    idade <- readLn :: IO Int
                    putStrLn (analisa idade)

analisa :: Int -> String
analisa idade
    | idade < 16 = "não eleitor"
    | idade >= 18 && idade < 65 = "eleitor obrigatório"
    | otherwise = "eleitor facultativo"


-- EXERCÍCIO 6

menu :: IO ()
menu = do 
            putStrLn "-- MENU --"
            putStrLn "(1) Salvar uma frase em um arquivo texto"
            putStrLn "(2) Imprimir o conteúdo do arquivo texto"
            putStrLn "(3) Sair"
            opcao <- readLn :: IO Int 
            case of opcao
                1 -> do salvararq
                        menu
                2 -> do imprimirarq
                        menu
                3 -> "programa encerrado"

salvararq :: IO ()
salvararq = do 
                putStrLn "digite a frase: "
                frase <- readLn
                appendFile "arq.txt" texto
                putStrLn "frase adicionada"

imprimirarq :: IO ()
imprimirarq = do 
                putStrLn "carregando arquivo..."
                texto <- readFile "arq.txt"
                putStrLn texto
                putStrLn "fim do arquivo"
