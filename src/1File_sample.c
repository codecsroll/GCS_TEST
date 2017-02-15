/*	
 * 		GCC가 아닌경우에는 common C feature ( older than C99)만을
 * 		사용하도록 code가 만들어져 있다.
 *
 * 		그러므로 full testing purpose인 경우에는 gcc를 사용하고
 * 		그외 다른 compiler에 대해서는common C feature에 문제가 없는지를
 * 		확인하는 방식으로 사용하면 된다.
 */
#include	<stdio.h>
#include	<stdlib.h>
#include	"sample.h"

#ifdef __GNUC__ 
struct { int test_yoon_a ; } ;
#else
static struct { int test_yoon_a ; } ;
#endif

char	*e1[] = {"", "White", "", "", "Black", "", "", "Gray", "Blue"};
char	*e2[] = {"Kim", "Lee", "Park"};
char	*e3[] = {"On", "Off"} ;
char * get_func_name ( void *fn_addr ) ;


main( int argc, char* argv[] )
{
	int i = 0 ;

	printf("=========== int main( int argc, char* argv[] ): Input ===================\n");
	printf("argc:%d\n", argc);
	for (i=0; i < argc-1 ; i++ ) {
		printf("argv[%d]=\"%s\"\n", argv[i] );
	}
	printf("=========== Input end ===================\n");

	api12 ( 'a' ) ;
	printf("\n=========== int main( int argc, char* argv[] ): Output ===================\n");
	printf("no explicit return\n");
	printf("=========== Output end ===================\n");
}

void api1(int a, char b, float c, unsigned long int d, long double e)
{
	long double	ret;

	int i;
    int j;
    int k;
	printf("=========== void api1(int a, char b, float c, unsigned long int d, long double e) Input ===================\n");
	printf("int a: %d\n", a);
	printf("char b: %c\n", b);
	printf("float c: %f\n", c);
	printf("unsigned long int d: %ul\n",d);
	printf("long double e: %Le\n", e);
	printf("=========== Input end ===================\n");

	
	ret = 1.0;
	
	while ( b != 0 ) {
		if ( a < 10 )
			ret -= a;
		else
			ret += a;
		if ( d > 50 )
			ret += d;
		b--;
	}
	
	if ( c != 0 )
		ret *= c;
	
	if ( e != 0 )
		ret *= e;
	else
		ret *= 2;
	

	printf("\n=========== enum enm3 api2(enum enm1 a, Enm2 b) Output ===================\n");
	printf("long double :  %Le\n", ret ) ;
	printf("=========== Output end ===================\n");
}

enum enm3 api2(enum enm1 a, Enm2 b)
{
	enum enm3	ret;
	
	printf("=========== enum enm3 api2(enum enm1 a, Enm2 b) Input ===================\n");
	printf("enum enm1 (1,4,7,8): %d\n", a );
	printf("enum enm1 (White, Black, Gray, Blue): %s\n", e1[a]);
	printf("Enm2 (0,1,2): %d\n", b);
	printf("Enm2 (Kim, Lee, Park): %s\n", e2[b]);
	printf("=========== Input end ===================\n");

	
	ret = (a - b) % 2;
	
	printf("\n=========== enum enm3 api2(enum enm1 a, Enm2 b) Output ===================\n");
	printf("enum enm3 (0,1): %d\n", ret);
	printf("enum enm3 (On, Off): %s\n", e3[ret]);
	printf("=========== Output end ===================\n");
	return ret;
}

char* api3(char *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa, char b[], char c[10])
{
	char	*ret;
	printf("=========== char* api3(char *a, char b[], char c[10]) Input ===================\n");
	printf("char *a:%s\n", aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa?aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa:"NULL" );
	printf("char b[]:%s\n", b?b:"NULL" );
	printf("char c[10]:%s\n", c?c:"NULL" );
	printf("=========== Input end ===================\n");

	ret = (char*)malloc(strlen(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa)+strlen(b)+strlen(c)+1);
	strcpy(ret, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa);
	strcat(ret, b);
	strcat(ret, c);

	printf("\n=========== char* api3(char *a, char b[], char c[10]) Output ===================\n");
	printf("char *ret : %s\n", ret?ret:"NULL" ) ;
	printf("=========== Output end ===================\n");
	return ret;
}

