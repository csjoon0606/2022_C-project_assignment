#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>

typedef struct _Dataformat //[평가항목 5] 구조체 사용
{
	char country[50];
	int confirmed;
	int dead;
	int recovered;
};

//1부터 원하는 번호까지 확진자 현황을 나타냄
void show_Status(struct _Dataformat A[], int n);
//원하는 번호 국가의 확진자를 나타냄
void show_espStatus(struct _Dataformat A[], int n);
//누적확진자 순으로 정렬
void Sort_confirmed(struct _Dataformat A[], int n);
//사망자 순으로 정렬
void Sort_dead(struct _Dataformat A[], int n);
//완치자 순으로 정렬
void Sort_recovered(struct _Dataformat A[], int n);
//사용자에게서 정보를 받아 기존 데이터에서의 누적확진자 순위 출력
void compare_confirmedData(struct _Dataformat A[], int n, int m);
//사용자에게서 정보를 받아 기존 데이터에서의 사망자 순위 출력
void compare_deadData(struct _Dataformat A[], int n, int m);
//사용자에게서 정보를 받아 기존 데이터에서의 완치자 순위 출력
void compare_recoveredData(struct _Dataformat A[], int n, int m);
//사용자가 원하는 국가의 각종 비율을 출력
void print_ratio_data(float a,float b,float c);
#endif // !HEADER_H
