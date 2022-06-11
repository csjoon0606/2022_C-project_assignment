/*[평가항목 1] 과제 설명
* 컴퓨터프로그래밍 평가과제 (배점 25점)
* 학과: 컴퓨터공학과
* 학번: 202203534
* 이름: 최성준
* 
* 과제 주제: 전세계 나라들의 확진자 데이터를 조회하고 분석하는 것을 도와주는 프로그램

*/



#define _CRT_SECURE_NO_WARNINGS
#define SCALE 10 //데이터셋 크기 조정 변수선언
#include <stdio.h>
#include "헤더.h"

int menu;
int n = 0;
int m = 0;
int p = 0;
int score = 0;

int main(void) {

	//COVID-19 데이터셋 [평가항목 3, 5] 구조체 배열 사용
	struct _Dataformat datalist[SCALE] = { {"미국",87114740,1035320,82935242},{"인도",43213355,524747,42644092},{"브라질",31417341,668007,30178187},
		{"프랑스",29753370,148710,29166768}, {"독일",26802782,140115,25850400}, {"영국",22382352,179217,22019930}, {"러시아",18369557,379883,17786254},
		{"대한민국",18218078,24351,969524}, {"이탈리아",17611607,167305,16820881}, {"터키",15072747,98965,14971256} };
	
	//Goto의 종착지점
	AAA:
	


	//메인메뉴 구성
	printf("\n----------------------전세계 코로나 정보 현황-----------------------\n");
	printf("       전세계 코로나 정보 열람시스템에 오신것을 환영합니다 \n");

	printf("              원하는 서비스의 번호를 입력해주십시오\n");
	printf("  1.순위  /  2.정보 비교 / 3.국가별 각종 비율 조회\n");
	scanf("%d", &menu);
		

	//데이터셋에서 특정 수치의 순위로 데이터를 불러오는 부분
		switch (menu)
		{
		case 1:
			printf("열람을 원하는 종류의 순위를 선택하시오\n");
			printf("--1.누적확진자 / 2.사망자 / 3.완치자 ---\n");
			scanf("%d", &n);
			switch (n) {
			case 1:
				Sort_confirmed(datalist, SCALE); //[평가항목 2] 함수 사용
				printf("특정 순위 국가의 정보만을 원한다면 1, 1등부터 순서대로의 정보를 원한다면 2를 입력하시오: ");
				scanf("%d", &m);
				if (m == 1) {
					printf("몇번째 정보를 원하십니까? :");
					scanf("%d", &p);
					printf("\n(누적확진자 수에 따라 정리된 순위)\n");
					show_espStatus(datalist, p); //[평가항목 2] 함수 사용
				}
				else if (m == 2) {
					printf("몇번째까지의 정보를 원하십니까? :");
					scanf("%d", &p);
					printf("\n(누적확진자 수에 따라 정리된 순위)\n");
					show_Status(datalist, p); //[평가항목 2] 함수 사용
				}
				break;
			case 2:
				Sort_dead(datalist, SCALE); //[평가항목 2] 함수 사용
				printf("특정 순위 국가의 정보만을 원한다면 1, 1등부터 순서대로의 정보를 원한다면 2를 입력하시오: ");
				scanf("%d", &m);
				if (m == 1) {
					printf("몇번째 정보를 원하십니까? :");
					scanf("%d", &p);
					printf("\n(사망자 수에 따라 정리된 순위)\n");
					show_espStatus(datalist, p); //[평가항목 2] 함수 사용
				}
				else if (m == 2) {
					printf("몇번째까지의 정보를 원하십니까? :");
					scanf("%d", &p);
					printf("\n(사망자 수에 따라 정리된 순위)\n");
					show_Status(datalist, p); //[평가항목 2] 함수 사용
				}
				break;
			case 3:
				Sort_recovered(datalist, SCALE); //[평가항목 2] 함수 사용
				printf("특정 국가의 정보만을 원한다면 1, 1번부터 순서대로의 정보를 원한다면 2를 입력하시오: ");
				scanf("%d", &m);
				if (m == 1) {
					printf("몇번째 정보를 원하십니까? :");
					scanf("%d", &p);
					printf("\n(완치자 수에 따라 정리된 순위)\n");
					show_espStatus(datalist, p); //[평가항목 2] 함수 사용
				}
				else if (m == 2) {
					printf("몇번째까지의 정보를 원하십니까? :");
					scanf("%d", &p);
					printf("\n(완치자 수에 따라 정리된 순위)\n");
					show_Status(datalist, p); //[평가항목 2] 함수 사용
				}
				break;
			default:
				printf("올바르지 않은 입력입니다.");
				break;
			}
			break;


		//사용자가 입력한 정보를 파일에 저장 후 데이터셋과 비교하는 부분   //[평가항목 6, 7] 파일 포인터 사용 및 파일 입출력
		case 2:
		{	struct _Dataformat input ={" ",0,0,0};
			FILE* fp;
			char C_name[50];
		printf("비교할 국가의 이름을 입력하시오:  ");
		scanf("%s", C_name);
		strcpy(input.country, C_name);

		if ((fp = fopen(C_name, "w")) == NULL) {
			fprintf(stderr, "입력파일 %s를 열 수 없습니다.\n", C_name);
			exit(1);
		}

		printf("비교를 원하는 정보를 입력하시오\n 1.누적확진자 2.사망자 3.완치자 \n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("누적확진자 수를 입력하시오: ");
			scanf("%d", &m);
			fprintf(fp, "%d", m);
			fclose(fp);

			if ((fp = fopen(C_name, "r")) == NULL) {
				fprintf(stderr, "입력파일 %s를 열 수 없습니다.\n", C_name);
				exit(1);
			}
			fscanf(fp, "%d", &score);
			Sort_confirmed(datalist, SCALE); //[평가항목 2] 함수 사용
			printf("%s의 누적확진자는 ", C_name);
			compare_confirmedData(datalist, score, SCALE); //[평가항목 2] 함수 사용
			break;
		case 2:
			printf("사망자 수를 입력하시오: ");
			scanf("%d", &m);
			fprintf(fp, "%d", m);
			fclose(fp);

			if ((fp = fopen(C_name, "r")) == NULL) {
				fprintf(stderr, "입력파일 %s를 열 수 없습니다.\n", C_name);
				exit(1);
			}
			fscanf(fp, "%d", &score);
			Sort_dead(datalist, SCALE); //[평가항목 2] 함수 사용
			printf("%s의 사망자는 ", C_name);
			compare_deadData(datalist, score, SCALE); //[평가항목 2] 함수 사용
			break;
		case 3:
			printf("완치자 수를 입력하시오: ");
			scanf("%d", &m);
			fprintf(fp, "%d", m);
			fclose(fp);

			if ((fp = fopen(C_name, "r")) == NULL) {
				fprintf(stderr, "입력파일 %s를 열 수 없습니다.\n", C_name);
				exit(1);
			}
			fscanf(fp, "%d", &score);
			Sort_recovered(datalist, SCALE); //[평가항목 2] 함수 사용
			printf("%s의 완치자는 ", C_name);
			compare_recoveredData(datalist, score, SCALE); //[평가항목 2] 함수 사용
			break;
		default:
			printf("올바르지 않은 입력값입니다.\n");
			break;
		}
		printf("\n");
		break;
		}



		//데이터셋에서 원하는 국가의 사망률과 완치율을 구하는 부분
		case 3:
			printf("이곳은 사용자가 원하는 국가의 Covid-19의 사망률, 완치율을 제공하는 서비스입니다.\n");
			printf("조회를 원하는 국가의 번호를 입력하시오.\n<입력가능 국가 목록>\n ");
			for (int i = 0; i < SCALE; i++) {
				printf("%d. %s  ", i + 1, datalist[i].country);
			}
			printf(": ");
			scanf("%d", &m);
			printf("%s의 Covid-19\n",datalist[m-1].country);
			print_ratio_data(datalist[m - 1].confirmed, datalist[m - 1].dead, datalist[m-1].recovered, m - 1); //[평가항목 2] 함수 사용
			
			
			break;


		default:
			break;
		}


		//GOTO 선언을 이용한 프로그램 재실행 코드
		int q;
		printf("계속하시겠습니까?( Y(1) / N(2) ): ");
		scanf("%d", &q);
		if (q == 2) {
			return 0;
		}
		else if(q ==1) {
			goto AAA;
		}
		else
		{
			printf("잘못된 입력입니다. 프로그램을 종료합니다\n");
		}
	
	return 0;
}