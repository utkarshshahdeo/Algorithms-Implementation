#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
ll m=3046201;
ll fact[3000004];
ll tree[400005];
ll ar[100005];
void factorial()
{
    ll i;
    fact[0]=1;
    for(i=1;i<3000002;i++)
        fact[i]=(fact[i-1]%m*i%m)%m;
}
ll power(ll a,ll b)
{
    if(b==0)
        return 1;
    else
    {
        ll x=power(a%m,b/2)%m;
        if(b%2==0)
            return (x%m*x%m)%m;
        else
            return ((a%m*x%m)%m*(x)%m)%m;
    }
}
void buildtree(ll node,ll a,ll b)
{
    if(a>b)
        return;
     if(a==b)
     {
        tree[node]=ar[a];
        return;
     }
    ll mid=(a+b)/2;
    buildtree(2*node,a,mid);
    buildtree(2*node+1,mid+1,b);
    tree[node]=(tree[2*node]+tree[2*node+1]);
}
ll getsum(ll node,ll ss,ll se,ll qs,ll qe)
{
  if(ss>se||ss>qe||se<qs) return 0;
  if(ss>=qs&&se<=qe)
    return tree[node];
    ll mid=(ss+se)/2;
    ll s1=getsum(2*node,ss,mid,qs,qe);
    ll s2=getsum(2*node+1,mid+1,se,qs,qe);
    return (s1+s2);
}
void updatevalue(ll node,ll ss,ll se,ll i,ll diff)
{
    if(i<ss||i>se)
        return;
    tree[node]=(tree[node]+diff);
    if(se!=ss)
    {
        ll mid=(ss+se)/2;
        updatevalue(2*node,ss,mid,i,diff);
        updatevalue(2*node+1,mid+1,se,i,diff);
    }
}
int main()
{
    ll i,k;
    ll q,a,b,n;
    factorial();
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&ar[i]);
    buildtree(1,1,n);
    scanf("%lld",&q);
    char s[10];
    while(q--)
    {
        scanf("%s",s);
        scanf("%lld %lld",&a,&b);
        if(s[0]=='c')
        {
           ll diff=b-ar[a];
           ar[a]=b;
           updatevalue(1,1,n,a,diff);
        }
        else
        {
        ll s=getsum(1,1,n,a,b);
        k=b-a+1;
        ll q=s/k;
        ll r=s-(q*k);
        //printf("%lld %lld %lld %lld\n",s,k,q,r);
        ll c=power(fact[q]%m,k-r)%m;
        ll d=power(fact[q+1]%m,r)%m;
        ll num=(fact[s]%m*fact[k]%m)%m;
        ll deno=(((c*d)%m*fact[r])%m*(fact[k-r])%m)%m;
        //printf("%lld %lld\n",num,deno);
        ll ans=(num%m*power(deno%m,m-2)%m)%m;
        printf("%lld\n",ans);
        }
    }
    return 0;
}

