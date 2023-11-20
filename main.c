#include <stdio.h>
#include <stdlib.h>


/**
* @brief ���������� ��������� ������� b
* @param �������� "a" ��� ������� b
* @param �������� "n" ��� ������� b
**/
float get_B(double a, double n);
/*
* @brief ���������� ��������� ������� square_func
* @param �������� "a" ��� ������� square_func
* @param �������� "b" ��� ������� square_func
**/
float square_func(float a, float b);

/*
* @brief ���������� ��������� ������� perimeter_func
* @param �������� "a" ��� ������� perimeter_func
* @param �������� "b" ��� ������� perimeter_func
**/
float perimeter_func(float a, float b);


/*
* @brief ����� ����� � ���������
* @return ���������� 0, ���� ��������� �������� ���������, ����� �� 0
**/
int main()
{
    float a, n;

    scanf_s("%f", &a);
    scanf_s("%f", &n);

    float b = get_B(a, n);
    float square = square_func(a, b);
    float perimeter = perimeter_func(a, b);

    printf("\n square=%f", square);
    printf("\n preimeter=%f", perimeter);
}

float get_B(float a, float n)
{
    return a * n / 100;
}


float square_func(float a, float b)
{
    return a * b;
}


float perimeter_func(float a, float b)
{
    return a * 2 + b * 2;
}