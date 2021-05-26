/* 学生成绩管理系统v5.0

  某班有最多不超过30人（具体人数由键盘输入）参加期末考试，最多不超过6门（具体门数由键盘输入）

 （1）录入每个学生的学号、姓名和各科考试成绩；
 （2）计算每门课程的总分和平均分；
 （3）计算每个学生的总分和平均分；
 （4）按照每个学生的总分由高到低排出名次表；
 （5）按照每个学生的总分由低到高排出名次表；
 （6）按照学号由小到大排出成绩表；
 （7）按照姓名的字典顺序排出成绩表；
 （8）按照学号查询学生排名及其各科考试成绩；
 （9）按照姓名查询学生排名及其各科考试成绩；		 （10）按照优秀（90-100分）、良好（80-89分）、中等（70-79分）、及格（60-69分）、不及格（0-59分）5个类别，统计每个类别的人数以及所占的百分比。
 （11）输出每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分。	//比v3.0增加了“多门课程”

  实验要求：定义结构体类型，用结构体数组作函数参数。
			菜单驱动，即：程序运行后，先显示菜单，按照用户输入的选项执行相应的操作。

  实验目的：在“学生成绩管理系统V4.0”的基础上，通过增加任务要求，熟悉结构体类型、结构体数组做函数参数、模块化程序设计方法，体会应用结构体代替普通的数组类型实现数据库管理的优越性。
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN  10		//字符串的最大长度
#define STU_NUM 30		//最多的学生人数
#define COURSE_NUM 6	//最多的考试科目数

typedef struct student
{
	long num;					//每个学生的学号
	char name[MAX_LEN];			//每个学生的姓名
	float score[COURSE_NUM];	//每个COURSE_NUM门功课的成绩
	float sum;					//每个学生的总成绩
	float aver;					//每个学生的平均成绩
}STU;

int  Menu(void);
void ReadScore(STU stu[], int n, int m);
void AverSumofEveryCourse(STU stu[], int n, int m);
void AverSumofEveryStudent(STU stu[], int n, int m);
void AverSumofEveryStudent_no_out(STU stu[], int n, int m);
void SortbyScore(STU stu[], int n, int m, int(*compare)(float a, float b));
int  Ascending(float a, float b);
int  Descending(float a, float b);
void SwapFloat(float* x, float* y);
void SwapLong(long* x, long* y);
void SwapChar(char x[], char y[]);
void AsSortbyNum(STU stu[], int n, int m);
void SortbyName(STU stu[], int n, int m);
void SearchbyNum(STU stu[], int n, int m);
void SearchbyName(STU stu[], int n, int m);
void StatisticAnalysis(STU stu[], int n, int m);
void PrintScore(STU stu[], int n, int m);

int main()
{
	int I;
	int n = 0, m = 0;	//m门课程，n个学生
	STU stu[STU_NUM];

	//输入学生的个数
	printf("input student number(n<%d):\n", STU_NUM);
	scanf("%d", &n);

	//输入课程的门数
	printf("input course number(n<=%d):\n", COURSE_NUM);
	scanf("%d", &m);

	while (1)
	{
		 I= Menu();	//显示菜单，并读取用户输入
		switch (I)
		{
		case 1:	ReadScore(stu, n, m);
			break;
		case 2:	AverSumofEveryCourse(stu, n, m);
			break;
		case 3: AverSumofEveryStudent(stu, n, m);
			break;
		case 4: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion
			SortbyScore(stu, n, m, Descending);
			printf("\nSort in descending order by score:\n");
			PrintScore(stu, n, m);
			break;
		case 5: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion
			SortbyScore(stu, n, m, Ascending);
			printf("\nSort in ascending order by score:\n");
			PrintScore(stu, n, m);
			break;
		case 6: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion
			AsSortbyNum(stu, n, m);
			printf("\nsort in ascending order by number:\n");
			PrintScore(stu, n, m);
			break;
		case 7: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion
			SortbyName(stu, n, m);
			printf("\nsort in dictionary order by name:\n");
			PrintScore(stu, n, m);
			break;
		case 8: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion
			SortbyScore(stu, n, m, Descending);			//sort in descending order by score
			printf("\nSort in descending order by score:\n");
			PrintScore(stu, n, m);
			SearchbyNum(stu, n, m);
			break;
		case 9: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion
			SortbyScore(stu, n, m, Descending);			//sort in descending order by score
			printf("\nSort in descending order by score:\n");
			PrintScore(stu, n, m);
			SearchbyName(stu, n, m);
			break;
		case 10: StatisticAnalysis(stu, n, m);
			break;
		case 11: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion 
			PrintScore(stu, n, m);
			break;
		case 0: printf("End of program!\n");
			exit(0);
		default: printf("Input error!\n");
		}
	}
	return 0;
}

/* 显示菜单，并获得用户键盘输入的数据 */
int   Menu(void)
{
	int i;
	system("title 学生成绩管理系统V5.0  By zwx");
	printf("\n\n");
	printf("\t\t\t                         学生成绩管理系统V5.0\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\t\t\t*                Management for Students' scores                             *\n");
	printf("\t\t\t*                1.  Input record                                            *\n");
	printf("\t\t\t*                2.  Caculate total and average score of every course        *\n");
	printf("\t\t\t*                3.  Caculate total and average score of every student       *\n");
	printf("\t\t\t*                4.  Sort in descending order by score                       *\n");
	printf("\t\t\t*                5.  Sort in ascending order by score                        *\n");
	printf("\t\t\t*                6.  Sort in ascending order by number                       *\n");
	printf("\t\t\t*                7.  Sort in dictionary order by name                        *\n");
	printf("\t\t\t*                8.  Search by number                                        *\n");
	printf("\t\t\t*                9.  Search by name                                          *\n");
	printf("\t\t\t*                10. Statistic analysis                                      *\n");
	printf("\t\t\t*                11. List record                                             *\n");
	printf("\t\t\t*                12. Write to a file                                         *\n");
	printf("\t\t\t*                13. Read from a file                                        *\n");
	printf("\t\t\t*                0.  Exit                                                    *\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t*****************Please Input your choice:");
	scanf("%d", &i);
	return i;

}

