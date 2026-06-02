#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 25
#define MAX_PEO 1000

typedef struct PeoInfo {            //构造个人信息类
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact {            //构造通讯录类  
	PeoInfo PeoInfo_1[MAX_PEO];
	int count;                      //记录当前通讯录的有效元素个数
}Contact;

void PrintIndexMenu();              //打印主菜单
void initContact(Contact* pcon);    //初始化通讯录
void AddContact(Contact* pcon);     //添加联系人
void DisplayContact(Contact* pcon); //显示通讯录信息
void DeleteContact(Contact* pcon);  //删除联系人
void ModifyContact(Contact* pcon);  //修改联系人
void SearchContact(Contact* pcon);  //搜索联系人
void SortContact(Contact* pcon);    //排序联系人

