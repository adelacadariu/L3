#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, suma = 0, nr;
	printf("n=");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		nr = i;
		while (nr != 0)
		{
			if ((nr & 1) == 1)
				suma++;
			nr = nr >> 1;
		}
	}
	printf("Suma este %d\n", suma);
	system("pause");
	return 0;
}
