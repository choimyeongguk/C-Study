#include <stdio.h>

int main()
{
	int time, t_H, t_M;  //���� �ð�, �ð�, �� 
	int crtH, crtM, finH, finM;  //���� �ð�, ���� ��, ��ħ �ð�, ��ħ �� 
	scanf("%d %d", &crtH, &crtM);
	scanf("%d", &time);
	
	t_H = time/60;  //���� �ð��� �ð��� ������ �����ش�. int���̹Ƿ� �Ҽ����� ���ư� 
	t_M = time - t_H*60;
	
	finH = crtH + t_H;  //�ܼ� ���� 
	finM = crtM + t_M;
	
	finH += finM/60;  //�п��� �̿��Ǵ� ��ŭ ���� 
	finM -= (finM/60)*60;  //�ð����� �̿��Ǵ� ��ŭ ���� 
	
	finH = finH%24;  //����� ��ħ �ð� 0~23 ������ ���� 
	
	printf("%d %d", finH, finM);
	
	return 0;
}
