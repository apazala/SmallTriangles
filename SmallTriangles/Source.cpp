#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double area(triangle *tr) {
	double s;
	double p;
	p = (tr->a + tr->b + tr->c) / 2.0;
	s = sqrt(p*(p - tr->a)*(p - tr->b)*(p - tr->c));

	return s;
}

int cmp_area(triangle* tra, triangle* trb) {
	const double epsilon = 0.0001;
	double diff = area(tra) - area(trb);
	int ret = 0;

	if (diff < -epsilon)
		ret = -1;
	else if (diff > epsilon)
		ret = 1;

	return ret;
}

void sort_by_area(triangle* tr, int n) {
	/*Insert sort*/
	int i, j;
	triangle x;
	for (i = 1; i < n; i++) {
		x = tr[i];
		j = i - 1;
		while (j >= 0 && cmp_area(tr + j, &x) > 0) {
			tr[j + 1] = tr[j];
			j--;
		}
		tr[j + 1] = x;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}