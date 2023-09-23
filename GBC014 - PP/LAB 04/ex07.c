#include <stdio.h>

float temp_fahrenheit (float c);

int main ( )
{
    float celsius;
    printf ("digite a temperatura em graus Celsius: ");
    scanf ("%f", &celsius);

    printf ("temperatura convertida em graus Fahrenheit: %.2f", temp_fahrenheit (celsius));

    return 0;
}

float temp_fahrenheit (float c)
{
    float f = c * (9.0/5.0) + 32.0;
    return f;
}