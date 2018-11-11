/**
 @file gobang.c
 @date 2018-11-9
 @author xpf/lyz 
 @version v1.3 
*/

#include "gobang_main.h"
#include <time.h>
#include <sys/time.h>
/*
�汾˵��:
1��ʵ���˼���Сֵ����,û��beta�ü����Ż�.
2������AI��һ����ʱ�����,����alpha��beta�Ĳü�,Ч��һ��,��ǿ�㵽4��(10s��)��
*/
u8 gBoard[M_SIZE][M_SIZE];                      //����
u8 AIChessColor = BLACE;                        //AIִ�׺���.
u8 humChessColor = WHITE;
u8 gDeep = DEEP;
u8 version = 2;

#if DEBUG
chess_queue gRecord;
#endif

/*��ʼ������*/
//static void gobang_init(void);
/*����ֵ��*/
static int max_alphabeta(s8 depth, chess_t chess, s32 alpha, s32 beta);
/*��С��*/	
static int min_alphabeta(s8 depth, chess_t chess, s32 alpha, s32 beta);

/*����Сֵ�㷨*/
void chess_ai_minmax_alphabeta(chess_t *chess, s8 depth);
/*�������*/
static int hum_play_chess(int,int,int);
/*AI����*/
static int AI_play_chess(Boolean isFirst);
/*Ӯ����*/
Boolean is_win(u8 x, u8 y, u8 color);
/*��ӡ����*/
//void print_chess_board(void);

//��ں���
int main()								//OK
{
	freopen("gobang.in","r",stdin);
	freopen("gobang.out","w",stdout);
	//printf("**************gobang v1.0***************\n");
	//printf("input:x y play chess \n");
	//printf("***************************************\n\n");
	//gobang_init();
	//printf("��ָ��AI������ɫ��0������ӣ�1�������\n");
	int tmp;
	scanf("%d",&tmp);
	 
	//�ڰ���ת�� 
	if (tmp==1) 
	{
		AIChessColor = BLACE;
		humChessColor = WHITE;
	} else 
	{
		AIChessColor = WHITE;
		humChessColor = BLACE;
	}
	
	int x,y,ret;
	//printf("��ָ���Ƿ�Ϊ��һ�����壬0��ʾ�ǣ�1��ʾ��\n");
	scanf("%d",&tmp);
	//printf("�����������������(x,y)���Կո�ָ�\n");
	ret = scanf("%d%d",&x,&y);
	//printf("������������15*15��������\n");
	int i,j;
	for (i=0;i<M_SIZE;i ++)
		for (j=0;j<M_SIZE;j ++)
		{
			int x;
			scanf("%d",&x);
			if (x==0) gBoard[i][j] = SPACE;
			if (x==1) gBoard[i][j] = WHITE;
			if (x==2) gBoard[i][j] = BLACE;
		}

   
    //�������
    if (tmp) goto AI; 
    ret = hum_play_chess(x,y,ret);
    if (GO_WIN == ret)   //ʤ��
    {
    	return GO_OK;
        //printf("Humber win!\n");
        //print_chess_board();
    }
    //print_chess_board();
    //AI����
    AI:
    if (tmp) ret = AI_play_chess(TRUE); else ret = AI_play_chess(FALSE);
    if (GO_WIN == ret)      //ʤ��,��ӡ����,�˳�ȥ
    {
    	return GO_OK;
        //printf("AI win!\n");
        //print_chess_board();
    }
    //print_chess_board();
	return GO_OK;
}

