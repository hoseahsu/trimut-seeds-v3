#include<cstdio>

int M,N,K;

char map[1001][1001];
int J[1001][1001], O[1001][1001], I[1001][1001];

int main()
{
  scanf("%d%d%d",&M,&N,&K);

  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      scanf(" %c", &map[i][j]);
    }
  }

  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      J[i][j] = J[i-1][j] + J[i][j-1] - J[i-1][j-1];
      O[i][j] = O[i-1][j] + O[i][j-1] - O[i-1][j-1];	
      I[i][j] = I[i-1][j] + I[i][j-1] - I[i-1][j-1];	
      if (map[i][j] == 'J') J[i][j]++;
      if (map[i][j] == 'O') O[i][j]++;
      if (map[i][j] == 'I') I[i][j]++;
    }
  }

  int a,b,c,d;
  while (K--) {
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%d %d %d\n",
	   J[c][d] - J[c][b-1] - J[a-1][d] + J[a-1][b-1],
	   O[c][d] - O[c][b-1] - O[a-1][d] + O[a-1][b-1],
	   I[c][d] - I[c][b-1] - I[a-1][d] + I[a-1][b-1]
	   );
  }
}