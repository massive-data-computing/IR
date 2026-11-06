#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main() {
    int level;
    system("clear");
    printf("=== 숫자 암기 게임 ===\n");
    printf("Level을 입력하세요: ");

    scanf("%d", &level);
    int total_elements = level*2;
    int numbers[total_elements];
    for (int i = 0; i < total_elements; i++) {
        numbers[i] = i + 1;
    }
    srand(time(NULL));
    for (int i = total_elements - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
    
        printf("\n다음 숫자를 외우세요!\n");
    for (int i=0; i<total_elements; i++) 
              printf("%d  ", numbers[i]);
    printf("\n");

    sleep(3);
    system("clear");
	
    getchar();
    printf("숫자를 입력하세요!\n");
    char answer_str[100];
    fgets(answer_str, sizeof(answer_str), stdin);

    int answers[total_elements*2];
    int cnt = 0;
    char *token = strtok(answer_str, " ");
    while (token != NULL) {
        int num = atoi(token);
        answers[cnt] = num;
        cnt++;
        token = strtok(NULL, " ");
    }

    for(int i=0; i<total_elements; i++) {
            if(numbers[i]!=answers[i]) {
                    printf("Fail!\n");
                    return 0;
            }
    }

    printf("Success!\n");
    return 0;

}

