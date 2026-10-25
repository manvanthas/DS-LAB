#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define MAX 100
 typedef struct {
    int data[MAX];
    int top;
} Stack;

void initialize(Stack *stack){
    stack ->top=-1;
}

int isEmpty(Stack *stack){
    return stack ->top==-1;
}

int isFull(Stack *stack){
    return stack ->top==MAX-1;
}

void push(Stack *stack,int value){
    if(isFull(stack)){
        return;
    }
    stack ->top++;
    stack ->data[stack ->top]=value;
}

int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("stack is empty\n");
        return -1;
    }
    int value=stack ->data[stack->top];
    stack ->top--;
    return value;

}

void displaystack(Stack *stack){
    if(isEmpty(stack)){
        printf("stack is empty\n");
        return;

    }
    printf("stack elements are >> ");
    for(int i=0;i<=stack ->top;i++){
        printf("%d",stack ->data[i]);
    }
}

void checkpalindrome(char *str){
    Stack s;
    initialize(&s);
    int len= strlen(str);
    for(int i=0;i<len;i++){
        push(&s,str[i]);
    }
    for(int i=0;i<=len/2;i++){
       if(pop(&s)!=str[i]){
        printf("not a palindrome");
        return;
       }
    }
    printf("it is a palindrome");
}

int main(){
    Stack stack;
    initialize(&stack);

    int choice,value;
    char str[MAX];

    while(1){
        printf("Menu\n");
        printf("1. push\n");
        printf("2.pop\n");
        printf("3.palindrome\n");
        printf("4.display\n");
        printf("exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                 printf("enter the integer to push\n");
                 scanf("%d",&value);
                 push(&stack,value);
                 break;
            case 2:
                 value =pop(&stack);
                 if(value !=-1){
                    printf("popped value is %d",value);
                 }
                 break;
            case 3:
                 printf("enter a string to check plaindrome: ");
                 scanf("%s",str);
                 checkpalindrome(str);
                 break;
            case 4:
                 displaystack(&stack);
                 break;
            case 5:
                 exit(0);
            default:
                 printf("INVALID CHOICE");
        }
    }
}