module Main (main) where

import System.IO (stdout, hSetBuffering, BufferMode(NoBuffering))

-- tipo de dados Student
type StudentId = Int 
type FirstName = String 
type LastName = String 
type Age = Int
type Student = (StudentId, FirstName, LastName, Age)

-- criar banco de dados
initialDatabase :: [Student]
initialDatabase = []

-- adicionar estudante ao banco de dados
adicionaStudent :: [Student] -> IO [Student]
adicionaStudent database = do
    putStrLn "\nDigite o ID:"
    stdId <- readLn :: IO StudentId
    putStrLn "Digite o nome:"
    stdFirstName <- getLine
    putStrLn "Digite o sobrenome:"
    stdLastName <- getLine
    putStrLn "Digite a idade:"
    stdAge <- readLn :: IO Age
    let cadastrado = (stdId, stdFirstName, stdLastName, stdAge)
    let databaseAtt = cadastrado : database
    putStrLn "\nEstudante cadastrado!\n"
    return databaseAtt

-- procurar estudante no bando de dados
procuraStudent :: StudentId -> [Student] -> IO ()
procuraStudent stdId database = do 
    let filtrados = filter (\(studentId, _, _, _) -> studentId == stdId) database
    case filtrados of
        [] -> putStrLn "\nEstudante não encontrado.\n"
        [(studentId, firstName, lastName, age)] -> do 
            putStrLn "\nEstudante encontrado!\n" 
            putStrLn $ "ID:" ++ show studentId
            putStrLn $ "Nome:" ++ show firstName
            putStrLn $ "Sobrenome:" ++ show lastName
            putStrLn $ "Idade:" ++ show age  

-- atualizar informações do estudante
atualizaStudent :: StudentId -> FirstName -> LastName -> Age -> [Student] -> IO [Student]
atualizaStudent stdId novoNome novoSobrenome novaIdade database = do 
    let databaseAtt = map (\(studentId, firstName, lastName, age) ->
                            if studentId == stdId 
                                then (studentId, novoNome, novoSobrenome, novaIdade)
                                else (studentId, firstName, lastName, age)
                        ) database
    putStrLn "\nEstudante atualizado!\n"
    return databaseAtt

-- imprimir banco de dados
printaDatabase :: [Student] -> IO ()
printaDatabase database = do
    putStrLn "\nBanco de datos atualizado:"
    mapM_ printaStudent database

printaStudent :: Student -> IO ()
printaStudent (stdId, stdFirstName, stdLastName, stdAge) = do
    putStrLn $ "\nID: " ++ show stdId
    putStrLn $ "Nome: " ++ stdFirstName
    putStrLn $ "Sobrenome: " ++ stdLastName
    putStrLn $ "Idade: " ++ show stdAge 

main :: IO ()
main = menu initialDatabase

menu :: [Student] -> IO ()
menu database = do 
    hSetBuffering stdout NoBuffering
        
    putStrLn "\nMenu"
    putStrLn "(1) Adicionar estudante"
    putStrLn "(2) Recuperar estudante por ID"
    putStrLn "(3) Atualizar informações do estudante"
    putStrLn "(4) Sair"
    opcao <- readLn :: IO Int 

    case opcao of
        1 -> do 
            novoDatabase <- adicionaStudent database
            printaDatabase novoDatabase
            menu novoDatabase
        2 -> do 
            putStrLn "\nDigite o ID do estudante:"
            stdId <- readLn :: IO StudentId
            procuraStudent stdId database
            menu database
        3 -> do 
            putStrLn "\nDigite o ID do estudante a ser atualizado:"
            stdId <- readLn :: IO StudentId
            putStrLn "Digite o novo nome:"
            novoNome <- getLine
            putStrLn "Digite o novo sobrenome:"
            novoSobrenome <- getLine
            putStrLn "Digite a nova idade:"
            novaIdade <- readLn :: IO Age
            novoDatabase <- atualizaStudent stdId novoNome novoSobrenome novaIdade database
            printaDatabase novoDatabase
            menu novoDatabase
        4 -> putStrLn "\nEncerrando o programa..."
        _ -> do 
            putStrLn "\nOpção inválida, tente novamente."
            menu database
