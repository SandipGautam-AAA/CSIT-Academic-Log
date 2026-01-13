#include <stdio.h>
#define MAX 50

int top = -1; // empty stack
int stack[MAX];

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    if (!isfull())
    {
        stack[++top] = data;
        printf("Pushed: %d\n", data);
    }
    else
    {
        printf("Stack is OverFlow:\n");
    }
}

void pop()
{
    if (!isempty())
    {
        int data = stack[top--];
        printf("Popped: %d\n", data);
    }
    else
    {
        printf("Stack is Underdflow\n");
    }
}

void display()
{
    if (!isempty())
    {
        for (int i = top; i > -1; i--)
        {
            printf("%d \n", stack[i]);
        }
    }
    else
    {
        printf("Stack is Underflow.\n");
    }
}

void peek()
{
    if (!isempty())
    {
        printf("Peak: %d\n", stack[top]);
    }
    else
    {
        printf("Stack is UnderFlow.\n");
    }
}

int main()
{

    do
    {
        printf("+----------------------+\n");
        printf("|      STACK MENU      |\n");
        printf("+----------------------+\n");
        printf("|  P[O]p               |\n");
        printf("|  P[U]sh              |\n");
        printf("|  P[E]ek              |\n");
        printf("|  D[I]splay           |\n");
        printf("|  E[X]it              |\n");
        printf("+----------------------+\n");

        char choice;
        printf("Enter your Choice: ");
        scanf(" %c", &choice);
        switch (choice)
        {
        // Case for Pop
        case 'o': case 'O':
            pop();
            break;

        // Case for Push
        case 'u': case 'U':
        {
            int data;
            printf("Enter the number: ");
            scanf("%d", &data);
            push(data);
            break;
        }

        // Case for Peek
        case 'e': case 'E':
            peek();
            break;

        // Case for Display
        case 'i': case 'I':
            display();
            break;

        // Case for Exit
        case 'x': case 'X':
            printf("Exiting.....");
            // Note: 'break' here only exits the switch.
            // break;
            return 0;

        // Equivalent to 'else'
        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (1);

    return 0;
}