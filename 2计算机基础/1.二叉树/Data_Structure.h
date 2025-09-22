/*
    文件：Data_Struecture.h                              
    说明：此文件定义所有程序共同用到的常量和类型。   
 */

#pragma once

#define TRUE		1
#define FALSE		0
#define OK			1
#define ERROR		0
	
#define MAX_INT ((unsigned)(-1)>>1)	// 最大整数，4字节时等于2147483647
#define MIN_INT (~MAX_INT)		    // 最小整数，4字节时等于-2147483648

typedef int Status;
typedef int ElemType;               // 大多数程序中，元素类型为整数