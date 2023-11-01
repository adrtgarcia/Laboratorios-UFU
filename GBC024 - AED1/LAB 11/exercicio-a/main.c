#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    fila *f = criar ( );

    inserir (f, 10);
    mostrar (f);

    inserir (f, 20);
    mostrar (f);

    remover (f);
    mostrar (f);

    inserir (f, 30);
    mostrar (f);

    inserir (f, 45);
    mostrar (f);

    inserir (f, 21);
    mostrar (f);

    remover (f);
    mostrar (f);

    remover (f);
    mostrar (f);

    limpar (f);

    return 0;
}
