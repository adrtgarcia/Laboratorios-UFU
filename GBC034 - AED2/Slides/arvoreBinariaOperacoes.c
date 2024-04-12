// inserção
void insere (registro x, apontador *p) {
  if (*p == NULL) {
    *p = (apontador) malloc (sizeof(no));
    (*p)->reg = x;
    (*p)->esq = NULL;
    (*p)->dir = NULL;
    return;
  }
  if (x.chave < (*p)->reg.chave) {
    insere(x, &(*p)->esq);
    return;
  }
  if (x.chave > (*p)->reg.chave) 
    insere(x, &(*p)->dir);
  else printf ("Erro: Registro ja existe na arvore.\n");
}

// remoção
void retira (registro x, apontador *p) {
  apontador aux;
  if (*p == NULL) {
    printf ("Erro: Registro nao esta na arvore.\n");
    return;
  }
  if (x.chave < (*p)->reg.chave) {
    retira(x, &(*p)->esq);
    return;
  }
  if (x.chave > (*p)->reg.chave) {
    retira(x, &(*p)->dir;
    return;
  }
  if ((*p)->esq != NUL) {
    antecessor(*p, &(*p)->esq);
    return;
  }
  aux = *p;
  *p = (*p)->dir;
  free(aux);
}

void antecessor (apontador q, apontador *r) {
  if ((*r)->dir != NULL) {
    antecessor(q, &(*r)->dir);
    return;
  }
  q->reg = (*r)->reg;
  q = *r;
  *r = (*r)->esq;
  free(q);
}

// criar
int main ( ) {
  tipoDicionario dicionario;
  registro x;
  inicializa(&dicionario);
  scanf("%d", &x.chave);
  while (x.chave > 0) {
    insere(x, &dicionario);
    scanf("%d", &x.chave);
  }
  //...
  return 0;
}
