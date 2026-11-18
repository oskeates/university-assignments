#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {

    int n, menu, min = 0, max = 0, cont = 1;

    double a, sum=0, highest, lowest;

    srand(time(NULL));

    printf("Enter the size of the array: ");
    
    //input validation
    do {
        if (scanf(" %d", &n) != 1) {
            scanf(" %*c");
            printf("Invalid input, input an integer > 0: ");
        }

        if (n <= 0) {
            printf("Invalid input, input an integer > 0: ");
        }
    } while (n <= 0);

    //list initialization
    float list[n];

    for (int i = 0; i < n; i++) {
        list[i] = 0;
    }
    while (cont) {

        //home menu
        puts("===================================");
        puts("           Array Menu");
        puts("===================================");

        printf("Current array: ");
        for (int k = 0; k < n; k++) {
            printf("%.2f ", list[k]);
        }

        puts("\n");
        printf("1. Reset Array\n2. Scalar Addition\n3. Scalar Multplication\n4. Print Statistics\n5. Reverse Array\n6. Sort Array\n7. Exit\n\n");
        printf("Enter your choice: ");

        //input validation
        do {
            if (scanf(" %d", &menu) != 1) {
                scanf(" %*c");
                printf("Invalid input, input an integer between 1 and 7 inclusive: ");
            } else if (menu > 7 || menu < 1) {
                printf("Invalid input, input an integer between 1 and 7 inclusive: ");
            }
        } while (menu > 7 || menu < 1);

        switch (menu) {
            case 1: //Reset array
                //input validation
                do {
                    if (min > max) {
                        printf("Invalid input, min must be less than max\n");
                    }

                    printf("Enter minimum integer: ");
                    scanf(" %d", &min);

                    printf("Enter maximum integer: ");
                    scanf(" %d", &max);
                } while (min > max);

                for (int i = 0; i < n; i++) {
                    list[i] = min + rand() % (max - min + 1);
                }

                puts("Array reset completed.");
                break;

            case 2: //Scalar addition
                printf("Enter an integer: ");

                //input validation
                do {
                    if (scanf(" %lf", &a) != 1) {
                        scanf(" %*c");
                        printf("Invalid input, enter an integer: ");
                    } else {
                        break;
                    }
                } while (1);

                for (int i = 0; i < n; i++) {
                    list[i] += a;
                }

                puts("Scalar addition completed.");
                break;
            
            case 3: //Scalar Multiplication
                //Input validation
                printf("Enter a non-zero integer: ");
                do {
                    if (scanf(" %lf", &a) != 1) {
                        scanf(" %*c");
                        printf("Invalid input, enter a non-zero integer: ");
                    } else if (a == 0) {
                        printf("Invalid input, enter a non-zero integer: ");
                    }
                } while (a == 0);

                for (int i = 0; i < n; i++) {
                    list[i] *= a;
                }
                
                puts("Scalar multiplication completed.");
                break;

            case 4: //Print statistics
                sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += list[i];
                }

                printf("Mean: %.2f\n", (double)sum / n);

                highest = list[0];
                lowest = list[0];

                for (int j = 0; j < n; j++) {
                    if (list[j] > highest) {
                        highest = list[j];
                    } else if (list[j] < lowest) {
                        lowest = list[j];
                    }
                }

                printf("Maximum: %.2f\n", highest);
                printf("Minimum: %.2f\n", lowest);

                puts("Calculating statistics completed.");
                break;

            case 5: // Reverse array
                for (int i = 0; i <= ((n - 1) / 2); i++) {
                    double temp = list[i];

                    list[i] = list[(n - 1) - i];

                    list[(n - 1) - i] = temp;
                }

                puts("List reversed.");
                break;

            case 6: //Sort array
                for (int i = 0; i < n - 1; i++) {
                    for (int k = 0; k < n - i - 1; k++){
                        if (list[k] > list[k + 1]){
                            double temp = list[k];
                            list[k] = list[k + 1];
                            list[k + 1] = temp;
                        }
                    }
                }

                puts("Array sorting complete.");
                break;

            case 7: //Exit
                cont = 0;
                puts("Exiting the program.");
                puts("Goodbye!");
                break;

        }

    }


}