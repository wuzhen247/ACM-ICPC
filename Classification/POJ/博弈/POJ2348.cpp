//POJ2348 Euclid's Game ���� 
/*
һ��b��a������������ʤ��
����b - a < a
     ���������ֻ����b��ȥa��û��ѡ�񣬱�ʤ̬�ͱذ�̬����ת����
����b - a > a
    �������Ǽ���b - ax < a;����������һ�¼�ȥa * (x - 1)������������ȥ�Ժ��Ǳذ�̬����ô��ǰΪ��ʤ̬��
�����ȥ֮��Ϊ��ʤ̬������֪��b - ax��״̬��b - a(x - 1)Ψһ����ת�Ƶ���״̬�����b - axΪ�ذ�̬����ǰΪ��ʤ̬��
   ����b - a > aΪ��ʤ��
 */ 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m;

int main()
{
    int num;
    while (scanf("%d%d", &n, &m),(n||m))
    {
        num = 1;
        while (true)
        {
            if (n < m)
              swap(n,m);
            if (n-m >= m || n % m == 0)
              break;
            num++;
            n -= m;
        }
        if (num % 2)
          printf("Stan wins\n");
        else
          printf("Ollie wins\n");
    }
    return 0;
}

