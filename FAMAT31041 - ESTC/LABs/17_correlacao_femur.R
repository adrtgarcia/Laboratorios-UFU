library(ggplot2)

femur$genero <- as.factor(femur$genero)
femur <- femur[,-1]

homens <- femur[femur$genero == "Male",]
mulheres <- femur[femur$genero == "Female",]

ggplot(data = mulheres, aes(x = altura, y = femur))+
  geom_point()

cor(homens$femur,homens$altura)
mean(homens$altura)

cor(mulheres$femur,mulheres$altura)

ggplot(data = homens, aes(x = altura, y = femur))+
  geom_point()

# modelo linear
modelo_linear <- lm(data = homens, formula = altura ~ femur)
modelo_linear

summary(homens$femur)