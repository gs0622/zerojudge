/*big number*/
#include <stdio.h>
#include <string.h>

typedef struct {
    int len; /*digit length*/
    char dig[1024]; /*digit*/
    int rev[1024]; /*reversed digit*/
} bignum_t;

void digrev(char *p, int *q, int len)
{
    char *m=p;
    int *n=q+len;
    for(*n--=0; n>=q; ++m, --n) *n=*m-'0';
}

void revdig(int *p, char *q, int len)
{
    int *m=p;
    char *n=q+len;
    for(*n--=0; n>=q; ++m, --n) *n=*m+'0';
}

void numbering(bignum_t *p)
{
    memset(p->rev, 0, 1024);
    p->len=strlen(p->dig), digrev(p->dig, p->rev, p->len);
}

void plus(bignum_t *p, bignum_t *q, bignum_t *r)
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
    revdig(r->rev, r->dig, r->len);
}

int largethan(bignum_t *p, bignum_t *q)
{
    int cmp = (p->len == q->len)? strcmp(p->dig, q->dig) : (p->len - q->len);
    return cmp = (cmp >= 0)? 1: 0;
}

void minus(bignum_t *p, bignum_t *q, bignum_t *r)
{
    int i, max, cmp = largethan(p, q);
    bignum_t *m, *n;
    r->len = max = (p->len > q->len)? p->len:q->len;
    if (cmp) m=p, n=q; else m=q, n=p;
    for (i=0;i<max;i++) r->rev[i] += m->rev[i] - n->rev[i];
    for (i=0;i<max;i++) if (r->rev[i]<0) r->rev[i]+=10, r->rev[i+1]-=1;
    for (i=max-1;i>0&&r->rev[i]==0;i--, r->len--);
    if (cmp) revdig(r->rev, r->dig, r->len);
    else r->dig[0]='-', revdig(r->rev, r->dig+1, r->len);
}

void mul(bignum_t *p, bignum_t *q, bignum_t *r)
{
    int i, j;
    memset(r->rev, 0, sizeof(r->rev));
    r->len = p->len + q->len + 1;
    for (i=0;i<p->len;i++)
        for (j=0;j<q->len;j++)
            r->rev[i+j] += p->rev[i] * q->rev[j];
    for (i=0;i<r->len;i++) r->rev[i+1]+=r->rev[i]/10, r->rev[i] %= 10;
    for (i=r->len-1;r->rev[i]==0;i--) r->len--; 
    revdig(r->rev, r->dig, r->len);
}

void div(bignum_t *p, bignum_t *q, bignum_t *r)
{
    int i, j, cmp = largethan(p, q);
    bignum_t a={};
    if (!cmp) {
        r->dig[0]='0';
        goto out;
    }
    for (i=0;i<p->len;i++) {
        strncat(a.dig, &p->dig[i], 1), numbering(&a);
        cmp = largethan(&a, q);
        if (!cmp && strcmp(r->dig, "0")>0) r->dig[r->len++]='0';
        if (!cmp) continue;
        for (j=9;j>0;j--) {
            bignum_t b={}, c={}; 
            sprintf(b.dig, "%d", j), numbering(&b);
            mul(q, &b, &c);
            cmp = largethan(&a, &c);
            if (cmp) {
                bignum_t d={};
                minus(&a, &c, &d);
                r->dig[r->len++]=b.dig[0];
                a = d;
                /*printf("b=%s a=%s r=%s\n", b.dig, a.dig, r->dig);*/
                if (0==strcmp(a.dig, "0")) a.dig[0]=0;
                break;
            }
        }
    }
out: return;
}

int main(void)
{
    char operator[4];
    bignum_t x, y;
#if 0
    freopen("a021.in", "r", stdin);
#endif  
    while (scanf("%s", x.dig)!=EOF) {
        bignum_t z = {};
        scanf("%s", operator); /*scanf() matches non-white-space characters*/
        scanf("%s", y.dig);
        numbering(&x), numbering(&y);
        switch (operator[0]) {
        case '+': plus(&x, &y, &z); break;
        case '-': minus(&x, &y, &z); break;
        case '*': mul(&x, &y, &z); break;
        case '/': div(&x, &y, &z); break;
        }
        printf("%s\n", z.dig);
    }
    return 0;
}
