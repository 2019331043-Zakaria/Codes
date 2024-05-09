#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /*FILE *fp_in, *fp_out;
    char input_file[] ="in.txt";
    char out_file[] = "out.txt";

    int num1,num2,sum;
    fp_in=fopen(input_file, "r");
    fp_out=fopen(out_file,"w");
   for(int i=1 ;i<=4 ;i++)
   { 
        fscanf(fp_in,"%d", &num1);
        fscanf(fp_in,"%d", &num2);
        sum=num2+num1;
        printf("%d + %d = %d\n",num1,num2,sum );
        fprintf(fp_out, "%d\n",sum );
   }
    fclose(fp_in);
    fclose(fp_out);
    fp_in=fopen(out_file,"a");
    fprintf(fp_in,"aasasa\n");
    fclose(fp_in);*/
    
   
    int x;
    int *p=&x;
    printf("%d %d\n",p, p+1 );


    return 0;
}
