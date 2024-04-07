#include <stdio.h>

int main()
{
	int N, index, i, j;
	char PS[51];
	char stack[26];

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		j = 0;
		index = 0;
		scanf("%s", PS);

		stack[index++] = PS[0]; // ù ��° ���� �־��ش�
		while (PS[++j] != '\0') // ���ڿ��� ���̸�ŭ �ݺ�
		{
			if (stack[top - 1] == '(' && PS[j] == ')')
				index--; // '('�� ')'�� ���޾� ���´ٸ� ������ �� ĭ �����
			else
				stack[index++] = PS[j]; // �ƴ϶�� ������ �� ĭ ä���
		}

		if (!index)
			printf("YES\n"); // �������� ���ÿ� ���� ���ٸ� ���� ����
		else
			printf("NO\n");
	}

	return 0;
}
