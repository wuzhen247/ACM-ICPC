//归并排序求逆序对
#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;

const int N = 500000+5;
int a[N], b[N]; 
ll ans;

void merge(int begin, int mid, int end)
{
	int i = begin, j = mid+1, num = begin;
	while (i <= mid && j <= end)
	{
		if (a[i] <= a[j])
			b[num++] = a[i++];
		else
		{
			ans += mid-i+1;
			b[num++] = a[j++];
		}
	}
	if (i > mid)
		while (j <= end)
			b[num++] = a[j++];
	if (j > end)
		while (i <= mid)
			b[num++] = a[i++];
	for (int k = begin; k <= end; k++)
		a[k] = b[k];
}

void mergesort(int l, int r)
{
	if (l < r)
	{
		int p = (l+r) >> 1;
		mergesort(l, p);
		mergesort(p+1, r);
		merge(l, p, r);
	}
}

int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		mergesort(0, n-1);
		printf("%lld\n", ans);
	}
	return 0;
}