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
	
	while (1)
	{
		scanf("%d", &I);
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
			printf("\n\t\t\tSort in descending order by score:\n");
			PrintScore(stu, n, m);
			break;
		case 5: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion
			SortbyScore(stu, n, m, Ascending);
			printf("\n\t\t\tSort in ascending order by score:\n");
			PrintScore(stu, n, m);
			break;
		case 6: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion
			AsSortbyNum(stu, n, m);
			printf("\n\t\t\tsort in ascending order by number:\n");
			PrintScore(stu, n, m);
			break;
		case 7: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion
			SortbyName(stu, n, m);
			printf("\n\t\t\tsort in dictionary order by name:\n");
			PrintScore(stu, n, m);
			break;
		case 8: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion
			SortbyScore(stu, n, m, Descending);			//sort in descending order by score
			printf("\n\t\t\tSort in descending order by score:\n");
			PrintScore(stu, n, m);
			SearchbyNum(stu, n, m);
			break;
		case 9: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion
			SortbyScore(stu, n, m, Descending);			//sort in descending order by score
			printf("\n\t\t\tSort in descending order by score:\n");
			PrintScore(stu, n, m);
			SearchbyName(stu, n, m);
			break;
		case 10: StatisticAnalysis(stu, n, m);
			break;
		case 11: AverSumofEveryStudent_no_out(stu, n, m);	//must run this function first, then run next funcion 
			PrintScore(stu, n, m);
			break;
		case 0: printf("\t\t\tEnd of program!\n");
			exit(0);
		default: printf("\t\t\tInput error!\n");
		}
	}
	return 0;
}


/* 输入n个学生的m门课的成绩 */
void ReadScore(STU stu[], int n, int m)
{
	printf("\n\t\t\t===============================================\n");
	printf("\t\t\t请输入学生学号、姓名及各科信息(输入0停止信息输入)\n");
	for (int i = 0; i < n; i++) 
	{
		printf("\t\t\t学号:");

		scanf("%ld", &stu[i].num);

		if (stu[i].num == 0) break;

		getchar();//吸收多余换行符

		printf("\t\t\t姓名：");

		gets(stu[i].name);

		printf("\t\t\t请输入各科成绩(没门成绩空格隔开)");
		stu[i].sum = 0;
		for (int j = 0; j < m; j++)
		{
			scanf("%f", &stu[i].score[j]);
			stu[i].sum += stu[i].score[j];
		}
	}
}

/* 计算每门课程的总分和平均分 */
void AverSumofEveryCourse(STU stu[], int n, int m)  // m门课程，n个学生
{
	float sum[COURSE_NUM] = { 0 };
	float average[COURSE_NUM] = { 0 };
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum[i] += stu[j].score[i];
		}
		average[i] = sum[i] / n;
		printf("\t\t\t第%d门课程的总分为：%.2f，平均分为%.2f\n", i + 1, sum[i], average[i]);
	}
	getch();
	
	
}

/* 计算每个学生各门课程的总分和平均分——有输出 */
void AverSumofEveryStudent(STU stu[], int n, int m)	// m门课程，n个学生
{
	int k;
	float sum[COURSE_NUM] = { 0 };
	float average[COURSE_NUM] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum[i] += stu[i].score[j];
		}
		average[i] = sum[i] / m;
		
	}
	getch();
	//输出：
	for (k = 0; k < n; k++)
	{
		printf("\t\t\t各学生成绩如下：\n");
		printf("\t\t\t学号：%ld\t姓名：%s\t总分：%0.2f\t平均分:%0.2f\t", stu[k].num, stu[k].name, stu[k].sum, stu[k].aver);
	}	printf("\n");

}

