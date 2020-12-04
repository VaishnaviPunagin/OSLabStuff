#include<stdio.h>
int main()
 {
     int ms, ps, nop, np, rempages, i, j, procno, pgno, pa, offset;
     int s[10], fno[10][20];
     printf("\nEnter the memory size: ");
     scanf("%d",&ms);
     printf("\nEnter the page size: ");
     scanf("%d",&ps);
     nop = ms/ps;
     printf("\nThe no. of pages available in memory are:%d ",nop);
     printf("\nEnter number of processes: ");
     scanf("%d",&np);
     rempages = nop;
     for(i=1;i<=np;i++)
     {
            printf("\nEnter no. of pages required for p[%d]: ",i);
            scanf("%d",&s[i]);
            if(s[i] >rempages)
            {
                  printf("\nMemory is Full");
                  break;
            }
            rempages = rempages - s[i];
            printf("\nEnter pagetable entry for p[%d]: ",i);
            for(j=1;j<=s[i];j++)
                  scanf("%d",&fno[i][j]);
      }
      printf("\nEnter process no. and pagenumber and offset: ");
      scanf("%d %d %d",&procno,&pgno, &offset);
      if(procno> np || pgno>= s[i] || offset>=ps)
            printf("\nInvalid Process or Page Number or offset\n\n");
      else
      {
            pa=fno[procno][pgno]*ps+offset;
            printf("\nThe Physical Address is: %d\n\n",pa);
      }
      return 0;
 }
