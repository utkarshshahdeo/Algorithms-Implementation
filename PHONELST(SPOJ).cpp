/*TRIE*/
/*Using Constructors*/
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
struct trie{
bool is_end;
struct trie *next[10];
trie() /*constructor*/
{
for(int i=0;i<10;i++)
    next[i]=NULL;
    is_end=0;
}
};
int main()
{
  int t,n,i,j;
  string str;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d",&n);
      trie *head,*tail;
      head=new trie;/*creating a new node having 10 pointers (0-9) initialised to null and */
                    /* bool end init to zero*/
      bool flag=1;
      while(n--)
      {
         cin>>str;
         if(flag)
         {
             tail=head;
             for(i=0;i<str.length();i++)
             {
                 if(tail->is_end)/*prefix found so the search reaches the end of a word*/
                 {
                     flag=0;
                     break;
                 }
                 int p=str[i]-'0';
                 if(tail->next[p]==NULL)/*If node not found create a new node for 'p'*/
                    tail->next[p]=new trie;
                tail=tail->next[p];
             }
             tail->is_end=1;
             for(i=0;i<10;i++)
             {
                 if(tail->next[i])
                 {
                    flag=0;
                    break;
                 }
             }
         }
      }
      if(flag)
        printf("YES\n");
      else
        printf("NO\n");
  }
  return 0;
}