/*
�������
*/
static int hum_play_chess(int x,int y,int ret)//OK
{
    //printf("play chess:");
    //ret = scanf("%d %d", &x, &y);
    //��ҵ���,��1����
    x = x - 1;
    y = y - 1;
    if (!ret)
    {   
        printf("Scanf Error.\n");
        return -2;
    }
    if (check(x)||check(y))
    {
        printf("Number Error.\n");
        return GO_ERROR;
    }
    if (gBoard[x][y] != SPACE)
    {
        printf("Has chess.\n");
        return GO_ERROR;    
    }      
    gBoard[x][y] = humChessColor;
    if (is_win(x, y, humChessColor))
    {
        return GO_WIN;
    }
    return GO_OK;
}
/*AI����*/
static int AI_play_chess(Boolean isFirst)//OK
{
    chess_t chess;
    chess.x = 0;
    chess.y = 0;
    //struct timeval start_t, end_t;
    //long use_time = 0;          //us
    //double use_time_sec = 0;
    if (isFirst)    //���̿յ�����,���һ���м����.(���Ӷ������ɲ���)
    {
    	//randomize(time(0));
    	chess.x =(int)(rand()%5) + 5;
        chess.y =(int)(rand()%5) + 5; 
    }
    else
    {
        //printf("Waiting AI...\n");
        //gettimeofday(&start_t, NULL);
        chess_ai_minmax_alphabeta(&chess, gDeep);
        //gettimeofday(&end_t, NULL);
        //use_time = 1000000*(end_t.tv_sec - start_t.tv_sec)+(end_t.tv_usec - start_t.tv_usec);
    }
    printf("%d %d\n",chess.x+1,chess.y+1);
    //printf("AI chess:(%d,%d),use time:%fs\n", chess.x+1, chess.y+1, use_time/1000000.0);
    gBoard[chess.x][chess.y] = AIChessColor;
    if (is_win(chess.x, chess.y, AIChessColor))
    {
        return GO_WIN;
    }
    return GO_OK;
}

/*��ʼ��*/
//static void gobang_init(void)				//OK
//{
//    u8 i, j;
//#if DEBUG
//    gRecord.len = gDeep;
//#endif
//    //AIChessColor = BLACE;                //����ΪAIִ����
//    //humChessColor = WHITE;
//    for (i=0; i<M_SIZE; i++)        
//    {
//        for (j=0; j<M_SIZE; j++)
//        {
//            gBoard[i][j] = SPACE;       //���̳�ʼ��
//        }
//    }  
//}

/*��ӡ����*/
//void print_chess_board(void)
//{
//    u8 i, j;
//    printf("   ");
//    for (i=0; i<M_SIZE; i++)
//    {
//        printf("%x ", i+1);
//    }
//    printf("\n  -------------------------------\n");
//    for (j=0; j<M_SIZE; j++)
//    {
//        
//        if (j<9)
//        {
//            printf("\n%d |", j+1);
//        }
//        else
//        {
//            printf("\n%d|", j+1);
//        }
//        for (i=0; i<M_SIZE; i++)
//        {
//            printf("%d ", gBoard[j][i]);
//        }
//        printf("|%d", j+1);
//    }
//    printf("\n  -------------------------------\n");
//}

/*�ж��Ƿ�ʤ��*/
Boolean is_win(u8 x, u8 y, u8 color)//OK
{
	int count = 0;
	int i,j;
	int size = 15;
	//��
	for (i=(x-4>0?x-4:0); (i<=x+4)&&(i<size); i++) 
	{
		if (color == (gBoard[i][y]))
		{
			count++;
			if (count >= 5)
			{
				return TRUE;
			}
		}
		else
		{
			count = 0;
		}
	}
	//��
	count = 0;
	for (j=(y-4>0?y-4:0); (j<=y+4)&&(j<size); j++) 
	{
		if (color == (gBoard[x][j]))
		{
			count++;
			if (count >= 5)
			{
				return TRUE;
			}
		}
		else
		{
			count = 0;
		}
	}
	//��б��(\)
	count = 0;
	for (i=x-4,j=y-4;(i<=x+4)&&(i<size)&&(j<=y+4)&&(j<size); i++,j++) 
	{
		if (check(i) || check(j)) continue;
		if (color == (gBoard[i][j]))
		{
			count++;
			if (count >= 5)
			{
				return TRUE;
			}
		}
		else
		{
			count = 0;
		}
	}
	//��б��(/)
	count = 0;
	for (i=x-4,j=y+4;(i<=x+4)&&(i<size)&&(j>=y-4)&&(j>=0); i++,j--) 
	{
		if (check(i) || check(j)) continue;
		if (color == (gBoard[i][j]))
		{
			count++;
			if (count >= 5)
			{
				return TRUE;
			}
		}
		else
		{
			count = 0;
		}
	}
	return FALSE;
}

