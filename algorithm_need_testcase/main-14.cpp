//viết các hoán vị của bộ số x1,x2,...,xn(trong đó x1,x2,...,xn có cùng số chữ số)


#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

double pw(double x,double k)
{
    double Pow=1;
    for (int i=1;i<=k;i++)
    {
        Pow*=x;
    }
    return Pow;
}
int main()
{
    int n,coso,cscs;
    int a[51];
    int x[51],mini[51];
    int p[51];
    int l,q;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x[i];p[i]=1;
    }
    
    //sắp xếp thứ tự
    for (int j=1;j<=n;j++)
    {
        l=1;//vị trí của số nhỏ thứ j
        q=0;//kiểm tra min[j] đã được gán giá trị chưa
        mini[j]=0;//giá trị nhỏ thứ j
        for (int t=1;t<=n;t++)
        {
            if (p[t]==1)// a[t] chưa bị loại
            {
                if (q==0)
                {
                    mini[j]=x[t];
                    l=t;
                    q++;
                }
                else if (mini[j]>x[t])
                {
                    mini[j]=x[t];
                    l=t;
                }
            }
        }
        p[l]=0;
    }
    
    //dựng tổ hợp
    coso=n;//hệ số
    cscs=n;
    int m=pw(n,n-2);
    while (m<=pw(n,n-2)*(n*n-1))
    {
        int test=m;
        int h=n-1;
        int check=0;
        int cs[50]={0};
        while (h>=0)
        {
            //mã hoá
            a[h]=test/pw(coso,h);
            if ((cs[a[h]]!=1)&&(check==0))
            {
                test=test-(a[h]*pw(coso,h));
                cs[a[h]]=1;
                
                a[h]=mini[a[h]+1];
                
                
                h--;
            }
            else
            {
                check++;
                break;
            }
        }
        if (check==0)
        {
            for (int j=n-1;j>=0;j--)
            {
                cout<<a[j];
            }
            cout<<endl;
        }
        m++;
    }
    
}