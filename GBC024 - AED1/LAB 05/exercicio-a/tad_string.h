#ifndef TAD_STRING_H_INCLUDED
#define TAD_STRING_H_INCLUDED

typedef struct str str;

str *criar ( );

void *preencher (str *s);

int tamanho (str *s);

int ocorrencias (str *s, char c);

void printar (str *s);

#endif // TAD_STRING_H_INCLUDED
