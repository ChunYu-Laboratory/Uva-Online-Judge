#include<stdio.h>
int ans[23]={1,2,3,5,8,12,20,34,57,98,170,300,536,966,1754,3210,
             5910,10944,20366,38064,71421,134480,254016};
main(){
    int n;
    while(scanf("%d",&n) && n)
        printf("%d\n",ans[(n-1940)/10]);
}
