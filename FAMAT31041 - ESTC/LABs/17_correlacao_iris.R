library(ggplot2)

data(iris)

ggplot(data = iris, aes(x = Petal.Length, y = Petal.Width)) +
  geom_point() +
  theme_minimal()

# coeficiente de correlação
cor(iris$Petal.Length,iris$Petal.Width)

# matriz de correlação
cor(iris[,-5])

setosa <- iris[iris$Species == "setosa",]
cor(setosa$Petal.Length,setosa$Petal.Width)
