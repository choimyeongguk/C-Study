#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 500000

int main()
{
	int N, numBroken, tmp, len, i, j;
	int l, r, numL=0, numR=0, minBut = 0, maxBut = 9, chk = 0;
	int minPress, minPressL = MAX, minPressR = MAX; 
	char target[7];
	char minSet[7], minSetL[7], minSetR[7];
	char remocon[10] = { 0 };
	
	scanf("%s", target);
	len = strlen(target);
	for(N=0, i=0;i<len;i++)  // 목표 번호를 정수형으로 변환 
	{
		N += (target[i]-48) * pow(10, len-i-1);
	}
	
	scanf("%d", &numBroken);
	if(numBroken>0)
	{
		for(i=0;i<numBroken;i++)
		{
			scanf("%d", &tmp);
			remocon[tmp] = 1;  // 고장난 버튼 저장 
		}
		while(remocon[minBut]==1) minBut++;  // 누를 수 있는 가장 작은 버튼 
		while(remocon[maxBut]==1) maxBut--;  // 누를 수 있는 가장 큰 버튼 
	}
	
	for(i=0;i<len;i++)
	{
		if(remocon[target[i]-48]==0)  // 사용 가능 
		{
			minSet[i] = target[i];
			minSetL[i] = target[i];
			minSetR[i] = target[i];
		}
		else  // 사용 불가능 -> 해당 숫자보다 작은 경우와 큰 경우로 나누어 생각 
		{
			l = target[i]-48; r = l;
			
			while(remocon[l]==1)
			{
				l--;
				if(l<0) break; 
			}
			while(remocon[r]==1)
			{
				r++;
				if(r>9)
				{
					r = -1;
					break;
				}
			}
			
			if(l<0 && r<0)
			{
				chk = -1;
				break;
			}
			
			if(l>=0)  // 왼쪽에 수가 존재하는 경우 
			{
				minSetL[i] = l+48;
				for(j=1;j<=len-i-1;j++)
				{
					minSetL[i+j] = maxBut+48;
				}
			}
			if(r>=0)  // 오른쪽에 존재하는 경우 
			{
				minSetR[i] = r+48;
				for(j=1;j<=len-i-1;j++)
				{
					minSetR[i+j] = minBut+48;
				}
			}
			chk = 1;
			break;
		}
	}
	
	if(chk==0)  // 숫자 버튼 만으로 target을 만들 수 있는 경우 
	{
		tmp = abs(N-100);
		minPress = len<tmp ? len:tmp;
	}
	else if(chk==1)  // left와 right로 갈라진 경우 
	{
		if(l>=0)
		{
			for(i=0;i<len;i++)
			{
				numL += (minSetL[i]-48) * pow(10, len-i-1);
			}
			minPressL = len + abs(N-numL);
			if(minSetL[0]=='0') minPressL--;
		
//			for(i=0;i<len;i++) printf("%c ", minSetL[i]);
//			printf(", numL = %d, minPressL = %d\n", numL, minPressL);
			
			for(tmp=0, i=0;i<len;i++)
			{
				if(minSetL[i]!='0')
				{
					tmp++;
					break;
				}
			}
			if(tmp==0) minPressL = 1 + N;
		}
		if(r>=0)
		{
			for(i=0;i<len;i++)
			{
				numR += (minSetR[i]-48) * pow(10, len-i-1);
			}
			minPressR = len + abs(N-numR);
			if(minSetR[0]=='0') minPressR--;
			
//			for(i=0;i<len;i++) printf("%c ", minSetR[i]);
//			printf(", numR = %d, minPressR = %d\n", numR, minPressR);
			
			for(tmp=0, i=0;i<len;i++)
			{
				if(minSetR[i]!='0')
				{
					tmp++;
					break;
				}
			}
			if(tmp==0) minPressL = 1 + N;
		}
		
		minPress = minPressL<minPressR ? minPressL:minPressR;
//		printf("minPressL = %d, minPressR = %d, minPress = %d\n", minPressL, minPressR, minPress);
		tmp = abs(N-100);
		minPress = minPress<tmp ? minPress:tmp;
//		printf("minPress = %d\n", minPress);
	}
	else minPress = abs(N-100);
	
	printf("%d", minPress);
	
	return 0;
}
