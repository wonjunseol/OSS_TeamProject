#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[30];
	int studentId;
	int totalNum;
	char teamProf[30];
	char rcName[30];
	int roomNum;
	char apply; //Y/N
}student;

int addStudent(student *plist, int count);
void goStudent(student *plist, int count);
void goNum(student *plist, int count);
void readStudent(student plist);
void listStudent(student *plist, int count);
int updateStudent(student *plist);
int selectDataNo(student *plist, int count);
void goCouncel(student *plist, int count);
int goDelete(student *plist, int count);
int deletePenalty(student *s);
int deleteStudent(student *s);
void searchPenalty(student *s,int count);
void saveData(student *s, int count);
int loadData(student s[], int count);
void showInfo();
int searchID(student *s, int count);
int selectMenu();
