#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int pt = 0;
int incir  = 0;

void *rad(void *q)
{
int i=0; 
	for (i=0; i < pt; i++)
	{	
		double x = (double)rand() / RAND_MAX;
		double y = (double)rand() / RAND_MAX;

		if (((x * x) + (y * y)) <= 1)
		{
			incir++;
		}
	}
	return NULL;
}

int main()
{
	srand(time(NULL));
printf("\nEnter the number of points to be used for calculating value if pi \n");
scanf("%d",&pt);

	pthread_t thread;
	pthread_create(&thread, NULL, &rad, NULL);
	pthread_join(thread, NULL);
	double pi = 4.0 * incir / pt ;
printf("\n The calculated value of pi for %d points ,\n Of which %d are inside circle ,\n PI = %lf \n",pt,incir,pi);
	return 0;
}
