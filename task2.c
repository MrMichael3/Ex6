// Michael Küchler, 16-924-318

#include <stdio.h>
#include <stdlib.h>

struct tuple{
	int val;
	int k;
};
struct tuple m[60][60];

//get the previous maximum
struct tuple maxPrev(int buy){
	struct tuple max;
	max.val = 0;
	max.k = 0;
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
int maxProfit(int price[], int n, int k){
	int max = 0;
	for(int b=0;b<n-1;b++){
		for(int s=b+1;s<n;s++){
			//add if greater than previous max and k limitation isnt reached
			if(price[s]-price[b] + maxPrev(b).val > max && maxPrev(b).k + 1 <= k){
				max = price[s]-price[b]+maxPrev(b).val;
				m[b][s].val = max;
				m[b][s].k = maxPrev(b).k + 1;
			}
		}
	}
	return max;
}

int main(){
	//Example from task sheet
	
	int price1[8] = {12,14,17,10,14,13,12,15};
	int n1 = 8;
	int k1 = 3;
	int profit1 = maxProfit(price1,n1,k1);
	printf("maxProfit: %d\n",profit1);

	//User input
	
	int price[50];
	int k;
	int n=0;
	printf("How much transactions (k)?\n");
	scanf("%i",&k);
	printf("Enter all prices: \n");
	while(scanf("%d",&price[n])){
		n++;
	}
	int profit = maxProfit(price,n,k);
	printf("maxProfit: %d\n",profit);
	
	return 0;
}
