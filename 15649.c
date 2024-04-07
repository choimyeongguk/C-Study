#include <stdio.h>
#include <stdlib.h>

void permutation(short depth, short n, short m, short* arr, char* usedChk)
{	
	short i;
	
	if(depth == m)
	{
		for(i=0;i<m;i++) printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(usedChk[i]==0)
			{
				usedChk[i] = 1;
				arr[depth] = i;
				permutation(depth+1, n, m, arr, usedChk);
				usedChk[i] = 0;
			}
		}
	}
}

int main()
{
	short n, m;
	short* arr;
	char* usedChk;
	
	scanf("%d %d", &n, &m);
	
	arr = (short*)malloc(m*sizeof(short));  // 순열 수열을 저장할 배열 
	usedChk = (char*)malloc(n*sizeof(char));  // 숫자 사용 여부 저장할 배열 
	
	permutation(0, n, m, arr, usedChk);
	
	return 0;
}
