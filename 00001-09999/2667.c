#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b)
{
	return *a - *b;
}

void grouping(char** map, int row, int col, int N, int groupNum, int* complex)
{
	if(row>0 && map[row-1][col]=='1')  // 위쪽에 그룹핑 되지 않은 가구 존재 
	{
		complex[groupNum]++;  // 그룹 개수 +1 
		map[row-1][col] += groupNum+1;  // 그룹 번호 매기기 
		grouping(map, row-1, col, N, groupNum, complex);  // 위쪽 가구에서 다시 조사 
	}
	if(col>0 && map[row][col-1]=='1')  // 왼쪽에 그룹핑 되지 않은 가구 존재 
	{
		complex[groupNum]++;
		map[row][col-1] += groupNum+1;
		grouping(map, row, col-1, N, groupNum, complex); 
	}
	if(row<N-1 && map[row+1][col]=='1')  // 아래쪽에 그룹핑 되지 않은 가구 존재 
	{
		complex[groupNum]++;
		map[row+1][col] += groupNum+1;
		grouping(map, row+1, col, N, groupNum, complex); 
	}
	if(col<N-1 && map[row][col+1]=='1')  // 오른쪽에 그룹핑 되지 않은 가구 존재 
	{
		complex[groupNum]++;
		map[row][col+1] += groupNum+1;
		grouping(map, row, col+1, N, groupNum, complex);
	}	
}

int main()
{
	int N, i, j;
	int groupNum = 0;  // 그룹의 개수 
	int* complex;  // 단지 번호에 따른 가구수 저장 
	char** map;  // 지도 이차원 배열 
	
	scanf("%d", &N);  // 지도 크기 입력 
	
	complex = (int*)malloc(((N*N+1)/2)*sizeof(int));  // 최악의 경우 상정한 그룹 개수 동적할당 
	for(i=0;i<(N*N+1)/2;i++) complex[i] = 0;
	
	map = (char**)malloc(N*sizeof(char*));  // 지도 이차원 배열 동적할당 
	for(i=0;i<N;i++) map[i] = (char*)malloc(N*sizeof(char));
	for(i=0;i<N;i++) scanf("%s", map[i]);  // 지도 입력 
	
	for(i=0;i<N;i++)  // i행 
	{
		for(j=0;j<N;j++)  // j열 
		{
			if(map[i][j]=='1')  // 그룹핑되지 않은 가구 발견 
			{
				complex[groupNum]++;  // 그룹 추가 후, 가구 수 1개 저장 
				map[i][j] += groupNum+1;  // 그룹 번호 매기기. 그룹 번호는 0부터 시작 
				grouping(map, i, j, N, groupNum, complex);  // 주위의 가구 그룹핑 
				groupNum++;  // 그룹 개수 1증가 
			}
		}
	}
	
	qsort(complex, groupNum, sizeof(int), compare);  // 그룹별 가구수 정렬 
	
	printf("%d\n", groupNum);
	for(i=0;i<groupNum;i++) printf("%d\n", complex[i]);  // 그룹별 가구수 출력 
	
	for(i=0;i<N;i++) free(map[i]);  // 이차원 배열 메모리 해제 
	free(map);
	return 0;
}
