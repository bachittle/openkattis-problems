#include <stdio.h>

int testVal(int num) {
	int range[10] = {0}; // range is to keep track of repeating numbers in order to make sure they are all unique. 
	int original = num;  // need to keep original number to test for divisibility. 
	
	while(num % 10 != 0) {
		if (original % (num % 10) != 0) return 0;
		else { 
			range[num % 10]++; 
			num /= 10;
		}
	}
	if (num > 0) return 0;
	for (int i = 0; i < 10; ++i) {
		if (range[i] > 1) return 0;	
	}
	return 1;
}

int main(void)
{
	int x, y, count = 0;
	scanf("%d", &x);
	scanf("%d", &y);
	
	for (; x <= y; x++) {
		count += testVal(x);	
	}

	printf("%d\n", count);

	return 0;
}
