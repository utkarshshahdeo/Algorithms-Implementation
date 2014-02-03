#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int t,a[1000000],temp,i,f,n,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        f=0;
        for(i=n-1;i>0;i--)
        {
            if(a[i]>a[i-1])
            {
                f=1;
                sort(a+i,a+n);
                for(j=i;j<n;j++)
                {
                    if(a[j]>a[i-1])
                    {
                        temp=a[i-1];
                        a[i-1]=a[j];
                        a[j]=temp;
                        break;
                    }
                }
                break;
            }
        }
        if(f==1)
        {
        for(i=0;i<n-1;i++)
        {
            printf("%d",a[i]);
        }
        printf("%d\n",a[n-1]);
        }
        else if(f==0)
        {
            printf("-1\n");
        }
    }
    return 0;
}

