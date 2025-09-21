#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <climits>
using namespace std;

// 比较函数
int cmp(const void* const pa, const void* const pb) {
    const int a = *(const int*)pa;
    const int b = *(const int*)pb;
    return (a - b);
}

int main() {
    int arr[3] = { -1, 0, INT_MAX};
    int* a = arr; int* b = arr+1; int* c = arr+2;
    if (cmp(a, b) < 0) {
        printf("%d < %d\n", *a, *b);
    }
    if (cmp(b, c) < 0) {
        printf("%d < %d\n", *b, *c);
    }
    if (cmp(c, a) < 0) {
        printf("%d < %d\n", *c, *a);
    }
    printf("测试中文显示");
    return 0;
}
