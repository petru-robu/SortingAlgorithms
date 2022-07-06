#include <bits/stdc++.h>
#include "heap.h"
#define S_MAX 10001
using namespace std;
ifstream fin("../vector.in");

void heapsort(int H[], int n)
{
  heapify(H, n);
  for(int i=n; i>=2; i--)
  {
    swap(H[1], H[i]);
    sift(H, i-1, 1);
  }
}


int main()
{
  int v[S_MAX], n;
  fin>>n;

  for(int i=1; i<=n; i++)
    fin>>v[i];

  heapsort(v, n);

  for(int i=1; i<=n; i++)
    cout<<v[i]<<' ';

  return 0;
}
