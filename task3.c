// Michael Küchler, 16-924-318

#include <stdio.h>
#include <stdlib.h>

struct vertex{
	int inhabited;
	int color; // 0: white, 1: grey, 2: black
	struct vertex *pre;
};
struct vertex *m[5][5];
int n = 5;
int time = 0;

void visit(int a, int b){
	//change to grey
	m[a][b]->color = 1;
	//search for adjacency
	for(int i=a-1;i<a+2;i++){
		for(int j=b-1;j<b+2;j++){
			//check if m[i][j] is still in the matrix
			if(i<5 && i>=0 && j<5 && j>=0){
				//if color is white and inhabited
				if(m[i][j]->color == 0 && m[i][j]->inhabited == 1){
					m[i][j]->pre = m[a][b];
					visit(i,j);
				}
			}
		}
	}
	m[a][b]->color = 2;
	
	
}
int countEcosystems(){
	int counter = 0;
	//all vertex white and pre is NIL
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			m[i][j]->color = 0;
			m[i][j]->pre = NULL;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//if white and inhabited: start of new tree
			if(m[i][j]->color == 0 && m[i][j]->inhabited == 1){
				counter++;
				visit(i,j);
			}
		}
	}
	return counter;
}








int main(){
	m[0][0]->inhabited = 1;m[0][1]->inhabited = 1;m[0][2]->inhabited = 0;m[0][3]->inhabited = 0;m[0][4]->inhabited = 1;
	m[1][0]->inhabited = 0;m[1][1]->inhabited = 1;m[1][2]->inhabited = 0;m[1][3]->inhabited = 0;m[1][4]->inhabited = 0;
	m[2][0]->inhabited = 1;m[2][1]->inhabited = 0;m[2][2]->inhabited = 0;m[2][3]->inhabited = 1;m[2][4]->inhabited = 1;
	m[3][0]->inhabited = 0;m[3][1]->inhabited = 0;m[3][2]->inhabited = 0;m[3][3]->inhabited = 0;m[3][4]->inhabited = 0;
	m[4][0]->inhabited = 1;m[4][1]->inhabited = 0;m[4][2]->inhabited = 1;m[4][3]->inhabited = 0;m[4][4]->inhabited = 1;
	int c = countEcosystems();
	printf("# distinct ecosystems: %d\n",c);
	return 0;
}
