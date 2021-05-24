#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <tchar.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include <math.h>
#include <time.h>
#include<iostream>

using namespace std;

void Swap(int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}


int Partition(int p, int r, int A[])
{
	int x, q, s;

	x = A[p];
	q = p;

	for (s = p + 1; s < r; s++) {
		if (A[s] < x) {
			q = q + 1;
			Swap(A[q], A[s]);
		}
	}

	Swap(A[p], A[q]);

	return q;
}

void QuickSort(int p, int r, int A[])
{
	int i, q;

	if (r <= p)
		return;

	i = rand() % (r - p + 1) + p;

	Swap(A[i], A[p]);

	q = Partition(q, r, A);
	QuickSort(p, q - 1, A);
	QuickSort(q + 1, r, A);
}

void BubbleSort(int size, int A[])
{
	int i, j;

	for (i = 1; i < size - 1; i++)
		for (j = i + 1; j < size; j++)
			if (A[i] > A[j])
				Swap(A[i], A[j]);
}

int main()
{
	srand( (unsigned)time( NULL ) );//usklaðivanje rand generatora sa sistemskim vremennom
	FILE  *file1,*file2;
	int vrijeme1,vrijeme2; 
	int i,size;
	

	printf("Unesi velicinu niza\n");
	scanf("%d",&size);
	
	//generiranje niza
	int *A=(int*)malloc(size*sizeof(int));
	for(i=0;i<size;i++)
			A[i]=rand() % 100;

	vrijeme1=GetTickCount();
	//pokreni quick sort
	
	vrijeme2=GetTickCount();
	// ispiši vrijeme sortiranja
	printf("vrijeme1:%d\n",vrijeme2-vrijeme1);
	
	//ispis u file
	file1 = fopen( "OutputQuickSort.txt", "w" );
	for(i=0;i<size;i=i++)
		fprintf(file1, "%d\n",A[i]);
	fclose(file1);
	
	//ponovno generiranje niza, pokretanje bubble sorta, ispis vremena i sortiranog niza u txt file

	free(A);
	return 0;
}