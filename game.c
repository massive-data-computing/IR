#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int gen_number(int level) {

  int lv[3] = {0, 10, 100};
  int hv[3] = {9, 99, 999};

  int r = lv[level] + rand()% (hv[level] - lv[level] + 1);
  return r;

}

int main(void) {

  int level;
  printf("Level=");
  scanf("%d", &level);

  srand(time(NULL));
  printf("%d 단계 게임 시작\n", level);

  time_t stime, etime;
  stime = time(NULL);
  int acc = 0;
  for(int i=1; i<=10; i++) {
    int a, b;
    a = gen_number(level);
    b = gen_number(level);

    int answer;
    printf("%d+%d=", a, b);
    scanf("%d", &answer);

    if(a+b==answer) acc++;

  }

  etime = time(NULL);
  printf("정답률=%f\n", acc/10.);
  printf("시간=%lus\n", (etime-stime));
}
