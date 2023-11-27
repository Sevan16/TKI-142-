#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief ������� �������� ������� ������������
* @param a-������ ������� ������������
* @param b-������ ������� ������������
* @param c-������ ������� ������������
* @return ������������ ������� ������������
*/
double Striangle(double a, double b, double c);

/**
* @brief ������� �������� ������� ��������������
* @param a-������ ������� ��������������
* @param b-������ ������� ��������������
* @return ������������ ������� ��������������
*/
double Srectangle(double a, double b);

/**
* @brief ������� �������� ����� �� ������������
* @return ���������� �������� � ������ ������
*/
double double_get_value();

/**
* @brief �������� �� ������������� ������������
* @param a-������ ������� ������������
* @param b-������ ������� ������������
* @param c-������ ������� ������������
* @return ���������� ������ � ������ ������
*/
int check_triangle(double a, double b, double c);

/**
* @brief ����� ����� � ���������
* @return ���������� 0 � ������ ������, ����� �� 0
*/
int main()
{
    int w;
    float a, b, c;
    printf("Chose triangle or rectangle:\n");
    printf("1 - Triangle\n");
    printf("2 - Rectangle\n");
    w = double_get_value();
    if (w == 1)
        {
        printf("Enter 1st side of triangle\n");
        a = double_get_value();
        printf("Enter 2nd side of triangle\n");
        b = double_get_value();
        printf("Enter 3rd side of triangle\n");
        c = double_get_value();
        if(check_triangle(a,b,c) == 1){
        printf("Area of this triangle is: %f", Striangle(a, b, c));
        }
        }
    else if (w == 2)
        {
        printf("Enter 1st side of rectangle\n");
        a = double_get_value();
        printf("Enter 2nd side of rectangle\n");
        b = double_get_value();
        printf("Area of this rectangle is: %f", Srectangle(a, b));
        }
    else 
    {
        printf("Please input only number 1 or 2");
    }
    return 0;
}



double Striangle(double a, double b, double c)
{
    const double p = 0.5*(a+b+c);
    return (sqrt(p*(p-a)*(p-b)*(p-c)));
}

double Srectangle(double a, double b)
{
    return (a*b);
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

int check_triangle(double a, double b, double c){
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
    {
        printf("This triangle is not exist.");
        return 0;    
    }
    return 1;
}
