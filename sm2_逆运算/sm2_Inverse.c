#include <stdio.h>

/*
�������ϵ�������
���룺��Fq��Fq�еķ���Ԫ��g
�������Ԫ�� g ^ -1
*/
int bin[16];
int r=-1;
int Inverse(int g,int q,int a)
{
    int x,e,i,tmp;
    //1����e = a % (q-1)����e = 0�������1
    e = a % (q-1);
    if(e == 0)
    {
        return 1;
    }
    //2����e�Ķ����Ʊ�ʾ��e=Er Er-1 ...... E0�����λEr=1
    while(e != 0)
    {
        x = e % 2;
        r++;
        bin[r] = x;
        e /= 2;
    }
    //3����x=g
    x=g;
    //4����i��r-1�½���0ִ�У�
    //  4.1 ��x=x^2
    //  4.2 ��Ei=1������x=g.x
    for(i=r-1;i>=0;i--)
    {
        x = (x * x) % q;
        if(bin[i] == 1)
        {
            x = (g * x) % q;
        }
    }
    return x;
}
int main()
{
    int c,g,q;
    printf("----------------------------�������е�������----------------------------\n");
    printf("\n\t\t\t\t��Fq�µ�g^-1\n\n");
    printf("-------------------------------------------------------------------------\n");
    
    printf("�����룬g,q��");
    scanf("%d,%d,",&g,&q);
    //1������c = g ^ q-2
    c = Inverse(g,q,q-2);
    //2�����c
    printf("\n%d^-1=%d\n\n",g,c);
    
    system("pause");
    return 0;
}