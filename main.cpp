#include "StdAfx.h"        //ide需要的头文件
#include <conio.h>         //C语言输入输出的头文件
#include<cstring>          //字符操作的头文件
#include"stdlib.h"         //清屏需要的头文件


//建立职工信息的结构体
struct Person
{
	char name[20];         //姓名
	char num[10];          //工号
	float postWage;        //岗位工资
	float ageWage;         //薪级工资
	float allowance;       //津贴
	float perWage;         //实务工资
	float payWage;         //应付工资
	float tax;             //个人所得税
	float realWage;        //实付工资
};

//建立临时的数组，使得职工的数据暂时保存到里面
Person zggz[100];

//声明文件指针
FILE*fp;

//职工人数，对职工进行计数，count >= 0，读取、保存、添加、删除都会改变人数
int count = 0;

//输出到屏幕时方便格式控制，被查询、删除、添加、修改函数调用
char name[] = "姓名";
char num[] = "工号";
char postWage[] = "岗位工资";
char ageWage[] = "薪级工资";
char allowance[] = "津贴";
char perWage[] = "实务工资";
char payWage[] = "应付工资";
char tax[] = "个人所得税";
char realWage[] = "实付工资";

float grsds(float);    //个人所得税函数的提前声明

bool checkUp(char str[10]);    //检查函数的提前声明

void read() //读取函数 输入文件中的数据到本文件的数组，无参数，无返回值 
{
	//第一个if开始，打开gx.dat文件
	if ((fp = fopen("gx.dat", "ab+")))
	{
		//feof()判断文件指针是否移到末尾，但是文件为空时也会执行一次
		while (!feof(fp))
		{
			char aGet = fgetc(fp);//接收文件的一个字符

								  //第一个if开始，接收字符不等于空时,开始把文件数据输入到动态数组中
			if (aGet != EOF)
			{
				fscanf(fp, "%s%s%f%f%f%f%f%f%f", &zggz[count].name, &zggz[count].num,
					&zggz[count].postWage, &zggz[count].ageWage, &zggz[count].allowance,
					&zggz[count].perWage, &zggz[count].payWage,
					&zggz[count].tax, &zggz[count].realWage);
				count++;
			}//第二个if结束

		}//while语句结束于指针移动到gx.dat文件的末尾

		fclose(fp);      //关闭文件
	}
	else
	{
		printf("\n打开文件失败！无法确定职工人数。");
	}//第一个if结束
}

//保存函数 输出修改后的数据到文件中去，无参数，无返回值
void write()
{
	system("cls");//清屏

				  //第一个if开始，判断是否有人
	if (count > 0)
	{
		//第二个if开始，打开gx.dat文件
		if ((fp = fopen("gx.dat", "wb")))
		{
			//把数组的数据输出到gx.dat文件去
			for (int i = 0; i < count; i++)
			{
				Person a = zggz[i];
				fprintf(fp, "\n%-20s%-10s%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f",
					a.name, a.num, a.postWage, a.ageWage,
					a.allowance, a.perWage, a.payWage, a.tax, a.realWage);
			}//for语句结束于i=n

			fclose(fp);     //关闭文件
			printf("保存成功！按回车继续\n");
		}
		else
		{
			printf("打开文件失败！按回车继续\n");
		}//第二个if语句结束

	}
	else
	{
		printf("\n职工人数为0！按回车继续\n");
	}//第一个if语句结束

	 //接收一个空格或回传
	scanf("%c");
	scanf("%c");
	system("cls");
}

