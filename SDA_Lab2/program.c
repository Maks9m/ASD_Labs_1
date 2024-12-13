#include <stdio.h>
#include <math.h>

int main(void)
{
    int ct = 0;//Operations counter
    int n;//Enter number
    float S = 0;//Sum of numbers
    float M = 1;//Multiplication of numbers
    int a = 1;//Power of 4

    printf("Введіть n: \n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        M = 1;
        for(int j = 1; j <= i; j++)
        {
            M = M * (j + cos((double) j));
            ct += 6;
        }
        a = a * 4;
        S += (M / (a - i));
        ct += 8;
    }
    ct += 4 + n;//Initialization of S, M, a, i and j(n times)
    printf("S = %.7f\n", S);//Result
    printf("Operations: %i\n", ct);//Amount of operations
}