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
//������types.h�е����� 

#define DEBUG           0				//�򿪵�����Ϣ
#define M_SIZE          15              //���̴�СΪ15x15
#define DEEP            3               //�������4��(����ʵ�ֵ��㷨4��������̫����)

#define check(x)    (((x)<0) || ((x)>=M_SIZE))

//����״̬��ɫ
#define    SPACE            0
#define    WHITE            1
#define    BLACE            2 

/*�Ʒְ�
�������ⶨ��,ֻ�����˲����ĸ������ϵķ�����������������һ�������͡�*/
typedef enum score_e
{
    WIN5 = 100000,          //5��           
    ALIVE4 = 10000,         //��4
    ALIVE3 = 1000,          //��3
    DIE4 = 1000,            //��4
    ALIVE2 = 100,           //��2
    DIE3 = 100,             //��3
    DIE2 = 10,              //��2
    ALIVE1 = 10             //��1
}score;

//����
typedef struct chess_s
{
    u8 x;
    u8 y;
}chess_t;

//���ӵ�����
typedef struct chess_queue_s
{
    chess_t chess[M_SIZE*M_SIZE];
    u8 len;
}chess_queue;

#endif
