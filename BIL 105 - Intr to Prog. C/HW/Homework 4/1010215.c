/*************************************************
 *   Erdinc Kandemir                             *
 *   150150110                                   *
 *   Homework 4                                  *
 *   CRN:22073                                   *
 *************************************************/
 #include <stdio.h>
#include <math.h>
#define PI 3.14159265358979												//define first .14 digits of pi
float basis[2][2];														
float point[1][2];
float procMat[2][2];													//defining global arrays for functions
void move(float procMat[][2]){						//move function
	int i,j;
	for (i=0; i<2; i++){							///simple matrix multiplication (SMM)
		for (j=0; j<2; j++){
			point[0][i]+= basis[i][j]*procMat[0][j];
			}
		}
	
}
	
void changeBasis(){														//function for asking andchanging basis
	scanf(" %f %f %f %f ", &basis[0][0], &basis[0][1], &basis[1][0], &basis[1][1] ); 
}
	
	
void rotateRight(degree){												//rotate right function
	int i,j,k;
	float sum=0;
	float roMat[2][2];
	roMat [0][0] = cos(degree*(PI/180));
	roMat [0][1] = sin(degree*(PI/180));
	roMat [1][0] = -sin(degree*(PI/180));
	roMat [1][1] = cos(degree*(PI/180));								///defining rotating matrix
	for (i=0; i<2; i++){												/// initiate temporary matrix
		for (j=0; j<2; j++){
			procMat[i][j]=0;
			}
		}
	for (i=0; i<2; i++){
		for (j=0; j<2; j++){
			for (k=0; k<2; k++){
				
				sum = sum + basis[i][k] * roMat[k][j]; 					///SMM
				}
				procMat[i][j] = sum;
				sum=0;
			}
		}
	
	for (i=0; i<2; i++){
		for (j=0; j<2; j++){
			basis[i][j]=procMat[i][j];
			}
		}
	}
	
void rotateLeft(degree){
	int i,j,k;
	float sum=0;
	float roMat[2][2];
	roMat [0][0] = cos(degree*(PI/180));
	roMat [0][1] = -sin(degree*(PI/180));
	roMat [1][0] = sin(degree*(PI/180));
	roMat [1][1] = cos(degree*(PI/180));
	for (i=0; i<2; i++){
		for (j=0; j<2; j++){
			procMat[i][j]=0;
			}
		}
	for (i=0; i<2; i++){
		for (j=0; j<2; j++){
			for (k=0; k<2; k++){
				
				sum = sum + basis[i][k] * roMat[k][j]; 					
				}
				procMat[i][j] = sum;
				sum=0;
			}
		}
	
	for (i=0; i<2; i++){
		for (j=0; j<2; j++){
			basis[i][j]=procMat[i][j];
			}
		}
	}


int main(){
	char proccess;
	float degree;
	int control = 1;
	basis[0][0] = 1; basis[0][1] = 0; basis[1][0] = 0; basis[1][1] = 1; ///initiate basis matrix
	point[0][0] = 0; point[1][0] = 0;									///initiate first point
	while ( (proccess = getchar()) && control){
		if(proccess == 'm'){											///---
			scanf(" %f %f ",&procMat[0][0], &procMat[0][1]);			
			move(procMat);												
																		
			}														
		if(proccess == 'c'){
			changeBasis();
			
			}															/// proccesses and calling functions
		if(proccess == 'r'){
			scanf(" %f ",&degree);
			rotateRight(degree);
			}
		if(proccess == 'l'){
			scanf(" %f ",&degree);
			rotateLeft(degree);
			
			}															///----
		if(proccess == 'd'){											///last print condition
			printf("Coordinates: %.2f %.2f",point[0][0],point[0][1]);
			control = 0;
			}
		
		
		}
	
	
	
	
	return 0;
	}
