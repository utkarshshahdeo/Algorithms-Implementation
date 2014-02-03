#include<cstdio>
#include<iostream>
#include<utility>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
#define edge pair<int,int>
pair<string,edge>play[250];
int n,m,p,sz1,sz2;
pair<int,int>team1[250];
pair<int,int>team2[250];
pair<int,int>on_field1[250];
pair<int,int>on_field2[250];
pair<int,int>bench1[250];
pair<int,int>bench2[250];
void sortinit()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(play[i].second.first<play[j].second.first)
             swap(play[i],play[j]);
             else if(play[i].second.first==play[j].second.first)
             {
                 if(play[i].second.second<play[j].second.second)
                    swap(play[i],play[j]);
             }
        }
    }
}
void sort_field()
{
    int i,j;
    for(i=0;i<p;i++)
    {
        for(j=i+1;j<p;j++)
        {
            if(on_field1[i].second<on_field1[j].second)
                swap(on_field1[i],on_field1[j]);
            else if(on_field1[i].second==on_field1[j].second)
            {
                if(on_field1[i].first<on_field1[j].first)
                    swap(on_field1[i],on_field1[j]);
            }
            if(on_field2[i].second<on_field2[j].second)
                swap(on_field2[i],on_field2[j]);
            else if(on_field2[i].second==on_field2[j].second)
            {
                if(on_field2[i].first<on_field2[j].first)
                    swap(on_field2[i],on_field2[j]);
            }
        }
    }
}
void sort_bench()
{
     int i,j;
     int k1=sz1-p;
     int k2=sz2-p;
     for(i=0;i<k1;i++)
     {
         for(j=i+1;j<k1;j++)
         {
             if(bench1[i].second>bench1[j].second)
                swap(bench1[i],bench1[j]);
             else if(bench1[i].second==bench1[j].second)
             {
                 if(bench1[i].first>bench1[j].first)
                    swap(bench1[i],bench1[j]);
             }
         }
     }
     for(i=0;i<k2;i++)
     {
         for(j=i+1;j<k2;j++)
         {
             if(bench2[i].second>bench2[j].second)
                swap(bench2[i],bench2[j]);
             else if(bench2[i].second==bench2[j].second)
             {
                 if(bench2[i].first>bench2[j].first)
                    swap(bench2[i],bench2[j]);
             }
         }
     }
}
int main()
{
    int t;
    freopen("C:\\Users\\Utkarsh\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\Utkarsh\\Desktop\\out.txt","w",stdout);
    scanf("%d",&t);
    int cs;
    for(cs=1;cs<=t;cs++)
    {
         int i,j;
         scanf("%d %d %d",&n,&m,&p);
         string name;
         string sr[100];
         int shot,ht;
         for(i=0;i<n;i++)
         {
             cin>>name;
             scanf("%d %d",&shot,&ht);
             play[i]=make_pair(name,edge(shot,ht));
         }
         //printf("\n");
         sortinit();
         map<int,string>play_id;
         int x;
         for(i=0;i<n;i++)
         {
             x=i+1;
             play_id[x]=play[i].first;
         }
         sz1=0;sz2=0;
         for(i=1;i<=n;i++)
         {
             if(i%2)
             {
              team1[sz1]=make_pair(i,0);
              sz1++;
             }
             else
             {
              team2[sz2]=make_pair(i,0);
              sz2++;
             }
         }
         for(i=0;i<p;i++)
         {
             on_field1[i]=team1[i];
             on_field2[i]=team2[i];
         }
         for(i=p;i<sz1;i++)
         {
             bench1[i-p]=team1[i];
         }
         //printf("%d %d\n",bench1[0].first,bench1[0].second);
         for(i=p;i<sz2;i++)
         {
             bench2[i-p]=team2[i];
         }
         //printf("%d %d\n",bench2[0].first,bench2[0].second);
         sort_field();
         sort_bench();
         /*for(i=0;i<p;i++)
            printf("%d %d\n",on_field1[i].first,on_field1[i].second);*/
         /*for(i=0;i<p;i++)
            printf("%d %d\n",on_field2[i].first,on_field2[i].second);*/
            int l=0;
            //for(l=0;l<sz2-p;l++)
              //  printf("%d %d\n",bench2[l].first,bench2[l].second);
         for(i=0;i<m;i++)
         {
            if(sz1>p)
            {
              for(j=0;j<p;j++)
                on_field1[j].second+=1;
              sort_field();
              sort_bench();
              swap(bench1[0],on_field1[0]);
              /*for(l=0;l<p;l++)
                printf("%d %d\n",on_field1[l].first,on_field1[l].second);*/
            }
            if(sz2>p)
            {
              for(j=0;j<p;j++)
                on_field2[j].second+=1;
              sort_field();
              sort_bench();
              swap(bench2[0],on_field2[0]);
            }
         }
         int sz3=0;
         for(i=0;i<p;i++)
         {
             sr[sz3]=play_id[on_field1[i].first];
             sz3++;
             sr[sz3]=play_id[on_field2[i].first];
             sz3++;
         }
         sort(sr,sr+sz3);
         printf("Case #%d: ",cs);
         for(i=0;i<sz3;i++)
            {cout<<sr[i];
            printf(" ");
            }
         cout<<endl;
    }
    return 0;
}
