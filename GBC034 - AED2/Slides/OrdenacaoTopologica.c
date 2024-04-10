void InsLista (TipoItem *Item, TipoLista *Lista) {
  TipoApontador Aux;
  Aux = Lista->Primeiro->Prox;
  Lista->Primeiro->Prox = (TipoApontador) malloc (sizeof(tipoCelula));
  Lista->Primeiro->Prox->Item = Item;
  Lista->Primeiro->Prox->Prox = Aux;
}
