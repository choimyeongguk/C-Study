#include <stdio.h>

// 배열 안 단어의 길이 반환. <string.h>의 strlen 함수로 대체 가능 
int len(char* word)
{
	int length = 0;
	while(*(word+length)!='\0') length++;
	return length;
} 

// 순행이면 1, 역순행이면 -1, 같으면 0. <string.h>의 strcmp 함수로 대체 가능 
int wordCheck(char* word1, char* word2)
{
	int num = 0;
	while(*(word1+num)!='\0')
	{
		if(*(word1+num)<*(word2+num)) return 1;
		if(*(word1+num)>*(word2+num)) return -1;
		num++;
	}
	return 0;
}

void merge(char* word, int left, int mid, int right)
{
	char sort[20000][51] = {0,};
	int l = left;
	int r = mid+1;
	int index = 0;
	int i;
	
	while(l<=mid && r<=right)
	{
		if(len(word+l*51)<len(word+r*51))
		{
			for(i=0;i<=len(word+l*51);i++) sort[index][i] = *(word+l*51+i);
			l++; index++;
		}
		else if(len(word+l*51)>len(word+r*51))
		{
			for(i=0;i<=len(word+r*51);i++) sort[index][i] = *(word+r*51+i);
			r++; index++;
		}
		else
		{
			if(wordCheck(word+l*51, word+r*51)==1)
			{
				for(i=0;i<=len(word+l*51);i++) sort[index][i] = *(word+l*51+i);
				l++; index++;
			}
			else
			{
				for(i=0;i<=len(word+r*51);i++) sort[index][i] = *(word+r*51+i);
				r++; index++;
			}
		}
	}
	
	while(l<=mid)
	{
		for(i=0;i<=len(word+l*51);i++) sort[index][i] = *(word+l*51+i);
		l++; index++;
	}
	while(r<=right)
	{
		for(i=0;i<=len(word+r*51);i++) sort[index][i] = *(word+r*51+i);
		r++; index++;
	}
	
	index--;
	while(index>=0)
	{
//		for(i=0;i<=len(sort+index*51);i++)
		for(i=0;i<=len(sort[index]);i++) *(word+(index+left)*51+i) = sort[index][i];
		index--;
	}
}

void mergeSort(char* word, int left, int right)
{
	int mid;
	if(left<right)
	{
		mid = (left+right)/2;
		mergeSort(word, left, mid);
		mergeSort(word, mid+1, right);
		merge(word, left, mid, right);
	}
}

int main()
{
	int N, i;
	char word[20000][51] = {0,};
	
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%s", word[i]);
	
	mergeSort(word, 0, N-1);
	
	for(i=0;i<N;i++)
	{
		if(len(word[i])!=len(word[i+1]) || wordCheck(word[i], word[i+1])!=0)
		{
			printf("%s\n", word[i]);
		}
	}
	
	
	return 0;
}
