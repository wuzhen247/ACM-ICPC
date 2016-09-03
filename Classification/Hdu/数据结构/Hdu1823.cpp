//二维线段树
#include <iostream>
#include <cstring>
#include <cstdio>

#define N 270
#define M 2100

using namespace std;

struct Nodes
{
    int l, r, val;
};

struct Nodep
{
    int l, r;
    Nodes son[M];
}tree[N];

void sub_build ( int f, int u, int l, int r )
{
    tree[f].son[u].l = l;
	tree[f].son[u].r = r;
    tree[f].son[u].val = -1;
    if ( l == r ) return;
    int mid = ( l + r ) >> 1;
    sub_build ( f, u<<1, l, mid );
    sub_build ( f, u<<1|1, mid+1, r );
}

void build ( int f, int l1, int r1, int l2, int r2 )
{
    tree[f].l = l1;
	tree[f].r = r1;
    sub_build ( f, 1, l2, r2 );
    if ( l1 == r1 ) 
		return;
    int mid = ( l1 + r1 ) >>1;
    build ( f<<1, l1, mid, l2, r2 );
    build ( f<<1|1, mid+1, r1, l2, r2 );
}

void sub_update ( int f, int u, int d2, int val )
{
	if ( u > M ) 
		return; 
    tree[f].son[u].val = max ( tree[f].son[u].val, val );
	if ( tree[f].son[u].l == d2 && tree[f].son[u].r == d2 )
	{
		tree[f].son[u].val = max ( tree[f].son[u].val, val );
		return;
	}
    int mid = ( tree[f].son[u].l + tree[f].son[u].r ) >> 1;
    if ( d2 <= mid )
        sub_update ( f, u<<1, d2, val );
    else
        sub_update ( f, u<<1|1, d2, val );
}

void update ( int f, int d1, int d2, int val )
{
	if ( f > N ) return;
    sub_update ( f, 1, d2, val );
	if ( tree[f].l == tree[f].r ) 
		return;
    int mid = ( tree[f].l + tree[f].r ) >> 1;
    if ( d1 <= mid )
        update ( f<<1, d1, d2, val );
    else
        update ( f<<1|1, d1, d2, val );
}

int sub_query ( int f, int u, int l2, int r2 )
{    
	if ( u > M ) return -1;  
    if ( tree[f].son[u].l == l2 && tree[f].son[u].r == r2 )
        return tree[f].son[u].val;
    int mid = ( tree[f].son[u].l + tree[f].son[u].r ) >> 1;
    if ( r2 <= mid )
        return sub_query ( f, u<<1, l2, r2 );
    else if ( l2 > mid )
        return sub_query ( f, u<<1|1, l2, r2 );
    else
        return max ( sub_query(f,u<<1,l2,mid), sub_query(f,u<<1|1,mid+1,r2) );
}

int query ( int f, int l1, int r1, int l2, int r2 )
{
	if ( f > N ) return -1; 
    if ( tree[f].l == l1 && tree[f].r == r1 )
        return sub_query ( f, 1, l2, r2 );
    int mid = ( tree[f].l + tree[f].r ) >> 1;
    if ( r1 <= mid )
        return query ( f<<1, l1, r1, l2, r2 );
    else if ( l1 > mid )
        return query ( f<<1|1, l1, r1, l2, r2 );
    else
        return max ( query(f<<1,l1,mid,l2,r2), query(f<<1|1,mid+1,r1,l2,r2) );
}

int main ()
{
    char ch[3];
    int m, h, hl, hr, ans;
    double a, l, al, ar;
    while ( scanf("%d",&m) != EOF && m )
    {
        memset(tree,0,sizeof(tree));
        build ( 1, 100, 200, 0, 1000 );
        while ( m-- )
        {    
            scanf("%s",ch);
            if ( ch[0] == 'I' )
            {
                scanf("%d%lf%lf", &h, &a, &l );
                update ( 1, h, (int)(a*10), (int)(l*10) );
            }
            else
            {
                scanf("%d%d%lf%lf", &hl, &hr, &al, &ar);
                if ( hl > hr ) 
					swap ( hl, hr );
                if ( al > ar ) 
					swap ( al, ar );
                ans = query ( 1, hl, hr, (int)(al*10), (int)(ar*10) );
                if ( ans < 0 ) printf("-1\n");
                else printf("%.1lf\n", ans/10.0 );
            }
        }
    }
    return 0;
}

