// ergter.cpp : 定义控制台应用程序的入口点。
#include "StdAfx.h"
#include <stdlib.h>
#include <stdio.h>
#include <wtypes.h>
#include <winbase.h>
#include <time.h>
#include <conio.h>
#include <iostream>
using namespace std;

struct Person
{
	char name[20];//姓名
	char num[10];//工号
	float postWage;//岗位工资
	float ageWage;//薪级工资
	float allowance;//津贴
	float perWage;//实务工资
	float payWage;//应付工资
	float tax;//个人所得税
	float realWage;//实付工资
};

//建立临时的动态内存，使得职工的数据保存到里面
Person *zggz=new Person[100];

//文件指针
FILE*fp;

//职工人数，对职工进行计数，n >= 0，读取、保存、添加、删除都会改变人数
int n=0;

//输出到屏幕时方便格式控制，被查询、删除、添加、修改函数调用
char name[]="姓名";
char num[]="工号";
char postWage[]="岗位工资";
char ageWage[]="薪级工资";
char allowance[]="津贴";
char perWage[]="实务工资";
char payWage[]="应付工资";
char tax[]="个人所得税";
char realWage[]="实付工资";

float grsds(float);

//读取函数 输入文件中的数据到本文件的数组，无参数，无返回值 
void read()
{
	if ((fp = fopen("gx.dat", "ab+")))
	{
		while (!feof(fp))
		{
			char a=fgetc(fp);
			char b=EOF;

			if(a!=b)
			{
				fscanf(fp, "%s%s%f%f%f%f%f%f%f", &zggz[n].name, &zggz[n].num,
					&zggz[n].postWage,&zggz[n].ageWage, &zggz[n].allowance, 
					&zggz[n].perWage,&zggz[n].payWage, &zggz[n].tax, &zggz[n].realWage);
				n++;
			}
		}
		fclose(fp);
	}
	else
	{
		printf("\n打开文件失败！无法确定职工人数。");
	}
}

//保存函数 输出修改后的数据到文件中去，无参数，无返回值
void write()
{
	system("cls");
	if (::n > 0)
	{
		if ((fp = fopen("gx.dat", "wb")))
		{
			for (int i = 0; i < ::n; i++)
			{
				Person a=zggz[i];
				fprintf(fp, "\n%-20s%-10s%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f",
					a.name, a.num, a.postWage, a.ageWage,
					a.allowance, a.perWage, a.payWage, a.tax,a.realWage);
			}
			fclose(fp);
			printf("保存成功！按回车继续\n");
		}
		else
		{
			printf("打开文件失败！按回车继续\n");
		}
	}
	else
	{
		printf("\n职工人数为0！按回车继续\n");
	}
	cin.get();
	cin.get();
	system("cls");
}

//查询函数 输入工号，查找数组中工号一致的信息，无参数，无返回值
void find()
{
	system("cls");
	char numkey[10];
	int k = 0;

	printf("输入你要查询的工号:");
	scanf("%s", numkey);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(numkey, zggz[i].num) == 0)
		{
			printf("\n已查到，记录为：\n");
			printf("姓名：%s\n工号：%s\n岗位工资：%.2f\n",
				zggz[i].name, zggz[i].num, zggz[i].postWage);
			printf("薪级工资：%.2f\n津贴：%.2f\n实力工资：%.2f\n",
				zggz[i].ageWage,zggz[i].allowance, zggz[i].perWage);
			printf("应付工资：%.2f\n个人所得税：%.2f\n实发工资：%.2f\n",
				zggz[i].payWage,zggz[i].tax, zggz[i].realWage);
			k = 1;
			break;
		}
	}
	if (!k)
	{
		printf("对不起，查无此人。\n");
	}
	printf("\n操作完成，请按下回车继续\n");
	cin.get();
	cin.get();
	system("cls");
}

