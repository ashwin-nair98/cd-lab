#include<stdio.h>
char p[10];
int n,l,k;
struct state
{
    char st;
    char alpha[20][2];
    int noe;
    char eclose[20];
    int el;
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

void eclosure(char states[])
{
    int w,i,j,fl=0;
    for(i=0;i<n;++i)
    {
        if(states[i]=='$')
        {
           p[l++]='$';
           return;
        }   
        
        for(j=0;j<n;++j)
        {
          if(s[j].st==states[i])
           {
              for(k=0;k<s[j].el;++k)
               { 
                  fl=0;
                  for(w=0;w<l;++w)
                   {
                      if(p[w]==s[j].eclose[k])
                        {
                          fl=1;                                 
                          break;
                        }  
                   }
                  if(fl==0)
                    p[l++]=s[j].eclose[k];    
               }
         }
     }               
   }
}

char trans(char state,char a)
{
    int j,i;
    for(i=0;i<n;++i)
       if(s[i].st==state)
         {
             for(j=0;j<s[i].noe;++j)
                if(s[i].alpha[j][0]==a)
                    return s[i].alpha[j][1];
         }
    return '$';                  
                          
}

main()
{
    int i,j,h,fl=0,ft,w;
    char k,c,f[12];
    printf("\n enter the number of states");
    scanf("%d",&n);

    for(i=0;i<n;++i)
    {
          while(getchar()!='\n');
        printf("\n enter the name of state %d ", i);
        scanf("%c",&s[i].st);
        printf("\n enter the no of transitions ");
        scanf("%d",&s[i].noe);
        printf("\n enter the input alphabet and the corresponding states");
        for(j=0;j<s[i].noe;++j)
        {
           scanf(" %c",&s[i].alpha[j][0]);
           scanf(" %c",&s[i].alpha[j][1]); 
        }
       
    } 
     printf("\n input the number of final states ");
        scanf("%d",&ft);
        for(j=0;j<ft;++j)
           scanf(" %c",&f[j]);
    for(i=0;i<n;++i)
    {
          l=0;
          for(j=0;j<10;++j)
               p[j]=0;
          p[l++]=s[i].st;     
          find(s[i].st);
           printf("\n  e closure of  state %c -", s[i].st);         
           s[i].el=l;
           for(h=0;h<l;++h)
           {
                printf(" %c ",p[h]);
                s[i].eclose[h]=p[h];
               
           }
           
           if(i==0)
           {
             fl=0;   
             for(h=0;h<l;++h)
             {   
                    for(w=0;w<ft;++w)
                       if(f[w]==p[h])
                         {
                           fl=1;
                           break;
                           
                         }  
            }
            if(fl==1)
              f[ft++]=s[0].st;
          }                           
    }
   for(i=0;i<n;++i)
    {
      for(j=0;j<s[i].noe;++j)
        {
             l=0;
             for(k=0;k<10;++k)
                p[k]=0;
            
             if(s[i].alpha[j][0]=='e')
                 continue;
             for(h=0;h<s[i].el;++h)
                 p[h]=trans(s[i].eclose[h],s[i].alpha[j][0]);
            
             eclosure(p);    
             printf("\n transition for state %c and alphabet %c :",s[i].st,s[i].alpha[j][0]); 
             for(h=0;h<l;++h)
                printf(" %c ",p[h]);
                 
             
             
        }        
        
    }
    printf("\n final states");
     
  for(j=0;j<ft;++j)
           printf(" %c",f[j]);  
  
}
