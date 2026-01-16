#include<stdio.h>
#define size 5
int top = -1;
int stack[size];

int isfull() {
    if(top == size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isempty() {
    if(top == -1){
        return 1;
    } else {
        return 0;
    }
}

void push(int data) {
    if(!isfull()) {
        stack[++top] = data;
        printf("Pushed: %d\n", data);
    } else {
        printf("Stack OverFlow.\n");

    }
}

int pop(){
    if(!isempty()) {
        int data = stack[top];
        top--;
        return data;
    } else {
        printf("Stack is UnderFlow\n");
    }
}

int peek() {
    if(!isempty()) {
        return stack[top];
    } else {
        printf("No element in stack.\n");
    }
}

void display() {
    if(!isempty()){
        for(int i=top; i>-1; i--){
            printf("%d  ", stack[i]);
        }
    }
}

int main() {
    pop();
    push(10);
    push(30);
    push(40);
    push(60);
    push(34);

    push(39);

    display();

    printf("\nPoped: %d\n", pop());
    display();


    return 0;
}