#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main() {
	int i = 1;
	int q = 0;
	int spaces = 0;
	int N;
	std::cout << "Enter the number of rows to be printed :" << std::endl;
	scanf_s("%d", &N);
	if ((N <= 0) | (N > 10)) {
		printf("Bad N = %d\r\n", N);
		return 0;
	}
	if ((2 * N - 1) >= 10)
		spaces = 2;
	else
		spaces = 1;
	for (i = 1, q = 0; i <= N; i++) {
		printf("%*s", (spaces + 1) * (N - i), "");
		while (q + i <= 2 * i - 1) {
			printf("%*d ", spaces, i + q);
			q++;
		}
		q--;
		while (q != 0) {
			q--;
			printf("%*d ", spaces, i + q);
		}
		printf("\r\n");

}
