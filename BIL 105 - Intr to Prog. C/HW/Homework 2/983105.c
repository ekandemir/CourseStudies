/*************************************************
 *   Erdinc Kandemir                             *
 *   150150110                                   *
 *   Homework 2                                  *
 *   CRN:22073                                   *
 *************************************************/
#include <stdio.h>														
int main(){
	char nucleotide;													//define nucleotides
	int a=0,t=0,g=0,c=0;												//define variables for printing
	int count_a=0, count_t=0, count_g=0, count_c=0;						//define variables for diseases
	int i=1;															//define i
	int cont;
	printf("Enter a seq.: ");											//text for request
	for(cont=0;cont<25;){												//loop to break after 25
		while((nucleotide=getchar()) != EOF && cont < 25){				//loop to request and break 25
			if(i == 1){													//condition to print only one times 
			printf("DNA seq.:     ");									//text to describe
				}
			switch(nucleotide){											//switch structure for evaluate chars,prints,counting for diseses
				case 'A':
				case 'a':
					a++;
					if(a-t <= 1){
						printf("A");
						count_a++;
						}
					break;
				case 'T':
				case 't':
					t++;
					if(t-a <= 1){
						printf("T");
						count_t++;
					}
					break;
				case 'G':
				case 'g':
					g++;
					if(g-c <= 1){
						printf("G");
						count_g++;
					}
					break;
				case 'C':
				case 'c':
					c++;
					if(c-g <= 1){
						printf("C");
						count_c++;
					}
					break;
				default:
					break;
				}
								
			if(a==t){													//conditions for not repeating
				a=t=0;
				}
			if(g==c){
				g=c=0;
				}		
				
			if(a-t >= 2){												//conditions to not evaluate repeated values
				a=1;
				}
			if(t-a >= 2){
				t=1;
				}
			if(g-c >= 2){
				g=1;
				}
			if(c-g >= 2){
				c=1;
				}	
			i++;
			if(nucleotide == '\n'){cont=25;break;}						//conditions for breaking loops
			if(nucleotide == 'x'||nucleotide == 'X'){cont=25;break;}
			if((count_a + count_t + count_g + count_c) == 10){cont=25;break;}
			cont++;
		}
	}

		if(nucleotide == 'x' || nucleotide == 'X'){printf("\nTerminated!");}							//conditions for printing
		else if(count_a+count_t+count_g+count_c==0){printf("\nNo data to test!");}
		else if(count_a == count_t && count_g == count_c){printf("\nHealthy!");}
		else if(count_a > count_t && count_g == count_c){printf("\nDisease: A nucleotide.");}
		else if(count_a > count_t && count_g > count_c){printf("\nDisease: G and A nucleotides.");}
		else if(count_a > count_t && count_c > count_g){printf("\nDisease: C and A nucleotides.");}
		else if(count_t > count_a && count_g == count_c){printf("\nDisease: T nucleotide.");}
		else if(count_t > count_a && count_g > count_c){printf("\nDisease: G and T nucleotides.");}
		else if(count_t > count_a && count_c > count_g){printf("\nDisease: C and T nucleotides.");}
		else if(count_g > count_c && count_a == count_t){printf("\nDisease: G nucleotide.");}
		else if(count_c > count_g && count_a == count_t){printf("\nDisease: C nucleotide.");}

			

return 0;
}
