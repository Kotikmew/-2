#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a[10000][10000], b[10000][10000], c[10000][10000];

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	double time_spent = 0.0;
	clock_t begin = clock();

	int i = 0, j = 0, r;
	int p = 10000;
	int elem_c;

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	for (i = 0;i < p;i++)
	{
		for (j = 0;j < p;j++)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	for (i = 0;i < p;i++)
	{
		for (j = 0;j < p;j++)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	i = 0; j = 0; r = 0;
	/*while (i<p)
	{
		while(j<p){
			elem_c = 0;
			while (r<p)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
				r++;
			}
			j++;
		}
		i++;
	}*/

	for (i = 0;i < p;i++)
	{
		for (j = 0;j < p;j++)
		{
			elem_c = 0;
			for (r = 0;r < p;r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
		printf("\n%d", i);
	}

	clock_t end = clock();
	printf("\n");
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds", time_spent);
	return(0);
}
