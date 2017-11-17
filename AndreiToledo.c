#include <stdio.h>

#define maxV 11
						 //a b c d e f g h i j k 
int graph[maxV][maxV] = {{0,1,0,0,0,0,0,1,0,0,0}, //a
						  {1,0,0,1,0,0,0,0,0,0,0}, //b
						  {0,0,0,1,0,0,0,0,0,0,0}, //c
						  {0,1,1,0,0,0,0,0,1,0,1}, //d
						  {0,0,0,0,0,1,0,0,0,0,1}, //e
						  {0,0,0,0,1,0,1,0,0,0,0}, //f
						  {0,0,0,0,0,1,0,1,0,0,1}, //g
						  {1,0,0,0,0,0,1,0,1,1,1}, //h
						  {0,0,0,1,0,0,0,1,0,1,0}, //i
						  {0,0,0,0,0,0,0,1,1,0,1}, //j
						  {0,0,0,1,1,0,1,1,0,1,0}  //k
						  };
						  
int degree[maxV]; //degree
int color[maxV];
int visited[maxV];
int order[maxV];

void sort(){ //ordenação
	int aux;
	for( int i=0; i < maxV; i++ ){
		for( int j = maxV - 1; j > i; j-- ){
			if( degree[order[j]] > degree[order[j-1]] ){ 
			aux = order[j];
			order[j] = order[j-1];
			order[j-1] = aux;
			}
		}	
	}
}

void countDegree(){
	int i,j;
	for(i = 0; i < maxV; i++){
		degree[i] = 0;
	}
	for(i = 0; i < maxV; i++){
		order[i] = i;
	}
	
	for(i = 0; i < maxV; i++){
		for(j = 0; j < maxV; j++){
			if(graph[i][j] == 1) degree[i] ++;
		}
		//printf("O grau do vértice %d é %d\n",i, degree[i]);
	}
	sort(i);
	for (i = 0; i < maxV; i++){
		printf(" %d,", order[i]);
	}
}

int main(){
	countDegree();
	return 0;
}