// Michael Küchler, 16-924-318

#include <stdio.h>
#include <stdlib.h>

struct vertex{
	int inhabited;
	char color[5];
	struct vertex *pre;
};
struct vertex m[20][20];
int countEcosystems(){
	
	
	
	
	return 0;
}








int main(){
	m[0][0].inhabited = 1;m[0][1].inhabited = 1;m[0][2].inhabited = 0;m[0][3].inhabited = 0;m[0][4].inhabited = 1;
	m[1][0].inhabited = 0;m[1][1].inhabited = 1;m[1][2].inhabited = 0;m[1][3].inhabited = 0;m[1][4].inhabited = 0;
	m[2][0].inhabited = 1;m[2][1].inhabited = 0;m[2][2].inhabited = 0;m[2][3].inhabited = 1;m[2][4].inhabited = 1;
	m[3][0].inhabited = 0;m[3][1].inhabited = 0;m[3][2].inhabited = 0;m[3][3].inhabited = 0;m[3][4].inhabited = 0;
	m[4][0].inhabited = 1;m[4][1].inhabited = 0;m[4][2].inhabited = 1;m[4][3].inhabited = 0;m[4][4].inhabited = 1;
	
	return 0;
}
