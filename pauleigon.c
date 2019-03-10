#include <stdio.h>

int main(void)
{
	int n, p, q;
	scanf("%d%d%d", &n, &p, &q);
	if ((p+q) / n % 2 == 0) printf("paul\n");
	else printf("opponent\n");

	return 0;
}
