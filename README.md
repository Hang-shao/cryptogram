# 国密算法实现
# ZUC
## ZUC_example_3
ZUC 国标中的三个例子
## v_mod
计算v=2^15*S4+2^17*S3+2^21*S2+2^20*S1+(1+2^8)*s0*mod(2^31-1)
## ZUC-Sbox
ZUC S盒实现
# SM3
## SM3
SM3 国标中例子实现
# SM2
## sm2_点集
求椭圆曲线上的点，例：y^2=x^3+ax+b，求(x,y)
## sm2_逆运算
求一个数的逆，例：求Fq下的g^-1
## sm2_平方根
求椭圆方程中的y值，即求平方根，例：y^2=g(mod p)，求y
## sm2_指数运算
求一个数的指数值，例：求Fq下的g^a

# SM4
## sm4_sbox
SM4的S盒实现，打印S盒
## sm4_string
对字符串加解密，可以设定加密次数
## sm4_txt
对TXT文本加解密
## sm4_picture
对图片加解密，目前针对是BMP文件
