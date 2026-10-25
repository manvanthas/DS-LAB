#include <stdio.h>
#include <string.h>
#define MAX 20

typedef struct {
    char name[100];
    int account_number;
    float balance;
} Customer;

void printCustomerWithLowBalance(Customer customers[], int count) {
    printf("Customers with balance <= $200:\n");
    for (int i = 0; i < count; i++) {
        if (customers[i].balance <= 200) {
            printf("%s\n", customers[i].name); // Added newline for proper output separation
        }
    }
}

void UpdateCustomersWithHighBalance(Customer customers[], int count) {
    printf("Customers with balance >= 1000 after adding $100:\n");
    for (int i = 0; i < count; i++) {
        if (customers[i].balance >= 1000) {
            customers[i].balance += 100;
            printf("%d %.2f\n", customers[i].account_number, customers[i].balance); // Added newline
        }
    }
}

int main() {
    int i, numCustomers;  
    Customer customers[MAX];
    printf("Enter the number of customers:\n");
    scanf("%d", &numCustomers);
    
    // Input customer information
    for (i = 0; i < numCustomers; i++) {
        printf("Enter name %d:\n", i + 1);
        scanf("%s", customers[i].name);
        printf("Enter account number for customer %d:\n", i + 1);
        scanf("%d", &customers[i].account_number);
        printf("Enter balance for customer %d:\n", i + 1);
        scanf("%f", &customers[i].balance);
    }

    printCustomerWithLowBalance(customers, numCustomers);
    UpdateCustomersWithHighBalance(customers, numCustomers); 
    
    return 0;
}