#include <stdio.h>
/*
�������ϵ�ָ������
���룺������a����Fq����Ԫ��g
�����g^a
*/
int bin[16];
int r=-1;
//���e�Ķ����Ʊ�ʾ����e�Ķ����ƴ�������bin�У����λ��������ĵ�һ��Ԫ��
void print_bin(int e)
{
    int x;
    while(e != 0)
    {
        x = e % 2;
        r++;
        bin[r] = x;
        e /= 2;
    }
}
int main()
{
    printf("----------------------------�������е�ָ������----------------------------\n");
    printf("\n\t\t\t\t��Fq�µ�g^a\n\n");
    printf("--------------------------------------------------------------------------\n");
    int a,q,g,x,e,i,tmp,result;
    
    printf("������a,q,g��");
    scanf("%d,%d,%d",&g,&q,&a);
    
    //1����e = a % (q-1)����e = 0�������1
    e = a % (q-1);
    if(e == 0)
    {
        return 1;
    }
    //2����e�Ķ����Ʊ�ʾ��e=Er Er-1 ...... E0�����λEr=1
    print_bin(e);

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
    //5�����x
    printf("\n%d^%d mod %d=%d\n",g,a,q,x);
    system("pause");
    return 0;
}