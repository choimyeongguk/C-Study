#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b)
{
	return *a - *b;
}

void grouping(char** map, int row, int col, int N, int groupNum, int* complex)
{
	if(row>0 && map[row-1][col]=='1')  // ���ʿ� �׷��� ���� ���� ���� ���� 
	{
		complex[groupNum]++;  // �׷� ���� +1 
		map[row-1][col] += groupNum+1;  // �׷� ��ȣ �ű�� 
		grouping(map, row-1, col, N, groupNum, complex);  // ���� �������� �ٽ� ���� 
	}
	if(col>0 && map[row][col-1]=='1')  // ���ʿ� �׷��� ���� ���� ���� ���� 
	{
		complex[groupNum]++;
		map[row][col-1] += groupNum+1;
		grouping(map, row, col-1, N, groupNum, complex); 
	}
	if(row<N-1 && map[row+1][col]=='1')  // �Ʒ��ʿ� �׷��� ���� ���� ���� ���� 
	{
		complex[groupNum]++;
		map[row+1][col] += groupNum+1;
		grouping(map, row+1, col, N, groupNum, complex); 
	}
	if(col<N-1 && map[row][col+1]=='1')  // �����ʿ� �׷��� ���� ���� ���� ���� 
	{
		complex[groupNum]++;
		map[row][col+1] += groupNum+1;
		grouping(map, row, col+1, N, groupNum, complex);
	}	
}

int main()
{
	int N, i, j;
	int groupNum = 0;  // �׷��� ���� 
	int* complex;  // ���� ��ȣ�� ���� ������ ���� 
	char** map;  // ���� ������ �迭 
	
	scanf("%d", &N);  // ���� ũ�� �Է� 
	
	complex = (int*)malloc(((N*N+1)/2)*sizeof(int));  // �־��� ��� ������ �׷� ���� �����Ҵ� 
	for(i=0;i<(N*N+1)/2;i++) complex[i] = 0;
	
	map = (char**)malloc(N*sizeof(char*));  // ���� ������ �迭 �����Ҵ� 
	for(i=0;i<N;i++) map[i] = (char*)malloc(N*sizeof(char));
	for(i=0;i<N;i++) scanf("%s", map[i]);  // ���� �Է� 
	
	for(i=0;i<N;i++)  // i�� 
	{
		for(j=0;j<N;j++)  // j�� 
		{
			if(map[i][j]=='1')  // �׷��ε��� ���� ���� �߰� 
			{
				complex[groupNum]++;  // �׷� �߰� ��, ���� �� 1�� ���� 
				map[i][j] += groupNum+1;  // �׷� ��ȣ �ű��. �׷� ��ȣ�� 0���� ���� 
				grouping(map, i, j, N, groupNum, complex);  // ������ ���� �׷��� 
				groupNum++;  // �׷� ���� 1���� 
			}
		}
	}
	
	qsort(complex, groupNum, sizeof(int), compare);  // �׷캰 ������ ���� 
	
	printf("%d\n", groupNum);
	for(i=0;i<groupNum;i++) printf("%d\n", complex[i]);  // �׷캰 ������ ��� 
	
	for(i=0;i<N;i++) free(map[i]);  // ������ �迭 �޸� ���� 
	free(map);
	return 0;
}
