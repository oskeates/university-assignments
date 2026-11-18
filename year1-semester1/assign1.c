#include <stdio.h>
#include <math.h>

int main(){

    char menuInput, operator;
    double num1, num2;

    while (1){

        puts("\n=============================");
        puts("Welcome to the C Calculator!");
        puts("=============================");
        puts("MAIN MENU");
        puts("B -> Binary Operations");
        puts("U -> Unary Operations");
        puts("E -> Exit");
        puts("-----------------------------");

        printf("Enter your choice: ");
        scanf(" %c", &menuInput);

        if (menuInput == 'b' || menuInput == 'B'){
            printf("Enter the first double number: ");
            scanf(" %lf", &num1);
            printf("Enter the second double number: ");
            scanf(" %lf", &num2);

            puts("-----------------------------");
            puts("+ -> addition\n- -> subtraction\n* -> multiplication\n/ -> division\n% -> remainder\nP -> power\nX -> maximum\nI -> minimum");
            puts("-----------------------------");
            printf("Enter binary operator: ");
            scanf(" %c", &operator);

            switch (operator){
                case '+':
                    printf("%.4f + %.4f = %.4f\n", num1, num2, num1 + num2);
                    break;

                case '-':
                    printf("%.4f - %.4f = %.4f\n", num1, num2, num1 - num2);
                    break;

                case '*':
                    printf("%.4f * %.4f = %.4f\n", num1, num2, num1 * num2);
                    break;

                case '/':
                    if (num2 != 0) {
                        printf("%.4f / %.4f = %.4f\n", num1, num2, num1 / num2);
                    } else {
                        puts("ERROR: Division by zero is not allowed");
                        puts("Program terminated");
                        return 1;
                    }
                    break;

                case '%':
                    if (num2 != 0){
                        printf("%.4f %% %.4f = %.4f\n", num1, num2, fmod(num1, num2));
                    } else {
                        puts("ERROR: Number must not equal 0 to use remainder");
                        puts("Program terminated");
                        return 1;
                    }
                    break;
                    
                case 'P':
                case 'p':
                    printf("%.4f ^ %.4f = %.4f\n", num1, num2, pow(num1, num2));
                    break;

                case 'X':
                case 'x':
                    if (num1 > num2){
                        printf("Max = %.4f\n", num1);
                    } else if (num1 < num2){
                        printf("Max = %.4f\n", num2);
                    } else {
                        printf("Equal: %.4f = %.4f\n", num1, num2);
                    }
                    break;
                
                case 'I':
                case 'i':
                    if (num1 < num2){
                        printf("Min = %.4f\n", num1);
                    } else if (num1 > num2){
                        printf("Min = %.4f\n", num2);
                    } else {
                        printf("Equal: %.4f = %.4f\n", num1, num2);
                    }
                    break;
                
                default:
                    puts("ERROR: Invalid Input");
                    puts("Program terminated");
                    return 1;

            }

            puts("Operation completed successfully.");

        } else if (menuInput == 'u' || menuInput == 'U'){
            printf("Enter a double number: ");
            scanf(" %lf", &num1);

            puts("-----------------------------");
            puts("S -> Square Root\nL -> Log\nE -> Exponential\nC -> Ceiling\nF -> Floor\nR -> Reciprocal");
            puts("-----------------------------");
            printf("Enter unary operator: ");
            scanf(" %c", &operator);

            switch (operator){
                case 'S':
                case 's':
                    if (num1 >= 0){
                        printf("sqrt(%.4f) = %.4f\n", num1, sqrt(num1));
                    } else {
                        puts("ERROR: Number must be greater than or equal to 0 to be square rooted");
                        puts("Program terminated");
                        return 1;
                    }
                    break;
                    
                case 'L':
                case 'l':
                    if (num1 > 0){
                        printf("log(%.4f) = %.4f\n", num1, log(num1));
                    } else {
                        puts("ERROR: Number must be greater than 0 to use log");
                        puts("Program terminated");
                        return 1;
                    }
                    break;

                case 'E':
                case 'e':
                    printf("e^%.4f = %.4f\n", num1, exp(num1));
                    break;

                case 'C':
                case 'c':
                    printf("ceil(%.4f) = %.4f\n", num1, ceil(num1));
                    break;

                case 'F':
                case 'f':
                    printf("floor(%.4f) = %.4f\n", num1, floor(num1));
                    break;

                case 'R':
                case 'r':
                    if (num1 != 0){
                        printf("1 / %.4f = %.4f\n", num1, 1.0/num1);
                    } else {
                        puts("ERROR: Number must not be 0 to use reciprocal");
                        puts("Program terminated");
                        return 1;
                    }
                    break;
                
                default:
                    puts("ERROR: Invalid input");
                    puts("Program terminated");
                    return 1;
            }

            puts("Operation completed successfully.");

        } else if (menuInput == 'e' || menuInput == 'E'){
            puts("Thank you for using the calculator!\nGoodbye!");
            return 0;

        } else {
            puts("ERROR: Invalid menu choice");
            puts("Program terminated.");
            return 1;
        }

    }

}