/*�Ʒֱ�,�������Ӹ���(bumber)�����˵Ŀ��Ӹ���(empty)*/
static u32 score_table(u8 number, u8 empty)//OK
{
    if (number >= 5)
    {
        return WIN5;
    }
    else if (number == 4)
    {
        if (empty == 2)	
		{
            return ALIVE4;
		}
        else if (empty==1)
		{
            return DIE4;
		}
    }
    else if (number == 3)	
    {
		if (empty == 2)	
		{
            return ALIVE3;
		}
		else if (empty == 1)
		{			
            return DIE3;
		}
	}
	else if (number == 2)
	{
		if (empty == 2)	
		{
            return ALIVE2;
		}
		else if (empty == 1)
		{			
            return DIE2;
		}
    }
    else if (number == 1&&empty == 2)
	{
        return ALIVE1;
	}
    return 0;
}


/*��б�ߡ���б�ߡ��ᡢ������ת��һά����������*/
static u32 count_score(u8 n[], u8 chessColor)//OK
{   
    u8 i = 1;           //n[0]�Ѿ���ǰ����
	u8 empty = 0;       //�յ�λ��
	u8 number = 0;      //���ӵĸ���
	u32 scoretmp = 0;
    if (n[0] == SPACE)	
    {
        empty++;
    }
	else if (n[0] == chessColor)
    {
        number++;
    }
    
    while (i < M_SIZE)
    {
        if (n[i] == chessColor)
        {
            number++;
        }
        else if (n[i] == SPACE)
        {
            if (number == 0)
            {
                empty = 1;
            }
            else
            {
                scoretmp += score_table(number, empty+1);
				empty = 1;
				number = 0;
            }
        }
        else//(n[i]!=chesscolor && n[i]!=SPACE)
		{
			scoretmp += score_table(number, empty);
			empty = 0;
			number = 0;
		}
		i++;
    }
    scoretmp += score_table(number, empty);
	return scoretmp;
}

/*�ѵ�ǰ�����������߶��浽һά����,Ȼ����һ�����*/
static s32 evaluate_board(void)//������������������//OK
{
	u32 AIScore=0;
	u32 humScore=0;
    u8 i, j;
    s8 x, y;        //�����u8,x--,y--����ʱ�������
    u8 n[M_SIZE];
    memset(n, 0, sizeof(n));
	//���� 
	for (i=0; i<M_SIZE; i++)
	{
        for(j=0; j<M_SIZE; j++)
        {
            n[j] = gBoard[i][j];
        }
    	AIScore += count_score(n, AIChessColor);
    	humScore += count_score(n, humChessColor);
    	memset(n, 0, sizeof(n));
	}
	//����
	for (j=0; j<M_SIZE; j++)
	{
		for(i=0; i<M_SIZE; i++)
        {      
            n[i] = gBoard[i][j];
        }
		AIScore += count_score(n, AIChessColor);
		humScore += count_score(n, humChessColor);
    	memset(n, 0, sizeof(n));
	} 
	//�ϰ���б��(\)
	for (i=0; i<M_SIZE; i++)
	{
		for(x=i,y=0; x<M_SIZE&&y<M_SIZE; x++,y++)
		{
            n[y] = gBoard[x][y];
		}
		AIScore += count_score(n, AIChessColor);
		humScore += count_score(n, humChessColor);
    	memset(n, 0, sizeof(n));
	} 
	//�°���б��
	for (j=1; j<M_SIZE; j++)
	{
		for(x=0,y=j; y<M_SIZE&&x<M_SIZE; x++,y++)
		{
            n[x] = gBoard[x][y];
		}
		AIScore += count_score(n, AIChessColor);
		humScore += count_score(n, humChessColor);
    	memset(n, 0, sizeof(n));
	} 
	//�ϰ뷴б��(/)
	for (i=0; i<M_SIZE; i++)
	{
		for(y=i,x=0; y>=0&&x<M_SIZE; y--,x++)
		{
            n[x] = gBoard[x][y];
		}
		AIScore += count_score(n, AIChessColor);
		humScore += count_score(n, humChessColor);
    	memset(n, 0, sizeof(n));
	} 
	//�°뷴б��
	for (j=1; j<M_SIZE; j++)
	{
		for (y=j,x=M_SIZE-1; y<M_SIZE&&x>=0; y++,x--)
		{
            n[y-j] = gBoard[x][y];
		}
		AIScore += count_score(n, AIChessColor);
		humScore += count_score(n, humChessColor);
    	memset(n, 0, sizeof(n));
	} 
    return AIScore-humScore;
}

