#include <stdio.h>
#include <stdlib.h>

void getNumbers(double x, double y)
{
    printf("\nEnter X: ");
    scanf("%lf", &x);
    printf("\nEnter Y: ");
    scanf("%lf", &y);
}

double add(double x, double y){
    return x + y;
}

double sub(double x, double y){
    return x - y;
}

double mul(double x, double y){
    return x * y;
}

double division(double x, double y){
    if(y == 0){
        printf("ERROR: Division by Zero.\n");
        return 0;
    }
    return x / y;
}

int main(){

    double x = 0, y = 0;
    
    int z = 0, w = 0; 
    while (z != 5)
    {
        printf("\n-------------Menu-------------\n| 1.) Addition               |\n| 2.) Subtraction            |\n| 3.) Multiply               |\n| 4.) Division               |\n| 5.) Exit                   |\n------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &z);

        switch (z) // Main menu
        {
        case 1: // Addition
        {
            getNumbers(x, y);
            printf("\nResult: %lf", add(x, y));
            break;
        }
        case 2: // Subtraction
        {
            getNumbers(x, y);
            printf("\nResult: %lf", sub(x, y));
            break;
        }
        case 3: // Multiplication
        {
            getNumbers(x, y);
            printf("\nResult: %lf", mul(x, y));
            break;
        }
        case 4: // Division
        {
            getNumbers(x, y);
            printf("\nResult: %lf", division(x, y));
            break;
        }
        case 5: // Exit program
        {
            printf("\nExiting program...");
            exit(0);
            break;
        }
        default: // Default behavior
        {
            printf("ERROR: Invalid entry.\n");
            break;
        }
        }
    }
    return 0;
}
