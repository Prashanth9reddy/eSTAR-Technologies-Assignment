
#include <stdio.h> 
#include<stdlib.h>

//#define SELF_TEST
#define MANUAL_TEST
int TEST_RANGE=10000;


/////////////////////////////////////////////////SELF TEST///////////////////////////////////////////////////////
#ifdef SELF_TEST
float poll_temperature()
        {
			float celsius=0;
			for(int i=0;i<10;i++)
			{
			celsius = celsius + (rand()%TEST_RANGE + rand()%9*0.12345 - TEST_RANGE/2);
			}
                return celsius;
        }
#endif


////////////////////////////////////////////////MANUAL TESTING////////////////////////////////////////////////////
#ifdef MANUAL_TEST
float poll_temperature()
	{
	int i=0;
	float celsius=0;
	for(i=0;i<10;i++)
	{
	float temp=0;
	printf("Please Enter Temperature Reading[%d]:- and Press Enter\n",i+1);
	if(scanf("%f",&temp)==1)
	{
	celsius += temp;
	}
	//else if(scanf("%f",&temp)==1)
	else
	{
	clean_stdin();
	//celsius=0;
	printf("Please Enter Valid Input. Only Integers are allowed\n");
	i--;
	}
	}

	return celsius;
	}
#endif

////////////////////////////////////////////////MAIN FUNCTION//////////////////////////////////////////////////////
void main()
{
    while(1)
    {
    printf("\t###################################Welcome To Temperature Calculator###########################################\n");
    float celsius=0;
    celsius=poll_temperature();
	fflush(stdin);
    printf("Average Of Last 10 Temperature Samples In Celsius:  %.1f\t",celsius);
    printf("In fahrenheit: %.1f\n",((celsius*1.8)+32))/10;
    sleep(1);
}
    
}


int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}
