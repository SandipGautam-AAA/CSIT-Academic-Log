// Infix to Postfix Conversion using Stack

#include<stdio.h>
#include<ctype.h>  // isalnum() , isalpha(), isdigit()

#define MAX 20

char Stack[MAX];
int top = -1;

void push(char x) 
{
    if (top == MAX - 1) 
    {
        printf("Stack overflow\n");
        return;
    }
    Stack[++top] = x;
}

char pop(){
    if(top == -1){{ 
        printf("Stack underflow\n");
        return '\0';
    }
    }
    return Stack[top--];
}

int priority(char x){
    if(x == '(') return 0;
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    if(x == '^') return 3;

    return -1;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int k = 0;
    char x;
    printf("Enter infix Expression: ");
    scanf("%s", infix);   //A+B-(C*D/E)\0

    for(int i = 0; infix[i] != '\0'; i++){
        if(isalnum(infix[i]))
        {
            postfix[k++] = infix[i];
        } 
        else if(infix[i] == '(') 
        {
            push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while((x = pop()) != '(')
            {
                postfix[k++] = x;
            }
            // pop();
        }
        else 
        {
            int Priority = priority(infix[i]);
            while(top != -1 && (priority(Stack[top]) >= priority(infix[i]))) 
            {
                postfix[k++] = pop();
            }

            push(infix[i]);
        }
    }
    while(top != -1){
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; 
    printf("Postfix Expression: %s\n", postfix);


    return 0;

}