/* 计算每个学生各门课程的总分和平均分——无输出 */
void AverSumofEveryStudent_no_out(STU stu[], int n, int m)	// m门课程，n个学生
{
	int k;
	float sum[COURSE_NUM] = { 0 };
	float average[COURSE_NUM] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum[i] += stu[i].score[j];
		}
		average[i] = sum[i] / m;

	}
	getch();
	//输出：
	/*for (k = 0; k < n; k++)
	{
		printf("\t\t\t各学生成绩如下：\n");
		printf("\t\t\t学号：%ld\t姓名：%s\t总分：%0.2f\t平均分:%0.2f\t", stu[k].num, stu[k].name, stu[k].sum, stu[k].aver);
	}	printf("\n");*/


}

/* 用选择法，将数组sum的元素值排序 */
void SortbyScore(STU stu[], int n, int m, int(*compare)(float a, float b))
{
	STU temp1 = { 0 };
	for (int i = 0; i < n - 1; i++) {
		if (stu[i].sum < stu[i + 1].sum) {
			temp1 = stu[i];
			stu[i] = stu[i + 1];
			stu[i + 1] = temp1;
		}
	}
	printf("\n\t\t\t============按总成绩从高到低排序===========\n");
	for (int j = 0; j < n; j++) {
		printf("\t\t\t该学生的学号为:%d\n", stu[j].num);
		printf("\t\t\t该学生的姓名为:");
		for (int k = 0; k < MAX_LEN; k++) {
			printf("\t\t\t%c", stu[j].name[k]);
		}
		printf("\n\t\t\t该学生的各科成绩为\n");
		for (int c = 0; c < m; c++) {
			printf("\t\t\t第%d门成绩为%.2f\n", c + 1, stu[j].score[c]);
		}
		printf("\t\t\t该学生的总成绩为:%.2f", stu[j].sum);
		printf("\n");
	}
	getch();
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
	STU temp1 = { 0 };
	for (int i = 0; i < n - 1; i++) {
		if (stu[i].num > stu[i + 1].num) {
			temp1 = stu[i];
			stu[i] = stu[i + 1];
			stu[i + 1] = temp1;
		}
	}
	printf("\n\t\t\t==============按学号从小到排序===============\n");
	for (int j = 0; j < n; j++) {
		printf("\t\t\t该学生的学号为:%d\n", stu[j].num);
		printf("\t\t\t该学生的姓名为:");
		for (int k = 0; k < MAX_LEN; k++) {
			printf("%c", stu[j].name[k]);
		}
		printf("\n\t\t\t该学生的各科成绩为\n");
		for (int c = 0; c < m; c++) {
			printf("\t\t\t第%d门成绩为%.2f\n", c + 1, stu[j].score[c]);
		}
		printf("\n");
	}
	getch();
}


/* 使用交换法，实现字符串按字典顺序排序 */
void SortbyName(STU stu[], int n, int m)
{
	STU temp1 = { 0 };
	for (int i = 0; i < n - 1; i++) {
		if (((int)(stu[i].name[0]) > (int)(stu[i + 1].name[0]))) {
			//将名字首字母转成成ASCII码从而比较大小排序
			temp1 = stu[i];
			stu[i] = stu[i + 1];
			stu[i + 1] = temp1;
		}
	}
	printf("\n\t\t\t==============按学号从小到排序===============\n");
	for (int j = 0; j < n; j++) {
		printf("\t\t\t该学生的学号为:%d\n", stu[j].num);
		printf("\t\t\t该学生的姓名为:");
		for (int k = 0; k < MAX_LEN; k++) {
			printf("\t\t\t%c", stu[j].name[k]);
		}
		printf("\n\t\t\t该学生的各科成绩为\n");
		for (int c = 0; c < m; c++) {
			printf("\t\t\t第%d门成绩为%.2f\n", c + 1, stu[j].score[c]);
		}
		printf("\t\t\t该学生的总成绩为:%.2f", stu[j].sum);
		printf("\n");
	}
	getch();
}

