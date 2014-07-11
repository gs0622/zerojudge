/*d873: 00465 - Overflow*/
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct {
    int len; /*digit length*/
    char dig[1024]; /*digit: MSB...LSB*/
    int rev[1024]; /*reversed digit, LSB...MSB*/
} bignum_t;

static void dig2rev(char *p, int *q, int len)
{
    char *m=p;
    int *n=q+len;
    for(*n--=0; n>=q; ++m, --n) *n=*m-'0';
}

static void rev2dig(int *p, char *q, int len)
{
    int *m=p;
    char *n=q+len;
    assert(p&&q);
    for(*n--=0; n>=q; ++m, --n) *n=*m+'0';
}

static void numbering(bignum_t *p)
{
    assert(p);
    p->len=strlen(p->dig), dig2rev(p->dig, p->rev, p->len);
}

static int cmp(bignum_t *p, bignum_t *q)
{
    assert(p&&q);
    if (p->len > q->len) return 1;
    else if (p->len < q->len) return -1;
    else { /*p->len == q->len*/
        int i;
        for (i=0;i<p->len;i++) {
            if (p->dig[i] > q->dig[i]) return 1;
            else if (p->dig[i] < q->dig[i]) return -1;
        }
        return 0; /*equal*/
    }
}

static void plus(bignum_t *p, bignum_t *q, bignum_t *r)
{
    int i, max;
    r->len = max = (p->len > q->len)? p->len:q->len;
    for (i=0;i<max;i++) {
        r->rev[i]+=p->rev[i]+q->rev[i];
        if (r->rev[i]>9) { /*carry*/
            if (i+1==max) r->len++;
            r->rev[i]-=10, r->rev[i+1]+=1;
        }
    }
    rev2dig(r->rev, r->dig, r->len);
}

static void mult(bignum_t *p, bignum_t *q, bignum_t *r)
{
    int i, j;
    r->len = p->len + q->len + 1;
    for (i=0;i<p->len;i++)
        for (j=0;j<q->len;j++)
            r->rev[i+j] += p->rev[i] * q->rev[j];
    for (i=0;i<r->len;i++) r->rev[i+1]+=r->rev[i]/10, r->rev[i] %= 10;
    for (i=r->len-1;r->rev[i]==0;i--) r->len--; 
    rev2dig(r->rev, r->dig, r->len);
}

int main(void)
{
    char operator;
    bignum_t operand[4];
    memset(operand, 0, sizeof(bignum_t)*4);
    sprintf(operand[3].dig, "%d", 2147483247), numbering(&operand[3]);
    while (scanf("%s %c %s", operand[0].dig, &operator, operand[1].dig)==3) {
        numbering(&operand[0]), numbering(&operand[1]);
        printf("%s %c %s\n", operand[0].dig, operator, operand[1].dig);
        if (cmp(&operand[0], &operand[3])>0)
            printf("first number too big\n");
        if (cmp(&operand[1], &operand[3])>0)
            printf("second number too big\n");
        if ('+'==operator) plus(&operand[0], &operand[1], &operand[2]);
        else if ('*'==operator) mult(&operand[0], &operand[1], &operand[2]);
        if (cmp(&operand[2], &operand[3])>0)
            printf("result too big\n");
    }   
    return 0;
}

