# operações básicas
2+2                # adição
1-10               # subtração
2*87               # produto
34/21              # divisão
3**6               # potenciação
3^6                # potenciação


a <- 123*98        # cria objetos
a_1 <- 123*98      # cria objetos
class(a)
12+1245 -> b       # cria objetos
w <- "furiosa"
class(w)
y <- TRUE          # ou T
class(y)


TRUE + FALSE
TRUE + TRUE
FALSE + FALSE


# vetores
x <- c(23,10,45)
x
d <- c(x,45)
d+c(TRUE,FALSE)
x[c(2,3,3)]
x < 30
sum(x<30)          # somando T + T + F
x[x<30]
which(x<30)
c(12,34,"cruzeiro")
23:10345
p<-23:10345
p[14]


dado1 <- sample(x = 1:6 ,size = 1000000, replace = TRUE)
dado1
# dado1[dado1==3]
sum(dado1 == 3)/1000000
mean(dado1 == 3)   # media que o 3 apareceu com relação aos 10000 lançamentos


dado2 <- sample(x = 1:6 ,size = 1000000, replace = TRUE)
soma <- dado1+dado2
soma[1:10]
mean(soma==3)
