#include <stdio.h>
// converta uma letra maiúscula em letra minúscula

int main ( )
{
    char ch;
    printf ("digite uma letra maiuscula: ", ch);

    ch = getchar ( );
    printf ("letra minuscula: %c", ch + 32);

    return 0;
}