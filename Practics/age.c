#include <stdio.h>

void ashram(int count) {
    int age;
    char choice;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 1 && age <= 25)
        printf("You are learning - BRAHMACHARYA ASHRAM\n");
    else if (age >= 26 && age <= 50)
        printf("You are learning - GRIHAST AASHRAM\n");
    else if (age >= 51 && age <= 75)
        printf("You are learning - VANAPRASTHA AASHRAM\n");
    else if (age >= 76 && age <= 100)
        printf("You are learning - SANYAS AASHRAM\n");
        else if (age< 0 )
        printf(" Paida nhi hua  \n");
    else
        printf("Out of KALYUG\n");

    printf("Do you want to continue? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        ashram(count + 1);   // recursive call
    } else if (choice == 'N' || choice == 'n') {
        printf("Thank you very much\n");
        printf("Program executed %d times\n", count);
    } else {
        printf("Incorrect Input\n");
    }
}

int main() {
    ashram(1);
    return 0;
}
