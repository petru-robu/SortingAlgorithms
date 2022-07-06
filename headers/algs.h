#include <bits/stdc++.h>
#include "heap.h"

#define S_MAX 100001
int tmp[S_MAX];

void BubbleSort(int v[], int n)
{
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n-i; j++)
      if(v[j]>v[j+1])
        swap(v[j], v[j+1]);
}

void SelectionSort(int v[], int n)
{
  for(int i=1; i<=n-1; i++)
    for(int j=i+1; j<=n; j++)
      if(v[i]>v[j])
        swap(v[i], v[j]);
}

void InsertionSort(int v[], int n)
{
  for(int i=2 ; i <= n ; i++)
  {
    int x=v[i];
    int p=i-1;
    while(p >= 0 && v[p] > x)
        v[p+1] = v[p], p --;
    v[p+1] = x;
  }
}

void QuickSort(int v[], int st, int dr)
{
  if(st<dr)
	{
		int m=(st+dr)/2;
		swap(v[st], v[m]);

		int i=st, j=dr, d=0;

		while(i<j)
		{
			if(v[i]>v[j])
			{
				swap(v[i], v[j]);
				d=1-d;
			}
			i+=d;
			j-= (1-d);
		}

		QuickSort(v, st , i-1);
		QuickSort(v, i+1 , dr);
	}
}

void MergeSort(int v[], int st, int dr)
{
  if(st < dr)
  {
    int m = st+(dr-st)/2;
    MergeSort(v, st, m);
    MergeSort(v, m+1, dr);

    int i=st, j=m+1, k=0;
    while(i<=m && j<=dr)
    {
      if(v[i]<v[j])
        tmp[++k] = v[i++];
      else
        tmp[++k] = v[j++];
    }

    while(i<=m)
      tmp[++k] = v[i++];
    while(j<=dr)
      tmp[++k] = v[j++];

    for(int i=st, j=1; i<=dr; i++, j++)
      v[i] = tmp[j];
  }
  else return;

}

void CountingSort(int v[], int n)
{
  int m = v[1];
  for(int i=2; i<=n; i++)
    m = max(m, v[i]);

  int vap[m+1];

  for(int i=0; i<=m; i++)
    vap[i]=0;

  for(int i=1; i<=n; i++)
    vap[v[i]]++;

  int k=0;
  for(int i=0; i<=m; i++)
  {
    while(vap[i]!=0)
    {
      v[++k]=i;
      vap[i]--;
    }
  }

}

void HeapSort(int H[], int n)
{
  heapify(H, n);
  for(int i=n; i>=2; i--)
  {
    swap(H[1], H[i]);
    sift(H, i-1, 1);
  }
}

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