void show_node(char *old_indent, NodePtr node)
{
	int		i;
	char	*indent;
	indent = (char *) calloc ( 1000, sizeof (char) ) ;

	printf("=========== void show_node(char *old_indent, NodePtr node) Input ==================\n");
	sprintf(indent, "\t%s", old_indent) ;

	if (node == (void *)0) {
		printf ("%sNodePtr node : NULL\n", indent);
		return;
	}

	printf("%senum enm1 node->a (1,4,7,8):%d\n",indent, node->a);
	printf("%senum enm1 node->a (White, Black, Gray, Blue):%s\n",indent, e1[node->a]);
	printf("%sint node->b:2 :%d\n", indent, node->b);
	printf("%sunsigned int node->c:4 : %d\n", indent, node->c);
	printf("%schar * node->d : %s\n", indent, (node->d)?(node->d):"NULL");
	for ( i=0; i<5 ; i++ ) 
			printf("%sfloat node->e[%d] (size 5): %f\n", indent, i, node->e[i] ) ;
	if ( node->next != (NodePtr)NULL ) {
			printf("\tstruct * node->next: %x\n", node->next );
			show_node (indent, node->next);
	} else 
			printf("\tstruct * node-> next:NULL\n");
	printf("=========== Input end ===================\n");

	printf("\n=========== void show_node(char *old_indent, NodePtr node) Output ===================\n");
	printf("void\n");
	printf("=========== Output end ===================\n");
}

void show_uni(union uni *a)
{
	int		i, j;
	printf("=========== void void show_uni(union uni *a)               Input ==================\n");
	printf("Enm2 a->a (0,1,2): %d\n", a->a);
	printf("Enm2 a->a (Kim, Lee, Park): %s\n", e2[a->a]);
	for ( i=0; i<7; i++ ) {
		for ( j=0; j<8; j++ )
			printf("*(int *a->c [%d][%d]) (size [7][8]): %d\n",  *(a->c[i][j]) );
	}
	printf("Node a->b\n");
	show_node("\t", &(a->b) );
	printf("=========== Input end ===================\n");


	printf("\n=========== void show_node(char *old_indent, NodePtr node) Output ===================\n");
	printf("void\n");
	printf("=========== Output end ===================\n");
}

cp_node(NodePtr dest, NodePtr src)
{
	int		i;

	printf("=========== int cp_node(NodePtr dest, NodePtr src)             Input ==================\n");
	printf("NodePtr dest : %x\n", dest);
	show_node ("\t", dest);
	printf("NodePtr src : %x\n", src);
	show_node ("\t", src);
	printf("=========== Input end ===================\n");

	if ( dest == (NodePtr)NULL )
		return;
	if ( src == (NodePtr)NULL )
		return;

	dest->a = src->a;
	dest->b = src->b;
	dest->c = src->c;
	if ( src->d != (char*)NULL ) {
		dest->d = (char*)malloc(strlen(src->d)+1);
	}
	for ( i=0; i<5; i++ )
		dest->e[i] = src->e[i];
	dest->next = src->next;
	printf("\n=========== int cp_node(NodePtr dest, NodePtr src)             Output ==================\n");
	printf("no explicit return\n");
	printf("=========== Output end ===================\n");
}

Node* api4(struct node *a, Node b, union uni c)
{
	Node	*ret;
	printf("=========== Node* api4(struct node *a, Node b, union uni c)    Input ==================\n");
	printf("struct node * a: %x\n", a);
	show_node ("\t", a);
	printf("Node &b: %x\n", &b) ;
	show_node ("\t", &b);
	printf("union uni &c: %x\n", &c);
	show_uni ( &c);
	printf("=========== Input end ===================\n");

	
	ret = (Node*)malloc(sizeof(Node));
	cp_node(ret, a);
	
	printf("\n=========== Node* api4(struct node *a, Node b, union uni c)    Output ==================\n");
	printf("Node * : %x\n", ret);
	show_node ( "\t", ret ) ;
	printf("=========== Output end ===================\n");
	return ret;
}

