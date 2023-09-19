#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char inf[256];  // �������� ����������
	struct node* next; // ������ �� ��������� ������� 
};

char Q_find_el[256];
struct node* Qhead = NULL, * Qlast = NULL;

struct node* Q_get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // �������� ������ ��� ����� ������� ������
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}

	printf("������� �������� �������: \n");   // ������ ������
	scanf("%s", s);
	if (*s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// ���������� ��������� �� ��������� �������
}

/* ���������������� ���������� � ������� �������� (� ������)*/
void queue_push(void)
{
	struct node* p = NULL;
	p = Q_get_struct();
	if (Qhead == NULL && p != NULL)	// ���� ������ ���, �� ������������� ������ ������
	{
		Qhead = p;
		Qlast = p;
	}
	else if (Qhead != NULL && p != NULL) // ������ ��� ����, �� ��������� � ������
	{
		p->next = Qhead;
		Qhead = p;
	}
	return;
}

/* ���������������� �������� �� ������� (�� �����)*/
void queue_pop() {
	struct node* sch = Qhead;

	if (Qhead == NULL) {
		printf("������� �����...\n");
		system("pause");
		return;
	}

	if (sch != Qlast) {
		while (sch->next != Qlast) {
			sch = sch->next;
		}
		printf("�������� : %s\n", Qlast->inf);
		free(Qlast);
		Qlast = sch;
		sch->next = NULL;
	}
	else {
		printf("�������� : %s\n", Qhead->inf);
		free(Qhead);
		Qhead = NULL;
		Qlast = NULL;
	}
	system("pause");

	return;
}

/* �������� ����������� ������. */
void Qreview(void)
{
	struct node* struc = Qhead;
	if (Qhead == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		printf("��� - %s, \n", struc->inf);
		struc = struc->next;
	}
	return;
}

/* ����� �������� �� �����������. */
struct node* Q_find(char* name)
{
	struct node* struc = Qhead;
	if (Qhead == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	printf("������� �� ������\n");
	return NULL;
}

void queue() {
	bool close = false;
	int c = -1;
	struct node* f = NULL;
	while (!close) {
		do {
			printf("[1]�������� �������\n[2]����������� �������\n[3]����� �������\n[4]������� ������� �� �������\n\n\n[0]�����.\n");
			scanf("%d", &c);
			system("cls");
		} while (c < 0 || c > 4);

		switch (c) {
		case 1:
			queue_push();
			system("cls");
			break;
		case 2:
			Qreview();
			system("pause");
			system("cls");
			break;
		case 3:
			printf("������� �������� �������, ������� ������ �����: \n");
			scanf("%s", Q_find_el);
			f = Q_find(Q_find_el);
			if (f)
				printf("\n�������: \n��� - %s,\n", f->inf);
			else
				printf("������ �� �������\n");
			system("pause");
			system("cls");
			break;
		case 4:
			queue_pop();
			system("cls");
			break;
		case 0:
			close = true;
			break;
		}
	}
}