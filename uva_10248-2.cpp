#include <stdio.h>
int n,m,ans[1500],anslen,map[15][15],ind[15],out[15];
char used[15];

void go(int now) {
	int i;
	for(i=9;i>=0;i--)
		if(map[now][i]) {
			map[now][i]--;
			go(i);
		}
	ans[anslen++] = now;
}

int main() {
	int i,j,tmp1,tmp2;

	while(scanf("%d%d",&n,&m) != EOF) {
		for(i=anslen=0;i<10;i++) {
			ind[i] = out[i] = used[i] = 0;
			for(j=0;j<10;j++)
				map[i][j] = 0;
		}			
		if(n == m && (n%10 == n/10)) {
			printf("%d\n",n);
			continue;
		}
	
		for(i=n;i<10;i++);
		for(;i<=m;i++) {
			used[i/10] = 1;
			used[i%10] = 1;
			map[i/10][i%10]++;
			out[i/10]++;
			ind[i%10]++;
			if(i/10 == i%10)	continue;
			map[i%10][i/10]++;
			out[i%10]++;
			ind[i/10]++;
		}
		
		/*tmp1 = tmp2 = -1;
		for(i=0;i<10;i++) {
			while(ind[i] > out[i]) {
				for(j=0;ind[i] > out[i] && j<10;j++) {
					if(ind[j] < out[j]) {
						map[i][j]++;
						out[i]++;
						ind[j]++;
						tmp1 = i, tmp2 = j;
					}
				}
			}
		}*/
		
		/*if(tmp1 != -1 && tmp2 != -1) {
			map[tmp1][tmp2]--;
			go(tmp2);
		} else {*/
			for(i=1;i<10 && out[i]==0;i++);
			if(i < 10)	go(i);
		
		for(i=anslen-1;i>0;i--)
			printf("%d",ans[i]);
		for(i=1;i<10;i++)
			if(i<=m && i>=n && used[i] == 0)
				printf("%d",i);
		puts("");
		
	}
	
	return 0;
}
