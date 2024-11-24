library(ggplot2)

grilo <- read.table(file = "grilo.txt", header = TRUE, sep = ',')

summary(grilo)
str(grilo)

correlacao <- cor(grilo$temperatura,grilo$frequencia) # ou: correlacao <- cor(grilo)

ggplot(data = grilo, aes(x = frequencia)) +
  geom_histogram(bins = 10,color = "pink") +
  theme_minimal()

ggplot(data = grilo, aes(x = temperatura, y = frequencia)) +
  geom_point() +
  theme_minimal() +
  geom_smooth(method = 'lm', se = FALSE)

modelo_linear <- lm(formula = frequencia ~ temperatura, data = grilo)
summary(grilo$temperatura)

w <- data.frame(temperatura = c(21,23.6,30.9))
predict(modelo_linear, newdata = w)