/* 输入n个学生的m门课的成绩 */
void ReadScore(STU stu[], int n, int m)
{
	int i, j, k=1;
	for (i = 0; i < n; i++)
	{
		printf("please input the student`s number:\t");
		scanf("%ld", &stu[i].num);
		printf("\n");
		printf("please input the student`s name:\t");
		scanf("%s", & stu[i].name);
		printf("\n");

		for (j = 0; j < m; j++)
		{
			printf("please input the student`s score(第 %d 门)：\t", k);
			k++;
			scanf("%d", &stu[i].score[j]);
			printf("\n");


		}
	}
}

/* 计算每门课程的总分和平均分 */
void AverSumofEveryCourse(STU stu[], int n, int m)  // m门课程，n个学生
{
	int i, j, k,x;
	float sum[COURSE_NUM];
	float aver[COURSE_NUM];
	for (i = 0; i < m; i++)
	{
		sum[i] = 0;

		for (j = 0; j < m; j++)
		{
			sum[i] += stu[i].score[j];

		}
	}
	for (k=0; k < m; k++)
	{
		aver[k] = sum[k] / m;

	}
	//输出
	for (x = 0; x < m; x++)
	{
		printf("第 %d 门课的总分：%f\t平均分：%f\t", x + 1, sum[x], aver[x]);
		printf("\n");

	}
	
}

/* 计算每个学生各门课程的总分和平均分——有输出 */
void AverSumofEveryStudent(STU stu[], int n, int m)	// m门课程，n个学生
{
	int i, j, k;
	

	for (i = 0; i < n; i++);
	{
		stu[i].sum = 0;

		for (j = 0; j < m; j++)
		{
			stu[i].sum += stu[i].score[j];

		}
		stu[i].aver = stu[i].sum / m;

	}
	//输出：
	for (k = 0; k < n; k++)
	{
		printf("各学生成绩如下：\n");
		printf("学号：%ld\t姓名：%s\t总分：%0.2f\t平均分:%0.2f\t", stu[k].num, stu[k].name, stu[k].sum, stu[k].aver);
	}	printf("\n");

}

