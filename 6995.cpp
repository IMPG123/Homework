// 6995.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "StdAfx.h"
#include <stdlib.h>
#include <stdio.h>
#include <wtypes.h>
#include <winbase.h>
#include <time.h>
#include <conio.h>
#include <iostream>
using namespace std;

int n=0;

struct Person
{
	char name[20];
	char num[10];
	float postWage;
	float ageWage;
	float allowance;
	float perWage;
	float payWage;
	float tax;
	float realWage;
};

Person zggz[30];

FILE*fp;

void read();
void write();
void find();
void list();
void modify();
void del();
void add();
float grsds(float);

int main()
{
	/*if ((fp = fopen("gx.dat", "a")))
		{
			for (int i = 0; i < ::n; i++)
			{
				Person a={"����","0001",1000,1000,1000,1000,0,0,0};
				fprintf(fp, "\n%-20s%-10s%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f",
					a.name, a.num, a.postWage, a.ageWage,
					a.allowance, a.perWage, a.payWage, a.tax,a.realWage);
				cout<<zggz[i].name;
			}
			fclose(fp);
			printf("����ɹ������س�����\n");
		}*/
	read();
	int m;
	while (1)
	{
		//system("color 0a");
		printf("\n\n\n                  ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n");
		printf("                        ��ӭʹ��ְ����Ϣ����ϵͳ\n\n");
		printf("                  +--------------------------------+\n");
		printf("                  |__________|  1.��ѯ  |__________|\n");
		printf("                  |__________|  2.�޸�  |__________|\n");
		printf("                  |__________|  3.���  |__________|\n");
		printf("                  |__________|  4.ɾ��  |__________|\n");
		printf("                  |__________|  5.����  |__________|\n");
		printf("                  |__________|  6.���  |__________|\n");
		printf("                  |__________|  7.�˳�  |__________|\n");
	    printf("                  +--------------------------------+\n\n");;
		printf("                  ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n\n");
		printf("                          �������Ӧ���ַ�[ ]\b\b");
		scanf_s("%d", &m);
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
				{
					//delete[]zggz; 
					return 0;
				}
			}
		}
		else
		{
			printf("\n\n��Чָ����س�������");
			cin.get();
			cin.get();
		}
	}
	return 0;
}
//��ȡ
void read()
{
	if ((fp = fopen("gx.dat", "r")))
	{
		while (!feof(fp))
		{
			fscanf(fp, "%s%s%f%f%f%f%f%f%f", &zggz[n].name, &zggz[n].num, &zggz[n].postWage, &zggz[n].ageWage, &zggz[n].allowance, &zggz[n].perWage, &zggz[n].payWage, &zggz[n].tax, &zggz[n].realWage);
			n++;
		}
		fclose(fp);
	}
	else
	{
		printf("\n���ļ�ʧ�ܣ��޷�ȷ��ְ��������");
	}
	cout<<n;
}


//����
void write()
{
	system("cls");
	if (::n > 0)
	{
		if ((fp = fopen("gx.dat", "w")))
		{
			for (int i = 0; i < ::n; i++)
			{
				Person a=zggz[i];
				fprintf(fp, "\n%-20s%-10s%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f",
					a.name, a.num, a.postWage, a.ageWage,
					a.allowance, a.perWage, a.payWage, a.tax,a.realWage);
				cout<<zggz[i].name;
			}
			fclose(fp);
			printf("����ɹ������س�����\n");
		}
		else
		{
			printf("���ļ�ʧ�ܣ����س�����\n");
		}
	}
	else
	{
		printf("\nְ������Ϊ0�����س�����\n");
	}
	cin.get();
	cin.get();
	system("cls");
}

