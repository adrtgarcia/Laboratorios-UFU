module Main (main) where

import System.Random
import System.IO (stdout, hSetBuffering, BufferMode(NoBuffering))

tentativas :: Int -> Int 
tentativas x = x + 1

jogar :: Int -> Int -> IO()
jogar numTentativas numAletorio = do
    let aux = tentativas numTentativas

    putStrLn ("\nTentativa " ++ show aux)
    putStr "Digite seu palpite: "
    num <- readLn :: IO Int 

    if num > numAletorio
        then do
            putStrLn "\nPalpite acima do número desejado, tente novamente."
            jogar aux numAletorio
    else if num < numAletorio 
        then do
            putStrLn "\nPalpite abaixo do número desejado, tente novamente."
            jogar aux numAletorio
    else do
            putStrLn "\nNúmero correto, parabéns!!"
            putStrLn ("Você acertou com " ++ show aux ++ " tentativas.")
                    
            leRecorde <- readFile "C:/Users/amand/OneDrive/Área de Trabalho/highscore.txt"
            let recorde = read leRecorde :: Int
            if aux < recorde
                then do                    
                    putStrLn "Você bateu o recorde!!\n"
                    writeFile "C:/Users/amand/OneDrive/Área de Trabalho/highscore.txt" (show aux)
            else 
                putStr "\n"
        
            putStrLn "Deseja jogar novamente? (Digite 's' para sim, ou qualquer coisa para sair)"
            opcao <- getLine
            if opcao == "s"
                then do
                    novoAletorio <- randomRIO(1, 100) :: IO Int 
                    jogar 0 novoAletorio
                else main

main :: IO()
main = do 
    hSetBuffering stdout NoBuffering
        
    putStrLn "\nBem-vindo ao Jogo de Adivinhação"
    putStrLn "(1) Jogar"
    putStrLn "(2) Ver recorde"
    putStrLn "(3) Sair"
    menu <- readLn :: IO Int 

    if menu == 1
        then do 
            numAletorio <- randomRIO(1, 100) :: IO Int 
            putStrLn "\nOlá jogador! Estou pensando em um número entre 1 e 100, tente adivinhar."
            jogar 0 numAletorio
    else if menu == 2
        then do 
            leRecorde <- readFile "C:/Users/amand/OneDrive/Área de Trabalho/highscore.txt"
            putStrLn ("\nO recorde atual é: " ++ leRecorde)
            main
    else if menu == 3
        then putStrLn "\nObrigado por jogar!"
    else do 
        putStrLn "\nOpção inválida, tente novamente."
        main
