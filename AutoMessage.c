#include <stdio.h>
#include <windows.h>

int main() {
	
	char room[32], msg[256];
	int count;
	
	printf("카카오톡 채팅방 이름을 입력해주세요 : ");
	gets(room);
	
	printf("메세지를 입력해주세요 : ");
	gets(msg);
	
	printf("메세지의 횟수를 입력해주세요 : ");
	scanf("%d", &count);
	
	if( count < 1) {
		count = 1;
		printf("회수가 1보다 작아 자동으로 1으로 정해졌습니다.");
	}
	 
	HWND k = FindWindow(NULL, (LPCSTR)room);
	HWND c = FindWindowEx(k, NULL, "RICHEDIT50W", NULL);
	
	do {
		Sleep(200);
		SendMessage(c, WM_SETTEXT, NULL, (LPARAM)msg);
		PostMessage(c, WM_KEYDOWN,  0X0D , 0);
	}while(count-- > 1);
	
	
	return 0;
}
