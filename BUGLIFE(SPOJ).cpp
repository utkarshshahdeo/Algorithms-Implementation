#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int ar[2002];
vector<int>p[2002];
int main()
{
    int t,i,j,a,b,n,m,k,f;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        f=0;
        queue<int>q;
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++)
        p[i].clear();
        for(i=0;i<=n;i++)
        ar[i]=-1;
        for(i=0;i<m;i++)
        {
          scanf("%d %d",&a,&b);
          p[a].push_back(b);
          p[b].push_back(a);
        }
        for(j=1;j<=n;j++)
        {
            if(ar[j]==-1)
            {
                q.push(j);
                ar[j]=1;
                while(!q.empty())
                {
                  for(i=0;i<p[q.front()].size();i++)
                  {
                      if(ar[p[q.front()][i]]==-1)
                      {
                          if(ar[q.front()]==0)
                          {
                          ar[p[q.front()][i]]=1;
                          q.push(p[q.front()][i]);
                          }
                          else if(ar[q.front()]==1)
                          {
                              ar[p[q.front()][i]]=0;
                              q.push(p[q.front()][i]);
                          }
                      }
                      else if(ar[p[q.front()][i]]==ar[q.front()])
                      {
                          printf("Scenario #%d:\n",k);
                          printf("Suspicious bugs found!\n");
                          f=1;
                          break;
                      }
                      else
                      continue;
                  }
                  q.front()=2;
                  q.pop();
                  if(f==1)
                  break;
                  }
                  if(f==1)
                  break;
                }
                else
                continue;
            }
            if(f==0)
            {
            printf("Scenario #%d:\n",k);
            printf("No suspicious bugs found!\n");
            }
        }
    return 0;
}


