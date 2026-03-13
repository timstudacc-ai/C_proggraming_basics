#include <stdio.h>
#include <math.h>
double my_cos(double x, double eps);
double true_cos(double x);
void print_header(void);
void printRow(double eps, double result, double exact, int iterations);

int last_call_iterations = 0; // Global variable to store iterations of the last call

int main()
{
}
double my_cos(double x, double eps)
{
    static int call_count = 0;                         // this will count how many times the function is called
    call_count++;                                      // increment the call count each time the function is called
    last_call_iterations = 0;                          // Reset for the current call
    double sum = 1.0;                                  // this is the first term of the series
    double term = 1.0;                                 // this will hold the current term being added to the sum
    int n = 1;                                         // this is the index of the term being calculated
    printf("Call count for my_cos: %d\n", call_count); // print the current call count
    while (fabs(term) > eps)
    {
        // calculate current term via formula: a_n = -x^2/(2n(2n-1)) * a_(n-1)
        // this avoids the need to calculate factorials directly (can cause overflow) and is more efficient
        term *= -(x * x) / ((2 * n - 1) * (2 * n));
        sum += term;
        n++;
        last_call_iterations++;
    }

    return sum;
}
double true_cos(double x)
{
    return cos(x);
}

void print_header(void)
{
    printf("Точність   Результат    Точне       Похибка     Ітерацій\n");
}
