#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int priority(char op) { 
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        default: return 0;
    } 
}

void rpn(char *in, char *out) { /*Reverse Polish Notation, a.k.a infix to postfix*/
    char stack[1024] = {};
    int i, j, top;
    for (i=0,j=0,top=0; in[i]!='\0'; i++)
    switch (in[i]) {
        case '(':
            stack[++top] = in[i]; break;
        case '+': case '-': case '*': case '/':  case '%':
            while (priority(stack[top]) >= priority(in[i])) out[j++] = stack[top--];
            stack[++top] = in[i];
            break;
        case ')':
            while (stack[top] != '(') out[j++] = stack[top--];
            top--;
            break;
        default: out[j++] = in[i];
    }
    while (top > 0) out[j++] = stack[top--];
}

static int calculate(char *s)
{
    char operand[32];
    int i, stack[64], top=-1;
    for (i=0;i<strlen(s);) {
        switch (s[i]) {
        case '+': case '-': case '*': case '/':  case '%': {
                int a=stack[top--], b=stack[top--];
                if ('+'==s[i]) stack[++top]=a+b;
                else if ('-'==s[i]) stack[++top]=a-b;
                else if ('*'==s[i]) stack[++top]=a*b;
                else if ('/'==s[i]) stack[++top]=a/b;
                else if ('%'==s[i]) stack[++top]=a%b;
                i++;
                break;
            }
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9': {
                int len=0;
                while (s[i]>='0'&&s[i]<='9'&&s[i]!=' '&& s[i]) operand[len++]=s[i++];
                stack[++top] = atoi(operand);
                break;
            }
        default: i++; break;
        }
    }
    return stack[top];
}

int main(void)
{
    char infix[1024], postfix[1024];
#if 0
    freopen("a017.in", "r", stdin);
#endif
    while (gets(infix)) {
        rpn(infix, postfix);
        printf("%d\n", calculate(postfix));
    }
    return 0;
}
