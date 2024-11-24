library(dplyr)
library(ggplot2)

femur <- read.csv("femur.csv")
str(femur)

# PASSO 1: analisar a correlação

homens <- femur |>
  filter(genero == "Male")
str(homens)
cor(homens$altura, homens$femur)
ggplot(data = homens, aes(x = femur, y = altura))+
  geom_point()

#cor.test: teste de hipoteses para verificar se o coefiiente de correlacao é zero
#H0: coeficiente de correlacao é zero
#Ha: coeficiente de correlacao não é zero

cor.test(homens$altura, homens$femur) # p-valor < 0.05, rejeitamos H0


# PASSO 2: determinar a reta de regressão

modelo <- lm(data = homens, formula = altura ~ femur)
modelo
summary(modelo)


# PASSO 3: analisar os resíduos (erros)

hist(modelo$residuals)

#H0: os residuos seguem uma distribuicao normal
#Ha: os residuos não seguem uma distribuicao normal

shapiro.test(modelo$residuals) # p-valor > 0.05, rejeitamos Ha
