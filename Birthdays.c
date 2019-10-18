#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	int *birthdays;
	int *p;
	int num;
	int iterations;
	int isEqual(int *birthdays, int num);
	int* checkEquality(int *eq);
	int* buildArray(int num);
	int* checkEqual(int num, int iterations, int *birthdays, int *p);
	double probability(int num, int iterations);
	void printEnter();

int main() {

	printf("Number of people \n"); 
	scanf("%i", &num);

	birthdays = malloc(num);

	printf("Number of iterations \n");
	scanf("%i", &iterations);

	p = malloc(iterations);
	p = checkEqual(num, iterations, birthdays, p);
	double prob = probability(num, iterations);
	printEnter();

	printf("%d",prob);

}

void printEnter() {
	printf("\n\n");
}

void printArray(int *p, int num) {
	printEnter();
	int *pEnd = p + num;
	while (p < pEnd) { // while loop
		printf("%i, %i\n",*p, p);
		p++;
	}
	p = p - num;
}

int* buildBirthdays(int *birthdays, int num) {
	// int *birthdays = malloc(num)
	int max = 365;
	int min = 1;	
	srand(time( NULL ));
	for (int i = 0; i < num; i++) { // seeds current time
		*birthdays = rand() % (max + 1 - min) + min;
		birthdays++;
	}
	birthdays = birthdays - num;
	return birthdays;
}

int isEqual(int *birthdays, int num) {
	int *birthdaysEnd = birthdays + num;
	while (birthdays < birthdaysEnd) {
		int *birthdaysCopy = birthdays;
		while (birthdaysCopy < birthdaysEnd) {
			birthdaysCopy++;
			if (*birthdays == *birthdaysCopy) {
				return 1;
			}
		}
		birthdays++;
	}
	return 0;
}

int* checkEqual(int num, int iterations, int *birthdays, int *p) {
	int *pEnd = p + iterations;
	while (p < pEnd) {
		int *q = buildBirthdays(birthdays, num);
		if (isEqual(q, num)) {
			*p = 1;
		}
		q = q - num;
		p++;
	}
	p = p - iterations;
	return p;
}

double probability(int num, int iterations) {
	int *pEnd = p + iterations;
	int totalTrue = 0;
	while (p < pEnd) {
		if (p) {
			totalTrue++;
		}
	}
	return (totalTrue / iterations) * 100;
}