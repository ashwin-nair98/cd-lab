#include<stdio.h>
char p[10];
int n,l;
struct state
{
    char st;
    char alpha[20][2];
    int noe;
}s[10];     

void find(char u)
{
     int i,h,j;
     int fl=0;
     for(i=0;i<n;++i)
          if(s[i].st==u)
               {
                    for(j=0;j<s[i].noe;++j)
                         if(s[i].alpha[j][0]=='e')
                          {
                            fl=0;
                            for(h=0;h<l;++h)
                                if(s[i].alpha[j][1]==p[h])
                                  {
                                     fl=1; 
                                     break;
                                  }
                           if(fl==0)
                             { 
                               p[l++]=s[i].alpha[j][1];           
                               find(s[i].alpha[j][1]); 
                              } 
                         }     
               }
             
     
}

void main()
{
    int i,j,h,fl=0;;
    char k,c;
    printf("\nEnter the number of states");
    scanf("%d",&n);

    for(i=0;i<n;++i)
    {
          while(getchar()!='\n');
        printf("\nEnter the name of state %d: ", i);
        scanf("%c",&s[i].st);
        printf("\nEnter the no of transitions: ");
        scanf("%d",&s[i].noe);
        printf("\nEnter the input alphabet and the corresponding states: ");
        for(j=0;j<s[i].noe;++j)
        {
           scanf(" %c",&s[i].alpha[j][0]);
           scanf(" %c",&s[i].alpha[j][1]); 
        }
    } 
    for(i=0;i<n;++i)
    {
          l=0;
          for(j=0;j<10;++j)
               p[j]=0;
          p[l++]=s[i].st;     
          for(j=0;j<s[i].noe;++j)
                if(s[i].alpha[j][0]=='e')
                    {
                          fl=0;
                          for(h=0;h<l;++h)
                              if(s[i].alpha[j][1]==p[h])
                                  {
                                     fl=1; 
                                     break;
                                  }
                           if(fl==0)
                             { 
                               p[l++]=s[i].alpha[j][1];           
                               find(s[i].alpha[j][1]); 
                              } 
                    }
           printf("\n  e closure of  state %c -", s[i].st);         
           for(h=0;h<l;++h)
                printf(" %c ",p[h]);                       
    }
}
