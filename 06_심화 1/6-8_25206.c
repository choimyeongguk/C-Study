#include <stdio.h>

int main()
{
	int i;
	double credit_sum=0, grade_sum=0;	//������ ����, (����*��������)�� �� 
	double credit, score;	//����, �������� 
	char grade[3];
	char subject[51];
	
	for(i=0;i<20;i++)
	{
		scanf("%s %lf %s", &subject, &credit, &grade);
		if(grade[0]!='P') 
		{
		if(grade[0]=='A'&&grade[1]=='+') score = 4.5f;
		if(grade[0]=='A'&&grade[1]=='0') score = 4.0f;
		if(grade[0]=='B'&&grade[1]=='+') score = 3.5f;
		if(grade[0]=='B'&&grade[1]=='0') score = 3.0f;
		if(grade[0]=='C'&&grade[1]=='+') score = 2.5f;
		if(grade[0]=='C'&&grade[1]=='0') score = 2.0f;
		if(grade[0]=='D'&&grade[1]=='+') score = 1.5f;
		if(grade[0]=='D'&&grade[1]=='0') score = 1.0f;
		if(grade[0]=='F') score = 0.0f;
		
		credit_sum += credit;
		grade_sum += score*credit;
		}
		
		/*
		scanf("%s %lf %s", subject, &creadit, &grade);
		if(grade[0]=='P') continue;
		credit_sum += credit;
		if(grade[0]=='F) continue;	// ������ �����ְ� ���� ����� �н�
		
		if(grade[0]=='A') score = 4.0f;
		else if(grade[0]=='B') score = 3.0f;
		else if(grade[0]=='C') score = 2.0f;
		else score = 1;
		if(grade[1]=='+') score += 0.5f
		
		grade_sum += score*credit
		*/

	}
	printf("%f", grade_sum/credit_sum);
	
	return 0;
}