//浏览函数 查看当前所有的数据，无参数，无返回值
void list()
{
	system("cls");
	printf("%-9s%-7s%-10s%-10s%-10s%-10s%-10s%-11s%-10s\n",
		name,num,postWage,ageWage,allowance,perWage,payWage,tax,realWage);
	for (int i = 0; i < n; i++)
	{
		printf("%-9s%-7s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-11.2f%-10.2f\n",
			zggz[i].name, zggz[i].num, zggz[i].postWage, zggz[i].ageWage,
			zggz[i].allowance, zggz[i].perWage, zggz[i].payWage,
			zggz[i].tax, zggz[i].realWage);
	}
	printf("\n操作完成！回车继续！\n");
	cin.get();
	cin.get();
	system("cls");
}

//修改函数 修改数组的信息，无参数，无返回值，调用个人所得税函数
void modify()
{
	system("cls");
	char numkey[10];
	int k = 0;

	printf("输入你要修改的工号：");
	scanf("%s", numkey);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(numkey, zggz[i].num) == 0)
		{
			printf("\n已查到，记录为：\n");
			printf("%-9s%-7s%-10s%-10s%-10s%-10s%-10s%-11s%-10s\n",
				name,num,postWage,ageWage,allowance,perWage,payWage,tax,realWage);
			printf("%-9s%-7s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-11.2f%-10.2f",
				zggz[i].name, zggz[i].num, zggz[i].postWage, zggz[i].ageWage,
				zggz[i].allowance, zggz[i].perWage, zggz[i].payWage, 
				zggz[i].tax, zggz[i].realWage);
			printf("\n请输入修改后的基本信息：\n");
			scanf("%s%s%f%f%f%f", &zggz[i].name, &zggz[i].num, 
				&zggz[i].postWage, &zggz[i].ageWage,
				&zggz[i].allowance, &zggz[i].perWage);
			zggz[i].payWage = zggz[i].postWage + zggz[i].ageWage 
				+ zggz[i].allowance + zggz[i].perWage;
			zggz[i].tax = grsds(zggz[i].payWage);
			zggz[i].realWage = zggz[i].payWage - zggz[i].tax;
			k = 1;
			fclose(fp);
			break;
		}
	}
	if (!k)
	{
		printf("\n\n对不起，没有这个人。");
		fclose(fp);
	}
	printf("\n操作完成，请按下回车继续");
	cin.get();
	cin.get();
	system("cls");
}

//删除函数 删除数组的一个元素，无参数，无返回值
void del()
{
	system("cls");
	char numkey[10];
	int k = 0;

	printf("输入你要删除的工号：");
	scanf("%s", numkey);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(numkey, zggz[i].num) == 0)
		{
			int l;

			printf("\n已查到，记录为：\n");
			printf("%-9s%-7s%-10s%-10s%-10s%-10s%-10s%-11s%-10s\n",
				name,num,postWage,ageWage,allowance,perWage,payWage,tax,realWage);
			printf("%-9s%-7s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-11.2f%-10.2f",
				zggz[i].name, zggz[i].num, zggz[i].postWage, zggz[i].ageWage,
				zggz[i].allowance, zggz[i].perWage, zggz[i].payWage, 
				zggz[i].tax, zggz[i].realWage);
			printf("\n你真的要删除吗？\n");
			printf("是，请输入 1;否，请输入 2\n");
			scanf("%d", &l);
			if (l == 1)
			{
					for (int j = i; j < n - 1; j++)
					{
						zggz[j] = zggz[j + 1];
					}
					strcpy(zggz[n - 1].name, " "); 
					strcpy(zggz[n - 1].num, " "); 
					zggz[n - 1].postWage = 0;
					zggz[n - 1].ageWage = 0;
					zggz[n - 1].allowance = 0; 
					zggz[n - 1].perWage = 0;
					zggz[n - 1].payWage = 0; 
					zggz[n - 1].tax = 0; 
					zggz[n - 1].realWage = 0;
					--n;
			}
			else
			{
				printf("好的我们不会删除这条记录的！\n");
			}
			k = 1;
			fclose(fp);
			break;
		}

	}
	if (!k)
	{
		printf("\n对不起，没有找到这个人。");
		fclose(fp);
	}
	printf("操作完毕，请按下回车继续\n");
	cin.get();
	cin.get();
	system("cls");
}

