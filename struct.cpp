#include <stdio.h>
#include <stdlib.h>
typedef struct tagNode
{
	char *p;
	int i;
}pNode;

struct point
{
	int x;
	int y;
};

struct node
{
	int i;
	struct node *p;
};

#define f(x) (x)*(x)
#define ff(x)  x*x
#define fff(x)  ((x)*(x))    //这种写法正确

typedef char *pStr;
char string[4] = "abc";
const char *p1 = string;
const pStr p2 = string;


int main(int argc, char const *argv[])
{
    p1++;
    printf("%s\n",p1);
    p2++;   //error: read-only variable is not assignable

    int a=6, b=2, c, cc, ccc;
    c = f(a);
    cc = ff(a);
    ccc = fff(a);
    printf("c=%d  cc=%d  ccc=%d\n", c, cc, ccc);

    c = f(a)/f(b);
    cc = ff(a)/ff(b);
    ccc = fff(a)/fff(b);
    printf("c=%d  cc=%d  ccc=%d\n", c, cc, ccc);

    node *np;
    np = (node*)malloc(sizeof(node));
    //node np;
    np->i = 1;
    printf("hhhhh:b%d\n",np->i);

    node *oneNode;
    oneNode = (node*)malloc(sizeof(node));
    oneNode->i = 2;

    np->p = oneNode;

    printf("%0x\n", np->p);
    printf("%0x\n", &np->p);

    free(oneNode);
    free(np);

    point pt;
    pt.x = 1;
    pt.y = 2;

	pNode tag;
	tag.p = "hello";
	tag.i = 2;
	printf("%s\n", tag.p);
	printf("%d\n", tag.i);
	return 0;
}