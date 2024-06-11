#include <stdio.h>
#include <mpfr.h>
#include <stdlib.h>
#define PRECISION 4000000
#define CYCLES 5

mpfr_t y, a, pi;
mpfr_t one, two, sqrttwo;

// Function to write mpfr_t value to file
void writeToFile(mpfr_t val, FILE *file)
{
    // Calculate the required buffer size
    size_t str_size = mpfr_snprintf(NULL, 0, "%.1000000Rf", val) + 1;
    char *str = (char *)malloc(str_size); // Allocate memory for string

    if (str != NULL)
    {
        mpfr_snprintf(str, str_size, "%.1000000Rf", val);
        fprintf(file, "pi = %s\n", str);
        free(str); // Free allocated memory
    }
    else
    {
        fprintf(stderr, "Memory allocation failed.\n");
    }
}

void f(mpfr_t result, mpfr_t y)
{
    mpfr_t temp;
    mpfr_init2(temp, PRECISION);

    mpfr_pow_ui(temp, y, 4, MPFR_RNDN);
    mpfr_set(result, temp, MPFR_RNDN);

    mpfr_ui_sub(temp, 1, temp, MPFR_RNDN);

    mpfr_rootn_ui(result, temp, 4, MPFR_RNDN);
    mpfr_clear(temp);
}

void newY(mpfr_t result, mpfr_t y)
{
    mpfr_t temp1, temp2;
    mpfr_init2(temp1, PRECISION);
    mpfr_init2(temp2, PRECISION);

    f(temp1, y);
    mpfr_neg(temp1, temp1, MPFR_RNDN);

    mpfr_add(temp1, one, temp1, MPFR_RNDN);

    f(temp2, y);
    mpfr_add(temp2, temp2, one, MPFR_RNDN);

    mpfr_div(result, temp1, temp2, MPFR_RNDN);
    mpfr_clear(temp1);
    mpfr_clear(temp2);
}

void newA(mpfr_t result, mpfr_t a, mpfr_t y, unsigned long k)
{
    mpfr_t temp1, temp2, temp3, exptwo;
    mpfr_init2(temp1, PRECISION);
    mpfr_init2(temp2, PRECISION);
    mpfr_init2(temp3, PRECISION);
    mpfr_init2(exptwo, PRECISION);

    // Right operation
    mpfr_set_d(temp1, 1, MPFR_RNDN);
    mpfr_add(temp1, temp1, y, MPFR_RNDN);
    mpfr_set(temp2, y, MPFR_RNDN);
    mpfr_sqr(temp2, temp2, MPFR_RNDN);
    mpfr_add(temp1, temp1, temp2, MPFR_RNDN);
    mpfr_mul(temp1, temp1, y, MPFR_RNDN);

    k = 2 * k + 3;
    mpfr_pow_ui(temp2, two, k, MPFR_RNDN);
    mpfr_mul(temp1, temp1, temp2, MPFR_RNDN);
    mpfr_neg(temp1, temp1, MPFR_RNDN);
    // Left operation
    mpfr_add(temp2, one, y, MPFR_RNDN);
    mpfr_pow_ui(temp2, temp2, 4, MPFR_RNDN);
    mpfr_mul(temp2, a, temp2, MPFR_RNDN);

    // Finalize
    mpfr_add(result, temp1, temp2, MPFR_RNDN);
    mpfr_clear(temp1);
    mpfr_clear(temp2);
    mpfr_clear(temp3);
    mpfr_clear(exptwo);
}

int main()
{
    // Initialize high-precision floats
    mpfr_init2(y, PRECISION);
    mpfr_init2(a, PRECISION);
    mpfr_init2(pi, PRECISION);

    mpfr_init2(one, PRECISION);
    mpfr_init2(two, PRECISION);
    mpfr_init2(sqrttwo, PRECISION);

    mpfr_set_d(one, 1, MPFR_RNDN);
    mpfr_set_d(two, 2, MPFR_RNDN);
    mpfr_set_d(sqrttwo, 2, MPFR_RNDN);
    mpfr_sqrt(sqrttwo, sqrttwo, MPFR_RNDN);

    mpfr_set(a, sqrttwo, MPFR_RNDN);
    mpfr_mul_ui(a, a, 4, MPFR_RNDN);
    mpfr_neg(a, a, MPFR_RNDN);
    mpfr_add_ui(a, a, 6, MPFR_RNDN);

    mpfr_set(y, sqrttwo, MPFR_RNDN);
    mpfr_add_si(y, y, -1, MPFR_RNDN);

    // Open file to write output
    FILE *file = fopen("pi_output.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    for (int i = 1; i <= CYCLES; i++)
    {
        newY(y, y);
        newA(a, a, y, i - 1);
        mpfr_ui_div(pi, 1, a, MPFR_RNDN);
    }

    // Write result to file
    writeToFile(pi, file);

    // Close the file
    fclose(file);

    // Clear memory
    mpfr_clear(y);
    mpfr_clear(a);
    mpfr_clear(pi);
    mpfr_clear(one);
    mpfr_clear(two);
    mpfr_clear(sqrttwo);

    return 0;
}
