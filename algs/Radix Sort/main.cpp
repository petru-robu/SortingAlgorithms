#include <bits/stdc++.h>
#define S_MAX 10001
using namespace std;
ifstream fin("../vector.in");


void RadixSort(int v[], int n)
{
  int aux[S_MAX+1];
  int frecv[256];
  for(int p = 0; p < 32; p += 8)
  {
      for(int i = 0; i < 256; i++)
          frecv[i] = 0;

      for(int i = 1; i <= n; i++)
          frecv[(v[i] >> p) & 255]++;

      for(int i = 1; i < 256; i++)
          frecv[i] += frecv[i - 1];

      for(int i = n; i >= 1; i--)
          aux[frecv[(v[i] >> p) & 255]--] = v[i];

      for(int i = 1; i <= n; i++)
          v[i] = aux[i];
  }
}


int main()
{
  int v[S_MAX], n;
  fin>>n;

  for(int i=1; i<=n; i++)
    fin>>v[i];

  RadixSort(v, n);

  for(int i=1; i<=n; i++)
    cout<<v[i]<<' ';
  return 0;
}
