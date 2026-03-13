#include <stdio.h>
#include <math.h>
double my_cos(double x, double eps);
double true_cos(double x);
void print_header(void);
void printRow(double eps, double result, double exact, int iterations);
void print_recursive_binary(int n);

int last_call_iterations = 0; // Global variable to store iterations of the last call

int main()
{
    double x;
    printf("=== Частина 1. Обчислення ряду cos(x) ===\n");
    printf("Введіть значення x (в радіанах): ");
    scanf("%lf", &x);

    double results[5];
    int iterations[5];
    double eps = 0.1;

    for (int i = 0; i < 5; i++)
    {
        results[i] = my_cos(x, eps);
        iterations[i] = last_call_iterations;
        eps /= 10.0;
    }

    print_header();
    eps = 0.1;
    for (int i = 0; i < 5; i++)
    {
        printRow(eps, results[i], true_cos(x), iterations[i]);
        eps /= 10.0;
    }

    printf("\n=== Частина 2. Рекурсивний вивід двійкового представлення числа ===\n");
    printf("Двійкове представлення числа y:\n");
    printf("Enter an integer: ");
    int y;
    scanf("%d", &y);
    printf("Binary representation: ");
    print_recursive_binary(y);
    printf("\n");
    return 0;
}
double my_cos(double x, double eps)
{
    static int call_count = 0;         // this will count how many times the function is called
    static int overall_iterations = 0; // this will count total iterations across all calls
    call_count++;                      // increment the call count each time the function is called
    last_call_iterations = 0;          // Reset for the current call
    double sum = 1.0;                  // this is the first term of the series
    double term = 1.0;                 // this will hold the current term being added to the sum
    int n = 1;                         // this is the index of the term being calculated
    while (fabs(term) > eps)
    {
        // calculate current term via formula: a_n = -x^2/(2n(2n-1)) * a_(n-1)
        // this avoids the need to calculate factorials directly (can cause overflow) and is more efficient
        term *= -(x * x) / ((2 * n - 1) * (2 * n));
        sum += term;
        n++;
        last_call_iterations++;
        overall_iterations++;
    }
    printf("Call number %d, iterations = %d, overall_iterations = %d\n", call_count, last_call_iterations, overall_iterations); // print the current call count
    return sum;
}
void print_recursive_binary(int n)
{
    if (n > 1)
    {
        print_recursive_binary(n / 2);
    }
    printf("%d", n % 2);
}

double true_cos(double x)
{
    return cos(x);
}

void print_header(void)
{
    printf("Precision   Result    Exact       Error     Iterations\n");
}

void printRow(double eps, double result, double exact, int iterations)
{
    double error = fabs(result - exact);
    printf("%-11.5f%-13.6f%-12.6f%-12.6f%d\n", eps, result, exact, error, iterations);
}
