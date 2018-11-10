/**
 @file gobang_main.h

 @date 2018-8-1

 @author xpf

 @version v1.0

*/
#ifndef __COBAND_MAIN_H
#define __COBAND_MAIN_H
/****************************************************************************
 *
* Header Files
*
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define GO_OK            (0)
#define GO_ERROR         (-1)
#define GO_WIN             1
#undef FALSE
#undef TRUE

#ifndef BOOLEAN_TYPE
#define BOOLEAN_TYPE
typedef enum { FALSE = 0, TRUE = 1 } Boolean;
#endif


typedef unsigned char		u8;
typedef signed char			s8;

typedef unsigned short		u16;
typedef unsigned int		u32;
typedef signed int			s32;

typedef int64_t			    s64;
typedef uint64_t			u64;
//以上是types.h中的内容 

#define DEBUG           0				//打开调试信息
#define M_SIZE          15              //棋盘大小为15x15
#define DEEP            3               //最大搜索4层(现在实现的算法4层搜索都太慢了)

#define check(x)    (((x)<0) || ((x)>=M_SIZE))

//棋子状态颜色
#define    SPACE            0
#define    WHITE            1
#define    BLACE            2 

/*计分板
分数随意定的,只考虑了不让四个方向上的分数加起来超过更高一级的棋型。*/
typedef enum score_e
{
    WIN5 = 100000,          //5连           
    ALIVE4 = 10000,         //活4
    ALIVE3 = 1000,          //活3
    DIE4 = 1000,            //死4
    ALIVE2 = 100,           //活2
    DIE3 = 100,             //死3
    DIE2 = 10,              //死2
    ALIVE1 = 10             //活1
}score;

//棋子
typedef struct chess_s
{
    u8 x;
    u8 y;
}chess_t;

//空子的序列
typedef struct chess_queue_s
{
    chess_t chess[M_SIZE*M_SIZE];
    u8 len;
}chess_queue;

#endif
