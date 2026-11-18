#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isPrime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void calculator()
{
    float number1, number2;
    char op;

    printf("Enter first number: ");
    scanf("%f", &number1);

    printf("Enter second number: ");
    scanf("%f", &number2);

    printf("Enter operator (+ - * /): ");
    scanf(" %c", &op);

    switch (op)
    {
    case '+':
        printf("Result: %.2f\n", number1 + number2);
        break;
    case '-':
        printf("Result: %.2f\n", number1 - number2);
        break;
    case '*':
        printf("Result: %.2f\n", number1 * number2);
        break;
    case '/':
        if (number2 == 0)
        {
            printf("Error: cannot divide by zero\n");
        }
        else
        {
            printf("Result: %.2f\n", number1 / number2);
        }
        break;
    default:
        printf("Invalid operator\n");
    }
}

void multiplicationTable()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n", n, i, n * i);
    }
}

void primeChecker()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num))
    {
        printf("%d is a prime number\n", num);
    }
    else
    {
        printf("%d is not a prime number\n", num);
    }
}

void guessingGame()
{
    srand(time(NULL));
    int secret = rand() % 100 + 1;
    int guess, attempts = 0;

    printf("Guess the number between 1 and 100\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > secret)
        {
            printf("Too high\n");
        }
        else if (guess < secret)
        {
            printf("Too low\n");
        }
        else
        {
            printf("Correct! You won in %d attempts\n", attempts);
        }
    } while (guess != secret);
}

int main()
{
    int choice;
    do
    {
        printf("\n====MINI TOOLKIT=====\n");
        printf("1. Calculator\n");
        printf("2. Multiplication table\n");
        printf("3. Prime number checker\n");
        printf("4. Guessing game\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            calculator();
            break;
        case 2:
            multiplicationTable();
            break;
        case 3:
            primeChecker();
            break;
        case 4:
            guessingGame();
            break;
        case 5:
            printf("Bye!\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}