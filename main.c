#include <stdio.h>
#include <string.h>
#include "penalty.h"

int main(){
	int menu;
	int result=0;
	int count=0;
	student plist[100];
	int index=0;
	count=loadData(plist);
	index=count;
while(1){
    menu=selectMenu();
    if(menu==0){ break;}
    if((menu==2)||(menu==3)||(menu==4))||(menu==5)||(menu==6)||(menu==7)||(menu==9){
        if(count==0){printf("데이터가 없습니다\n"); continue;
    }
}
else if (menu == 1){
          count += addStudent(plist, count);
}
else if(menu==2){
    int delete=selectno(plist,index);
    if(delete==0){
        printf("취소됨\n");
        continue;
    }
    else{
     printf("%s 학생의 벌점을 수정하시겠습니까(취소=0)(수락=1):",plist[index-1].name);
    int deleteok;
    scanf("%d",&deleteok);
    if(deleteok==0){printf("취소됨\n"); continue;}
    else if(deleteok==1){
        deletePenalty(&plist[delete-1]);
        printf("벌점 수정 완료!\n");
    }
    }
}
else if(menu==3){
    int delete=selectno(plist,index);
    if(delete==0){
        printf("취소됨\n");
        continue;
    }
    else{
     printf("진짜로 삭제하시겠습니까(취소=0)(수락=1):");
    int deleteok;
    scanf("%d",&deleteok);
    if(deleteok==0){printf("취소됨\n"); continue;}
    else if(deleteok==1){
        deleteStudent(&plist[delete-1]);
        printf("삭제 완료!\n");
    }
    }
}
else if(menu == 4) {
     printf("\n");
     int no = selectDataNo(plist, count);
     if(no == 0) {
         printf("=> 취소됨!\n");
         continue;
     }
     updateStudent(&plist[no-1]);
     printf("\n");
}	
else if(menu==6){
    searchPenalty(slist,index);
}
else if(menu==8){
    saveData(slist,index);
}
else if(menu==10){
    showInfo();
}
}
