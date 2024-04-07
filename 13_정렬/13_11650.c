#include <stdio.h>

void merge(int* x, int* y, int left, int mid, int right)
{
	int arrX[100000];
	int arrY[100000];
	int l = left;
	int r = mid+1;
	int index = 0;
	
	while(l <= mid && r <= right)
	{
		if(x[l] < x[r])
        {	
			arrX[index] = x[l];
			arrY[index] = y[l];
            index++;
			l++;
		}
		else if(x[l] == x[r] && y[l] < y[r])
		{
			arrX[index] = x[l];
			arrY[index] = y[l];
			index++;
			l++;
			
		}
		else
        {	arrX[index] = x[r];
        	arrY[index] = y[r];
            index++;
			r++;
		}
	}
	
	while(l <= mid)
    {	
		arrX[index] = x[l];
		arrY[index] = y[l];
        index++;
		l++;
	}
	while(r <= right)
    {	
		arrX[index] = x[r];
    	arrY[index] = y[r];
        index++;
		r++;
	}
	index--;
	
	while(index >= 0)
	{
		x[left + index] = arrX[index];
		y[left + index] = arrY[index];
		index--;
	}
}

void mergeSort(int* x, int* y, int left, int right)
{
	int mid;
	if(left<right)
	{
		mid = (left+right)/2;
		mergeSort(x, y, left, mid);
		mergeSort(x, y, mid+1, right);
		merge(x, y, left, mid, right);
	}
}

int main()
{
	int N, i;
	int x[100000];
	int y[100000];
	
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%d %d", &x[i], &y[i]);
	
	mergeSort(x, y, 0, N-1);
	
	for(i=0;i<N;i++) printf("%d %d\n", x[i], y[i]);
	
	return 0;
}
