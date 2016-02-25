
#include <stdio.h>
#define N 1000
qsort( int* a, int lo, int hi )
{
  int h, l, p, t;
  if (lo < hi) {
     l = lo;
     h = hi;
     p = a[hi];
     do {
          while ((l < h) && (a[l] <= p)) l++;
          while ((h > l) && (a[h] >= p)) h--;
          if (l < h) {
             t = a[l]; a[l] = a[h]; a[h] = t;
          }
     } while (l < h);

     t = a[l]; a[l] = a[hi]; a[hi] = t;

     qsort( a, lo, l-1 );
     qsort( a, l+1, hi );
  }
}
int main()
{
   int n, i;
   int a[N];
   scanf ("%d", &n);
   for( i = 0 ; i < n ; i++ )
      scanf("%d", &a[i]);

   qsort(a, 0, n - 1);

   for( i = 0 ; i < n ; i++ )
      printf("%d ", a[i]);
}
