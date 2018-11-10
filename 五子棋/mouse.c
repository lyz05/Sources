#include <windows.h>  
#include <stdio.h>  


int main(void)  
{  
	// 获取标准输入输出设备句柄  
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);        
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE); 
 
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	INPUT_RECORD	mouseRec;
	DWORD			res;
	COORD			crPos, crHome = {0, 0};
 
	printf("[Cursor Position] X: %2lu  Y: %2lu\n", 0, 0);	// 初始状态
 
	while (1)
	{
		ReadConsoleInput(hIn, &mouseRec, 1, &res);
 
		if (mouseRec.EventType == MOUSE_EVENT)
		{
			if (mouseRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
				{
					break;	// 左键双击 退出循环
				}
			}			
			
			crPos = mouseRec.Event.MouseEvent.dwMousePosition;
			GetConsoleScreenBufferInfo(hOut, &bInfo);
			SetConsoleCursorPosition(hOut, crHome);
			printf("[Cursor Position] X: %2lu  Y: %2lu", crPos.X, crPos.Y);
			SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition);
 
			switch (mouseRec.Event.MouseEvent.dwButtonState)
			{
			case FROM_LEFT_1ST_BUTTON_PRESSED:			// 左键 输出A
				FillConsoleOutputCharacter(hOut, 'A', 1, crPos, &res);
				break;		// 如果使用printf输出，则之前需要先设置光标的位置
 
			case RIGHTMOST_BUTTON_PRESSED:				// 右键 输出a
				FillConsoleOutputCharacter(hOut, 'a', 1, crPos, &res);
				break;
 
			default:
				break;
			}
		}		
	}
 
	CloseHandle(hOut);  // 关闭标准输出设备句柄  
	CloseHandle(hIn);   // 关闭标准输入设备句柄  
	return 0;  
}  