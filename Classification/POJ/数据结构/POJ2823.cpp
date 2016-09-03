//POJ2823 Sliding Window 单调队列 
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 1000005
using namespace std;

struct Que
{
	int v,id;
};

Que minq[N],maxq[N];
int n,k,a[N],front,rear;

inline int Incq(int f, int r, int d)
{
	int mid;
	while(f <= r)
	{
		mid = (f + r)>>1;
		if(minq[mid].v == d)
			return mid;
		if(minq[mid].v < d)
			f = mid + 1;
		else
			r = mid - 1;
	}
	return f;
}

inline int Desq(int f, int r, int d)
{
	int mid;
	while(f <= r)
	{
		mid = (f + r)>>1;
		if(maxq[mid].v == d)
			return mid;
		if(maxq[mid].v > d)
			f = mid + 1;
		else
			r = mid - 1;
	}
	return f;
}

int main()
{
	int i;
	scanf("%d%d",&n,&k);
	{
		for(i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		//单调队列求最小——维持k区间的递增队列
		minq[1].v = a[1];
		minq[1].id = 1;
		front = rear = 1;
		for(i = 2; i <= k; i++)//删队尾，入队
		{
			rear = Incq(front, rear, a[i]);
			minq[rear].v = a[i];
			minq[rear].id = i;
		}

		printf("%d", minq[1].v);// 队首即为第一个滑动窗口的最小值
		for(i = k + 1; i <= n; i++)
		{
			rear = Incq(front, rear, a[i]);//删队尾，入队, 维持区间范围
			minq[rear].v = a[i];
			minq[rear].id = i;
			if(i - minq[front].id >= k)//删队首，维持区间范围 
				front++;
			printf(" %d", minq[front].v);//队首为第i-k+1个滑动窗口的最小值
		}
		printf("\n");

		maxq[1].v = a[1];
		maxq[1].id = 1;
		front = rear =1;
		for(i = 1; i <= k; i++)
		{
			rear = Desq(front, rear, a[i]);
			maxq[rear].v = a[i];
			maxq[rear].id = i;
		}
		printf("%d", maxq[1].v);
		for(i = k + 1; i <= n; i++)
		{
			rear = Desq(front, rear, a[i]);
			maxq[rear].v = a[i];
			maxq[rear].id = i;
			if(i - maxq[front].id >= k)
				front++;
			printf(" %d", maxq[front].v);
		}
		printf("\n");
	}
	return 0;
}