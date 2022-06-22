#include <bits/stdc++.h>
#include "algs.h"
using namespace std;

ifstream fin("vector.in");

int main()
{
  int v[S_MAX], n;
  fin>>n;
  for(int i=1; i<=n; i++)
    fin>>v[i];

  QuickSort(v, 1, n);
  print(v, n);
  MergeSort(v, 1, n);
  print(v, n);
  SelectionSort(v, n);
  print(v, n);
  InsertionSort(v, n);
  print(v, n);
  BubbleSort(v, n);
  print(v, n);
  CountingSort(v, n);
  print(v, n);
  RadixSort(v, n);
  print(v, n);
  HeapSort(v, n);
  print(v, n);



}
