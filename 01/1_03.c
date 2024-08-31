#include <stdio.h>

int main()
{
	float fahr, celsius;
	int upper, lower, step;
	
	upper = 300;
	lower = 0;
	step = 20;

	fahr = lower;
	
	printf(" F\tC\n");
	while (fahr <= upper)
	{
		celsius = 5.0 * (fahr-32.0) / 9;
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;	
	}
}
