#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#define DBL_EPSILON 1e-9

/**
 * @brief проверка на равенство двух чисел
 * @param a – первое число
 * @param b – второе число
 * @return возвращает 0, если числа не равны друг другу, 1, если числа равны
 */
int compareDouble(double a, double b);

/**
 * @breaf расчитывает значение y
 * @param x - аргумент функции
 * @return возвращает значение y
*/
double y (double x);


/**
 * @breaf проверяет правильность ввода данных
 * @return возвращает результат в случае успеха
*/
double double_get_value();

/**
 * @breaf проверка на корректность ввода данных
 * @param start - начальное значение отрезка функции
 * @param end - конечное значение отрезка функции
*/
void check_interval(double start, double end);

/**
 * @breaf проверка на корректность ввода данных
 * @param step - шаг между двумя значениями функции
*/
void check_step(double step);

/**
 * @breaf Точка входа в программу
 * @return Возвращает 0, если ошибок нет, не 0, если ошибки присутствуют.
*/
int main()
{
    printf("Input the start number of x: ");
    double start = double_get_value();
    printf("Input the end number of x: ");
    double end = double_get_value();
    check_interval(start, end);
    printf("Input the delta x: ");
    double step = double_get_value();
    check_step(step);
    double x = start;
    while (x < end+step)
    {
        if ((3 + sin(3.6 * x) == 0))
        {
            printf("%lf", x);
            printf(" no answer");
            x = x + step;
        }
        else
        {
            printf("%lf", x);
            printf(" ");
            printf("%lf\n", y(x));
            x = x + step;
        }
    }

    return 0;
}

double y (double x)
{
    return(x - 1/(3 + sin(3.6 * x)));
}

int compareDouble(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

double double_get_value(){
    double result;
    double scanf_result = scanf("%lf", &result);
    if (scanf_result!=1){
        errno = EIO;
        perror("Input/Output error.");
        abort();
    }
    return result;
}

void check_interval(double start, double end){
    if ((start > end) || (compareDouble(start, end)))
    {
        errno = EIO;
        perror("Input/Output error.");
        abort();
    }
}

void check_step(double step)
{
    if ((step < 0) || (compareDouble(step, 0))) {
        errno = EIO;
        perror("Input/Output error.");
        abort();
    }
}