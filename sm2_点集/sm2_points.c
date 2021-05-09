#include <stdio.h>

/*
    ��Fp�ϵ���Բ���ߵĵ㼯
    ��Բ���ߣ�y^2=x^3+ax+b
    ���룺����p������a��b
    �����(x,y)
*/

int flag; //flag=0����ʾ������ƽ������flag=1����ʾy=0��flag=2,��ʾ������ƽ����
int bin[16];
int r = -1;
//���e�Ķ����Ʊ�ʾ����e�Ķ����ƴ�������bin�У����λ��������ĵ�һ��Ԫ��
void print_bin(int e)
{
    int x;
    while (e != 0)
    {
        x = e % 2;
        r++;
        bin[r] = x;
        e /= 2;
    }
}
int index(int g, int q, int a)
{
    int x, e, i, tmp;
    //1����e = a % (q-1)����e = 0�������1
    e = a % (q - 1);
    if (e == 0)
    {
        return 1;
    }
    //2����e�Ķ����Ʊ�ʾ��e=Er Er-1 ...... E0�����λEr=1
    print_bin(e);

    //3����x=g
    x = g;
    //4����i��r-1�½���0ִ�У�
    //  4.1 ��x=x^2
    //  4.2 ��Ei=1������x=g.x
    for (i = r - 1; i >= 0; i--)
    {
        x = (x * x) % q;
        if (bin[i] == 1)
        {
            x = (g * x) % q;
        }
    }
    return x;
}

int square(int g, int p)
{
    /*
     ��g=0����ֻ��һ��ƽ��������y=0
      ��g��0������0������2��ƽ��������y��һ��ƽ��������ô����һ������ p-y
     */
    int u, z, y;
    if (g == 0)
    {
        y = 0;
        flag = 1;
        return y;
    }
    else
    {
        /*
        ��p=3(mod4)�������������u��ʹ��p=4u+3
        1��y=g^(u+1) mod p
        2��z=y^2 mod p
        3����z=g�������y�����򲻴���ƽ����
        */
        if (p % 4 == 3)
        {
            u = (p - 3) / 4;
            y = index(g, p, u + 1);
            r = -1;
            z = index(y, p, 2);
            r = -1;
            if (z == g)
            {
                flag = 2;
                return y;
            }
            else
            {
                flag = 0;
                //printf("������ƽ������\n");
            }
        }
        /*
       ��p=5(mod8)�������������u��ʹ��p=8u+5
       1��z=g^(2u+1) mod p
       2����z=1(mod p)������y=g^(u+1) mod p�����y����ֹ�㷨
       3����z=-1(mod p)������y=(2g*(4g)^u) mod p�����y����ֹ�㷨
       4�����������ƽ����
       */
        else if (p % 8 == 5)
        {
            u = (p - 5) / 8;
            z = index(g, p, 2 * u + 1);
            r = -1;
            if (z == 1)
            {
                flag = 2;
                y = index(g, p, u + 1);
                return y;
            }
            if (z == -1)
            {
                y = (2 * g * index(4 * g, p, u)) % p;
                return y;
                flag = 2;
            }
            flag = 0;
            //printf("������ƽ������\n");
        }
        else
        {
            printf("��������ʵĲ�����\n");
        }
    }
    return -1;
}

int main()
{
    int a, b, p, y, x, A, count = 0; //count��¼�������
    printf("----------------------------��Fp�ϵ���Բ���ߵĵ㼯----------------------------\n");
    printf("\n\t\t\ty^2=x^3+ax+b����(x,y)\n\n");
    printf("------------------------------------------------------------------------\n");

    printf("���������룬a b p��");
    scanf("%d %d %d", &a, &b, &p);

    //1��ѡȡx��0��x<p
    for (x = 0; x < p; x++)
    {
        A = (x * x * x + a * x + b) % p;
        if (A == 0)
        {
            printf("(%d,0)\t", x);
            count++;
            continue;
        }
        y = square(A, p);
        //ֻ��һ������y=0
        if (flag == 1)
        {
            printf("(%d,%d)\t", x, y);
            count++;
        }
        else if (flag == 2)
        {
            printf("(%d,%d)\t", x, y);
            count++;
            printf("(%d,%d)\t", x, p - y);
            count++;
        }
        else
        {
            continue;
        }
    }
    printf("\n����Բ���ߵĵ���Ϊ(��������Զ��)��%d\n",count+1);

    system("pause");
    return 0;
}