/*[���׸� 1] ���� ����
* ��ǻ�����α׷��� �򰡰��� (���� 25��)
* �а�: ��ǻ�Ͱ��а�
* �й�: 202203534
* �̸�: �ּ���
* 
* ���� ����: ������ ������� Ȯ���� �����͸� ��ȸ�ϰ� �м��ϴ� ���� �����ִ� ���α׷�

*/



#define _CRT_SECURE_NO_WARNINGS
#define SCALE 10 //�����ͼ� ũ�� ���� ��������
#include <stdio.h>
#include "���.h"

int menu;
int n = 0;
int m = 0;
int p = 0;
int score = 0;

int main(void) {

	//COVID-19 �����ͼ� [���׸� 3, 5] ����ü �迭 ���
	struct _Dataformat datalist[SCALE] = { {"�̱�",87114740,1035320,82935242},{"�ε�",43213355,524747,42644092},{"�����",31417341,668007,30178187},
		{"������",29753370,148710,29166768}, {"����",26802782,140115,25850400}, {"����",22382352,179217,22019930}, {"���þ�",18369557,379883,17786254},
		{"���ѹα�",18218078,24351,969524}, {"��Ż����",17611607,167305,16820881}, {"��Ű",15072747,98965,14971256} };
	
	//Goto�� ��������
	AAA:
	


	//���θ޴� ����
	printf("\n----------------------������ �ڷγ� ���� ��Ȳ-----------------------\n");
	printf("       ������ �ڷγ� ���� �����ý��ۿ� ���Ű��� ȯ���մϴ� \n");

	printf("              ���ϴ� ������ ��ȣ�� �Է����ֽʽÿ�\n");
	printf("  1.����  /  2.���� �� / 3.������ ���� ���� ��ȸ\n");
	scanf("%d", &menu);
		

	//�����ͼ¿��� Ư�� ��ġ�� ������ �����͸� �ҷ����� �κ�
		switch (menu)
		{
		case 1:
			printf("������ ���ϴ� ������ ������ �����Ͻÿ�\n");
			printf("--1.����Ȯ���� / 2.����� / 3.��ġ�� ---\n");
			scanf("%d", &n);
			switch (n) {
			case 1:
				Sort_confirmed(datalist, SCALE); //[���׸� 2] �Լ� ���
				printf("Ư�� ���� ������ �������� ���Ѵٸ� 1, 1����� ��������� ������ ���Ѵٸ� 2�� �Է��Ͻÿ�: ");
				scanf("%d", &m);
				if (m == 1) {
					printf("���° ������ ���Ͻʴϱ�? :");
					scanf("%d", &p);
					printf("\n(����Ȯ���� ���� ���� ������ ����)\n");
					show_espStatus(datalist, p); //[���׸� 2] �Լ� ���
				}
				else if (m == 2) {
					printf("���°������ ������ ���Ͻʴϱ�? :");
					scanf("%d", &p);
					printf("\n(����Ȯ���� ���� ���� ������ ����)\n");
					show_Status(datalist, p); //[���׸� 2] �Լ� ���
				}
				break;
			case 2:
				Sort_dead(datalist, SCALE); //[���׸� 2] �Լ� ���
				printf("Ư�� ���� ������ �������� ���Ѵٸ� 1, 1����� ��������� ������ ���Ѵٸ� 2�� �Է��Ͻÿ�: ");
				scanf("%d", &m);
				if (m == 1) {
					printf("���° ������ ���Ͻʴϱ�? :");
					scanf("%d", &p);
					printf("\n(����� ���� ���� ������ ����)\n");
					show_espStatus(datalist, p); //[���׸� 2] �Լ� ���
				}
				else if (m == 2) {
					printf("���°������ ������ ���Ͻʴϱ�? :");
					scanf("%d", &p);
					printf("\n(����� ���� ���� ������ ����)\n");
					show_Status(datalist, p); //[���׸� 2] �Լ� ���
				}
				break;
			case 3:
				Sort_recovered(datalist, SCALE); //[���׸� 2] �Լ� ���
				printf("Ư�� ������ �������� ���Ѵٸ� 1, 1������ ��������� ������ ���Ѵٸ� 2�� �Է��Ͻÿ�: ");
				scanf("%d", &m);
				if (m == 1) {
					printf("���° ������ ���Ͻʴϱ�? :");
					scanf("%d", &p);
					printf("\n(��ġ�� ���� ���� ������ ����)\n");
					show_espStatus(datalist, p); //[���׸� 2] �Լ� ���
				}
				else if (m == 2) {
					printf("���°������ ������ ���Ͻʴϱ�? :");
					scanf("%d", &p);
					printf("\n(��ġ�� ���� ���� ������ ����)\n");
					show_Status(datalist, p); //[���׸� 2] �Լ� ���
				}
				break;
			default:
				printf("�ùٸ��� ���� �Է��Դϴ�.");
				break;
			}
			break;


		//����ڰ� �Է��� ������ ���Ͽ� ���� �� �����ͼ°� ���ϴ� �κ�   //[���׸� 6, 7] ���� ������ ��� �� ���� �����
		case 2:
		{	struct _Dataformat input ={" ",0,0,0};
			FILE* fp;
			char C_name[50];
		printf("���� ������ �̸��� �Է��Ͻÿ�:  ");
		scanf("%s", C_name);
		strcpy(input.country, C_name);

		if ((fp = fopen(C_name, "w")) == NULL) {
			fprintf(stderr, "�Է����� %s�� �� �� �����ϴ�.\n", C_name);
			exit(1);
		}

		printf("�񱳸� ���ϴ� ������ �Է��Ͻÿ�\n 1.����Ȯ���� 2.����� 3.��ġ�� \n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("����Ȯ���� ���� �Է��Ͻÿ�: ");
			scanf("%d", &m);
			fprintf(fp, "%d", m);
			fclose(fp);

			if ((fp = fopen(C_name, "r")) == NULL) {
				fprintf(stderr, "�Է����� %s�� �� �� �����ϴ�.\n", C_name);
				exit(1);
			}
			fscanf(fp, "%d", &score);
			Sort_confirmed(datalist, SCALE); //[���׸� 2] �Լ� ���
			printf("%s�� ����Ȯ���ڴ� ", C_name);
			compare_confirmedData(datalist, score, SCALE); //[���׸� 2] �Լ� ���
			break;
		case 2:
			printf("����� ���� �Է��Ͻÿ�: ");
			scanf("%d", &m);
			fprintf(fp, "%d", m);
			fclose(fp);

			if ((fp = fopen(C_name, "r")) == NULL) {
				fprintf(stderr, "�Է����� %s�� �� �� �����ϴ�.\n", C_name);
				exit(1);
			}
			fscanf(fp, "%d", &score);
			Sort_dead(datalist, SCALE); //[���׸� 2] �Լ� ���
			printf("%s�� ����ڴ� ", C_name);
			compare_deadData(datalist, score, SCALE); //[���׸� 2] �Լ� ���
			break;
		case 3:
			printf("��ġ�� ���� �Է��Ͻÿ�: ");
			scanf("%d", &m);
			fprintf(fp, "%d", m);
			fclose(fp);

			if ((fp = fopen(C_name, "r")) == NULL) {
				fprintf(stderr, "�Է����� %s�� �� �� �����ϴ�.\n", C_name);
				exit(1);
			}
			fscanf(fp, "%d", &score);
			Sort_recovered(datalist, SCALE); //[���׸� 2] �Լ� ���
			printf("%s�� ��ġ�ڴ� ", C_name);
			compare_recoveredData(datalist, score, SCALE); //[���׸� 2] �Լ� ���
			break;
		default:
			printf("�ùٸ��� ���� �Է°��Դϴ�.\n");
			break;
		}
		printf("\n");
		break;
		}



		//�����ͼ¿��� ���ϴ� ������ ������� ��ġ���� ���ϴ� �κ�
		case 3:
			printf("�̰��� ����ڰ� ���ϴ� ������ Covid-19�� �����, ��ġ���� �����ϴ� �����Դϴ�.\n");
			printf("��ȸ�� ���ϴ� ������ ��ȣ�� �Է��Ͻÿ�.\n<�Է°��� ���� ���>\n ");
			for (int i = 0; i < SCALE; i++) {
				printf("%d. %s  ", i + 1, datalist[i].country);
			}
			printf(": ");
			scanf("%d", &m);
			printf("%s�� Covid-19\n",datalist[m-1].country);
			print_ratio_data(datalist[m - 1].confirmed, datalist[m - 1].dead, datalist[m-1].recovered, m - 1); //[���׸� 2] �Լ� ���
			
			
			break;


		default:
			break;
		}


		//GOTO ������ �̿��� ���α׷� ����� �ڵ�
		int q;
		printf("����Ͻðڽ��ϱ�?( Y(1) / N(2) ): ");
		scanf("%d", &q);
		if (q == 2) {
			return 0;
		}
		else if(q ==1) {
			goto AAA;
		}
		else
		{
			printf("�߸��� �Է��Դϴ�. ���α׷��� �����մϴ�\n");
		}
	
	return 0;
}