#include <stdio.h>

int main()
{
	int N, i;
	int winner[1001];
	
	scanf("%d", &N);
	
	winner[1] = winner[3] = winner[4] = winner[5] = 0;  // 선수(상근)이 이김 
	winner[2] = 1;  // 후수(창영)이 이김 
	
	for(i=6;i<=N;i++)
	{ㄹ 
		if(winner[i-1]==1 || winner[i-3]==1 || winner[i-4]==1) winner[i] = 0;
		else winner[i] = 1;
	}
	
	// 풀이 :
	//  winner[N] = 0 -> 선수가 이김, winner[N] = 1 -> 후수가 이김 
	//  만약 돌이 M개 있고 상근이 선수일 때, 상근은 돌을 1개, 3개, 4개 가져갈 수 있다.
	//  각각의 경우에 대해 winner[M-1], winner[M-3], winner[M-4]의 경우가 정해질 것이다.
	//  각 경우에 대해 상근이 후수, 창영이 선수로 위치가 뒤바뀌게 된다.
	//  즉 winner[M-1], winner[M-3], winner[M-4] 중에 후수(상근)가 이기는 경우가 있어야만
	//  상근이 그것을 선택해서 최종적으로 winner[M]에서 이길 수 있는 것이다. 
	
	//  요약 : 1개, 3개, 4개를 선택한 경우에 대해 선수와 후수의 위치가 뒤바뀌어 게임을 처음부터 한다고 생각해보자. 
	
	printf("%s", winner[N] ? "CY":"SK");
	
	return 0;
}
