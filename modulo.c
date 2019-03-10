#include <stdio.h>

int modulo(int a[]) {
	int range[42] = {0}, count = 0;

	for (int i = 0; i < 10; ++i) {
		range[a[i]]++;	
	}

	for (int i = 0; i < 42; ++i) {
		if (range[i] >= 1) count++;	
	}

	return count;
}

int main(void)
{
	int numbers[10];
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &numbers[i]);
		numbers[i] %= 42;
	}

	printf("%d\n", modulo(numbers));

	return 0;
}
