#include <stdio.h>

int arr[100];
int size;

void Insert(int loc, int val) {
    if (loc > size || loc < 0) {
        printf("invalid location\n");
    } else {
        for (int i = size; i > loc; i--) {
            arr[i] = arr[i - 1];
        }
        arr[loc] = val;
        size++;
        printf("element inserted successfully \n");
    }
}

void Delete(int loc) {
    if (loc >= size || loc < 0) {
        printf("invalid location\n");
    } else {
        for (int i = loc; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        printf("element deleted successfully \n");
    }
}

void Display() {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Break() {
    printf("exiting the program \n");
}

int main() {
    int i, loc, val, choice;
    
    printf("enter the size of array: ");
    scanf("%d", &size);
    
    printf("enter the elements of an array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    while (1) {
        // Clean menu string fixed without stray numbers or linebreaks
        printf("\nenter the choice you want to select:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. display array\n");
        printf("4. exit the program\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("enter your new element: ");
                scanf("%d", &val);
                printf("enter the location to be inserted in the array: ");
                scanf("%d", &loc);
                Insert(loc, val);
                break;
                
            case 2:
                printf("enter the location to be deleted in the array: ");
                scanf("%d", &loc);
                Delete(loc);
                break;
                
            case 3:
                printf("the array is >> ");
                Display();
                break;
                
            case 4:
                Break();
                return 0;
                
            default:
                printf("invalid choice\n");
                break;
        }
    }
    
    return 0;
}