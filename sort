// Sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

const int MaxSize = 30;
FILE *fp;

struct Node
{
	char num[5];     //药品编号（基数排序）
	char name[10];   //药品名称
	float price;     //药品单价（冒泡排序）
	int count;       //销售数量（快速排序） 
	float sale;      //本药品销售额（堆排序） 
};

struct SequenList
{
	Node node[MaxSize+1];   //node[0]=null
	int length;
}seqList;

void ReadDrugInfo(SequenList &seqList)
{
	seqList.length = 0;
	if (fp = fopen("DrugInfo.txt", "r+"))
	{
		while (!feof(fp))
		{
			char c = fgetc(fp);
			if (c != EOF)
			{
				seqList.length++;
				fscanf(fp, "%s %s %f %d %f", &seqList.node[seqList.length].num, &seqList.node[seqList.length].name,
					&seqList.node[seqList.length].price, &seqList.node[seqList.length].count, &seqList.node[seqList.length].sale);	
			}
		}
		fclose(fp);
	}
	else
	{
		cout << "打开药品信息表失败！";
	}
}

void Swap(Node node[], int i, int j)
{
	Node temp = node[i];
	node[i] = node[j];
	node[j] = temp;
}

void PrintSequenList(SequenList seqList)
{
	for (int i = 1; i <= seqList.length; i++)
	{
		cout << seqList.node[i].num << " "
			<< seqList.node[i].name << " "
			<< seqList.node[i].price << " "
			<< seqList.node[i].count << " "
			<< seqList.node[i].sale << endl;

	}
}

void RadixSortByNum(Node node[], int n)
{
	int i, j;
	int buckets[256];           //桶
	Node temp[MaxSize+1];       //缓存
	int maxbit = 4;             //最大位数
	for (i = maxbit - 1; i >= 0; i--)   //从右到左
	{
		//桶的初始化
		for ( j = 0;  j < 256;  j++)
		{
			buckets[j] = 0;
		}
		//放入桶
		for (j = 1; j <= n; j++)
		{
			buckets[(node[j].num[i])]++;
		}
		//为了放入缓存的索引正确
		for (j = 1; j < 256; j++)
		{
			buckets[j] += buckets[j - 1];
		}
		for (j = n; j >= 1; j--)
		{
			int pos = buckets[node[j].num[i]];
			temp[pos] = node[j];
			buckets[node[j].num[i]]--;
		}
	}
	for (i = 1; i <= n; i++)
	{
		node[i] = temp[i];
	}
}
void RadixSortByNum(SequenList &seqList)
{

	RadixSortByNum(seqList.node, seqList.length);
}

void BubbleSortByPrice(SequenList &seqList)
{
	for (int i = 1; i < seqList.length; ++i)
	{
		for (int j = 1; j < seqList.length - i+1; ++j)
		{
			if (seqList.node[j].price > seqList.node[j+1].price)
			{
				Swap(seqList.node, j, j + 1);
			}
		}
	}
}

int Partition(Node node[], int lo, int hi)
{
	int i = lo, j = hi + 1;
	int partition = node[lo].count;
	while (true)
	{
		while (node[++i].count < partition) { if (i == hi)break; }
		while (partition < node[--j].count) { if (j == lo) break; }
		if (i >= j) break;
		Swap(node, i, j);
	}
	Swap(node, lo, j);
	return j;
}
void QuickSortByCount(Node node[], int lo, int hi)
{
	if (lo >= hi) return;
	int j = Partition(node, lo, hi);
	QuickSortByCount(node, lo, j - 1);
	QuickSortByCount(node, j + 1, hi);
}
void QuickSortByCount(SequenList &seqList)
{
	int lo = 1, hi = seqList.length;
	QuickSortByCount(seqList.node, lo, hi);
}

void Sink(Node node[], int k, int N)
{
	while (2 * k <= N)
	{
		int j = 2 * k;
		if (j < N&&node[j].sale < node[j + 1].sale) j++;
		if (node[k].sale > node[j].sale) break;
		Swap(node, k, j);
		k = j;
	}
}
void HeapSortBySale(SequenList &seqList)
{
	int N = seqList.length;
	for (int k = N/2; k >= 1 ; k--)
	{
		Sink(seqList.node, k, N);
	}
	while (N > 1)
	{
		Swap(seqList.node, 1, N--);
		Sink(seqList.node, 1, N);
	}
}

void ShowSort(SequenList seqList,void (*sort)(SequenList&))
{
	system("cls");
	sort(seqList);
	PrintSequenList(seqList);
	cin.get();
	cin.get();
	system("cls");
}

int main()
{
	ReadDrugInfo(seqList);
	//PrintSequenList(seqList);
	while (true)
	{
		cout << "1:按药品编号进行排序（基数排序法）" << endl;
		cout << "2:按药品单价进行排序（冒泡排序法）" << endl;
		cout << "3:按销售数量进行排序（快速排序法）" << endl;
		cout << "4:按销售额进行排序（堆排序法）" << endl;
		cout << "5:退出" << endl;
		cout << "请输入操作数：";
		int header;
		cin >> header;
		switch (header)
		{
		case 1:
			ShowSort(seqList, RadixSortByNum);
			break;
		case 2:
			ShowSort(seqList, BubbleSortByPrice);
			break;
		case 3:
			ShowSort(seqList, QuickSortByCount);
			break;
		case 4:
			ShowSort(seqList, HeapSortBySale);
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
}
