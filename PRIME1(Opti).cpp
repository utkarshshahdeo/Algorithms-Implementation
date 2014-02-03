#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t,n,m,i,j,k;
     scanf("%d",&t);
     while(t--)
     {
         scanf("%d %d",&n,&m);
         int mark[m-n+1];
         memset(mark,0,sizeof(mark));
         int p;
         for(p=2;p*p<=m;p++)
         {
             k=n/p;
             k=k*p;
             for(i=k;i<=m;i+=p)
             {
                 if(i>=n&&i!=p)
                 mark[i-n]=1;
             }
         }
         for(i=0;i<=m-n;i++)
         {
             if(!mark[i]&&(n+i)!=1)
                printf("%d\n",n+i);
         }
         printf("\n");
     }
    return 0;
}

