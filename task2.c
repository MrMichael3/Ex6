// Michael Küchler, 16-924-318

#include <stdio.h>
#include <stdlib.h>

struct tuple{
	int val;
	int k;
};
//matrix buy x sell
struct tuple m[60][60];

//get the previous maximum
struct tuple maxPrev(int buy){
	struct tuple max;
	max.val = 0;
	max.k = 0;
	//try top-down to improve algorithm
	for(int b=0;b<buy-1;b++){
		for(int s=b+1;s<buy;s++){
			if(m[b][s].val > max.val){
				max.val = m[b][s].val;
				max.k = m[b][s].k;
			}
		}
	}
	return max;
}
//solution without buy limitation (k)
int maxProfitLight(int price[], int n, int k){
	int max = 0;
	int isChanged = 0;
	for(int b=0;b<n-1;b++){
		for(int s=b+1;s<n;s++){
			if(price[s]-price[b] + maxPrev(b).val > max){
				//isChanged = 1;
				max = price[s]-price[b]+maxPrev(b).val;
				m[b][s].val = max;
				m[b][s].k = maxPrev(b).k + 1;
				printf("max: %d in [%d][%d]\n",max,b,s);
			}
		}
		/*if(isChanged){
			k--;
			isChanged = 0;
			if(k<= 0){
				return max;
			}
		}*/
	}
	return max;
}
/*
int maxProfit(int price[], int n, int k){
	int max;
	
	for(int x=1;x<=k;x++){
		for(int b=0;b<n-1;b++){
			max = 0;
			for(int s=b+1;s<n;s++){
				if(price[s]-price[b]>max){
					max = price[s]-price[b];
					printf("max: %d in [%d][%d]\n",max,b,s);
					m[b][s] = max;
				}
			}
			
		}
	}
	return maxPrev(n);
}*/

int main(){
	int price[8] = {12,14,17,10,14,13,12,15};
	int n = 8;
	int k = 3;
	int profit = maxProfitLight(price,n,k);
	//profit = maxProfitLight(price,n);
	printf("maxProfit: %d\n",profit);
	
	
	/*int price[50];
	int k;
	int n=0;
	printf("How much transactions (k)?\n");
	scanf("%i",&k);
	printf("Enter all prices: \n");
	while(scanf("%d",&price[n])){
		n++;
	}
	int profit = maxProfit(price,n,k);
	printf("maxProfit: %d\n",profit);*/
	return 0;
}
