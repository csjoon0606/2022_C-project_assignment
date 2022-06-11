#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>

typedef struct _Dataformat //[���׸� 5] ����ü ���
{
	char country[50];
	int confirmed;
	int dead;
	int recovered;
};

//1���� ���ϴ� ��ȣ���� Ȯ���� ��Ȳ�� ��Ÿ��
void show_Status(struct _Dataformat A[], int n);
//���ϴ� ��ȣ ������ Ȯ���ڸ� ��Ÿ��
void show_espStatus(struct _Dataformat A[], int n);
//����Ȯ���� ������ ����
void Sort_confirmed(struct _Dataformat A[], int n);
//����� ������ ����
void Sort_dead(struct _Dataformat A[], int n);
//��ġ�� ������ ����
void Sort_recovered(struct _Dataformat A[], int n);
//����ڿ��Լ� ������ �޾� ���� �����Ϳ����� ����Ȯ���� ���� ���
void compare_confirmedData(struct _Dataformat A[], int n, int m);
//����ڿ��Լ� ������ �޾� ���� �����Ϳ����� ����� ���� ���
void compare_deadData(struct _Dataformat A[], int n, int m);
//����ڿ��Լ� ������ �޾� ���� �����Ϳ����� ��ġ�� ���� ���
void compare_recoveredData(struct _Dataformat A[], int n, int m);
//����ڰ� ���ϴ� ������ ���� ������ ���
void print_ratio_data(float a,float b,float c);
#endif // !HEADER_H
