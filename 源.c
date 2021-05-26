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

	while (1)
	{
		 I= Menu();	//��ʾ�˵�������ȡ�û�����
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

/* ��ʾ�˵���������û�������������� */
int   Menu(void)
{
	int i;
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
	scanf("%d", &i);
	return i;

}

/* ����n��ѧ����m�ſεĳɼ� */
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
			printf("please input the student`s score(�� %d ��)��\t", k);
			k++;
			scanf("%d", &stu[i].score[j]);
			printf("\n");


		}
	}
}

/* ����ÿ�ſγ̵��ֺܷ�ƽ���� */
void AverSumofEveryCourse(STU stu[], int n, int m)  // m�ſγ̣�n��ѧ��
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
	//���
	for (x = 0; x < m; x++)
	{
		printf("�� %d �ſε��ܷ֣�%f\tƽ���֣�%f\t", x + 1, sum[x], aver[x]);
		printf("\n");

	}
	
}

/* ����ÿ��ѧ�����ſγ̵��ֺܷ�ƽ���֡�������� */
void AverSumofEveryStudent(STU stu[], int n, int m)	// m�ſγ̣�n��ѧ��
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
	//�����
	for (k = 0; k < n; k++)
	{
		printf("��ѧ���ɼ����£�\n");
		printf("ѧ�ţ�%ld\t������%s\t�ܷ֣�%0.2f\tƽ����:%0.2f\t", stu[k].num, stu[k].name, stu[k].sum, stu[k].aver);
	}	printf("\n");

}

/* ����ÿ��ѧ�����ſγ̵��ֺܷ�ƽ���֡�������� */
void AverSumofEveryStudent_no_out(STU stu[], int n, int m)	// m�ſγ̣�n��ѧ��
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
		printf("��ѧ���ɼ����£�\n");
		printf("ѧ�ţ�%ld\t������%s\t�ܷ֣�%0.2f\tƽ����:%0.2f\t", stu[k].num, stu[k].name, stu[k].sum, stu[k].aver);
	}	printf("\n");*/

}

/* ��ѡ�񷨣�������sum��Ԫ��ֵ���� */
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


/* ʹ�ý�������ʵ���ַ������ֵ�˳������ */
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

/* ����ѧ�ţ�����ѧ���ɼ�����ʾ���ҽ�� */
void SearchbyNum(STU stu[], int n, int m)
{

}

/* ������������ѯѧ����������ʾ���ҽ�� */
void SearchbyName(STU stu[], int n, int m)
{

}

/* ͳ�Ƹ��������ε�ѧ������������ռ�İٷֱ� */
void StatisticAnalysis(STU stu[], int n, int m)	//m�ſγ̣�n��ѧ��
{

}

/* ��ӡѧ���ɼ� */
void PrintScore(STU stu[], int n, int m)
{

}