//查询函数 输入工号，查找数组中工号一致的信息，无参数，无返回值
void find()
{
	system("cls");            //清屏
	char numkey[10];          //声明输入工号
	bool ki = 0;               //当找到对应的工号ki=1,没有找到ki=0

	printf("输入你要查询的工号:");
	scanf("%s", numkey);      //给输入工号赋值

							  //从第一个数组元素开始搜索
	for (int i = 0; i < count; i++)
	{
		//判断输入工号和数组元素的工号一致
		if (strcmp(numkey, zggz[i].num) == 0)
		{
			//找到就打印出职工信息，并跳出当前循环
			printf("\n已查到，记录为：\n");
			printf("姓名：%s\n工号：%s\n岗位工资：%.2f\n",
				zggz[i].name, zggz[i].num, zggz[i].postWage);
			printf("薪级工资：%.2f\n津贴：%.2f\n实力工资：%.2f\n",
				zggz[i].ageWage, zggz[i].allowance, zggz[i].perWage);
			printf("应付工资：%.2f\n个人所得税：%.2f\n实发工资：%.2f\n",
				zggz[i].payWage, zggz[i].tax, zggz[i].realWage);
			ki = 1;
			break;
		}//if结束

	}//for结束于i=count，搜索完毕

	 //没有找到对应的工号,此时ki=0
	if (!ki)
	{
		printf("对不起，查无此人。\n");
	}

	printf("\n操作完成，请按下回车继续\n");

	//接收一个空格或回传
	scanf("%c");
	scanf("%c");
	system("cls");
}

//浏览函数 查看当前所有的数据，无参数，无返回值
void list()
{
	system("cls");
	printf("%-9s%-7s%-10s%-10s%-10s%-10s%-10s%-11s%-10s\n",
		name, num, postWage, ageWage, allowance, perWage, payWage, tax, realWage);

	//从第一个数组元素开始打印
	for (int i = 0; i < count; i++)
	{
		printf("%-9s%-7s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-11.2f%-10.2f\n",
			zggz[i].name, zggz[i].num, zggz[i].postWage, zggz[i].ageWage,
			zggz[i].allowance, zggz[i].perWage, zggz[i].payWage,
			zggz[i].tax, zggz[i].realWage);
	}//for结束于i=count

	printf("\n操作完成！回车继续！\n");

	//接收一个空格或回传
	scanf("%c");
	scanf("%c");
	system("cls");
}

//修改函数 修改数组的信息，无参数，无返回值，调用个人所得税函数
void modify()
{
	system("cls");          //清屏
	char numkey[10];        //声明输入工号
	bool ki = 0;             //当找到对应的工号ki=1,没有找到ki=0

	printf("输入你要修改的工号：");
	scanf("%s", numkey);    //给输入工号赋值

							//从第一个数组元素开始搜索
	for (int i = 0; i < count; i++)
	{
		//判断输入工号和数组元素的工号一致
		if (strcmp(numkey, zggz[i].num) == 0)
		{
			//找到了就把原来的信息打印出来
			printf("\n已查到，记录为：\n");
			printf("%-9s%-7s%-10s%-10s%-10s%-10s%-10s%-11s%-10s\n",
				name, num, postWage, ageWage, allowance, perWage, payWage, tax, realWage);
			printf("%-9s%-7s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-11.2f%-10.2f",
				zggz[i].name, zggz[i].num, zggz[i].postWage, zggz[i].ageWage,
				zggz[i].allowance, zggz[i].perWage, zggz[i].payWage,
				zggz[i].tax, zggz[i].realWage);

			//防止职工号重复
			while (1)
			{
				//声明一个变量，把修改后的数据暂时放在这里
				Person one;

				//把原来的职工号暂时改变
				strcpy(zggz[i].num, "0000");

				//输入信息并计算
				printf("\n请输入修改后的姓名、工号、岗位工资、薪级工资、津贴、实力工资：\n");
				scanf("%s%s%f%f%f%f", &one.name, &one.num,
					&one.postWage, &one.ageWage,
					&one.allowance, &one.perWage);
				one.payWage = one.postWage + one.ageWage
					+ one.allowance + one.perWage;
				one.tax = grsds(one.payWage);
				one.realWage = one.payWage - one.tax;

				//判断是否有重复的工号，没有则跳出当前循环
				if (!checkUp(one.num))
				{
					zggz[i] = one; //修改后的数据没有问题才赋值
					break;
				}//检查完毕

			}//while结束

			ki = 1;
			break;
		}//if结束

	}//for结束于i=count，搜索完毕

	 //没有找到对应的工号,此时ki=0
	if (!ki)
	{
		printf("\n\n对不起，没有这个人。");
	}

	printf("\n操作完成，请按下回车继续");

	//接收一个空格或回传
	scanf("%c");
	scanf("%c");
	system("cls");
}

