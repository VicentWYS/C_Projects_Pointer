#include "test.h"
#include <stdio.h>

//理解指针变量含义
void pointer_Meaning(){
    int x = 10;
    int *p = &x;

    printf("x的地址：%p\n", &x);
    printf("p的值：%p\n", p);

    printf("x的值：%d\n", x);
    printf("*p的值：%d\n", *p);

    printf("x在内存中占的字节：%d\n", sizeof(x));
    printf("p在内存中占的字节：%d\n", sizeof(p));
}


//区分 *p++ 与 (*p)++
void divide(){
    int x=10;
    int *p = &x;

    printf("*p = %d\n", *p);
    printf("p = %p\n", p);  //之前指针的值
    printf("*p++ = %d\n", *p++);
    printf("p = %p\n", p);  //之后指针的值
    printf("sizeof(p) = %d\n", sizeof(p));

    x=10;
    p = &x;

    printf("\n(*p) = %d\n", (*p));
    printf("(*p)++ = %d\n", (*p)++);
    printf("(*p) = %d\n", (*p));

}


//数组与指针的联系
//结果都一样
void pointer_array(){
    int a[3] = {1,2,3};
    int *p = a;

    for(int i=0; i<3; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");

    for(int i=0; i<3; i++){
        printf("%d\t", *(a+i));
    }
    printf("\n");

    for(int i=0; i<3; i++){
        printf("%d\t", *(p+i));
    }
    printf("\n");

    for(int i=0; i<3; i++){
        printf("%d\t", p[i]);
    }
    printf("\n");
}


//二位数组与指针的联系
void pointer_22array(){
    int a[2][3] = {{1,2,3},{4,5,6}};
    int *p = &a[0][0];  //不能用 int *p = a;
    printf("访问a[1][2]:\n");

    printf("a[1][2]: %d\n",     a[1][2]);
    printf("*(*(a+1)+2): %d\n", *(*(a+1)+2));
    printf("*(a[1]+2): %d\n",   *(a[1]+2));
    printf("*(p+1*3+2): %d\n",  *(p+1*3+2)); //3为矩阵列数

}


//指向一维数组的指针
void pointer_1array(){
    int a[2][3] = {{1,2,3},{4,5,6}};
    int (*p)[3];

    p = a;  //等价于 p = &a[0]
    printf("a[0][1]:\n");
    printf("%d\n", a[0][1]);
    printf("%d\n", (*p)[1]);

    p = a + 1;  //等价于 p = &a[1]
    printf("a[1][1]:\n");
    printf("%d\n", a[1][1]);
    printf("%d\n", (*p)[1]);

}


//数组指针
void array_pointer2(){
    int a[3] = {1,2,3};
    int *p[3] = {&a[0], &a[1], &a[2]};


    for(int i=0; i<3; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    for(int i=0; i<3; i++){
        printf("%d ", *p[i]);
    }
    printf("\n");

}


//二维数组与指针
void array_pointer3(){
    int a[2][3] = {{1,2,3},{4,5,6}};
    int *p[2] = {a[0], a[1]};   //a[0] = &a[0][0],  a[1] = &a[1][0]

    printf("集中方式访问数组元素a[0][0]:\n");
    printf("%d\n", a[0][0]);
    printf("%d\n", *a[0]);
    printf("%d\n", *p[0]);

}

//一维数组与指针
void array_pointer4(){
    char *p[] = {"hello", "harry", "potter","!"};   //以字符串形式处理
    char w[][5] = {"hello", "tom", "marry", "!"};   //这只是一个二位维的 字符数组，基本单元是字符

    for(int i=0; i<4; i++){
        printf("%s\t", p[i]);
    }
    printf("\n");

    //二维字符数组
    for(int i=0; i<4; i++){
        printf("%c\t", w[i][0]);
    }
    printf("\n");

}


//指针作为函数参数
void pointer_parameter(){
    int a[] = {1,2,3};
    printf("数组a的首地址为：%p\n", a);
    //printf("a中元素的和为：%d\n", sumarray(a,3));
    printf("a中元素的和为：%d\n", sumarray_pointer(a,3));
}

//数组元素求和
int sumarray(int a[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + a[i];
    }
    return sum;
}

//数组元素求和 (指针为参数)
int sumarray_pointer(int *p, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + *(p+i);
    }
    return sum;
}


//求二维数组元素之和
void pointer_parameter2(){
    int a[2][3] = {{1,2,3},{4,5,6}};

    printf("a的存储首地址为：%p\n", a);
    printf("a中元素的和为：%d\n", sumarry_22(a,2,3));
}

//求二维数组元素之和
int sumarry_22(int a[][3], int m, int n){
    int sum = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            sum = sum + a[i][j];
        }
    }

    return sum;
}


//求二维数组元素之和(只传递数组第一个元素的地址)
void pointer_parameter3(){
    int a[2][3] = {{1,2,3},{4,5,6}};

    printf("数组元素之和为：%d\n", sumarry_22_3(&a[0][0],2,3));
}

//求二维数组元素之和(只传递数组第一个元素的地址)
int sumarry_22_3(int *p, int m, int n){
    int sum = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            sum = sum + *(p+i*n+j);
        }
    }

    return sum;
}


//指针与字符串
void string_pointer(){
    char s1[] = {'H', 'e', 'l', 'l', 'o'};  //s1没有串结束符,不能用%s输出
    char s2[] = {"Hello"};
    char s3[] = "Hello";
    char s4[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char *s5 = "Hello";

    printf("s1:");
    for(int i=0; i<sizeof(s1); i++){
        printf("%c", s1[i]);
    }
    printf("\n");

    printf("s2:%s\n", s2);
    printf("s3:%s\n", s3);
    printf("s4:%s\n", s4);
    printf("s5:%s\n", s5);
}