api5(char *a[], int (*b[])[4][3])
{
	int		i=0, j=0, k=0;
	
	printf("=========== api5(char *a[], int (*b[])[4][3])  Input ==================\n");
	while ( a[i] != (char*) NULL ){ 
		i++ ;
		printf("char *a[%d] (size []): %s\n", i, (a[i])?(a[i]):"NULL");
	}

	for ( i=0; i<1; i++ ) {
		if ( b[i] != (int(*)[4][3])NULL ) {
			for ( j=0; j<4; j++ ) {
				for ( k=0; k<3; k++ )
					printf("int (*(b[%d]))[%d][%d]) (size (*[])[4][3]) %d \n", i, j, k, (*(b[i]))[j][k]);
			}
		}
		else
			printf("int (*(b[]))[4][3]): NULL\n"); 
	}
	printf("=========== Input end ===================\n");


	printf("\n=========== api5(char *a[], int (*b[])[4][3]) Output ==================\n");
	printf("no explicit return\n");
	printf("=========== Output end ===================\n");
}

Node *api6(float *a, struct node (*b)[])
{
	int		i;

	printf("=========== Node *api6(float *a, struct node (*b)[]) Input  ==================\n");
	if ( a != (float *) NULL ) {
	for ( i=0; i<3; i++)
		printf("float *(a +%d) : %f\n",i, *a);
	}

	for ( i=0 ; i<1; i++ ){
		printf("sturct node (*b)[%d] : %s \n", &((*b)[i]));
		show_node("\t", &((*b)[i]));
	}
	printf("=========== Input end ===================\n");


	printf("\n=========== Node* *api6(float *a, struct node (*b)[]) Output ==================\n");
	printf("no explicit return\n");
	printf("=========== Output end ===================\n");
}

NodePtr api7(Enm2 a, Node b)
{
	printf("=========== NodePtr api7(Enm2 a, Node b) Input =================\n");
	printf("Enm2 a (0,1,2): %d\n", a);
	printf("Enm2 a (Kim, Lee, Park): %s\n", e2[a]);
	printf("Node &b : %x \n", (void *) &b);
	show_node("\t", &b);
	printf("=========== Input end ===================\n");

	
	printf("\n=========== NodePtr api7(Enm2 a, Node b) Output ==================\n");
	printf("NodePtr : %x\n", (void *) &b);
	show_node("\t", &b);
	printf("=========== Output end ===================\n");
	return &b;
}

int api8 (Node **a) {
	int i = 0 ;

	printf("=========== int api8 (Node **a) Input  ==================\n");
	if (a == (void *)0) 
		printf ("Node ** a : NULL\n");
	else
		while ( *a ) {
		printf ("Node * (a+%d) : %x\n",i, (*a)+i);
		show_node ("\t", (*a)+i);
		}
	printf("=========== Input end ===================\n");


	printf("\n=========== int api8 (Node **a) Output ==================\n");
	printf("no explicit return\n");
	printf("=========== Output end ===================\n");
}

int api9 (
					NodePtr (*fn1) (Enm2, Node), 
					int (*fn2) (char *[], int (*[])[4][3]),
					Enm2 a, Node b, char *c[], int (*d[])[4][3] 
					) {
	int i=0,j=0,k=0;

	printf("=========== int api9 ( \n");
	printf("===========           NodePtr (*fn1) (Enm2, Node), \n");
	printf("===========           int (*fn2) (char *[], int (*[])[4][3]),\n");
	printf("===========           Enm2 a, Node b, char *c[], int (*d[])[4][3]) Input ======\n");
	printf("fn1 : %s\n", get_func_name ( fn1 ) );;
	printf("fn2 : %s\n", get_func_name ( fn2 ) );;
	printf("Enm2 a (0,1,2): %d\n", a);
	printf("Enm2 a (Kim, Lee, Park): %s\n", e2[a]);
	printf("Node &b : %x \n", &b);
	show_node("\t", &b);

	if ( c != ( char **) NULL ) {
		printf("char *c[] (address): %x\n", (void *) c ) ;
		while ( c[i] != (char*) NULL ) {
			i++ ;
			printf("char *c[%d] (size []): %s\n", i, (c[i])?(c[i]):"NULL");
		}
	} else
			printf("char *c[] : NULL\n");

	if ( d != NULL ) {
			printf("int (*d[])[4][3] (address): %x\n", d ) ;
			for ( i=0; i<1; i++ ) {
					if ( d[i] != (int(*)[4][3])NULL ) {
							for ( j=0; j<4; j++ ) {
									for ( k=0; k<3; k++ )
											printf("int (*(d[%d]))[%d][%d]) (size (*[])[4][3]) %d \n", i, j, k, (*(d[i]))[j][k]);
							}
					}
					else
							printf("int (*(b[%d]))[4][3]): NULL", i); 
			}
	}
	else
			printf("int (*d[])[4][3]  : NULL\n");
	printf("=========== Input end ===================\n");


	fn1 (a, b);
	fn2 (c, d);

	printf("\n=========== int api9()   Output ==================\n");
	printf("no explicit return\n");
	printf("=========== Output end ===================\n");
}

