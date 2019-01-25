#define _CRT_SECURE_NO_WARNINGS

#define SPACEBAR 32

#include <stdio.h>
#include <stdlib.h>//문자열 변환, 의사 난수 생성, 동적 메모리 관리 등의 함수들을 포함하고 있다.
#include <time.h>
#include <Windows.h>//윈도우용의 수많은 함수들을 정의한다.
#include<conio.h> //콘솔 입출력과 관련된 함수가 정의 되어있다.
int main(void)
{
   int i = 0;
   int j = 0;
   int k = 1;
   long long t;
   int p = -1;
   int option;
   int ch = 0;
   while (1) {
      printf("옵션을 선택해 주세요(1=다운 워치,2=업워치:");
      scanf("%d", &option);
      switch (option)
      {
      case 1:
         printf("몇분으로 하시겠습니까? 단위는 시간 분 초 입니다.:");
         scanf("%d%d%d", &i, &j, &k);
         printf("%d시간 %d분 %d초후에 비프음을 발생시킵니다.1초후 시작됩니다.", i, j, k);
         Sleep(999);
         while (1)
         {
            t = time(0);
            if (t > p) {
               p = t;
               system("cls");
               printf("\n\n\n\n\n\n\n      %d시간%d분%d초 남음 ", i, j, k);
               k--;
               if (k < 0) {
                  k = 59;
                  j--;
                  if (j < 0) {
                     j = 59;
                     i--;
                     if (i < 0)
                     {
                        while (1) {
                           system("cls");
                           printf("\n\n\n\n\n\n\n     ");
                           Sleep(400);
                        }
                     }
                  }
               }
            }
            if (_kbhit()) { //키보드가 눌렸는지 확인하고 결과 리턴
               ch = _getch(); //키보드가 눌렸는지 확인한다.
               if (ch == SPACEBAR) {
                  system("cls");//화면을 청소한다.
                  printf("스페이스바 입력으로 강제적 종료됩니다.\n");
                  Sleep(1500);//Sleep은 딜레이를 주는 함수이다.
                  return 0;
               }
            }
            Sleep(100);
         }
         break;
      case 2:
         while (1)
         {
            t = time(0);
            if (t > p) {
               p = t;
               system("cls");
               printf("\n\n\n\n\n\n\n     %d시간 %d분 %d초 경과 ", i, j, k);
               k++;
               if (j >= 60) {
                  ch = _getch();
                  if (ch == SPACEBAR) {
                     system("cls");
                     printf("스페이스바 입력으로 강제적 종료됩니다.\n");
                     Sleep(1500);
                     return 0;
                  }
               }
               Sleep(100);
            }
            Sleep(5);
         }
         break;
      default:
         printf("1,2가 아닌 값을 입력 하셨습니다. \n");
      }
      return 0;
   }
}