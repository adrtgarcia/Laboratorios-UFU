install.packages("Stat2Data")

library(Stat2Data)
library(ggplot2)

populacao <- sample(0:1, size = 100000, replace = TRUE,prob = c(0.9,0.1))
valor_real <- mean(populacao)

amostra <- sample(populacao, size = 200, replace = TRUE)
media <- mean(amostra)

?prop.test 
prop <- prop.test(sum(amostra == 1), 200, p = 0.1, alternative = "two.sided")

# x = soma dos sucessos
# n = tamanho da amostra
# p = probabilidade que queremos testar se está certa

prop


data("Oysters")
Oysters

ggplot(Oysters,aes(x = TwoD, y = Volume)) +
  geom_point() +
  theme_minimal()

correlacao <- cor(Oysters$TwoD,Oysters$Volume)

cor.test(Oysters$TwoD,Oysters$Volume)

# p-valor: rejeita ou aceita a hipótese

ggplot(Oysters,aes(x = TwoD, y = Volume)) +
  geom_point() +
  theme_minimal() +
  geom_smooth(method = "lm")

modelo <- lm(formula = Volume  ~ TwoD  , Oysters)
summary(modelo)

hist(modelo$residuals)

shapiro.test(modelo$residuals)