/* 按照学号，查找学生成绩并显示查找结果 */
void SearchbyNum(STU stu[], int n, int m)
{
	int find = -1;
	//记录需要查找的学号,并作为查找成功与否的标识符
	printf("\t\t\t请输入要查找的学号：");
	scanf("%d", &find);
	for (int i = 0; i < n; i++) {
		if (stu[i].num == find) {
			printf("\n\t\t\t查找成功\n");
			printf("\t\t\t该学生的学号为%d\n", stu[i].num);
			printf("\t\t\t该学生的姓名为:");
			for (int k = 0; k < MAX_LEN; k++) {
				printf("\t\t\t%c", stu[i].name[k]);
			}
			printf("\n\t\t\t该学生的各科成绩为\n");
			for (int c = 0; c < m; c++) {
				printf("\t\t\t第%d门成绩为%.2f\n", c + 1, stu[i].score[c]);
			}
			printf("\t\t\t该学生的总成绩为:%.2f", stu[i].sum);
			printf("\n");
			find = -2;
		}
	}
	if (find != -2) {
		printf("\t\t\t查无此人\n");
		printf("\t\t\t按任意键继续");
	}
	getch();
}

/* 按照姓名，查询学生排名并显示查找结果 */
void SearchbyName(STU stu[], int n, int m)
{
	int is_find = 0;
	char find[STU_NUM];
	printf("\t\t\t请输入要查找的姓名：");
	getchar();
	gets(find);
	for (int i = 0; i < n; i++) {
		if (strcmp(stu[i].name, find) == 0) {
			printf("\n\t\t\t查找成功\n");
			printf("\t\t\t该学生的学号为%d\n", stu[i].num);
			printf("\t\t\t该学生的姓名为:");
			for (int k = 0; k < MAX_LEN; k++) {
				printf("\t\t\t%c", stu[i].name[k]);
			}
			printf("\n\t\t\t该学生的各科成绩为\n");
			for (int c = 0; c < m; c++) {
				printf("\t\t\t第%d门成绩为%.2f\n", c + 1, stu[i].score[c]);
			}
			printf("\t\t\t该学生的总成绩为:%.2f", stu[i].sum);
			printf("\n");
			is_find = 1;
		}
	}
	if (is_find != 1) {
		printf("\t\t\t查无此人\n");
		printf("\t\t\t按任意键继续");
	}
	getch();
}

/* 统计各个分数段的学生人数及其所占的百分比 */
void StatisticAnalysis(STU stu[], int n, int m)	//m门课程，n个学生
{
	int i, vgod, gods, jige, unjige;
	i = 0; vgod = 0; gods = 0; jige = 0; unjige = 0;
	for (i = 0; i < n; i++)
	{
		if (stu[i].sum >= 90)
		{
			vgod++;
		}
		if (stu[i].sum >= 80 && stu[i].sum < 90)
		{
			gods++;
		}
		if (stu[i].sum >= 60)

		{
			jige++;
		}
		if (stu[i].sum < 60)
		{
			unjige++;
		}
	}

	printf("\t\t\t本次成绩情况如下：\n 优秀率：%1f %%\n 良好率：%1f %%\n 及格率： %1f %%  \n不及格率：%1f %% \n", (float)vgod * 100 / n, (float)gods * 100 / n, (float)jige * 100 / n, (float)unjige * 100 / n);
}



/* 打印学生成绩 */
void PrintScore(STU stu[], int n, int m)
{
	printf("\t\t\t==============以下为学生信息==============");
	for (int j = 0; j < n; j++) {
		printf("\t\t\t该学生的学号为:%d\n", stu[j].num);
		printf("\t\t\t该学生的姓名为:");
		for (int k = 0; k < MAX_LEN; k++) {
			printf("\t\t\t%c", stu[j].name[k]);
		}
		printf("\n\t\t\t该学生的各科成绩为\n");
		for (int c = 0; c < m; c++) {
			printf("\t\t\t第%d门成绩为%.2f\n", c + 1, stu[j].score[c]);
		}
		printf("\t\t\t该学生的总成绩为:%.2f", stu[j].sum);
		printf("\n");
	}
	getch();
}
//zwx 完成

