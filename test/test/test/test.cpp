#include <stdio.h>
#include <math.h>

void solve_equation(double a, double b, double c)
{
    double delta = b * b - 4 * a * c;
    if (a == 0)
    {
        printf("不是一元二次方程\n");
    }
    else if (delta >= 0)
    {
        printf("x1=%.2lf,x2=%.2lf\n", (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a));
    }
    else if (delta < 0)
    {
        double solve = -b / (2 * a);
        double imaginary_solve = sqrt(-delta) / (2 * a);
        printf("x1=%.2lf+%.2lfi,x2=%.2lf-%.2lfi\n", solve, imaginary_solve, solve, imaginary_solve);
    }
}
int main()
{
    double a = 0.0, b = 0.0, c = 0.0;
    scanf("%lf %lf %lf", &a, &b, &c);
    solve_equation(a, b, c);
    return 0;
}