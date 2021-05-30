/* ѧ���ɼ�����ϵͳv5.0

  ĳ������಻����30�ˣ����������ɼ������룩�μ���ĩ���ԣ���಻����6�ţ����������ɼ������룩

 ��1��¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ���
 ��2������ÿ�ſγ̵��ֺܷ�ƽ���֣�
 ��3������ÿ��ѧ�����ֺܷ�ƽ���֣�
 ��4������ÿ��ѧ�����ܷ��ɸߵ����ų����α�
 ��5������ÿ��ѧ�����ܷ��ɵ͵����ų����α�
 ��6������ѧ����С�����ų��ɼ���
 ��7�������������ֵ�˳���ų��ɼ���
 ��8������ѧ�Ų�ѯѧ������������ƿ��Գɼ���
 ��9������������ѯѧ������������ƿ��Գɼ���		 ��10���������㣨90-100�֣������ã�80-89�֣����еȣ�70-79�֣�������60-69�֣���������0-59�֣�5�����ͳ��ÿ�����������Լ���ռ�İٷֱȡ�
 ��11�����ÿ��ѧ����ѧ�š����������ƿ��Գɼ����ܷ֡�ƽ�����Լ�ÿ�ſγ̵��ֺܷ�ƽ���֡�	//��v3.0�����ˡ����ſγ̡�

  ʵ��Ҫ�󣺶���ṹ�����ͣ��ýṹ������������������
			�˵������������������к�����ʾ�˵��������û������ѡ��ִ����Ӧ�Ĳ�����

  ʵ��Ŀ�ģ��ڡ�ѧ���ɼ�����ϵͳV4.0���Ļ����ϣ�ͨ����������Ҫ����Ϥ�ṹ�����͡��ṹ������������������ģ�黯������Ʒ��������Ӧ�ýṹ�������ͨ����������ʵ�����ݿ�������Խ�ԡ�
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN  10		//�ַ�������󳤶�
#define STU_NUM 30		//����ѧ������
#define COURSE_NUM 6	//���Ŀ��Կ�Ŀ��

typedef struct student
{
	long num;					//ÿ��ѧ����ѧ��
	char name[MAX_LEN];			//ÿ��ѧ��������
	float score[COURSE_NUM];	//ÿ��COURSE_NUM�Ź��εĳɼ�
	float sum;					//ÿ��ѧ�����ܳɼ�
	float aver;					//ÿ��ѧ����ƽ���ɼ�
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
	int n = 0, m = 0;	//m�ſγ̣�n��ѧ��
	STU stu[STU_NUM];

	//����ѧ���ĸ���
	printf("input student number(n<%d):\n", STU_NUM);
	scanf("%d", &n);

	//����γ̵�����
	printf("input course number(n<=%d):\n", COURSE_NUM);
	scanf("%d", &m);

	system("title ѧ���ɼ�����ϵͳV5.0  By zwx");
	printf("\n\n");
	printf("\t\t\t                         ѧ���ɼ�����ϵͳV5.0\n");
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


/* ����n��ѧ����m�ſεĳɼ� */
void ReadScore(STU stu[], int n, int m)
{
	printf("\n\t\t\t===============================================\n");
	printf("\t\t\t������ѧ��ѧ�š�������������Ϣ(����0ֹͣ��Ϣ����)\n");
	for (int i = 0; i < n; i++) 
	{
		printf("\t\t\tѧ��:");

		scanf("%ld", &stu[i].num);

		if (stu[i].num == 0) break;

		getchar();//���ն��໻�з�

		printf("\t\t\t������");

		gets(stu[i].name);

		printf("\t\t\t��������Ƴɼ�(û�ųɼ��ո����)");
		stu[i].sum = 0;
		for (int j = 0; j < m; j++)
		{
			scanf("%f", &stu[i].score[j]);
			stu[i].sum += stu[i].score[j];
		}
	}
}

/* ����ÿ�ſγ̵��ֺܷ�ƽ���� */
void AverSumofEveryCourse(STU stu[], int n, int m)  // m�ſγ̣�n��ѧ��
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
		printf("\t\t\t��%d�ſγ̵��ܷ�Ϊ��%.2f��ƽ����Ϊ%.2f\n", i + 1, sum[i], average[i]);
	}
	getch();
	
	
}

