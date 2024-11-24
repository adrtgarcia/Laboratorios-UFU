library(ggplot2)
library(palmerpenguins)
library(dplyr)

pinguim <- penguins
pinguim <- na.omit(pinguim)

cor(pinguim[,3:6],)

ggplot(data = pinguim, aes(x = flipper_length_mm, 
                           y = body_mass_g,
                           color = species)) + 
  geom_point() +
  theme_minimal() +
  geom_smooth(method = 'lm')

pinguim |>
  filter(species == 'Chinstrap')|>
  select(flipper_length_mm,body_mass_g)|>
  cor()

modelo <- lm(formula = flipper_length_mm ~ body_mass_g + bill_length_mm, 
              data = pinguim)
modelo
summary(modelo)