//删除函数 删除数组的一个元素，无参数，无返回值
void del()
{
	system("cls");          //清屏
	char numkey[10];        //声明输入工号
	bool ki = 0;             //当找到对应的工号ki=1,没有找到ki=0

	printf("输入你要删除的工号：");
	scanf("%s", numkey);    //给输入工号赋值

							//从第一个数组元素开始搜索
	for (int i = 0; i < count; i++)
	{
		//第一个if开始，判断输入工号和数组元素的工号一致
		if (strcmp(numkey, zggz[i].num) == 0)
		{
			int de;        //删除标识符

						   //找到了就把原来的信息打印出来
			printf("\n已查到，记录为：\n");
			printf("%-9s%-7s%-10s%-10s%-10s%-10s%-10s%-11s%-10s\n",
				name, num, postWage, ageWage, allowance, perWage, payWage, tax, realWage);
			printf("%-9s%-7s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-11.2f%-10.2f",
				zggz[i].name, zggz[i].num, zggz[i].postWage, zggz[i].ageWage,
				zggz[i].allowance, zggz[i].perWage, zggz[i].payWage,
				zggz[i].tax, zggz[i].realWage);
			printf("\n你真的要删除吗？\n");
			printf("是，请输入 1;否，请输入 2\n");

			//防止用户输入无效的指令
			while (1)
			{
				scanf("%d", &de);    //给删除标识符赋值
				printf("%d",de);
									 //判断是否给删除标识符正确赋值
				if (de == 1 || de == 2)
				{
					break;
				}
				else
				{
					printf("无效指令！请重新输入！\n");
				}//if结束

			}//while结束于de=1或者de=2

			 //第二个if开始，根据删词标识符判断是否删除
			if (de == 1)
			{
				//从找到的数组元素开始，前面的数组元素被后一个数组元素赋值
				for (int j = i; j < count - 1; j++)
				{
					zggz[j] = zggz[j + 1];
				}

				//把最后一个数组元素清空，并且人数减1
				strcpy(zggz[count - 1].name, " ");
				strcpy(zggz[count - 1].num, " ");
				zggz[count - 1].postWage = 0;
				zggz[count - 1].ageWage = 0;
				zggz[count - 1].allowance = 0;
				zggz[count - 1].perWage = 0;
				zggz[count - 1].payWage = 0;
				zggz[count - 1].tax = 0;
				zggz[count - 1].realWage = 0;
				--count;
			}
			else
			{
				printf("好的我们不会删除这条记录的！\n");
			}//第二个if结束

			ki = 1;
			fclose(fp);
			break;
		}//第一个if结束

	}//for结束于i=n，搜索完毕

	 //没有找到对应的工号,此时k=0
	if (!ki)
	{
		printf("\n对不起，没有找到这个人。");
		fclose(fp);
	}

	printf("操作完毕，请按下回车继续\n");

	//接收一个空格或回传
	scanf("%c");
	scanf("%c");
	system("cls");
}