/* ����ÿ��ѧ�����ſγ̵��ֺܷ�ƽ���֡�������� */
void AverSumofEveryStudent(STU stu[], int n, int m)	// m�ſγ̣�n��ѧ��
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
	//�����
	for (k = 0; k < n; k++)
	{
		printf("\t\t\t��ѧ���ɼ����£�\n");
		printf("\t\t\tѧ�ţ�%ld\t������%s\t�ܷ֣�%0.2f\tƽ����:%0.2f\t", stu[k].num, stu[k].name, stu[k].sum, stu[k].aver);
	}	printf("\n");

}

/* ����ÿ��ѧ�����ſγ̵��ֺܷ�ƽ���֡�������� */
void AverSumofEveryStudent_no_out(STU stu[], int n, int m)	// m�ſγ̣�n��ѧ��
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
	//�����
	/*for (k = 0; k < n; k++)
	{
		printf("\t\t\t��ѧ���ɼ����£�\n");
		printf("\t\t\tѧ�ţ�%ld\t������%s\t�ܷ֣�%0.2f\tƽ����:%0.2f\t", stu[k].num, stu[k].name, stu[k].sum, stu[k].aver);
	}	printf("\n");*/


}

/* ��ѡ�񷨣�������sum��Ԫ��ֵ���� */
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
	printf("\n\t\t\t============���ܳɼ��Ӹߵ�������===========\n");
	for (int j = 0; j < n; j++) {
		printf("\t\t\t��ѧ����ѧ��Ϊ:%d\n", stu[j].num);
		printf("\t\t\t��ѧ��������Ϊ:");
		for (int k = 0; k < MAX_LEN; k++) {
			printf("\t\t\t%c", stu[j].name[k]);
		}
		printf("\n\t\t\t��ѧ���ĸ��Ƴɼ�Ϊ\n");
		for (int c = 0; c < m; c++) {
			printf("\t\t\t��%d�ųɼ�Ϊ%.2f\n", c + 1, stu[j].score[c]);
		}
		printf("\t\t\t��ѧ�����ܳɼ�Ϊ:%.2f", stu[j].sum);
		printf("\n");
	}
	getch();
}



/* ʹ�����ݰ����������� */
int Ascending(float a, float b)
{
	return a < b;
}


/* ʹ�����ݰ��ս������� */
int Descending(float a, float b)
{
	return a > b;
}


