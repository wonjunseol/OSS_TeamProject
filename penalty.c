#include "penalty.h"

int selectMenu(){
    int menu;
    printf("\n*** HGU Penalty System ***\n");
    printf("1. 벌점 추가\n"); 
    printf("2. 벌점 삭제(학번으로 학생 검색 후 벌점 삭제)\n"); 
    printf("3. 학생 삭제(학번으로 학생 검색 후 학생 삭제)\n"); 
    printf("4. 벌점 수정\n"); 
    printf("5. 벌점을 받은 학생 조회\n"); 
    printf("6. 학번 검색\n");
    printf("7. 벌점 검색(총 벌점이 찾는 벌점에 해당하는 학생들 리스트)\n");
    printf("8. 상담 신청\n");
    printf("9. 파일 저장\n");
    printf("10. 전체삭제\n");
    printf("11. 공지사항 및 벌점 종류\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int searchID(student *s, int count){
 int search;
    printf("찾으시는 학번은(취소: 0)? ");
    scanf("%d",&search);
    if (search==0) {
        return -2;
    }
    for(int i=0;i<100;i++){
        if(s[i].totalNum==0){
            continue;
        }
        if(s[i].studentId==search){
            return i;
            }
         }
    return -1;
}


int deletePenalty(student *s){
    printf("몇점을 삭제하시겠습니까?");
    int num;
    scanf("%d",&num);
    s->totalNum-=num;
    return 1;
}

int deleteStudent(student *s){
    s->totalNum=0;
    return 1;
}

void searchPenalty(student *s,int count){
    int snt=0;
    int search
    printf("찾으시는 총벌점은?");
    scanf("%d",&search);
    for(int i=0;i<count;i++){
        if(s[i].totalNum==-1){continue;}
        if(s[i].totalNum==search){
		printf("*****************\n");
         	readStudent(s[i]);
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
        fprintf(fp,"%s %d %s %s %d %d %c\n",s[i].name,s[i].studentId,s[i].teamProf,s[i].rcName,s[i].roomNum,s[i].totalNum,s[i].apply);
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
<<<<<<< HEAD

=======
void showInfo(){
printf("--한동대학교 생활관 공지사항 및 벌점 종류--\n\n");
printf("한동대학교의 학생 생활관은 "공동 생활 공간"으로 나를 지키고 타인을 배려하는 마음으로 함께 수칙을 지켜나갑시다.\n\n
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
>>>>>>> 3d12585df3109978d6a1013b6a448978a13606ef
}

int addStudent(student *plist, int count) {
    int check = 0;
    getchar();
    printf("\n");
    listStudent(plist, count);
    printf("학생을 추가하시겠습니까? 아니면 기존에 있는 학번에 벌점을 추가하시겠습니까?(학생 추가: 0, 벌점 추가: 1) ");
    scanf("%d", &check);
    if(check == 0) {
        goStudent(plist, count);
        printf("%s학생이 벌점 1점으로 추가되었습니다.\n", plist[count].name);
    }
    else if(check == 1) {
        goNum(plist, count);
    }
    return 1;
}

void goStudent(student *plist, int count) {
    int go;
    printf("추가할 학생의 이름은? ");
    scanf("%s", plist[count].name);
    printf("추가할 학생의 학번은? ");
    scanf("%d", &plist[count].studentId);
    printf("추가할 학생의 팀교수님은? ");
    scanf("%s", plist[count].teamProf);
    printf("추가할 학생의 RC는? ");
    scanf("%s", plist[count].rcName);
    printf("추가할 학생의 호실은? ");
    scanf("%d", &plist[count].roomNum);
    printf("벌점 몇 점을 추가하시겠습니까? ");
    scanf("%d", &go);
    plist[count].totalNum += go;
    printf("%s학생의 벌점이 %d점 추가되었습니다.\n", plist[count].name, go);
}

void goNum(student *plist, int count) {
    int check;
    int go = 0;
    int goNum;
    printf("벌점을 줄 학생의 학번은? ");
    scanf("%d", &check);
    for(int i=0; i<count; i++) {
        if(check == plist[i].studentId) {
            go = 1;
            printf("벌점 몇 점을 추가하시겠습니까? ");
            scanf("%d", &goNum);
            plist[i].totalNum += goNum;
            printf("%s학생의 벌점이 %d점 추가되었습니다.\n", plist[i].name, goNum);
            break;
        }
    }
    if(go == 0) {
        printf("해당 학번의 학생이 없습니다.\n");
    }
}

void goCouncel(student *plist, int count) {
    int check;
    int yes;
    int checkNum=0;
    char day[5];
    printf("상담을 신청할 학번을 입력하세요. ");
    scanf("%d", &check);
    for(int i=0; i<100; i++) {
        if(plist[i].totalNum != 0) { 
            if(check == plist[i].studentId) {
                checkNum =1;
                if(plist[i].apply == 'N') { 
                    if(plist[i].totalNum >= 7 && plist[i].totalNum < 10) {
                        printf("해당 학번의 학생의 총 벌점은 %d점이므로 상담신청이 가능합니다.\n", plist[i].totalNum);
                        printf("%s교수님과 상담을 신청하시겠습니까? (신청: 1, 취소: 0) ", plist[i].teamProf);
                        scanf("%d", &yes);
                        if(yes == 1) {
                            printf("%s교수님과의 상담 신청이 완료되었습니다.\n", plist[i].teamProf);
                            plist[i].apply = 'Y';
                            break;
                        }
                        else {
                            printf("취소됨!\n");
                        }
                    }
                    else {
                        printf("총 벌점이 7점 미만이라 상담을 신청할 수 없습니다. 해당 학번의 총 벌점: %d\n", plist[i].totalNum);
                        break;
                    }
                }
                else {
                    printf("이미 상담이 신청 된 학생입니다.\n");
                    break;
                }
            }
            //else {
                
            //}
        }
        //else if(plist[i].totalNum == 0) {
        //    printf("입력하신 학번은 없는 학번입니다.\n");
         //   break;
        //}
    }
    if(checkNum == 0) {
        printf("입력한 학번은 없는 학번입니다.\n");
    }
}
           
