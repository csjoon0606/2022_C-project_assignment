
//[���׸� 8] ���߼ҽ� ���� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "���.h"



//1���� ���ϴ� ��ȣ���� Ȯ���� ��Ȳ�� ��Ÿ�� //[���׸� 2] �Լ� ���
void show_Status(struct _Dataformat A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d��° ������ ���� %s������ �ڷγ� ��Ȳ\n ����Ȯ����: %d\n �����: %d\n ��ġ��: %d\n", i+1, A[i].country, A[i].confirmed, A[i].dead, A[i ].recovered);
	}
}



//���ϴ� ��ȣ ������ Ȯ���ڸ� ��Ÿ�� //[���׸� 2] �Լ� ���
void show_espStatus(struct _Dataformat A[], int n) {
	printf("%d��° ������ ���� %s������ �ڷγ� ��Ȳ\n ����Ȯ����: %d\n �����: %d\n ��ġ��: %d\n", n,A[n-1].country, A[n-1].confirmed, A[n-1].dead, A[n-1].recovered);
}

//����Ȯ���� ������ ���� //[���׸� 2] �Լ� ���
void Sort_confirmed(struct _Dataformat A[], int n) {
	struct _Dataformat tmp;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (A[i].confirmed < A[j].confirmed) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
}
//����� ������ ���� //[���׸� 2] �Լ� ���
void Sort_dead(struct _Dataformat A[], int n) {
	struct _Dataformat tmp;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (A[i].dead < A[j].dead) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
}
//��ġ�� ������ ���� //[���׸� 2] �Լ� ���
void Sort_recovered(struct _Dataformat A[], int n) {
	struct _Dataformat tmp;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (A[i].recovered < A[j].recovered) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
}
//����ڿ��Լ� ������ �޾� ���� �����Ϳ����� ����Ȯ���� ���� ��� //[���׸� 2] �Լ� ���
void compare_confirmedData(struct _Dataformat A[], int n, int m) {
	int score=1;
	for (int i = 0; i < m;i++) {
		if (n < A[i].confirmed) {
			score++;
		}
	}
	printf("���� �� ���迡�� %d���Դϴ�.", score);
}
//����ڿ��Լ� ������ �޾� ���� �����Ϳ����� ����� ���� ��� //[���׸� 2] �Լ� ���
void compare_deadData(struct _Dataformat A[], int n, int m) {
	int score = 1;
	for (int i = 0; i < m; i++) {
		if (n < A[i].dead) {
			score++;
		}
	}
	printf("���� �� ���迡�� %d���Դϴ�.", score);
}
//����ڿ��Լ� ������ �޾� ���� �����Ϳ����� ��ġ�� ���� ��� //[���׸� 2] �Լ� ���
void compare_recoveredData(struct _Dataformat A[], int n, int m) {
	int score = 1;
	for (int i = 0; i < m; i++) {
		if (n < A[i].recovered) {
			score++;
		}
	}
	printf("���� �� ���迡�� %d���Դϴ�.", score);
}

//������ ����ϴ� �Լ� //[���׸� 2] �Լ� ���
float cal_ratio(float a, float b) {
	float result;
	result =(b / a) * 100;
	return result;
}

//����ڰ� ���ϴ� ������ ���� ������ ���   //[���׸� 2, 6] �Լ� ��� �� ������ Ȱ��
void print_ratio_data(float a, float b, float c) {
	float result;
	float (*pf)(float, float);

	pf = cal_ratio;
	result = pf(a,b);
	printf("�����: %f\n", result);
	result = pf(a,c);
	printf("��ġ��: %f\n", result);
}