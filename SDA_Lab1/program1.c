#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    float y;
    printf("Введіть x: \n");
    scanf("%f", &x);
    if(x < -1)
    {
        y = 15*x - 2;
        printf("y = %.4f\n", y);
    }
    else
    {
        if (x >= 0 && x <= 8 || x >= 16)
        {
            y = -0.6*x*x + 9;
            printf("y = %.4f\n", y);
        }
        else
        {
            printf("Функція не має розвʼязків\n");
        }
    }
    return 0;
}