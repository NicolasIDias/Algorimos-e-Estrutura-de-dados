#include <stdio.h>

int power(int n1, int n2)
{
    if (n1 == 0)
        return 0;
    else if (n2 == 0)
        return 1;
    else if (n2 == 1)
        return n1;
    else
    {
        return n1 * power(n1, n2 - 1);
    }
}

int main()
{

    printf("%d", power(2, 6));

    return 0;
}