#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define size 10000
#define INF -9999
swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
typedef struct {
	int heap[size];
	int count;
}pq;
push(pq* q, int data)
{
	if (q->count >= size - 1) return INF;
	q->heap[q->count] = data;
	int now = q->count;
	int parent = (now - 1) / 2;
	while (q->count > 0 && q->heap[now] > q->heap[parent])
	{
		swap(&q->heap[now], &q->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	q->count++;
}
pop(pq* q)
{
	if (q->count <= 0) return INF;
	int res = q->heap[0];
	q->count--;
	q->heap[0] = q->heap[q->count];
	int now = 0, left = 1, right = 2;
	int target = now;
	while (left < q->count)
	{
		if (q->heap[target] < q->heap[left]) target = left;
		if (q->heap[target] < q->heap[right] && q->count > right) target = right;
		if (now == target) break;
		else {
			swap(&q->heap[now], &q->heap[target]);
			now = target;
			left = now * 2 + 1;
			right = now * 2 + 2;
		}
	}
	return res;
}
main()
{
	int n, data;
	scanf("%d", &n);
	pq q;
	q.count = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &data);
		push(&q, data);
	}
	for(int i = 0; i < n; i++) {
		int data = pop(&q);
		printf("%d ", data);
	}

}