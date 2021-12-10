#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
Vartotojas iveda neneigiamus skaicius. 
Jei neigiamas skaicius ar raide parasyti jog bloga ivestis
0 = programos pabaiga
Ar pirminis skaicius
Jei jis ne pirminis - atspausdinti artimiausia pirmini skaiciu
Jei tokiu skaiciu yra du, juos abu reikia atspausdinti
*/

int main()
{
    int correct, isPrime = 1, num1 = 0, num2 = 0, distance1 = 0, distance2 = 0;
    char str;
    long long num;
    
    printf
    (
        "\nThis program checks if an entered number is prime, if it's not, the program returns the closest prime number(s)\n"
        "A sequence of numbers have to be seperated by whitespace (Enter, Space, Tab, Etc.)\n"
        "Entering the value of 0 stops the program\n"
        "Please enter a positive integer :\n"
    );

    do
    {
        // Check if Number is entered Correctly
        do 
        {
            correct = scanf("%lld%c", &num, &str) && (isspace(str)) && (num - (int)num == 0) && (num >= 0); // Check if Number is an integer and if it does not exceed memory limit
        
            if(!correct)
            {
                printf("!Invalid number!\n");
                scanf("%*[^\n,' ',\t]");
            }

        } while (!correct);
        
        if(num == 0) // Program terminated if Number is 0. Welcome to THE MATRIX
        {
            printf("I Can Only Show You The Door. You're The One That Has To Walk Through It.\n-Morpheus");
            return 0;
        }

        printf("Number %d entered successfully!\n",num);

        for(int i = 2; (i * i) <= num; ++i) // Check if entered number is PRIME
        {
            if(num % i == 0)
            {
                isPrime = 0;
                break;
            }
        }

        if(isPrime & num != 1) // Print the number if it is Prime ( for some reason.... The number 1 is not considered PRIME, )
        {
            printf("%d is prime\n", num);
        }
        else
        {
            num1 = num, num2 = num; 

            // If the number is not Prime calculate the nearest prime numbers
            // Calculates nearest prime number which is lesser than the entered value
            while (!isPrime)
            {
                num1--;
                isPrime = 1;

                for (int i = 2; (i * i) <= num1; ++i)
                {
                    if(num1 % i == 0)
                    {
                        isPrime = 0;
                        break;
                    }
                }
            }

            // Calculates nearest prime number which is greater than the entered value
            isPrime = 0;

            while (!isPrime)
            {
                num2++;
                isPrime = 1;
                for (int i = 2; (i * i) <= num2; ++i)
                {
                    if(num2 % i == 0)
                    {
                        isPrime = 0;
                        break;
                    }
                }
            }
            // Calculate distances between prime numbers and the entered value
            distance1 = (num - num1);
            distance2 = (num2 - num);
            
            // Print out the nearest value
            if (distance1 == distance2)
            {
                printf("%lld is not prime, nearest prime numbers are : %d ir %d\n", num, num1, num2);
            }
            else if (distance1 < distance2 && num != 1) //The number 1 is not considered PRIME
            {
                printf("%lld is not prime, nearest prime number is : %d\n", num, num1);
            }
            else
            {
                printf("%lld is not prime, nearest prime number is : %d\n", num, num2);
            }
        }
    } while (1);
        
    return 0;
}