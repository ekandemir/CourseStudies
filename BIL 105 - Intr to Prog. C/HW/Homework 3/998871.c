/*************************************************
 *   Erdinc Kandemir                             *
 *   150150110                                   *
 *   Homework 3                                  *
 *   CRN:22073                                   *
 *************************************************/
#include <stdio.h>

float two,one,zero;
float dom1,dom2;	
																													//global variables
int i;
float equation(float x){																							//function for get x and returnf(x)
	float fx;
	fx = two*x*x+one*x+zero;
	return fx;
}
float bisection(float dom1, float dom2){																			//function for main bisection

		if(equation((dom1+dom2)/2) * equation(dom1) > 0 && (dom1+dom2)/2-dom1>0.0001 && dom1!=dom2){
			dom1=(dom1+dom2)/2;
			return bisection(dom1,dom2);
			}
		else if(equation((dom1+dom2)/2) * equation(dom2) > 0 && (dom1+dom2)/2 - dom2<0.0001 && dom1!=dom2){
			dom2=(dom1+dom2)/2;
			return bisection(dom1,dom2);
			}
		else if(equation((dom1+dom2)/2) == 0){
			return (dom1+dom2)/2;
			}
		else if(equation(dom1) <= 0.001){
			return(dom1);			
			}
		else if(equation(dom2) <= 0.001){
			return(dom2);	
			}

	
	return 0;
	}
float domainFinder(float dom1, float dom2){																			//function for situation of roots are between the domain. return any middle value between roots 

	if((equation(dom1)*equation((dom1+dom2)/2) > 0 && dom1!=dom2)||equation((dom1+dom2)/2)==0){
		if(two>0){
			if(equation(dom1)-equation((dom1+dom2)/2) >= equation(dom2)-equation((dom1+dom2)/2)){
				dom1 = (dom1+dom2)/2;
				return domainFinder(dom1,dom2);		
				}
			if(equation(dom2)-equation((dom1+dom2)/2) > equation(dom1)-equation((dom1+dom2)/2)){
				dom2 = (dom1+dom2)/2;
				return domainFinder(dom1,dom2);		
				}
			}
		else if(two<0){
			if(equation(dom1)-equation((dom1+dom2)/2) >= equation(dom2)-equation((dom1+dom2)/2)){
				dom2 = (dom1+dom2)/2;
				return domainFinder(dom1,dom2);			
				}
			if(equation(dom2)-equation((dom1+dom2)/2) > equation(dom1)-equation((dom1+dom2)/2)){
				dom1 = (dom1+dom2)/2;
				return domainFinder(dom1,dom2);			
				}
			}
		}
	else{
		return (dom1+dom2)/2;
		}

		return 0;
	
	}
void findRoots(float dom1, float dom2){																						//whole finding root conditions and printing them
	float root1,root2;
	float tempdom;
	if(equation(dom1)*equation(dom2)<0){
		root1= bisection(dom1,dom2);	
		printf("Root: x=%.3f",root1);	
		}
	else if (equation(dom1)*equation(dom2)>=0){
		tempdom=domainFinder(dom1,dom2);
		if(equation(dom1)==0 || equation(dom2)==0){
			if(equation(dom1)==0){
				if(equation(tempdom)*equation(dom2)>0){printf("Root: x=%.3f",dom1);}
				else{root2=bisection(tempdom,dom2);printf("Roots: x=%.3f, x=%.3f",dom1,root2);}
				}
				
			else if(equation(dom2)==0){
				if(equation(tempdom)*equation(dom1)>0){printf("Root: x=%.3f",dom2);}
				else{root2=bisection(dom1,tempdom);printf("Roots: x=%.3f, x=%.3f",root2,dom2);}
				}
			else if(equation(dom1)==0 && equation(dom2)==0){printf("Roots: x=%.3f, x=%.3f",dom1,dom2);}
			
			}
		else{
			if(equation(tempdom)*equation(dom1)>0){
				printf("No roots found");	
				}
			else{	
				root1=bisection(dom1,tempdom);
				root2=bisection(tempdom,dom2);
				printf("Roots: x=%.3f, x=%.3f",root1,root2);
				}
			}
	
		}

		

	
	
	}


int main(){
	scanf("%f %f %f %f %f", &two, &one, &zero, &dom1, &dom2);															//getting parameters
	printf("Entered equation: %.0fx^2 + %.0fx + %.0f\n",two,one,zero);													//printing equation
	printf("Domain: %.0f, %.0f\n",dom1,dom2);																			//printing domain
	findRoots(dom1,dom2);																								//calling boss
	return 0;
}


