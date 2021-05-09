#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef unsigned char u8;//0~255
typedef unsigned int u31;//

/* the state registers of LFSR LFSR��16�׼Ĵ��� */

/* c = a + b mod (2^31 �C 1) */
u31 ISD_ZUC_AddM(u31 a, u31 b)
{
	u31 c = a + b;
	if (c & 0x80000000)
	{
		c = (c & 0x7FFFFFFF) + 1;
	}
	return c;  
}

/* LFSR with initialization mode LFSR��ʼ��ģʽ */
#define MulByPow2(x, k) ((((x) << k) | ((x) >> (31 - k))) & 0x7FFFFFFF)
u31 ISD_ZUC_LFSRWithInitialisationMode(u31 S0, u31 S1, u31 S2, u31 S3, u31 S4)
{
	u31 f, v;

	f = S0;
	v = MulByPow2(S0, 8);
	f = ISD_ZUC_AddM(f, v);

	v = MulByPow2(S1, 20);
	f = ISD_ZUC_AddM(f, v);

	v = MulByPow2(S2, 21);
	f = ISD_ZUC_AddM(f, v);

	v = MulByPow2(S3, 17);
	f = ISD_ZUC_AddM(f, v);

	v = MulByPow2(S4, 15);
	f = ISD_ZUC_AddM(f, v);

	return f;
}

u31 S_NUM(u31 a[])
{
	u31 sum = 0;
	//������תʮ����
	for (int i = 0; i < 32; i++)
	{
		sum = sum * 2 + (a[i] - '0'); //'0'��Ӧ��ASCII��ֵ��'1'��Ӧ��ASCII��ֵ���Ϊ1,ͨ��ch-'0'����ֱ�����int�͵�ֵ1����0
	}
	return sum;
}

int main()
{
	/*����v=2^15*S4+2^17*S3+2^21*S2+2^20*S1+(1+2^8)*s0*mod(2^31-1);*/
	u31 input[5],output;
	
	printf("--------------------------------------\n������5��31λ��ʮ����������\n");
	for (int i = 0; i < 5; i++)
	{
		/*55554B55,7F0E1E62,78CCC71D,430F03C,600E071*/
		scanf("%x", &input[i]);
		printf("S%d=%d\n",i,input[i]);
	}
	printf("--------------------------------------\n��ʼ���㣺\n");
	output=ISD_ZUC_LFSRWithInitialisationMode(input[0], input[1], input[2], input[3], input[4]);
	printf("\noutput=%x\n--------------------------------------", output);
	return 0;
}