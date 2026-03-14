#include <stdio.h>
#include <math.h>
const double PI = 3.141592653589793;
// Function prototypes
double my_cos(double x, double eps);
double true_cos(double x);
void print_header(void);
void printRow(double eps, double result, double exact, int iterations);
void print_recursive_binary(int n);

int last_call_iterations = 0; // Global variable to store iterations of the last call

int main()
{
    double x;
    printf("=== Part 1. Computing the cosine series ===\n");
    printf("Enter the value of x (in radians): ");
    scanf("%lf", &x);

    double results[5]; // to store results for different eps values
    int iterations[5]; // to store iterations for different eps values
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

    printf("\n=== Part 2. Recursive output of binary representation of a number ===\n");
    printf("Binary representation of number y:\n");
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
    x = fmod(x, 2 * PI);               // reduce x to the range [0, 2π) for better convergence
    while (fabs(term) > eps)
    {
        // calculate next term via formula: a_n = -x^2/(2n(2n-1)) * a_(n-1)
        // this avoids the need to calculate factorials directly (can cause overflow) and is more efficient
        // so first iteration calculates second term
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
    printf("%d", n % 2); // print the most significant bit first (after the recursive calls) to get the correct order of bits
}

double true_cos(double x)
{
    return cos(x);
}

void print_header(void)
{
    printf("%-11s%-13s%-12s%-12s%s\n", "Precision", "Result", "Exact", "Error", "Iterations");
}

void printRow(double eps, double result, double exact, int iterations)
{
    double error = fabs(result - exact);
    printf("%-11.5f%-13.6f%-12.6f%-12.6f%d\n", eps, result, exact, error, iterations);
}
