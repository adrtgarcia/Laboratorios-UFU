#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    pilha *p = criar ( );

    push (p, 11);
    mostrar (p);

    push (p, 34);
    mostrar (p);

    pop (p);
    mostrar (p);

    pop (p);
    mostrar (p);

    push (p, 23);
    mostrar (p);

    push (p, 45);
    mostrar (p);

    pop (p);
    mostrar (p);

    push (p, 121);
    mostrar (p);

    push (p, 22);
    mostrar (p);

    pop (p);
    mostrar (p);

    pop (p);
    mostrar (p);

    limpar (p);

    return 0;
}
