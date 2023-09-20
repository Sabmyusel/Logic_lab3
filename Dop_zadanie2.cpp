#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char inf[256];  // полезная информация
	struct node* next; // ссылка на следующий элемент 
};

char S_find_el[256];
struct node* Shead = NULL, * Slast = NULL;

struct node* S_get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
	scanf("%s", s);
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в стек элемента (в вершину)*/
void stack_push(void)
{
	struct node* p = NULL;
	p = S_get_struct();
	if (Shead == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		Shead = p;
		Slast = p;
	}
	else if (Shead != NULL && p != NULL) // список уже есть, то вставляем в вершину
	{
		p->next = Shead;
		Shead = p;
	}
	return;
}

/* Последовательное удаление из стека (из вершины)*/
void stack_pop() {

	if (Shead == NULL) {
		printf("Стек пуст...\n");
		system("pause");
		return;
	}
	struct node* sch = Shead->next;

	printf("Удаление : %s\n", Shead->inf);
		
	free(Shead);
	Shead = sch;

	system("pause");

	return;
}

/* Просмотр содержимого списка. */
void Sreview(void)
{
	struct node* struc = Shead;
	if (Shead == NULL)
	{
		printf("Стек пуст\n");
	}
	while (struc)
	{
		printf("Имя - %s, \n", struc->inf);
		struc = struc->next;
	}
	return;
}

/* Поиск элемента по содержимому. */
struct node* S_find(char* name)
{
	struct node* struc = Shead;
	if (Shead == NULL)
	{
		printf("Стек пуст\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	printf("Элемент не найден\n");
	return NULL;
}

void stack() {
	bool close = false;
	int c = -1;
	struct node* f = NULL;
	while (!close) {
		do {
			printf("[1]Добавить элемент\n[2]Просмотреть стек\n[3]Найти элемент\n[4]Удалить элемент из стека\n\n\n[0]Назад.\n");
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
			printf("Введите название объекта, который хотите найти: \n");
			scanf("%s", S_find_el);
			f = S_find(S_find_el);
			if (f)
				printf("\nНайдено: \nИмя - %s, ", f->inf);
			else
				printf("Ничего не найдено\n");
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