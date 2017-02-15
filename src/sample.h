
#ifdef __GNUC__ 
struct { int test_yoon_a ; } ;
#endif

enum enm1 {White=1, Black=4, Blue=8, Gray=7} test;
typedef enum {Kim, Lee, Park} Enm2;
enum enm3 {On, Off};

typedef struct node {
	enum enm1		a;
	int				b:2;
	unsigned int	c:4;
	char			*d;
	float			e[5];
	struct node		*next;
} Node;

typedef Node*	NodePtr;

union uni {
	Enm2	a;
	int		*c[7][8];
	Node	b;
};


void api1(int a, char b, float c, unsigned long int d, long double e);
enum enm3 api2(enum enm1 a, Enm2 b);
char* api3(char *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa, char b[], char c[10]);
Node* api4(struct node *a, Node b, union uni c);
api5(char *a[], int (*b[])[4][3]);
Node *api6(float *a, struct node (*b)[]);
NodePtr api7(Enm2 a, Node b);
int api8 (Node **a); 
int api9 (NodePtr (*fn1) (Enm2, Node), int (*fn2) (char *[], int (*[])[4][3]),
		Enm2 a, Node b, char *c[], int (*d[])[4][3]);
#ifdef __GNUC__ 
char api10 ( a, b,c,d,e,f );
float api11 ( a, b, c );
#endif
float api12 ( char c );