/* 计算每个学生各门课程的总分和平均分——无输出 */
void AverSumofEveryStudent_no_out(STU stu[], int n, int m)	// m门课程，n个学生
{
	int i, j, k;


	for (i = 0; i < n; i++);
	{
		stu[i].sum = 0;

		for (j = 0; j < m; j++)
		{
			stu[i].sum += stu[i].score[j];

		}
		stu[i].aver = stu[i].sum / m;

	}
	
	/*for (k = 0; k < n; k++)
	{
		printf("各学生成绩如下：\n");
		printf("学号：%ld\t姓名：%s\t总分：%0.2f\t平均分:%0.2f\t", stu[k].num, stu[k].name, stu[k].sum, stu[k].aver);
	}	printf("\n");*/

}

/* 用选择法，将数组sum的元素值排序 */
void SortbyScore(STU stu[], int n, int m, int(*compare)(float a, float b))
{
	int i, j, k, t;

	char(*p)[MAX_LEN];
	p = stu->name;

	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if ((*compare)(stu[j].sum, stu[k].sum))  k = j;
		}
		if (k != j)
		{
			for (t = 0; t < m; t++)
			{
				SwapFloat(&stu[k].score[t], &stu[i].score[t]);
			}
			SwapFloat(&stu[k].sum, &stu[i].sum);
			SwapFloat(&stu[k].aver, &stu[i].aver);
			SwapLong(&stu[k].num, &stu[i].num);
			SwapChar(p + k, p + i);


		}
	}
}

/* 使得数据按照升序排序 */
int Ascending(float a, float b)
{
	return a < b;
}


/* 使得数据按照降序排序 */
int Descending(float a, float b)
{
	return a > b;
}


/* 交换两个单精度浮点型数据 */
void SwapFloat(float* x, float* y)
{
	float temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/* 交换两个长整型数据 */
void SwapLong(long* x, long* y)
{
	long temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/* 交换两个字符串 */
void SwapChar(char x[], char y[])
{
	char temp[MAX_LEN];

	strcpy(temp, x);
	strcpy(x, y);
	strcpy(y, temp);
}

/* 按照选择法，将数组num的元素值按照从小到大排序 */
void AsSortbyNum(STU stu[], int n, int m)
{
	int i, j, k, t;

	char(*p)[MAX_LEN];
	p = stu->name;

	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (stu[j].num<stu[k].num)  k = j;
		}
		if (k != j)
		{
			for (t = 0; t < m; t++)
			{
				SwapFloat(&stu[k].score[t], &stu[i].score[t]);
			}
			SwapFloat(&stu[k].sum, &stu[i].sum);
			SwapFloat(&stu[k].aver, &stu[i].aver);
			SwapLong(&stu[k].num, &stu[i].num);
			SwapChar(p + k, p + i);


		}
	}
}


/* 使用交换法，实现字符串按字典顺序排序 */
void SortbyName(STU stu[], int n, int m)
{
	int i, j, t;
	char(*p)[MAX_LEN];
	p = stu->name;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(stu[j].name, stu[i].name) < 0)
			{
				for (t = 0; t < m; t++)
				{
					SwapFloat(&stu[i].score[t], &stu[j].score[t]);
				}
				SwapFloat(&stu[i].sum, &stu[j].sum);
				SwapFloat(&stu[i].aver, &stu[j].aver);
				SwapLong(&stu[i].num, &stu[j].num);
				SwapChar(p + i, p + j);
			}
		}
	}
}

/* 按照学号，查找学生成绩并显示查找结果 */
void SearchbyNum(STU stu[], int n, int m)
{

}

/* 按照姓名，查询学生排名并显示查找结果 */
void SearchbyName(STU stu[], int n, int m)
{

}

/* 统计各个分数段的学生人数及其所占的百分比 */
void StatisticAnalysis(STU stu[], int n, int m)	//m门课程，n个学生
{

}

/* 打印学生成绩 */
void PrintScore(STU stu[], int n, int m)
{

}

