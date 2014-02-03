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
#define pii pair<int,int>

struct comp{
  bool operator()(const pii &a,const pii &b)
  {
  return a.second>b.second;
  }
};
priority_queue<pii,vector<pii>,comp>Q;
int main()
{
    int u,v,w,i,j,k,n,e,s;
    scanf("%d %d",&n,&e);
    vector<pii>G[n+1];
    int dist[n+1];
    bool mark[n+1];
    for(i=0;i<e;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        G[u].push_back(pii(v,w));
        G[v].push_back(pii(u,w));
    }
    scanf("%d",&s);
    for(i=0;i<=n;i++)
    dist[i]=INF;
    dist[s]=0;
    Q.push(pii(s,0));
    while(!Q.empty())
    {
        u=Q.top().first;
        if(mark[u])continue;
        Q.pop();
        int sz=G[u].size();
        for(i=0;i<sz;i++)
        {
         v=G[u][i].first;
         w=G[u][i].second;
         if(!mark[v]&&dist[u]+w<dist[v])
         {
          dist[v]=dist[u]+w;
          Q.push(pii(v,dist[v]));
         }
        }
        mark[u]=1;
    }
    for(i=0;i<n;i++)
        printf("%d %d\n",i,dist[i]);
    return 0;
}
