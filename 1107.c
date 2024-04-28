#include <stdio.h>
#include <math.h>

int main()
{
	int target, N, numBroken, minPress = 0, butSet = 0;
	int num, min, maxBut=9, minBut=0, digit = 0, i, j;
	int remocon[10] = { 0 };  // 버튼 고장 여부 저장. 0-정상, 1-고장
	
	scanf("%d", &target);
	N = target;
	
	scanf("%d", &numBroken);
	if(numBroken>0)
	{
		for(i=0;i<numBroken;i++)
		{
			scanf("%d", &num);
			remocon[num]++;
		}	
		while(remocon[maxBut]==1) maxBut--;  // 누를 수 있는 가장 큰 숫자 
		while(remocon[minBut]==1) minBut++;  // 누를 수 있는 가장 작은 숫자 
	}
	
	while(target%(int)pow(10, ++digit)!=target);  // target 자리수 계산

	for(i=digit;i>=1;i--)
	{
		num = target/(int)pow(10,i-1);  // i번째 자리수 숫자
		min = minBut;
		if(i==digit) min = 0;
		for(j=minBut;j<=maxBut;j++)
		{
			if(remocon[j]==1) continue;

			if(j==num)
			{
				min = j;
				break;
			}
			min = abs(target-min*pow(10, i-1))<abs(target-j*pow(10, i-1)) ? min:j;
		}
		if(min!=0)
		{
			butSet += min*pow(10, i-1);
		}
		minPress++;
		target %= (int)pow(10, i-1);
		
		if(min>num)
		{
			for(j=0;j<i-1;j++)
			{
				butSet += minBut*pow(10, j);
				minPress++;
			}
			break;
		}
		if(min<num)
		{
			for(j=0;j<i-1;j++)
			{
				butSet += maxBut*pow(10, j);
				minPress++;
			}
			break;
		}
	}
	minPress += abs(N-butSet);
	
	minPress = minPress<abs(N-100) ? minPress:abs(N-100);
	printf("%d", minPress);
	
	return 0;
}
