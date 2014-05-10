#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int priority(char op) { 
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        default: return 0;
    } 
}

void rpn(char *in, char *out) { /*Reverse Polish Notation, a.k.a infix to postfix*/
    char postfix[1024] = {};
    int ii, oo, pp;
    for (ii=0,oo=0,pp=0; in[ii]!='\0';)
    switch (in[ii]) {
        case '(':
            postfix[++pp] = in[ii++]; break;
        case '+': case '-': case '*': case '/':  case '%':
            while (priority(postfix[pp]) >= priority(in[ii])) out[oo++] = postfix[pp--];
            postfix[++pp] = in[ii++];
            break;
        case ')':
            while (postfix[pp] != '(') out[oo++] = postfix[pp--];
            pp--,ii++;
            break;
        default: out[oo++] = in[ii++];
    }
    while (pp > 0) out[oo++] = postfix[pp--];
    out[oo]='\0'; /*null-terminator*/
}

static int calculate(char *s)
{
    int i, stack[1024], top=-1;
    for (i=0;i<strlen(s);) {
        switch (s[i]) {
        case '+': case '-': case '*': case '/':  case '%': {
                int b=stack[top--], a=stack[top--]; /*operand in stack order*/
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
                char operand[64]={};
                int len=0;
                while (isdigit((int)s[i])) operand[len++]=s[i++];
                stack[++top] = atoi(operand);
                break;
            }
        default: i++; break;
        }
    }
    return stack[0];
}

int main(void)
{
    char infix[1024], postfix[1024];
#if 0
    freopen("a017.in", "r", stdin);
#endif
    while (gets(infix)) {
        rpn(infix, postfix);
        /*puts(postfix);*/
        printf("%d\n", calculate(postfix));
    }
    return 0;
}