//����
void find()
{
	system("cls");
	char numkey[10];
	printf("������Ҫ��ѯ�Ĺ���:");
	scanf("%s", numkey);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(numkey, zggz[i].num) == 0)
		{
			printf("\n�Ѳ鵽����¼Ϊ��\n");
			printf("������%-20s���ţ�%-10s��λ���ʣ�%-10.2fн�����ʣ�%-10.2f������%-10.2fʵ�����ʣ�%-10.2fӦ�����ʣ�%-10.2f��������˰��%-10.2fʵ�����ʣ�%-10.2f\n", 
				zggz[i].name, zggz[i].num, zggz[i].postWage, zggz[i].ageWage,
				zggz[i].allowance, zggz[i].perWage, zggz[i].payWage, zggz[i].tax, zggz[i].realWage);
			k = 1;
			fclose(fp);
			break;
		}
	}
	if (!k)
	{
		printf("�Բ��𣬲��޴��ˡ�\n");
		fclose(fp);
	}
	printf("\n������ɣ��밴�»س�����\n");
	cin.get();
	cin.get();
	system("cls");

}

//���
void list()
{
	system("cls");
	cout<<n;
	printf("������ְ���ţ���λ���ʣ�н�����ʣ�������ʵ���ʣ�Ӧ�����ʣ���������˰��ʵ������\n");
	for (int i = 0; i < n; i++)
	{
		printf("%-20s%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n",
			zggz[i].name, zggz[i].num, zggz[i].postWage, zggz[i].ageWage,
			zggz[i].allowance, zggz[i].perWage, zggz[i].payWage, zggz[i].tax, zggz[i].realWage);
	}
	printf("������ɣ��س�������\n");
	cin.get();
	cin.get();
	system("cls");
}

//�޸�
void modify()
{
	system("cls");
	char numkey[10];
	printf("������Ҫ�޸ĵĹ��ţ�");
	scanf("%s", numkey);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(numkey, zggz[i].num) == 0)
		{
			printf("\n�Ѳ鵽����¼Ϊ��\n");
			printf("%-20s%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n",
				zggz[i].name, zggz[i].num, zggz[i].postWage, zggz[i].ageWage,
				zggz[i].allowance, zggz[i].perWage, zggz[i].payWage, zggz[i].tax, zggz[i].realWage);
			printf("\n�������޸ĺ�Ļ�����Ϣ��\n");
			scanf("%s%s%f%f%f%f", &zggz[i].name, &zggz[i].num, &zggz[i].postWage, &zggz[i].ageWage, 
				&zggz[i].allowance, &zggz[i].perWage);
			zggz[i].payWage = zggz[i].postWage + zggz[i].ageWage + zggz[i].allowance + zggz[i].perWage;
			zggz[i].tax = grsds(zggz[i].payWage);
			zggz[i].realWage = zggz[i].payWage - zggz[i].tax;
			k = 1;
			fclose(fp);
			break;
		}
	}
	if (!k)
	{
		printf("\n\n�Բ���û������ˡ�");
		fclose(fp);
	}
	printf("\n\n������ɣ��밴�»س�����");
	cin.get();
	cin.get();
	system("cls");
}

//ɾ��
void del()
{
	system("cls");
	char numkey[10];
	printf("������Ҫɾ���Ĺ��ţ�");
	scanf("%s", numkey);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(numkey, zggz[i].num) == 0)
		{
			int l;
			printf("\n�Ѳ鵽����¼Ϊ��\n");
			printf("%-20s%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n",
				zggz[i].name, zggz[i].num, zggz[i].postWage, zggz[i].ageWage,
				zggz[i].allowance, zggz[i].perWage, zggz[i].payWage, zggz[i].tax, zggz[i].realWage);
			printf("\n�����Ҫɾ����\n");
			printf("�ǣ������� 1 \n");
			printf("�������� 2 \n");
			scanf("%d", &l);
			if (l == 1)
			{
					for (int j = i; j < n - 1; j++)
					{
						zggz[j] = zggz[j + 1];
					}
					strcpy(zggz[n - 1].name, " "); strcpy(zggz[n - 1].num, " "); zggz[n - 1].postWage = 0; zggz[n - 1].ageWage = 0;
					zggz[n - 1].allowance = 0; zggz[n - 1].perWage = 0; zggz[n - 1].payWage = 0; zggz[n - 1].tax = 0; zggz[n - 1].realWage = 0;
					--n;
			}
			else
			{
				printf("�õ����ǲ���ɾ��������¼�ģ�\n");
			}
			k = 1;
			fclose(fp);
			break;
		}

	}
	if (!k)
	{
		printf("\n�Բ���û���ҵ�����ˡ�");
		fclose(fp);
	}
	printf("�밴�»س�����\n");
	cin.get();
	cin.get();
	system("cls");
}

