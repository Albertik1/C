#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack{
    unsigned int maxTop;
    int top;
    int *data;
}stack_t;

void create(stack_t *st){
    st->maxTop=14;
    st->top=-1;
    st->data=(int *)malloc(sizeof(int));
}

void push(stack_t *st, int num){
    st->data[++st->top]=num;
}

int stack_size(stack_t *st){
    return (st->top)+1;
}

int pop(stack_t *st){
    return st->data[st->top--];
}

int arithmetic(char op, int a, int b){
    if (op == '+')
        return a+b;
    else if (op == '-')
        return a-b;
    else if (op == '*')
        return a*b;
    return a/b;
}



int main(){
    stack_t *s=(stack_t*)malloc(sizeof(stack_t)); char string[100]; int i;
    while(scanf("%s", string) == 1){
        create(s);
        int flag=1;
        for (i=0; i<strlen(string); i++){
            if (isalnum(string[i]) != 0)
                push(s, string[i]-'0');
            else{
                if (stack_size(s) < 2){
                    flag=0;
                    break;
                }
                else
                    push(s, arithmetic(string[i], pop(s), pop(s)));
            }
        }
        if (flag == 0 || stack_size(s)>1)
            printf("Input Error\n");
        else
            printf("%d\n", pop(s));
    }
    return 0;
}
