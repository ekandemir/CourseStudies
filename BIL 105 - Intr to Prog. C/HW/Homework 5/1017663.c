/*************************************************
 *   Erdinc Kandemir                             *
 *   150150110                                   *
 *   Homework 5                                  *
 *   CRN:22073                                   *
 *************************************************/

#include <stdio.h>
#include <stdlib.h>
int checkCoruption(char *check, int min, int max, int n){						//check function parameters: array|min ascii val|max ascii val
	int i;
	for (i=0; i<n; i++){
		if (*(check+i)>max || *(check+i)<min){
			return 0;
			}
		}
	return 1;
	
	}
	





int* decryptAuxiliaries(char *auxA, int *aux2f){						//auxiliaries function return mode and modifier as an array
	if(checkCoruption(auxA, 48, 49,2)==1){
	
		aux2f[0]=((*(auxA+0))-48)*2+(*(auxA+1)-48);
		aux2f[1]=((*(auxA+2))-48)*4+((*(auxA+3))-48)*2+((*(auxA+4))-48);//very simple solution to binary to decimal
		return aux2f;
		}
	return NULL;
	}
	
	
char* decryptName(char *name, int *auxA){
	if(checkCoruption(name, 97, 122,10)==1 && auxA!=NULL){
		int a;
		int temp;
		switch((*(auxA))){												//modes
			case 0:{
				break;
				}
			case 1:{
				for(a=0; a<10; a++){
					*(name+a)=((((*(name+a))-(*(auxA+1)))-71)%26)+97;	//mode:1 = "modify" steps backward
					}
				break;
				}
			case 2:{
				for(a=0; a<10; a++){
					*(name+a)=((((*(name+a))+(*(auxA+1)))-97)%26)+97;	//mode:2 = "modify" steps forward
					}
				break;
				}
			case 3:{
				for(a=0; a<5; a++){										//mode:3 = reverse
					temp=*(name+a);
					*(name+a)=*(name+(9-a));
					*(name+(9-a))= temp;
					}
				break;
				}			
			}
		return name;
		}
	return NULL;
	}
char* decryptNumber(char* number){
	if(checkCoruption(number, 48, 57,9)==1){
		int a,b;
		int** number2t = (int**) malloc(3*sizeof(int*));
		for (a=0; a<3; a++){
			*(number2t+a)= malloc(3*sizeof(int));
			}
		int** temp = (int**) malloc(3*sizeof(int*));
		for (a=0; a<3; a++){
			*(temp+a)= malloc(3*sizeof(int));
			}															//member allocation for arrays
		for(a=0; a<9; a++){
			*(*(number2t+(a/3))+(a%3)) = (*(number+a))-48;				//convert 9x1 array to 3x3 array
			}
		for(a=0; a<3; a++){
			for(b=0; b<3; b++){
				temp[a][b] = number2t[b][a];							//transpose proccess
				
				}
			}
		for(a=0; a<3; a++){
			for(b=0; b<3; b++){
				number[3*a+b] = temp[a][b]+48;
				
				}
			}
		return number;
		}
	
	return NULL;
	}


int main(){
	int i=0;
	int aux2f[2];
	char element;														//char for name arrays
	
	char *name = (char*) malloc(10 * sizeof(char));
	char *number = (char*) malloc(9 * sizeof(char));
	char *aux = (char*) malloc(5 * sizeof(char));
	printf("Enter the data to decrypt:");								//identify arrays
	while(i<10 && (element=getchar())){									//loop for name |||first 10 character	
		*(name+i)=element;
		i++;
		}
	i=0;
	while(i<9 && (element = getchar())){								//loop for number |||next 9 character
		*(number+i) = element;
		i++;
		}
	i=0;
	while(i<5 && (element = getchar())){
		*(aux+i) = element;
		i++;
		}
		
		char *ptrNumber = decryptNumber(number);
		int *ptrAuxiliaries = decryptAuxiliaries(aux,aux2f);
		char *ptrName = decryptName(name, decryptAuxiliaries(aux,aux2f));	//pointers for printing
	if(ptrName != NULL && ptrNumber != NULL  && ptrAuxiliaries != NULL){
		
		printf("Decrypted ---\nName: ");
		for(i=0; i<10; i++){
			printf("%c",*(ptrName+i));
			}
		printf("\nNumber: ");
		for(i=0; i<9; i++){
			printf("%c",*(ptrNumber+i));
			}
		printf("\nMode: %d",*(ptrAuxiliaries));
		printf("\nModifier: %d",*(ptrAuxiliaries+1));					//prints
		}
	else
		printf("Data is corrupted");									//condition of corruption
    return 0;
}
