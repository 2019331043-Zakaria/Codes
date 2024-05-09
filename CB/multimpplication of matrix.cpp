#include <stdio.h>
#define mat 1000
int first[mat][mat],second[mat][mat],multiply[mat][mat];
int main()
{
  int m, n, p, q, c, d, k, sum = 0;

  printf("The dimension  of first matrix:\n");
  scanf("%d%d", &m, &n);


  printf("Dimension of second matrix:\n");
  scanf("%d%d", &p, &q);

  if (n != p)
    printf("The multiplication isn't possible.\n");
  else
  {
   printf("Enter elements of first matrix:\n");

  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      scanf("%d", &first[c][d]);

    printf("Enter elements of second matrix:\n");

    for (c = 0; c < p; c++){
      for (d = 0; d < q; d++){
        scanf("%d", &second[c][d]);
      }
    }

    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
        for (k = 0; k < p; k++) {
          sum = sum + first[c][k]*second[k][d];
        }

        multiply[c][d] = sum;
        sum = 0;
      }
    }

  printf("Multiply is:\n");

    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%4d", multiply[c][d]);

      printf("\n");
    }
  }

  return 0;
}

