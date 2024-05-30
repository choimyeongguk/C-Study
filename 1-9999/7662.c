#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int val;
	int ord;
} HEAP;

HEAP* min; int minS;  // �ּ���. ���� ���� �Է� ������ ���� ���� 
HEAP* max; int maxS;  // �ִ��� 
char* data;  // ��ɾ� �Է� ������ �� ����. �ش� ������ ���� �ԷµǾ����� 1, ���� �Ǿ����� 0 
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
		
		Qsize = 0;  // ��ü �ڷ��� ���� 
		
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
				insert(num, j);  // ���� ������ �Բ� ���� 
				Qsize++;
			}
			else
			{
				if(!Qsize)  // �ڷ� ������ 0�ε� ����� ����̸� ���� 
				{
					minS = maxS = 0;
					continue;
				}
				while(!data[min[1].ord] && minS>0) removeMin();  // �̹� ������ 
				while(!data[max[1].ord] && maxS>0) removeMax();  // �׿��ִ� �ڷ� ����� 
				
				if(num==-1) removeMin();
				else removeMax();
				Qsize--;
			}
		}
		
		if(Qsize)
		{
			while(!data[min[1].ord]) removeMin();
			while(!data[max[1].ord]) removeMax();  // �׿��ִ� �ڷ� ����� 
			printf("%d %d\n", max[1].val, min[1].val);
		}
		else printf("EMPTY\n");
		
		free(min);
		free(max);
		free(data);
	}
	
	return 0;
}
