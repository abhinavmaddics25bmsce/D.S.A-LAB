#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push();
void pop();
void display();
int main(){
    int choice;
    while(1){
        printf("STACK OPERATIONS\n");
        printf("1.push 2.pop 3.display 4.exit\n");
        printf("Enter your choice(1-4):\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice\n");

        }
    }
    return 0;
}
void push(){
    int value;
    if (top==MAX-1){
        printf("Stack is full\n");
    }
    else{
        printf("Enter value to be pushed:\n");
        scanf("%d",&value);
        top++;
        stack[top]=value;
    }
}
void pop(){
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        printf("Popped %d from the stack\n",stack[top]);
        top--;
    }
}
void display(){
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("|%d|\n",stack[i]);
        }
    }

}