//添加函数 添加一个元素到数组中，无参数，无返回值，调用个人所得税函数
void add()
{
	system("cls");    //清屏

					  //声明添加的人数变量
	int time;

	printf("你想添加几个职工的信息？（人数大于0或者小于100）\n");
	scanf("%d", &time);   //输入要添加的人数

						  //判断添加的人数是否合法,合法就跳出循环
	while (1)
	{
		if (time<0 || time>100)
		{
			printf("职工人数错误，请重新输入要添加的职工人数\n");
			scanf("%d", &time);
		}
		else
		{
			break;
		}
	}

	printf("请按姓名、工号、岗位工资、薪级工资、津贴、实力工资输入职工的基本信息：\n");
	printf("每输入完一个人的信息请换行！\n");

	//依次输入信息
	for (int i = 0; i<time; i++)
	{
		//防止职工号有重复
		while (1)
		{
			//声明一个变量，把输入数据暂时保存在这个变量中
			Person one;

			//把输入数据赋给临时变量
			scanf("%s%s%f%f%f%f", &one.name, &one.num,
				&one.postWage, &one.ageWage,
				&one.allowance, &one.perWage);
			one.payWage = one.postWage + one.ageWage
				+ one.allowance + one.perWage;
			one.tax = grsds(one.payWage);
			one.realWage = one.payWage - one.tax;

			//检查职工号是否有重复，没有就跳出当前循环
			if (!checkUp(one.num))
			{
				//人数加1
				++count;

				//没有问题的数据才能被赋值
				zggz[count - 1] = one;
				break;
			}//检查完毕

		}//while结束

	}//for循环结束

	printf("添加成功，添加职工的信息为：\n");
	printf("%-9s%-7s%-10s%-10s%-10s%-10s%-10s%-11s%-10s\n",
		name, num, postWage, ageWage, allowance, perWage, payWage, tax, realWage);

	//依次打印出添加后的职工信息
	for (int i = time; i>0; i--)
	{
		printf("%-9s%-7s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-11.2f%-10.2f\n",
			zggz[count - i].name, zggz[count - i].num,
			zggz[count - i].postWage, zggz[count - i].ageWage,
			zggz[count - i].allowance, zggz[count - i].perWage,
			zggz[count - i].payWage, zggz[count - i].tax,
			zggz[count - i].realWage);
	}//for循环结束于i=0

	printf("\n操作完毕，请按下回车继续：\n");

	//接收一个空格或回传
	scanf("%c");
	scanf("%c");
	system("cls");
}

//个人所得税函数 计算个人的所得税，参数为浮点数，返回一个浮点数
float grsds(float wage)
{
	//根据个人所得税的计算公式
	if (wage <= 500)
	{
		return (float)(wage * 0.05);
	}
	else if (wage <= 2000)
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
		return (float)(14625 + (wage - 60000)*0.35);
	}
	else if (wage <= 100000)
	{
		return (float)(21625 + (wage - 80000)*0.4);
	}
	else
	{
		return (float)(29625 + (wage - 100000)*0.45);
	}//多条if结束

}

//检查函数，检查工号是否有函数，参数为字符串，返回一个布尔值,真为职工号有重复，反之没有
bool checkUp(char str[10])
{
	bool ki = 0;  //判断标识符，ki=0为没有重复，ki=1有重复

				  //检查每个数组元素
	for (int i = 0; i<count; i++)
	{
		//判断是否有重复的工号
		if (strcmp(str, zggz[i].num) == 0)
		{
			printf("工号已存在，请重新输入！\n");
			ki = 1;
		}//if结束

	}//for结束于i=count,检查完毕

	return ki;
}

int main()
{
	int handle;//操作标识符

	read();//调用读取函数，初始化职工信息

	while (1)
	{
		printf("\n\n\n        ### 欢迎使用广西民族大学软件与信息安全学院职工工资管理系统 ###\n\n");
		printf("        请选择数字<1-7>                                   \n");
		printf("        ==============================================================\n");
		printf("        :                     1、 查询职工工资记录                   :\n");
		printf("        :                     2、 修改职工工资记录                   :\n");
		printf("        :                     3、 添加职工工资记录                   :\n");
		printf("        :                     4、 删除职工工资记录                   :\n");
		printf("        :                     5、 保存职工工资记录                   :\n");
		printf("        :                     6、 浏览职工工资记录                   :\n");
		printf("        :                     7、 退出系统                           :\n");
		printf("        ==============================================================\n");
		printf("                        \n");
		printf("                        \n");
		printf("		              请输入一个数字[ ]\b\b");
		scanf_s("%d", &handle);//给操作标识符赋值

							   //判断标识符是否正确
		if (handle >= 1 && handle <= 7)
		{
			//根据操作标识符的不同使用不同的函数
			switch (handle)
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
				return 0;
			}//switch结束

		}
		else
		{
			printf("\n\n无效指令，按回车请重试");
			scanf("%c");
			scanf("%c");
		}//if结束
	}
	return 0;
}


