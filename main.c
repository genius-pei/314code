#include"process.h"

double total =1024.0;
double speed =1.0;

void DownLoad()
{
  double curr=0.0;
  while(curr<=total)
  {
    FlashProcess(total,curr);//更新进度

    curr +=speed;//模拟下载行为
    usleep(30000);

  }
}
int main()
{
 // Process();
 // DownLoad();
  return 0;
}
