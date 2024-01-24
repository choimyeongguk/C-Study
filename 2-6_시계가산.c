#include <stdio.h>

int main()
{
	int time, t_H, t_M;  //가산 시간, 시간, 분 
	int crtH, crtM, finH, finM;  //현재 시간, 현재 분, 마침 시간, 마침 분 
	scanf("%d %d", &crtH, &crtM);
	scanf("%d", &time);
	
	t_H = time/60;  //가산 시간을 시간과 분으로 나눠준다. int형이므로 소수점은 날아감 
	t_M = time - t_H*60;
	
	finH = crtH + t_H;  //단순 가산 
	finM = crtM + t_M;
	
	finH += finM/60;  //분에서 이월되는 만큼 가산 
	finM -= (finM/60)*60;  //시간으로 이월되는 만큼 감산 
	
	finH = finH%24;  //감산된 마침 시간 0~23 범위로 조정 
	
	printf("%d %d", finH, finM);
	
	return 0;
}
