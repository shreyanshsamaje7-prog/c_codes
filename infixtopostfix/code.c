#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
    if(top < MAX-1) stack[++top] = c;
}

char pop(){
    if(top == -1) return '\0';
    return stack[top--];
}

char peek(){
    if(top == -1) return '\0';
    return stack[top];
}

int precedence(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

int isOperator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/';
}

int main(){
    char infix[MAX], postfix[MAX];
    int i, k = 0;
    if(scanf("%s", infix)!=1) return 0;
    int n = strlen(infix);
    for(i = 0; i < n; i++){
        char c = infix[i];
        if(isalnum((unsigned char)c)){
            postfix[k++] = c;
        } else if(c == '('){
            push(c);
        } else if(c == ')'){
            while(top != -1 && peek() != '('){
                postfix[k++] = pop();
            }
            if(peek() == '(') pop();
        } else if(isOperator(c)){
            while(top != -1 && isOperator(peek()) && precedence(peek()) >= precedence(c)){
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while(top != -1){
        if(peek() != '(' && peek() != ')') postfix[k++] = pop();
        else pop();
    }
    postfix[k] = '\0';
    printf("%s\n", postfix);
    return 0;
}