/* old style */
char api10 ( a, b,c,d,e,f ) 
int a,c,d,e ;
char f,b ;
{ 
	printf("=========== char api10 ( a, b,c,d,e,f )\n");
	printf("            int a,c,d,e ;     \n");
	printf("            char f,b ; ============== Input =============\n");
	printf("int a: %d\n", a);
	printf("int c: %d\n", c);
	printf("int d: %d\n", d);
	printf("int e: %d\n",e);
	printf("char f: %c\n",f);
	printf("char b: %c\n",b);
	printf("=========== Input end ===================\n");


	printf("\n=========== int api10() Output ==================\n");
	printf("no explicit return\n");
	printf("=========== Output end ===================\n");
}


/* goto label */
float api11 ( a, b, c )
		int a,c,b ;
{
	printf("=========== float api11 ( a, b, c )\n");
	printf("            int a,c,b; ============== Input =============\n");
	printf("int a: %d\n", a);
	printf("int c: %d\n", c);
	printf("int b: %d\n", b);
	printf("=========== Input end ===================\n");
	a = 3 ;

hello:
	b = 4;
	/*goto hello ;*/
	printf("\n=========== float api11() Output ==================\n");
	printf("no explicit return\n");
	printf("=========== Output end ===================\n");
}

/* switch and break, continue */
float api12 ( char c ) 
{
	int i = 0;
	int b = 0;
	printf("=========== float api12 ( char  c ) Input ================\n");
	printf("char c: %c\n", c);
	printf("=========== Input end ===================\n");

	for ( i =0; i< 3 ; i ++ ) {
	switch ( c ) {
		case 'a': printf ("a");
				  for ( i= 0 ; i < 3 ; i ++ ) {
					  printf ("a-1");
					  hello:
					  printf ("a-2") ;
				  }
				  printf("a-3") ;
				  break ;
		case 'b': printf("b");
				  printf("b-1" );
				  goto hello;
		case 'c': printf("c");
				  continue ;
		case 'd': printf("d");
				  printf("d-1" );
		default:
				  printf("e") ;
	}

	}

	printf("\n=========== float api12() Output ==================\n");
	printf("float : 1.0\n");
	printf("=========== Output end ===================\n");
	return 1.0;
}

/* goto, switch, for, continue */

char * get_func_name ( void *fn_addr ) {
	if ( fn_addr == (void *) api1 ) 
		return " api1() ";
	else if( fn_addr == (void *) api2 ) 
		return " api2() ";
	else if( fn_addr == (void *) api3 ) 
		return " api3() ";
	else if( fn_addr == (void *) api4 ) 
		return " api4() ";
	else if( fn_addr == (void *) api5 ) 
		return " api5() ";
	else if( fn_addr == (void *) api6 ) 
		return " api6() ";
	else if( fn_addr == (void *) api7 ) 
		return " api7() ";
	else if( fn_addr == (void *) api8 ) 
		return " api8() ";
	else if( fn_addr == (void *) api9 ) 
		return " api9() ";
	else if( fn_addr == (void *) api10 ) 
		return " api10() ";
	else if( fn_addr == (void *) api11 ) 
		return " api11() ";
	else if( fn_addr == (void *) api12 ) 
		return " api12() ";
	else if( fn_addr == (void *) show_node ) 
		return " show_node() ";
	else if( fn_addr == (void *) show_uni ) 
		return " show_uni() ";
	else if( fn_addr == (void *) cp_node ) 
		return " cp_node() ";
	else 
		return " unknown_address ";
}

