#include<cstdio>
using namespace std;
long long power(long long w,long long y);
long long sum(long long x,long long k);
long long m;
int main()
{
    long long t,a,d,r,n,ans,f;
    scanf("%lld",&t);
    while(t--)
    {
        f=0;
        scanf("%lld %lld %lld",&a,&d,&r);
        scanf("%lld %lld",&n,&m);
        if(n==1)
        {
        ans=a%m;
        f=1;
        }
        if(n==2)
        {
        ans=(a%m+d%m)%m;
        f=1;
        }
        if(f==0)
        {
        if(n%2==0)
        {
            ans=((a%m*power(r%m,n/2-1)%m)%m+(d%m*sum(r,n/2)%m)%m)%m;
        }
        else if(n%2!=0)
        {
           ans=((a%m*power(r%m,n/2)%m)%m+(r%m*d%m*sum(r,n/2)%m)%m)%m;
        }
        }
       printf("%lld\n",ans);
    }
    return 0;
}
long long power(long long w,long long y)
{
    long long p;
    if(y==0)
    return 1%m;
    if(y==1)
    return w%m;
    p=power(w,y/2)%m;
    if(y%2==0)
    return (p%m*p%m)%m;
    else if(y%2!=0)
    return (w%m*(p%m*p%m)%m)%m;
}
long long sum(long long x,long long k)
{
   long long f,ans,tempx;
   if(k==1)
   return 1%m;
   if(k==2)
   return (1+x)%m;
   else
   {
   f=(k-1)/2;
   tempx=(x%m*x%m)%m;
   ans=((1%m+x%m)%m*sum(tempx,f+1)%m)%m;
   if(k%2!=0)
   {
   ans=(ans%m-power(x%m,k)%m)%m;
   if(ans<0)
   ans=ans+m;
   return ans%m;
   }
   else
   return ans%m;
   }
}

