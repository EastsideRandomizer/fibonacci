#include <stdio.h>
int sequence(int n);
int sequence2(int n);

int sequence(int n){
	int i;
	long long int n_1=0;
	long long int n_2=1;
	long long int sum = 0;
	for(i = 1; i < n ; i++ ){
		sum = n_1+n_2;
			n_2 = n_1;
			n_1 = sum;
	}
	return sum;
}

int sequence2(int max){
	int i;
	long long int n_1=0;
	long long int n_2=1;
	long long int sum = 0;
	// generates the sequence until the number specified in argv[0]
	for(i = 1; max >= sum; i++ ){
		printf("%llu ",sum);
		sum = n_1+n_2;
		n_2 = n_1;
		n_1 = sum;
	}
		return 0;
}
