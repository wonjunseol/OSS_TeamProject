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

void saveData(student *s, int count){
    FILE *fp;
    fp=fopen("penalty.txt","wt");
    for(int i=0;i<count;i++){
        if(s[i].totalNum==-1) continue;
        fprintf(fp,"%s %d %u %s %s %d %c\n",s[i].name,s[i].studentId,s[i].totalNum,s[i].teamProf,s[i].rcName,s[i].roomNum,s[i].apply);
    }
    fclose(fp);
    printf("=>저장됨!");
}

int loadData(student *s){
    int i=0;
    FILE *fp;
    fp=fopen("penalty.txt","rt");
    if(fp==NULL){
        printf("파일 없음\n");
        return 0;
    }
    for(;i<100;i++){
        fscanf(fp,"%s",s[i].name);
        if(feof(fp)) break;
        fscanf(fp,"%d",&s[i].studentId);
        fscanf(fp,"%u",&s[i].totalNum);
        fscanf(fp,"%s",&s[i].teamProf); 
        fscanf(fp,"%s",s[i].rcName);
        fscanf(fp,"%d",s[i].roomNum);
        fscanf(fp,"%c",s[i].apply);        
}    fclose(fp);
    printf("=>로딩 성공!\n");
    return i;
}

void readStudent(student plist) {
    printf("	 %s %d %s교수님 %s %d\n", plist.name, plist.studentId, plist.teamProf, plist.rcName, plist.roomNum);
}

void listStudent(student *plist, int count) {
    printf("*****************\n");
    for(int i=0; i<count; i++) {
        if(plist[i].totalNum == 0) {
            continue;
        }
        printf("%2d ", i+1);
        readStudent(plist[i]);
    }
}
void showInfo(){
    printf("
한동대학교의 학생 생활관은 "공동 생활 공간"으로 나를 지키고 타인을 배려하는 마음으로 함께 수칙을 지켜나갑시다.\n\n
*생활관 건물 내에서 음주 및 흡연을 하는 학생이 적발시 운영내규 벌점기준표에 의거하여 퇴사 조치대상이므로 기숙사내에서는 절대로 음주와 흡연을 금지하여 주시길 바랍니다.*\n\n
무단 외박 - 1점\n
생활관 내에 외부인 출입 및 숙박 - 2점\n
공동사용구역에 음식물 및 쓰레기무단투기 - 2점\n
인원점검표에 허위기재 - 3점\n
생활관 관련 시설물을 고의로 파괴 또는 훼손 - 3점\n
형사상 위범 행위자(절도. 폭력) - 4점\n
생활관 내에서 음주, 흡연 - 퇴거\n
남.여 기숙사 무단 출입 - 퇴거\n\n

*벌점 7점시 팀교수님 면담*\n
*벌점 10점시 퇴거*\n")
}
