// 입력에서 방향에 관한 정보가 주어지지 않음 -> 연결 리스트가 아닌 행렬를 이용해 구현하자!
#include <stdio.h>
#include <stdlib.h>

void relationSet(char** tree, int parentNode, int N)
{
	int i;
	
	//부모 행에 연결된 자식 노드 탐색 
	for(i=1;i<=N;i++)
	{
		if(tree[parentNode][i]==1)  // 부모->자식 연결쌍 발견 
		{
			tree[i][parentNode] = 0;  // 자식->부모 연결쌍 삭제 
			relationSet(tree, i, N);  // 찾은 자식을 다시 부모로 설정하고 함수 호출 
		}
	}
}

int main()
{
	int N, a, b, i, j;
	char** tree;  // 트리의 구조를 저장할 배열(행렬) 
	
	scanf("%d", &N);  // 트리 노드 개수 입력 
	tree = (char**)malloc((N+1)*sizeof(char*));  // 행렬 동적할당. 1부터 세는게 편하기 때문에 N+1개 할당 
	for(i=0;i<N+1;i++) tree[i] = (char*)malloc((N+1)*sizeof(char));
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) tree[i][j] = '\0';  // NULL로 초기화 
	
	for(i=0;i<N-1;i++)
	{
		scanf("%d %d", &a, &b);  // 두 노드 부모/자식 순서 상관없이 입력 
		tree[a][b]++;  // 행렬에 저장 
		tree[b][a]++;
	}
	
	relationSet(tree, 1, N);  // 부모/자식 관계 정리. 단순 사이클이 없는 그래프에서 트리로의 변환 
	
	for(j=2;j<=N;j++)  // 열(자식) 
	{
		for(i=1;i<=N;i++)  // 행(부모) 
		{
			if(tree[i][j]==1)
			{
				printf("%d\n", i);
				break;
			}
		} 
	}
	
	for(i=0;i<N+1;i++) free(tree[i]);
	free(tree);
	return 0;
} 
