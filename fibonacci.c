#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int sequenceToN(int n);
int nInSequence(int n);
int checkIfNumberOnly(char *s); 
int printOption();
int main(int argc, char *argv[]){
    int c;
	char *n1 = NULL;
	int n = 0;
	int aopt = 0, bopt = 0;
	int index;
	int argumentCount = 0; 

	while ( (c = getopt(argc, argv, "ab")) != -1) {
		switch (c) {
        case 'a':
			aopt = 1;
            break;
        case 'b':
			bopt = 1;
            break;
		case '?':
             if (optopt == 'c')
               fprintf (stderr, "Option -%c requires an argument.\n", optopt);
             else if (isprint (optopt))
               fprintf (stderr, "Unknown option `-%c'.\n", optopt);
             else
               fprintf (stderr, "Unknown option character `\\x%x'.\n",optopt);
			 return 1;
        default:
			printOption();
			return 0;
			break;
        }
     }
	
	for (index = optind; index < argc ; index++) {
	    n1 = argv[index];
		argumentCount++;
	}
	// check of we have too many arugments.
	if(argumentCount > 1){
		fprintf (stderr, "ERROR: Too many arugments.\n");
		printOption();
		return 0;
	}
	// If we don't have enough arguments.
	if( (aopt == 0 && bopt == 0) || n1 == NULL){
		fprintf (stderr, "ERROR : Not enough arguments. \n");
		printOption();
		return 0;
	} else if((aopt == 0 && bopt == 0)){
		fprintf (stderr, "ERROR : You must specify an option \n");
		printOption();
		return 0;
	}
	else if((aopt == 1 && bopt == 1) && n1 != NULL){
		fprintf (stderr, "ERROR : -a and -b cannot be used at the same time \n");
		printOption();
		return 0;
	} else {
		//We want to check whether arugment of -n only contains numbers
		if(checkIfNumberOnly(n1) == 0){
			fprintf (stderr, "ERROR : -n can only contain Positive numbers");
			return 0;
		}  else {
			// Converts into integer.
			n = atoi(n1);
			// check for options 
			if (aopt == 1){
				nInSequence(n);
			} else if (bopt == 1){
				sequenceToN(n);
			}				
		}
	}
	return 0;
}

int nInSequence(int n){
	printf("Number: %d\n",n);
	long long int number;
	number = sequence(n);
	printf("Fibonacci Sequence until %d number : %llu",n,number);
	return 0;
}

int sequenceToN(int maxnumber){
	printf("Fibonacci Sequence until %d : ",maxnumber);
	sequence2(maxnumber);
	return 0;
}

int checkIfNumberOnly(char *s){
	int i = 0;
	int len = (int)(strlen(s));
	for(i = 0; i < len; i++){
			if(!((s[i] >= '0' && s[i] <= '9')|| s[i] == ' ') )
				return 0;
	}
	return 1;
}

int printOption(){	
	printf("\n");
	printf("fibonacci: fibonacci <number> <option> \n");
	printf("<number>: Any non-zero integer \n");
	printf("<option>: \n");
	printf("\t -a: Generates the <number>-th number in the fibonacci sequence. \n");
	printf("\t -b: Generates the fibonacci sequence until <number>. \n \t (Note: If the number does not live in the fibonacci Sequence. The program will generate until the number that is just smaller than the number specified.)\n");
	printf("\t NOTE: -a and -b cannot used at the same time.");
	return 0;
}
