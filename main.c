#include <stdio.h>
#include <string.h>

int main(void)
{
    long creditCardNumber;

    do
    {
        printf("KART NUMARASINI GIRINIZ: \n");
        scanf("%ld", &creditCardNumber);
    }
    while (creditCardNumber <= 0);

    long workingCC = creditCardNumber;
    int sum = 0;
    int count = 0;
    long divisor = 10;
    char result[11];

 
    while (workingCC > 0)
    {
        int lastDigit = workingCC % 10;
        sum = sum + lastDigit;
        workingCC = workingCC / 100;
    }

 
    workingCC = creditCardNumber / 10;
    while (workingCC > 0)
    {
        int lastDigit = workingCC % 10;
        int timesTwo = lastDigit * 2;
        sum = sum + (timesTwo % 10) + (timesTwo / 10);
        workingCC = workingCC / 100;
    }

   
    workingCC = creditCardNumber;
    while (workingCC != 0)
    {
        workingCC = workingCC / 10;
        count++;
    }

   
    for (int i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    int firstDigit = creditCardNumber / divisor;
    int firstTwoDigits = creditCardNumber / (divisor / 10);

    
    if (sum % 10 == 0)
    {
        if (firstDigit == 4 && (count == 13 || count == 16))
        {
            strcpy(result, "VISA");
        }
        else if ((firstTwoDigits == 34 || firstTwoDigits == 37) && count == 15)
        {
            strcpy(result, "AMEX");
        }
        else if ((50 < firstTwoDigits && firstTwoDigits < 56) && count == 16)
        {
            strcpy(result, "MASTERCARD");
        }
        else 
        {
            strcpy(result, "GECERSIZ KART");
        }
    }
    else
    {
        strcpy(result, "GECERSIZ KART");
    }

    printf("%s\n", result);
}