//添加函数 添加一个元素到数组中，无参数，无返回值，调用个人所得税函数
void add()
{
	system("cls");
	++::n;
	printf("请按姓名、工号、岗位工资、薪级工资、津贴、实力工资输入职工的基本信息：\n");
	scanf("%s%s%f%f%f%f", &zggz[n - 1].name, &zggz[n - 1].num,
		&zggz[n - 1].postWage, &zggz[n - 1].ageWage,
		&zggz[n - 1].allowance, &zggz[n - 1].perWage);
	zggz[n - 1].payWage = zggz[n - 1].postWage + zggz[n-1].ageWage 
		+ zggz[n-1].allowance + zggz[n-1].perWage ;
	zggz[n - 1].tax = grsds(zggz[n - 1].payWage);
	zggz[n - 1].realWage = zggz[n - 1].payWage - zggz[n - 1].tax;
	printf("添加成功，这个职工的信息为：\n");
	printf("%-9s%-7s%-10s%-10s%-10s%-10s%-10s%-11s%-10s\n",
				name,num,postWage,ageWage,allowance,perWage,payWage,tax,realWage);
	printf("%-9s%-7s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-11.2f%-10.2f",
				zggz[n-1].name, zggz[n-1].num, zggz[n-1].postWage, zggz[n-1].ageWage,
				zggz[n-1].allowance, zggz[n-1].perWage, zggz[n-1].payWage, 
				zggz[n-1].tax, zggz[n-1].realWage);
	printf("\n操作完毕，请按下回车继续：\n");
	cin.get();
	cin.get();
	system("cls");
}

//个人所得税函数 计算个人的所得税，参数为浮点数，返回一个浮点数
float grsds(float wage)
{
	if (wage <= 500)
	{
		return (float)(wage * 0.05);
	}
	else if (wage<=2000)
	{
		return (float)(25 + (wage - 500) * 0.1);
	}
	else if (wage <= 5000)
	{
		return (float)(175 + (wage - 5000)*0.15);
	}
	else if (wage <= 20000)
	{
		return (float)(625 + (wage - 5000)*0.2);
	}
	else if (wage <= 40000)
	{
		return (float)(3625 + (wage - 20000)*0.25);
	}
	else if (wage <= 60000)
	{
		return (float)(8625 + (wage - 40000)*0.3);
	}
	else if (wage <= 80000)
	{
		return (float)(14625 + (wage-60000)*0.35);
	}
	else if (wage <= 100000)
	{
		return (float)(21625 + (wage-80000)*0.4);
	}
	else
	{
		return (float)(29625 + (wage-100000)*0.45);
	}
}

int main()
{
	int m;//操作变量

	read();//调用读取函数，初始化职工信息
	while (1)
	{
		system("color 70");//改变cmd窗口的背景和字体颜色
		printf("\n\n\n                  ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n");
		printf("                        欢迎使用职工信息管理系统\n\n");
		printf("                  +--------------------------------+\n");
		printf("                  |__________|  1.查询  |__________|\n");
		printf("                  |__________|  2.修改  |__________|\n");
		printf("                  |__________|  3.添加  |__________|\n");
		printf("                  |__________|  4.删除  |__________|\n");
		printf("                  |__________|  5.保存  |__________|\n");
		printf("                  |__________|  6.浏览  |__________|\n");
		printf("                  |__________|  7.退出  |__________|\n");
	    printf("                  +--------------------------------+\n\n");;
		printf("                  ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n\n");
		printf("                          请输入对应的字符[ ]\b\b");
		scanf_s("%d", &m);//给变量赋值
		if (m >= 1 && m <= 7)
		{
			switch (m)
			{
			case 1: find();
				break;
			case 2: modify();
				break;
			case 3: add();
				break;
			case 4: del();
				break;
			case 5: write();
				break;
			case 6: list();
				break;
			case 7:
				delete[]zggz; 
				return 0;
			}
		}
		else
		{
			printf("\n\n无效指令，按回车请重试");
			cin.get();
			cin.get();
		}
	}
	return 0;
}
