/*************************************************
 *   Erdinc Kandemir                             *
 *   150150110                                   *
 *   Homework 1                                  *
 *   CRN:22073                                   *
 *************************************************/


#include <stdio.h>

int main(){
    int divider = 2;
    int number;
    int power = 0;
    int control = 1;                                            //Define variables
    printf("Enter a number:");
    while(control==1){
        scanf("%d",&number);
        if(number>=2 && number<=32767){                         //Validation check
            printf("Prime factorization of %d:", number);
            while (number!=1){
                if(number % divider == 0){                      //to find divisor of number
                    number = number / divider;
                    power++;                                    //counting powers
                }
                else{
                    if(power!=0){                               //avoid unneccessary prime numbers
                        if(number != 1){
                            printf("%d^%d",divider,power);}
                        printf(" * ");}
                    divider++;
                    power = 0;
                }
                if(number==1){                                  //print last prime multipliar and end programme
                    printf("%d^%d\n",divider,power);
                    control = 0;
                    break;
                    
                }
            }
        }
        else{                                                   //case of invalid number
            printf("Enter a valid number:");
        }
    }
    return 0;
}

