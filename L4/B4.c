#include <stdio.h>
#include <stdlib.h>

typedef struct transf
{
	int bit;
	struct transf* urm;
}nod;
nod* adaug(nod* pr, int bit)
{
	nod* p;
	p = (nod*)malloc(sizeof(nod));
	p->bit = bit;
	p->urm = pr;
	pr = p;
	return pr;

}
void afisez(nod* pr)
{
	nod* q;
	int contor = 0;
	for (q = pr; q != NULL; q = q->urm)
		printf("%d", q->bit);
	printf("\n");

}
int main()
{
	nod* pr;
	int n, r;
	pr= NULL;
	scanf("%d", &n);
	while (n != 0)
	{
		r = n % 2;
		pr= adaug(pr, r);
		n = n / 2;
	}
	afisez(pr);
	system("pause");
	return 0;
}
