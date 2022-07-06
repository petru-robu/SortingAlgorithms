#include <bits/stdc++.h>

void print(int v[], int n)
{
  for(int i=1; i<=n; i++)
    std::cout<<v[i]<<' ';
  std::cout<<'\n';
}

void read(int v[], int n, istream &in)
{
    for(int i=1; i<=n; i++)
        in>>v[i];
}