/*�Ƿ����ھ�:����֮���Ƿ����Ӵ���(�����Ƕ��ֻ����Լ����Ӷ�����)*/
static Boolean has_neighbors(int x, int y)//OK
{
	int s = 2;	//����֮������
	u8 i = 0, j = 0;
	for (i=(x-s>0?x-s:0); i<=x+s&&i<M_SIZE; i++)
		for (j=(y-s>0?y-s:0); j<=y+s&&j<M_SIZE; j++)
			if (i!=0 || j!=0)
				if (SPACE != (gBoard[i][j]))
					return TRUE;
	return FALSE;
}

//�������Ż�:��Ŀ��������Ƚ��й��֣�Ȼ������,��Ϊalpha-beta��֦�����ڿ���˳��.
/*������������(�������ӵĿ�λ)*/
static void generate_point(chess_queue *queue)	//OK
{
    int i,j,k = 0;
	for (i=0; i<M_SIZE; i++)
    {   
		for (j=0; j<M_SIZE; j++)
        {      
			if ((gBoard[i][j]==SPACE) && has_neighbors(i,j))//���ھӵĿ���,��Ϊ�����ӵĶ���
			{
                queue->chess[k].x = i;
                queue->chess[k].y = j;
                queue->len = k+1;
                k++;
			}
        }
    }
}

#if 0
static int max_alphabeta(s8 depth, chess_t chess)	
{
	s32 res = evaluate_board();
    u8 i, x, y;
    s32 tmpScore;
    s32 best = -WIN5;
    chess_queue queue; 
	if ((depth <= 0) || (is_win(chess.x, chess.y, humChessColor)))//��һ�������������ܲ�����Ӯ
	{
        return res;
	}
	generate_point(&queue);			//���ɿ��������ӵĿ�������
	for (i=0; i<queue.len; i++)
	{
	    x = queue.chess[i].x;
        y = queue.chess[i].y;
        gBoard[x][y] = AIChessColor;    //������һ����
        tmpScore = min_alphabeta(depth-1, queue.chess[i]);
        gBoard[x][y] = SPACE;           //�ָ��ɿ���
		if (tmpScore > best)
        {
            best = tmpScore; 
        }
	} 
	return best;
}

static int min_alphabeta(s8 depth, chess_t chess)										 
{
	s32 res = evaluate_board();
    u8 i, x, y;
    s32 tmpScore;
    s32 best = WIN5;
    chess_queue queue;
    if ((depth <= 0) || (is_win(chess.x, chess.y, AIChessColor)))//��һ����AI������ܲ�����Ӯ
    {
        return res;
    }
	generate_point(&queue);
	for (i=0; i<queue.len; i++)
	{
	    x = queue.chess[i].x;
        y = queue.chess[i].y;
        gBoard[x][y] = humChessColor;    //������һ����
        tmpScore = max_alphabeta(depth-1, queue.chess[i]);
        gBoard[x][y] = SPACE;  
		if (tmpScore < best)
        {
            best = tmpScore; 
        }
	} 
	return best;
}
#endif

//alpha����ʾĿǰΪֹ��һ���ҵ�����С��
//beta����ʾĿǰΪֹ��һ���ҵ��������
/*��min�㣨��ң�����ʱ,����������*/
static int min_alphabeta(s8 depth, chess_t chess, s32 alpha, s32 beta)
{
	s32 res = evaluate_board();
    u8 i, x, y;
    s32 tmpScore;
    s32 best = WIN5;
    chess_queue queue;
#if DEBUG    
    if (depth <= 0)
    {
        if (res > 0)
        {
            for (i=0; i<gRecord.len; i++)
            {
                printf("deep%d:(%d,%d)->", gDeep-i, gRecord.chess[i].x, gRecord.chess[i].y);
            }
            printf("%d\n", res);
        }
    }
#endif
    if ((depth <= 0) || (is_win(chess.x, chess.y, AIChessColor)))//��һ����AI������ܲ�����Ӯ
    {
        return res;
    }
    if (check(chess.x)| check(chess.y))
    {
        printf("Min Error!\n");
        return GO_ERROR;
    }
	generate_point(&queue);
	for (i=0; i<queue.len; i++)
	{
	    x = queue.chess[i].x;
        y = queue.chess[i].y;
        gBoard[x][y] = humChessColor;    //������һ����
    #if DEBUG
        gRecord.chess[gRecord.len-depth].x = x; 
        gRecord.chess[gRecord.len-depth].y = y;
    #endif
    
        tmpScore = max_alphabeta(depth-1, queue.chess[i], best<alpha?best:alpha, beta);
        gBoard[x][y] = SPACE;  
		if (tmpScore < best)
        {      
            best = tmpScore; 
        }

        if (tmpScore < beta)
        {
            break;
        }
	} 
	return best;
}

