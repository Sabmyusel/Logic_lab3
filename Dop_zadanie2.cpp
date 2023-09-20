#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char inf[256];  // �������� ����������
	struct node* next; // ������ �� ��������� ������� 
};

char S_find_el[256];
struct node* Shead = NULL, * Slast = NULL;

struct node* S_get_struct(void)
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

/* ���������������� ���������� � ���� �������� (� �������)*/
void stack_push(void)
{
	struct node* p = NULL;
	p = S_get_struct();
	if (Shead == NULL && p != NULL)	// ���� ������ ���, �� ������������� ������ ������
	{
		Shead = p;
		Slast = p;
	}
	else if (Shead != NULL && p != NULL) // ������ ��� ����, �� ��������� � �������
	{
		p->next = Shead;
		Shead = p;
	}
	return;
}

/* ���������������� �������� �� ����� (�� �������)*/
void stack_pop() {

	if (Shead == NULL) {
		printf("���� ����...\n");
		system("pause");
		return;
	}
	struct node* sch = Shead->next;

	printf("�������� : %s\n", Shead->inf);
		
	free(Shead);
	Shead = sch;

	system("pause");

	return;
}

/* �������� ����������� ������. */
void Sreview(void)
{
	struct node* struc = Shead;
	if (Shead == NULL)
	{
		printf("���� ����\n");
	}
	while (struc)
	{
		printf("��� - %s, \n", struc->inf);
		struc = struc->next;
	}
	return;
}

/* ����� �������� �� �����������. */
struct node* S_find(char* name)
{
	struct node* struc = Shead;
	if (Shead == NULL)
	{
		printf("���� ����\n");
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

void stack() {
	bool close = false;
	int c = -1;
	struct node* f = NULL;
	while (!close) {
		do {
			printf("[1]�������� �������\n[2]����������� ����\n[3]����� �������\n[4]������� ������� �� �����\n\n\n[0]�����.\n");
			scanf("%d", &c);
			system("cls");
		} while (c < 0 || c > 4);

		switch (c) {
		case 1:
			stack_push();
			system("cls");
			break;
		case 2:
			Sreview();
			system("pause");
			system("cls");
			break;
		case 3:
			printf("������� �������� �������, ������� ������ �����: \n");
			scanf("%s", S_find_el);
			f = S_find(S_find_el);
			if (f)
				printf("\n�������: \n��� - %s, ", f->inf);
			else
				printf("������ �� �������\n");
			system("pause");
			system("cls");
			break;
		case 4:
			stack_pop();
			system("cls");
			break;
		case 0:
			close = true;
			break;
		}
	}
}