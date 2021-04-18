//file: mã hoá hệ k_phân


#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

int main()
{
    int n,coso,a[50],cscs;
    cin>>n;
    coso=2;//hệ số
    cscs=log(n)/log(coso);
    int h=cscs;
    while (h>=0)
    {
        a[h]=n/pow(coso,h);
        n-=(a[h]*pow(coso,h));
        h--;
    }
    for (int j=cscs;j>=0;j--)
    {
        cout<<a[j];
    }
}