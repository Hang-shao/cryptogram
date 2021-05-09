#include <stdio.h>

/*
    ģ����ƽ�������
        y^2=g(mod p)
    ���룺������p������g��0<g<p
    �����������g��ƽ�����������һ��ƽ����mod p�����������������ƽ������
*/

int bin[16];
int r=-1;
int index(int g,int q,int a)
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
    int g,p,y,u,z;
    printf("----------------------------ģ����ƽ�������----------------------------\n");
    printf("\n\t\t\ty^2=g(mod p)����y\n\n");
    printf("------------------------------------------------------------------------\n");
    
    printf("�����룬g,p��");
    scanf("%d,%d",&g,&p);
   /*
    ��g=0����ֻ��һ��ƽ��������y=0
     ��g��0������0������2��ƽ��������y��һ��ƽ��������ô����һ������ p-y
    */
    if(g == 0)
    {
        y=0;
        printf("y=%d\n",y);
    }else
    {
        /*
        ��p=3(mod4)�������������u��ʹ��p=4u+3
        1��y=g^(u+1) mod p
        2��z=y^2 mod p
        3����z=g�������y�����򲻴���ƽ����
        */
        if(p % 4 == 3)
        {
            u = (p-3)/4;
            y = index(g,p,u+1);
            z = index(y,p,2);
            if(z == g)
            {
                printf("y1=%d,y2=%d",y,p-y);
            }else
            {
                printf("������ƽ������\n");
            }
        }
         /*
        ��p=5(mod8)�������������u��ʹ��p=8u+5
        1��z=g^(2u+1) mod p
        2����z=1(mod p)������y=g^(u+1) mod p�����y����ֹ�㷨
        3����z=-1(mod p)������y=(2g*(4g)^u) mod p�����y����ֹ�㷨
        4�����������ƽ����
        */
        else if(p % 8 == 5)
        {
            u = (p-5)/8;
            z = index(g,p,2*u+1);
            if(z == 1)
            {
                y = index(g,p,u+1);
                printf("y1=%d,y2=%d",y,p-y);
            }
            if(z == -1)
            {
                y = (2*g*index(4*g,p,u)) % p;
                printf("y1=%d,y2=%d",y,p-y);
            }
            printf("������ƽ������\n");
        }
        else
        {
           printf("��������ʵĲ�����\n");
        }  
    }
    
    system("pause");
    return 0;
}