//���
void add()
{
	system("cls");
	++::n;
	//cout<<::n;
	printf("�밴���������š���λ���ʡ�н�����ʡ�������ʵ����������ְ���Ļ�����Ϣ��\n");
	scanf("%s%s%f%f%f%f", &zggz[n - 1].name, &zggz[n - 1].num, &zggz[n - 1].postWage, &zggz[n - 1].ageWage, &zggz[n - 1].allowance, &zggz[n - 1].perWage);
	zggz[n - 1].payWage = zggz[n - 1].postWage + zggz[n-1].ageWage + zggz[n-1].allowance + zggz[n-1].perWage ;
	zggz[n - 1].tax = grsds(zggz[n - 1].payWage);
	zggz[n - 1].realWage = zggz[n - 1].payWage - zggz[n - 1].tax;
	printf("��ӳɹ������ְ������ϢΪ��\n���������š���λ���ʡ�н�����ʡ�������ʵ�����ʡ�Ӧ�����ʡ���������˰��ʵ������");
	printf("\n%-20s%-10s%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f",
		zggz[n - 1].name, zggz[n - 1].num, zggz[n - 1].postWage, zggz[n - 1].ageWage,
		zggz[n - 1].allowance, zggz[n - 1].perWage, zggz[n - 1].payWage, zggz[n - 1].tax, zggz[n - 1].realWage);
	printf("\n������ϣ��밴�»س�������\n");
	cin.get();
	cin.get();
	system("cls");
}


//�����������˰
float grsds(float wage)
{
	if (wage <= 500)
	{
		return (float)(wage * 0.05);
	}
	else if (wage<=2000)
	{
		return (float)(500 * 0.05 + (wage - 500) * 0.1);
	}
	else if (wage <= 5000)
	{
		return (float)(500 * 0.05 + (2000 - 500) * 0.1 + (wage - 5000)*0.15);
	}
	else if (wage <= 20000)
	{
		return (float)(500 * 0.05 + (2000 - 500) * 0.1 + (5000 - 2000)*0.15 + (wage - 5000)*0.2);
	}
	else if (wage <= 40000)
	{
		return (float)(500 * 0.05 + (2000 - 500) * 0.1 + (5000 - 2000)*0.15 + (20000 - 5000)*0.2 + (wage - 20000)*0.25);
	}
	else if (wage <= 60000)
	{
		return (float)(500 * 0.05 + (2000 - 500) * 0.1 + (5000 - 2000)*0.15 + (20000 - 5000)*0.2 + (40000 - 20000)*0.25 + (wage - 40000)*0.3);
	}
	else if (wage <= 80000)
	{
		return (float)(500 * 0.05 + (2000 - 500) * 0.1 + (5000 - 2000)*0.15 + (20000 - 5000)*0.2 + (40000 - 20000)*0.25 + (60000 - 40000)*0.3+(wage-60000)*0.35);
	}
	else if (wage <= 100000)
	{
		return (float)(500 * 0.05 + (2000 - 500) * 0.1 + (5000 - 2000)*0.15 + (20000 - 5000)*0.2 + (40000 - 20000)*0.25 + (60000 - 40000)*0.3 + (80000 - 60000)*0.35+(wage-80000)*0.4);
	}
	else
	{
		return (float)(500 * 0.05 + (2000 - 500) * 0.1 + (5000 - 2000)*0.15 + (20000 - 5000)*0.2 + (40000 - 20000)*0.25 + (60000 - 40000)*0.3 + (80000 - 60000)*0.35 + (100000 - 80000)*0.4+(wage-100000)*0.45);
	}
}

 

