int qtd = 0;
  if (pai == AB || mae == AB) {
    strcpy(filho[qtd++], "A"); strcpy(filho[qtd++], "B");
    if (pai == A || pai == B || mae == A || mae == B ||
        (pai == AB && mae == AB))
      strcpy(filho[qtd++], "AB");
  } else {
    strcpy(filho[qtd++], "O");
    if (pai == A || mae == A) strcpy(filho[qtd++], "A");
    if (pai == B || mae == B) strcpy(filho[qtd++], "B");
    if ((pai == A && mae == B) || (pai == B && mae == A))
      strcpy(filho[qtd++], "AB");
  }
  return qtd;
