/*Shortest Path in a Grid*/
#include<cstring>
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
using namespace std;
#define S(a) scanf("%d",&a)
#define SL(a) scanf("%lld",&a);
#define SF(a) scanf("%lf",&a);
#define P(a) printf("%d\n",a)
#define Pr(a) printf("%d ",a);
#define PL(a) printf("%lld\n",a);
#define Prl(a) printf("%lld ",a);
#define for(i,a,b) for(i=(a);i<(b);i++)
#define Fill(a,b) memset(a,0,sizeof(a))
#define fillv(ar,n,v) fill_n(ar,n,v)
typedef long long ll;
const int inf=1000000007;
const int mod=1000000007;
int gcd(int a,int b){return(b)?gcd(b,a%b):a;}
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
int main()
{
    int t,i,j,k,n,ans;
    char s[10];
    int ar[10][10];
    S(t);
    cin.ignore();
    while(t--)
    {
        gets(s);
        int a=(int)s[0]-96;
        int b=(int)s[1]-48;
        int d1=(int)s[3]-96;
        int d2=(int)s[4]-48;
        Fill(ar,0);
        queue<pair<int,int> >Q;
        Q.push(make_pair(a,b));
        ar[a][b]=1;
        int flag=0;
        while(!Q.empty())
        {
          a=Q.front().first;
          b=Q.front().second;
          Q.pop();
          for(i,0,9)
          {
            if(a+dx[i]>0&&a+dx[i]<9&&b+dy[i]>0&&b+dy[i]<9&&ar[a+dx[i]][b+dy[i]]==0)
            {
               ar[a+dx[i]][b+dy[i]]=ar[a][b]+1;
               if(a+dx[i]==d1&&b+dy[i]==d2)
               {
                flag=1;
                break;
               }
               Q.push(make_pair(a+dx[i],b+dy[i]));
            }
          }
          if(flag==1)
            break;
        }
        P(ar[d1][d2]-1);
    }
    return 0;
}


