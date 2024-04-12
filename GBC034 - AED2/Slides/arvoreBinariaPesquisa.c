void pesquisa (registro *x, apontador *p) {
  if (*p == NULL) {
    printf ("Erro: Registro nao esta na arvore.\n");
    return;
  }
  if (x->chave < (*p)->reg.chave) {
    pesquisa(x, &(*p)->esq);
    return;
  }
  if (x->chave > (*p)->reg.chave) {
    pesquisa(x, &(*p)->dir);
  }
  else *x = (*p)->reg;
}