/* �������������ȸ��������� */
void SwapFloat(float* x, float* y)
{
	float temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/* ������������������ */
void SwapLong(long* x, long* y)
{
	long temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/* ���������ַ��� */
void SwapChar(char x[], char y[])
{
	char temp[MAX_LEN];

	strcpy(temp, x);
	strcpy(x, y);
	strcpy(y, temp);
}

/* ����ѡ�񷨣�������num��Ԫ��ֵ���մ�С�������� */
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
	printf("\n\t\t\t==============��ѧ�Ŵ�С������===============\n");
	for (int j = 0; j < n; j++) {
		printf("\t\t\t��ѧ����ѧ��Ϊ:%d\n", stu[j].num);
		printf("\t\t\t��ѧ��������Ϊ:");
		for (int k = 0; k < MAX_LEN; k++) {
			printf("%c", stu[j].name[k]);
		}
		printf("\n\t\t\t��ѧ���ĸ��Ƴɼ�Ϊ\n");
		for (int c = 0; c < m; c++) {
			printf("\t\t\t��%d�ųɼ�Ϊ%.2f\n", c + 1, stu[j].score[c]);
		}
		printf("\n");
	}
	getch();
}


/* ʹ�ý�������ʵ���ַ������ֵ�˳������ */
void SortbyName(STU stu[], int n, int m)
{
	STU temp1 = { 0 };
	for (int i = 0; i < n - 1; i++) {
		if (((int)(stu[i].name[0]) > (int)(stu[i + 1].name[0]))) {
			//����������ĸת�ɳ�ASCII��Ӷ��Ƚϴ�С����
			temp1 = stu[i];
			stu[i] = stu[i + 1];
			stu[i + 1] = temp1;
		}
	}
	printf("\n\t\t\t==============��ѧ�Ŵ�С������===============\n");
	for (int j = 0; j < n; j++) {
		printf("\t\t\t��ѧ����ѧ��Ϊ:%d\n", stu[j].num);
		printf("\t\t\t��ѧ��������Ϊ:");
		for (int k = 0; k < MAX_LEN; k++) {
			printf("\t\t\t%c", stu[j].name[k]);
		}
		printf("\n\t\t\t��ѧ���ĸ��Ƴɼ�Ϊ\n");
		for (int c = 0; c < m; c++) {
			printf("\t\t\t��%d�ųɼ�Ϊ%.2f\n", c + 1, stu[j].score[c]);
		}
		printf("\t\t\t��ѧ�����ܳɼ�Ϊ:%.2f", stu[j].sum);
		printf("\n");
	}
	getch();
}

/* ����ѧ�ţ�����ѧ���ɼ�����ʾ���ҽ�� */
void SearchbyNum(STU stu[], int n, int m)
{
	int find = -1;
	//��¼��Ҫ���ҵ�ѧ��,����Ϊ���ҳɹ����ı�ʶ��
	printf("\t\t\t������Ҫ���ҵ�ѧ�ţ�");
	scanf("%d", &find);
	for (int i = 0; i < n; i++) {
		if (stu[i].num == find) {
			printf("\n\t\t\t���ҳɹ�\n");
			printf("\t\t\t��ѧ����ѧ��Ϊ%d\n", stu[i].num);
			printf("\t\t\t��ѧ��������Ϊ:");
			for (int k = 0; k < MAX_LEN; k++) {
				printf("\t\t\t%c", stu[i].name[k]);
			}
			printf("\n\t\t\t��ѧ���ĸ��Ƴɼ�Ϊ\n");
			for (int c = 0; c < m; c++) {
				printf("\t\t\t��%d�ųɼ�Ϊ%.2f\n", c + 1, stu[i].score[c]);
			}
			printf("\t\t\t��ѧ�����ܳɼ�Ϊ:%.2f", stu[i].sum);
			printf("\n");
			find = -2;
		}
	}
	if (find != -2) {
		printf("\t\t\t���޴���\n");
		printf("\t\t\t�����������");
	}
	getch();
}

/* ������������ѯѧ����������ʾ���ҽ�� */
void SearchbyName(STU stu[], int n, int m)
{
	int is_find = 0;
	char find[STU_NUM];
	printf("\t\t\t������Ҫ���ҵ�������");
	getchar();
	gets(find);
	for (int i = 0; i < n; i++) {
		if (strcmp(stu[i].name, find) == 0) {
			printf("\n\t\t\t���ҳɹ�\n");
			printf("\t\t\t��ѧ����ѧ��Ϊ%d\n", stu[i].num);
			printf("\t\t\t��ѧ��������Ϊ:");
			for (int k = 0; k < MAX_LEN; k++) {
				printf("\t\t\t%c", stu[i].name[k]);
			}
			printf("\n\t\t\t��ѧ���ĸ��Ƴɼ�Ϊ\n");
			for (int c = 0; c < m; c++) {
				printf("\t\t\t��%d�ųɼ�Ϊ%.2f\n", c + 1, stu[i].score[c]);
			}
			printf("\t\t\t��ѧ�����ܳɼ�Ϊ:%.2f", stu[i].sum);
			printf("\n");
			is_find = 1;
		}
	}
	if (is_find != 1) {
		printf("\t\t\t���޴���\n");
		printf("\t\t\t�����������");
	}
	getch();
}

/* ͳ�Ƹ��������ε�ѧ������������ռ�İٷֱ� */
void StatisticAnalysis(STU stu[], int n, int m)	//m�ſγ̣�n��ѧ��
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

	printf("\t\t\t���γɼ�������£�\n �����ʣ�%1f %%\n �����ʣ�%1f %%\n �����ʣ� %1f %%  \n�������ʣ�%1f %% \n", (float)vgod * 100 / n, (float)gods * 100 / n, (float)jige * 100 / n, (float)unjige * 100 / n);
}



/* ��ӡѧ���ɼ� */
void PrintScore(STU stu[], int n, int m)
{
	printf("\t\t\t==============����Ϊѧ����Ϣ==============");
	for (int j = 0; j < n; j++) {
		printf("\t\t\t��ѧ����ѧ��Ϊ:%d\n", stu[j].num);
		printf("\t\t\t��ѧ��������Ϊ:");
		for (int k = 0; k < MAX_LEN; k++) {
			printf("\t\t\t%c", stu[j].name[k]);
		}
		printf("\n\t\t\t��ѧ���ĸ��Ƴɼ�Ϊ\n");
		for (int c = 0; c < m; c++) {
			printf("\t\t\t��%d�ųɼ�Ϊ%.2f\n", c + 1, stu[j].score[c]);
		}
		printf("\t\t\t��ѧ�����ܳɼ�Ϊ:%.2f", stu[j].sum);
		printf("\n");
	}
	getch();
}
//zwx ���

