using namespace std;
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<queue>
#define MAX 1000001
#define INF (1<<20)
#define edge pair<int,int>
int n,m;
long long p;
long long ans;
vector< pair<int,edge> >G;
void reset(int *parent);
int findset(int x,int *parent);
void kruskal(int *parent);
int main()
{
    int t,i,j,u,v;
    long long w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&p,&n,&m);
        int parent[n+2];
        reset(parent);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            G.push_back(make_pair(w,edge(u,v)));
        }
       int pu,pv;
       sort(G.begin(),G.end());
       for(i=0;i<m;i++)
       {
       pu=findset(G[i].second.first,parent);
       pv=findset(G[i].second.second,parent);
       if(pu!=pv)
       {
        ans+=(long long)G[i].first;
        parent[pu]=parent[pv];
       }
      }
        printf("%lld\n",ans);
    }
    return 0;
}
void reset(int *parent)
{
    for(int i=1;i<=n;i++)
        parent[i]=i;
        ans=0;
}
int findset(int x,int *parent)
{
    if(x!=parent[x])
        parent[x]=findset(parent[x],parent);
    return parent[x];
}
