#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int val;
	int ord;
} HEAP;

HEAP* min; int minS;  // 최소힙. 값과 값의 입력 순서를 같이 저장 
HEAP* max; int maxS;  // 최대힙 
char* data;  // 명령어 입력 순으로 값 저장. 해당 순서에 값이 입력되었으면 1, 삭제 되었으면 0 
int Qsize;

void swap(HEAP* x, HEAP* y)
{
	HEAP tmp = *x;
	*x = *y;
	*y = tmp;
}

void insert(int x, int y)
{
	int loc = ++minS;
	min[loc].val = x;
	min[loc].ord = y;
	while(min[loc/2].val>min[loc].val)
	{
		swap(&min[loc/2], &min[loc]);
		loc /= 2;
	}
	
	loc = ++maxS;
	max[loc].val = x;
	max[loc].ord = y;
	while(max[loc/2].val<max[loc].val)
	{
		swap(&max[loc/2], &max[loc]);
		loc /= 2;
	}
}

void removeMin()
{
	data[min[1].ord] = 0;
	
	int loc, small, tmp;
	min[(small=loc=1)] = min[minS--];
	
	while(loc*2<=minS)
	{
		tmp = loc*2;
		if(min[tmp].val<min[small].val) small = tmp;
		tmp = loc*2+1;
		if(tmp<=minS && min[tmp].val<min[small].val) small = tmp;
		
		if(small!=loc)
		{
			swap(&min[small], &min[loc]);
			loc = small;
		}
		else break;
	}
}

void removeMax()
{
	data[max[1].ord] = 0;
	
	int loc, big, tmp;
	max[(big=loc=1)] = max[maxS--];
	
	while(loc*2<=maxS)
	{
		tmp = loc*2;
		if(max[tmp].val>max[big].val) big = tmp;
		tmp = loc*2+1;
		if(tmp<=maxS && max[tmp].val>max[big].val) big = tmp;
		
		if(big!=loc)
		{
			swap(&max[big], &max[loc]);
			loc = big;
		}
		else break;
	}
}

int main()
{
	int T, N, num, i, j;
	char cmd;
	
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		scanf("%d", &N);
		
		Qsize = 0;  // 전체 자료의 개수 
		
		min = (HEAP*)calloc(N, sizeof(HEAP));
		min[0].val = -2147483648; minS = 0;
		
		max = (HEAP*)calloc(N, sizeof(HEAP));
		max[0].val = 2147483647; maxS = 0;
		
		data = (char*)calloc(N, sizeof(char));
		for(j=0;j<N;j++) data[j] = 0;
		
		for(j=0;j<N;j++)
		{
			scanf(" %c %d", &cmd, &num);
			
			if(cmd=='I')
			{
				data[j] = 1;
				insert(num, j);  // 값과 순서를 함께 저장 
				Qsize++;
			}
			else
			{
				if(!Qsize)  // 자료 개수가 0인데 지우는 명령이면 무시 
				{
					minS = maxS = 0;
					continue;
				}
				while(!data[min[1].ord] && minS>0) removeMin();  // 이미 지워진 
				while(!data[max[1].ord] && maxS>0) removeMax();  // 쌓여있는 자료 지우기 
				
				if(num==-1) removeMin();
				else removeMax();
				Qsize--;
			}
		}
		
		if(Qsize)
		{
			while(!data[min[1].ord]) removeMin();
			while(!data[max[1].ord]) removeMax();  // 쌓여있는 자료 지우기 
			printf("%d %d\n", max[1].val, min[1].val);
		}
		else printf("EMPTY\n");
		
		free(min);
		free(max);
		free(data);
	}
	
	return 0;
}