/*��max�㣨����AI������ʱ,������õ����*/
static int max_alphabeta(s8 depth, chess_t chess, s32 alpha, s32 beta)	
{
	s32 res = evaluate_board();
    u8 i, x, y;
    s32 tmpScore;
    s32 best = -WIN5;
    chess_queue queue;
#if DEBUG    
    if (depth <= 0)
    {
        //if (res > 0)
        {
            for (i=0; i<gRecord.len; i++)
            {
                printf("deep%d:(%d,%d)->", gDeep-i, gRecord.chess[i].x, gRecord.chess[i].y);
            }
            printf("%d\n", res);
        }
    }
#endif   
	if ((depth <= 0) || (is_win(chess.x, chess.y, humChessColor)))//��һ�������������ܲ�����Ӯ
	{
        return res;
	}
    if (check(chess.x)| check(chess.y))
    {
        printf("Max Error!\n");
        return GO_ERROR;
    }
	generate_point(&queue);

	for (i=0; i<queue.len; i++)
	{
	    x = queue.chess[i].x;
        y = queue.chess[i].y;
        gBoard[x][y] = AIChessColor;    //������һ����
    #if DEBUG
        gRecord.chess[gRecord.len-depth].x = x;
        gRecord.chess[gRecord.len-depth].y = y;
    #endif
        tmpScore = min_alphabeta(depth-1, queue.chess[i], alpha, best>beta?best:beta);
        gBoard[x][y] = SPACE;           //�ָ��ɿ���
		if (tmpScore > best)
        {      
            best = tmpScore; 
        }
        if (tmpScore > alpha)
        {
            break;
        }
	} 
	return best;
}

/*����Сֵ����depth��������Ž�*/
void chess_ai_minmax_alphabeta(chess_t *chess, s8 depth)
{
	u8 i = 0, k = 0;
    u8 x = 0, y = 0;
    s32 tmp = 0;
    s32 best = -WIN5;
    chess_queue option_queue;           //��ѡ�Ŀ��Ӷ���
    chess_queue sure_queue;             //����ʵ�����λ��
	generate_point(&option_queue);
    
	for (i=0; i<option_queue.len; i++)
	{
        x = option_queue.chess[i].x;
        y = option_queue.chess[i].y;
	    gBoard[x][y] = AIChessColor;    //��������AIѡ����ɫ����ֹ����ݹ�ʱ���ٵݹ鵽
    #if DEBUG							//���ڴ�ӡ����
	    gRecord.chess[gRecord.len-depth].x = x;      
        gRecord.chess[gRecord.len-depth].y = y;
        printf("###############deep:%d(%d,%d)################\n", depth, x, y);
    #endif
        tmp = min_alphabeta(depth-1, option_queue.chess[i], WIN5, -WIN5);        
		if (tmp == best)
        {      
            sure_queue.chess[k].x = option_queue.chess[i].x;
            sure_queue.chess[k].y = option_queue.chess[i].y;
			sure_queue.len = k+1;
            k++;
        }
		if (tmp > best)    //�ҵ�һ�����õķ�,����ǰ���λ��ȫ�����
		{
			best = tmp;
            k = 0;
			sure_queue.len = 1;         //�����ѡ����
            sure_queue.chess[k].x = option_queue.chess[i].x;
            sure_queue.chess[k].y = option_queue.chess[i].y;
		}
		gBoard[x][y] = SPACE;           //�ָ��ɿ���
	}
	k =(int)(rand()%sure_queue.len);    //����ж����߷���,���ѡ��һ��
	if (check(sure_queue.chess[k].x)||check(sure_queue.chess[k].y))
    {
        chess->x = 0;
        chess->y = 0;
        printf("Error AI space(%d,%d)\n", sure_queue.chess[k].x, sure_queue.chess[k].y);
        return;
    }
	chess->x = sure_queue.chess[k].x;
	chess->y = sure_queue.chess[k].y;
}


