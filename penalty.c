#include "penalty.h"

int selectMenu(){
    int menu;
    printf("\n*** HGU Penalty System ***\n");
    printf("1. 벌점 추가\n"); 
    printf("2. 벌점 삭제\n"); 
    printf("3. 벌점 수정\n"); 
    printf("4. 벌점 조회\n"); 
    printf("5. 벌점 검색\n"); 
    printf("6. 벌점 사례 검색\n");
    printf("7. 파일 저장\n");
    printf("8. 전체삭제\n");
    printf("공지사항 및 벌점 종류");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int deletePenalty(student *s){
    printf("몇점을 삭제하시겠습니까?");
    int num;
    scanf("%d",&num);
    s->totalNum-=num;
    return 1;
}

int deleteStudent(student *s){
    s->totalNum=-1;
    return 1;
}

void searchPenalty(student *s,int count){
    int snt=0;
    int search
    printf("찾으시는 총벌점은?");
    scanf("%d",&search);
    for(int i=0;i<count;i++){
        if(s[i].totalNum==-1){continue;}
        if(s[i]->totalNum==search){
         printf("이름 학번 벌점 팀교수님 rc 호실 상담신청여부");
         printf("===============================\n");
         readScore(s[i]);
         snt++;
        }
    }
    if(snt==0){
        printf("검색된 데이터 없음\n");
    }
}
