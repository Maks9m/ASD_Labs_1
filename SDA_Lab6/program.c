#include <stdio.h>
#include <stdbool.h>

void MakeMatrix(int a, int b, int M[a][b]);
void ShellAlg(int d, int a, int b, int M[a][b], int T, int i);

int main(void)
{
    int a = 9;   // Кількість рядків
    int b = 8;   // Кількість стовпчиків
    int M[a][b]; // Матриця
    int T;
    int d = 4;

    /*
    18    3   -3   -2  -20   -3    3   -4
    -4   14   -7    4  -13    7  -18  -15
   -17  -16    2    3    9   10   14   17
   -19  -17  -15   -9   -2   -2    4    6
    14   14   13   10    9    2   -3   -4
    20   20    7   -1   -3   -4   -4   -8
    11  -16    5   -3   -8  -12    1  -15
    11   22   33   44   55   66   77   88
    -1    1    0    1    1    1    1    1
    */

    printf("Введіть матрицю:\n");
    for (int i = 0; i < a; i++) // Ввід матриці
    {
        printf("%i-й рядок:\n", i);
        for (int j = 0; j < b; j++)
        {
            scanf("%i", &M[i][j]);
        }
    }
    
    printf("Задана матриця: \n");
    MakeMatrix(a, b, M);

    for (int i = 0; i < a; i++)
    {
        ShellAlg(d, a, b, M, T, i);
    }
    
    printf("Сортована матриця: \n");
    MakeMatrix(a, b, M);
}

void MakeMatrix(int a, int b, int M[a][b])
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%4i ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void ShellAlg(int d, int a, int b, int M[a][b], int T, int i)
{
    for (int j = 0; j < b - d - 1; j++)
    {
        T = M[i][j];
        if (M[i][j + d] > T)
        {
            M[i][j] = M[i][j + d];
            M[i][j + d] = T;
        }
    }
    if (d == 1)
    {
        bool correct;//Остання перевірка масиву
        do
        {
            correct = true;
            for (int j = 0; j < b - 1; j++)
            {
                T = M[i][j];
                if (M[i][j + 1] > T)
                {
                    M[i][j] = M[i][j + 1];
                    M[i][j + 1] = T;
                    correct = false;
                }
            }
        } while (!correct);
    }
    else
    {
        ShellAlg(d / 2, a, b, M, T, i);
    }
}