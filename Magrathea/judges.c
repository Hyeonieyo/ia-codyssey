#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char judges_array[5][256 * 7]; // 각 심사자 정보 저장을 위한 배열
    int judge_count = 0;

    // 참여 프로젝트 및 심사 풀 인원 입력
    char project[256];
    int pool_size, selected_members;

    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력       #\n");
    printf("####################################\n");
    printf("> 참여 프로젝트: ");
    fgets(project, 256, stdin);
    project[strcspn(project, "\n")] = 0;

    printf("> 심사 풀 인원: ");
    scanf("%d", &pool_size);
    printf("> 선발 멤버 수: ");
    scanf("%d", &selected_members);
    getchar();

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", pool_size);
    printf("++++++++++++++++++++++++++++++++++++\n");

    while (judge_count < pool_size) {
        char name[256], gender[256], affiliation[256];
        char position[256], expertise[256], email[256], phone[256];

        // 심사자 정보 입력
        printf("*심사자 %d: ", judge_count + 1);
        fgets(name, 256, stdin);
        name[strcspn(name, "\n")] = 0; // 개행 문자 제거

        printf("성별: ");
        fgets(gender, 256, stdin);
        gender[strcspn(gender, "\n")] = 0;

        printf("소속: ");
        fgets(affiliation, 256, stdin);
        affiliation[strcspn(affiliation, "\n")] = 0;

        printf("직함: ");
        fgets(position, 256, stdin);
        position[strcspn(position, "\n")] = 0;

        printf("전문분야: ");
        fgets(expertise, 256, stdin);
        expertise[strcspn(expertise, "\n")] = 0;

        printf("메일: ");
        fgets(email, 256, stdin);
        email[strcspn(email, "\n")] = 0;

        printf("전화: ");
        fgets(phone, 256, stdin);
        phone[strcspn(phone, "\n")] = 0;

        // JSON 형식으로 배열에 저장
        snprintf(judges_array[judge_count], sizeof(judges_array[judge_count]), 
                 "{\"이름\":\"%s\", \"성별\":\"%s\", \"소속\":\"%s\", \"직함\":\"%s\", \"전문분야\":\"%s\", \"메일\":\"%s\", \"전화\":\"%s\"}",
                 name, gender, affiliation, position, expertise, email, phone);

        judge_count++;
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 풀 확인 여부
    char confirm;
    printf("“심사자 풀을 확인할까요?” Y/N: ");
    scanf(" %c", &confirm);

    if (confirm == 'Y') {
        printf("[PROJECT] %s\n", project);
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력       #\n");
        printf("####################################\n");

        for (int i = 0; i < judge_count; i++) {
            printf("%s\n", judges_array[i]);
            printf("-----------------------------------\n");
        }
    } else {
        printf("프로그램을 종료합니다.\n");
    }

    return 0;
}
