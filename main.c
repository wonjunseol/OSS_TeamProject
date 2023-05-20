#include <stdio.h>
#include <string.h>
#include "penalty.h"

int main() {
    student plist[100];
    int count = 0, menu;
    int index=0;
    int check;
    for(int i=0; i<100; i++) {
        plist[i].apply = 'N';
        plist[i].totalNum = 0;
    }
    count=loadData(plist, 100);
    index=count;
    
    
    while(1) {
        menu = selectMenu();
        if((menu==2)||(menu==3)||(menu==4) || (menu==4) || (menu==6) || (menu==7) || (menu==8) || (menu==9) || (menu==10)){
            if(count==0){
                printf("데이터가 없습니다.\n"); 
                continue;
            }
        }
        if (menu == 1){
            addStudent(plist, count);
            if(plist[count].totalNum != 0) {
                count++;
            }

        }

        else if(menu==2) {
            listStudent(plist, count);
             int num=searchID(plist, count); 
            if(num == -2) {
                printf("=> 취소됨!\n");
                continue;
            }
            else if (num != -1){
                printf("%s 학생의 벌점을 삭제하시겠습니까(취소=0)(수락=1): ",plist[count].name);
                int deleteok;
                scanf("%d",&deleteok);
                if(deleteok==0){
                    printf("취소됨!\n"); continue;
                }
                else if(deleteok==1){
                    deletePenalty(&plist[num]);
                    printf("벌점 수정 완료!\n");
                }
            }
            else if(num == -1) {
                printf("찾으시는 학번이 없습니다.\n");
            }
        }

        else if(menu==3){
            listStudent(plist, count);
             int num=searchID(plist, count); 
            if(num == -2) {
                printf("=> 취소됨!\n");
                continue;
            }
            else if(num != -1){
                printf("%s 학생을 삭제하시겠습니까(취소=0)(수락=1): ",plist[count].name);
                int deleteok;
                scanf("%d",&deleteok);
                if(deleteok==0) {
                    printf("취소됨!\n"); 
                    continue;
                }
                else if(deleteok==1) {
                    deleteStudent(&plist[num]);
                    printf("삭제 완료!\n");
                }
            }
            else if(num == -1) {
                printf("찾으시는 학번이 없습니다.\n");
            }  
        }

        else if(menu == 4) {
            printf("\n");
            int num=searchID(plist, index); 
            if(num == 0) {
                printf("=> 취소됨!\n");
                continue;
            }
            updateStudent(&plist[num]);
            printf("\n");
        }

        else if(menu == 5) { //5. 벌점 리스트함수(조회)(리스트, (ex. 7점시 교수님 면담. 10점시 퇴거))
            if(count >0) {
                printf("\n");
                printf("벌점을 받은 모든 학생들의 리스트\n");
                listStudent(plist, count);
            }
            else {
                printf("입력된 학생이 없습니다.\n");
            }
        }

        else if(menu == 6){
            listStudent(plist, count);
            int num=searchID(plist, index);  
            if(num == -2) {
                printf("=> 취소됨!\n");
                continue;
            }
            if(num == -1) {
                printf("찾으시는 학번이 없습니다.\n");
            }  
            else {
                readStudent(plist[num]);
            }
        }

        else if(menu==7) {
            searchPenalty(plist,count);
        }

        else if(menu == 8) { 
            //7. 상담 신청(1. 학번 입력 2. 7점 미만이면 7점 미만이므로 신청 불가합니다. 
            //7점 이상이면 22200377.prof 이 교수님과 상담을 신청하시겠습니까? 1  0 으로 입력 받고 신청완료되었습니다. 
            //그리고 상담 신청 Y로 바꿈. -> 학번 없으면 없음 띄우기. -> 신청을 이미 했으면 1 번 후에 이미 신청되었습니다.)
            goCouncel(plist, index);
        }

        else if(menu==9){
            saveData(plist,count);
        }

        else if(menu == 10) {
            printf("정말로 삭제하시겠습니까?(삭제: 0, 취소: 1) ");
            scanf("%d", &check);
            if(check == 0) {
                count = goDelete(plist, count);
            }
            else {
                printf("취소됨!\n");
            }
        }

        else if(menu==11){
            printf("\n");
            showInfo();
        }

        else if(menu == 0) {
            break;
        }
    }
}
