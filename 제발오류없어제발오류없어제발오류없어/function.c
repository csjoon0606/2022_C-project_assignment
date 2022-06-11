
//[평가항목 8] 다중소스 파일 사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "헤더.h"



//1부터 원하는 번호까지 확진자 현황을 나타냄 //[평가항목 2] 함수 사용
void show_Status(struct _Dataformat A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d번째 순번의 국가 %s에서의 코로나 현황\n 누적확진자: %d\n 사망자: %d\n 완치자: %d\n", i+1, A[i].country, A[i].confirmed, A[i].dead, A[i ].recovered);
	}
}



//원하는 번호 국가의 확진자를 나타냄 //[평가항목 2] 함수 사용
void show_espStatus(struct _Dataformat A[], int n) {
	printf("%d번째 순번의 국가 %s에서의 코로나 현황\n 누적확진자: %d\n 사망자: %d\n 완치자: %d\n", n,A[n-1].country, A[n-1].confirmed, A[n-1].dead, A[n-1].recovered);
}

//누적확진자 순으로 정렬 //[평가항목 2] 함수 사용
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
//사망자 순으로 정렬 //[평가항목 2] 함수 사용
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
//완치자 순으로 정렬 //[평가항목 2] 함수 사용
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
//사용자에게서 정보를 받아 기존 데이터에서의 누적확진자 순위 출력 //[평가항목 2] 함수 사용
void compare_confirmedData(struct _Dataformat A[], int n, int m) {
	int score=1;
	for (int i = 0; i < m;i++) {
		if (n < A[i].confirmed) {
			score++;
		}
	}
	printf("현재 전 세계에서 %d위입니다.", score);
}
//사용자에게서 정보를 받아 기존 데이터에서의 사망자 순위 출력 //[평가항목 2] 함수 사용
void compare_deadData(struct _Dataformat A[], int n, int m) {
	int score = 1;
	for (int i = 0; i < m; i++) {
		if (n < A[i].dead) {
			score++;
		}
	}
	printf("현재 전 세계에서 %d위입니다.", score);
}
//사용자에게서 정보를 받아 기존 데이터에서의 완치자 순위 출력 //[평가항목 2] 함수 사용
void compare_recoveredData(struct _Dataformat A[], int n, int m) {
	int score = 1;
	for (int i = 0; i < m; i++) {
		if (n < A[i].recovered) {
			score++;
		}
	}
	printf("현재 전 세계에서 %d위입니다.", score);
}

//비율을 계산하는 함수 //[평가항목 2] 함수 사용
float cal_ratio(float a, float b) {
	float result;
	result =(b / a) * 100;
	return result;
}

//사용자가 원하는 국가의 각종 비율을 출력   //[평가항목 2, 6] 함수 사용 및 포인터 활용
void print_ratio_data(float a, float b, float c) {
	float result;
	float (*pf)(float, float);

	pf = cal_ratio;
	result = pf(a,b);
	printf("사망률: %f\n", result);
	result = pf(a,c);
	printf("완치율: %f\n", result);
}