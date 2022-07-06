#include <bits/stdc++.h>
#include <chrono>
#include "headers/algs.h"
#include "headers/utilities.h"

#define PREC 2

using namespace std;
using namespace std::chrono;

ifstream fin("iofiles/vector.txt");
ofstream fout("iofiles/timings.txt");

int main()
{
  int v[S_MAX], n;
  fin>>n;
  for(int i=1; i<=n; i++)
    fin>>v[i];
  
  fout<<fixed<<setprecision(PREC);

  auto start= high_resolution_clock::now(), stop= high_resolution_clock::now();
  auto duration=duration_cast<nanoseconds>(stop - start);

  start = high_resolution_clock::now();
  InsertionSort(v, n);
  stop = high_resolution_clock::now();
  duration = duration_cast<nanoseconds>(stop - start);
  fout<<"Insertion Sort: "<< duration.count()<<"ms "<<'\n';

  read(v, n, fin);

  start = high_resolution_clock::now();
  BubbleSort(v, n);
  stop = high_resolution_clock::now();
  duration = duration_cast<nanoseconds>(stop - start);
  fout<<"Bubble Sort: "<< duration.count()<<"ms "<<'\n';

  read(v, n, fin);

  start = high_resolution_clock::now();
  SelectionSort(v, n);
  stop = high_resolution_clock::now();
  duration = duration_cast<nanoseconds>(stop - start);
  fout<<"Selection Sort: "<< duration.count()<<"ms "<<'\n';

  read(v, n, fin);

  start = high_resolution_clock::now();
  MergeSort(v, 1, n);
  stop = high_resolution_clock::now();
  duration = duration_cast<nanoseconds>(stop - start);
  fout<<"Merge Sort: "<< duration.count()<<"ms "<<'\n';

  read(v, n, fin);

  start = high_resolution_clock::now();
  QuickSort(v, 1, n);
  stop = high_resolution_clock::now();
  duration = duration_cast<nanoseconds>(stop - start);
  fout<<"Quick Sort: "<< duration.count()<<"ms "<<'\n';

  read(v, n, fin);

  start = high_resolution_clock::now();
  CountingSort(v, n);
  stop = high_resolution_clock::now();
  duration = duration_cast<nanoseconds>(stop - start);
  fout<<"Counting Sort: "<< duration.count()<<"ms "<<'\n';

  read(v, n, fin);

  start = high_resolution_clock::now();
  RadixSort(v, n);
  stop = high_resolution_clock::now();
  duration = duration_cast<nanoseconds>(stop - start);
  fout<<"Radix Sort: "<< duration.count()<<"ms "<<'\n';  
  
  return 0;
}