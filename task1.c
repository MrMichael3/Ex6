// Michael Küchler, 16-924-318

#include <stdio.h>
#include <stdlib.h>

int m[50][501];
void init(){
	for(int i=0;i<50;i++){
		for(int j=0;j<501;j++){
			m[i][j] = -1;
		}
	}
}

int knapsackRecursive(int capacity, int mass[], int profit[], int n){
	if (n<0 || capacity <= 0){
		return 0;
	}
	//profit without n
	int without = knapsackRecursive(capacity,mass,profit,n-1);
	if(mass[n] <= capacity){
		int newCapacity = capacity - mass[n];
		//profit with n
		int with = profit[n] + knapsackRecursive(newCapacity,mass,profit, n-1);
		if(with > without){
			return with;
		}
	}
	return without;
}

int knapsackMemoized(int capacity, int mass[], int profit[], int n){
	if(m[n][capacity] >= 0){
		return m[n][capacity];
	}
	if (n<0 || capacity <= 0){
		return 0;
	}
	int without = knapsackMemoized(capacity,mass,profit,n-1);
	if(mass[n] <= capacity){
		int newCapacity = capacity - mass[n];
		int with = profit[n] + knapsackMemoized(newCapacity,mass,profit,n-1);	
	
		if(with > without){
			m[n][capacity] = with;
			return with;
		}	
	}
	m[n][capacity] = without;
	return without;
}
int knapsackDynamic(int capacity, int mass[], int profit[], int n){
	for(int i = 0;i<=n;i++){ 
		for(int j = 0;j<=capacity;j++){
			if(j == 0 || i == 0){
				m[i][j] = 0;
			}
			/*
			int without = m[i-1][j];
			//check if item has enough space
			if(mass[i] <= j){
				int newCapacity = j - mass[i];
				int with = profit[i] + m[i-1][newCapacity];
				//store max value
				m[i][j] = with;
			}
			if(m[i][j] < without){
				m[i][j] = without;
			}*/
			if(mass[i] <=j){
				int newCapacity = j - mass[i];
				int with = profit[i] + m[i-1][newCapacity];
				int without = m[i-1][j];
				if(with>without){
					m[i][j] = with;
				}
				else{
					m[i][j] = without;
				}
			}
		}
	}
	return m[n][capacity];
}

int main(){
	time_t t;
	srand((unsigned) time(&t));
	//create the knapsacks
	int mass1[4] = {6,3,2,4};
	int profit1[4] = {50,60,40,20};
	int n1 = 4;
	int capacity1 = 10;
	
	int mass2[10] = {23,31,29,44,53,58,63,85,89,82};
	int profit2[10] = {92,57,49,68,60,43,67,84,87,72};
	int n2 = 10;
	int capacity2 = 165;
	
	int mass3[50];
	for(int i = 0;i<50;i++){
		mass3[i] = rand() % 100 + 1;
	}
	int profit3[50];
	for(int i = 0;i<50;i++){
		profit3[i] = rand() % 100 + 1;
	}
	int n3 = 50;
	int capacity3 = 500;
// A) Recursive
	printf("Recursive Way:\n");
	
	int profitRecursive1 = knapsackRecursive(capacity1, mass1, profit1, n1-1);
	printf("max profit 1: %d\n",profitRecursive1);
	
	int profitRecursive2 = knapsackRecursive(capacity2, mass2, profit2, n2-1);
	printf("max profit 2: %d\n",profitRecursive2);
	
	//doesn't terminates!
	/* 
	int profitRecursive3 = knapsackRecursive(capacity3, mass3, profit3, n3);
	printf("max profit 3: %d\n",profitRecursive3);
	*/
// B) Memoized	
	printf("Memoized Way:\n");
	
	init();
	int profitMemoized1 = knapsackMemoized(capacity1,mass1,profit1,n1-1);
	printf("max profit: %d\n",profitMemoized1);
	
	init();
	int profitMemoized2 = knapsackMemoized(capacity2,mass2,profit2,n2-1);
	printf("max profit: %d\n",profitMemoized2);
	
	init();
	int profitMemoized3 = knapsackMemoized(capacity3,mass3,profit3,n3-1);
	printf("max profit: %d\n",profitMemoized3);
// C) Dynamic	
	printf("Dynamic Way:\n");
	
	init();
	int profitDynamic1 = knapsackDynamic(capacity1,mass1,profit1,n1-1);
	printf("max profit: %d\n",profitDynamic1);
	
	init();
	int profitDynamic2 = knapsackDynamic(capacity2,mass2,profit2,n2-1);
	printf("max profit: %d\n",profitDynamic2);
	
	init();
	int profitDynamic3 = knapsackDynamic(capacity3,mass3,profit3,n3-1);
	printf("max profit: %d\n",profitDynamic3);
	
	
	return 0;
}

