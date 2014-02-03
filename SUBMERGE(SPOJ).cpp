/*Articulation Point of a graph*/

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 10005
#define FOR(i,a,b) for(i=(a);i<(b);i++)
vector<int>Graph[MAX];
struct tree{
int backe,disco,children;
bool is_arti;
}node[MAX];
void init()
{
    int i;
    FOR(i,0,MAX)
    {
    Graph[i].clear();
    node[i].backe=0;
    node[i].disco=0;
    node[i].children=0;
    node[i].is_arti=0;
    }
}
void find_articulation(int v,int n)
{
    int i,w;
    node[v].backe=node[v].disco;
    FOR(i,0,Graph[v].size())
    {
       w=Graph[v][i];
       if(!node[w].disco)
       {
           node[w].disco=node[v].disco+1;
           node[v].children+=1;
           find_articulation(w,n);
           node[v].backe=min(node[v].backe,node[w].backe);
           if(node[v].disco>1&&node[w].backe>=node[v].disco)
            node[v].is_arti=1;
       }
       else if(node[w].disco<node[v].disco-1)
        node[v].backe=min(node[v].backe,node[w].disco);
    }
       if(node[v].disco==1&&node[v].children>=2)
        node[v].is_arti=1;
}
int main()
{
    int n,m,a,b,i,j;
    while(1)
    {
        init();
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)
            break;
        FOR(i,0,m)
        {
            scanf("%d %d",&a,&b);
            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }
        int c=0;
        node[1].disco=1;
        find_articulation(1,n);
        FOR(i,0,n+1)
        {
            if(node[i].is_arti)
            {
                c+=1;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}

