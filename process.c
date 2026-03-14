#include"process.h"
#include<string.h>
#define SIZE 101
#define STYLE '='
void FlashProcess(double total, double current)
{
    char buffer[SIZE];
    memset(buffer, 0, sizeof(buffer));
    const char *lable="|/-\\";
    int len = strlen(lable);
    static int cnt = 0;
    // 新增：标记进度是否已完成（静态变量，多次调用保持状态）
    static int is_finished = 0;

    // ========== 核心修复1：边界处理 ==========
    // 防止current超过total导致进度条越界，同时避免浮点精度问题
    if (current >= total) {
        current = total; // 强制将进度锁定为100%
        // 仅在第一次完成时执行结束逻辑，避免重复换行
        if (!is_finished) {
            // 填充100%的进度条
            int i = 0;
            for (; i < 100; i++) {
                buffer[i] = STYLE;
            }
            // 打印最终100%进度条，用\n替代\r，结束刷新并换行
            printf("[%-100s][100.0%%][%c]\n", buffer, lable[cnt % len]);
            fflush(stdout);
            is_finished = 1; // 标记为已完成，后续调用不再刷新
        }
        return; // 进度完成后直接返回，不再执行后续刷新逻辑
    }

    // ========== 核心修复2：重置完成标记（如果进度回退） ==========
    if (is_finished) {
        is_finished = 0;
    }

    // ========== 原有逻辑保留（仅优化） ==========
    // 计算进度百分比（0~100），避免负数（比如current为0时）
    int num = (int)(current * 100 / total);
    // 限制num不超过100（双重保险）
    num = num > 100 ? 100 : num;
    int i = 0;
    for(; i < num; i++)
    {
        buffer[i] = STYLE;
    }

    double rate = current / total;
    cnt %= len;
    // 正常进度仍用\r覆盖刷新
    printf("[%-100s][%.1f%%][%c]\r", buffer, rate * 100, lable[cnt]);
    cnt++;
    fflush(stdout);
}







void Process()

{
  const char *lable="|/-\\";
  int len=strlen(lable);

  char processbuff[SIZE];
 memset(processbuff, '\0',sizeof(processbuff));

 int cnt =0;
 while(cnt<=100)
 {
   printf("[%-100s][%d%%][%c]\r",processbuff,cnt,lable[cnt%len]);
  fflush(stdout);
   processbuff[cnt++]= STYLE;
   
  usleep(50000);

 }
 printf("\n");
}
//version 2

void Process3() 
{

}



