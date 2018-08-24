// Retorna a distancia de edição da palavra s2 para s1, ou seja, quantas operações de Inserção, Remoção e Substituição eu preciso fazer para transformar s2 em s1.

int edit_dist(char s1[], char s2[]) {
  int i, j, tam1, tam2, memo[TAMP][TAMP];
  tam1 = strlen(s1); tam2 = strlen(s2);
  for (i = 0; i <= tam1; i++) memo[0][i] = i;
  for (i = 0; i <= tam2; i++) memo[i][0] = i;
  for (i = 1; i <= tam1; i++) {
    for (j = 1; j <= tam2; j++) {
      if (s1[i - 1] == s2[j - 1]) memo[i][j] = memo[i - 1][j - 1];
      else memo[i][j] = min(memo[i - 1][j], min(memo[i][j - 1], memo[i - 1][j - 1])) + 1;
    }
  }
  return memo[tam1][tam2];
}
