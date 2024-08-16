# dataset iris
iris
View(iris)


# embaralhamento dos dados
iris <- iris[sample(nrow(iris)),]
n <- round(0.8 * nrow(iris))


# gerando os grupos de treinamento e teste
treinamento <- iris[1:n,]
View(treinamento)

teste <- iris[-(1:n),]
View(teste)


# gerando gráficos com ggplot
ggplot(data = treinamento, aes(x = Petal.Length, y = Petal.Width, col = Species)) + 
  geom_point(size = 1.5, alpha = 0.5) + 
  theme_minimal()

