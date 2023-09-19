#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char inf[256];  // полезная информация
	struct node* next; // ссылка на следующий элемент 
};

char Q_find_el[256];
struct node* Qhead = NULL, * Qlast = NULL;

struct node* Q_get_struct(void)
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

/* Последовательное добавление в очередь элемента (в начало)*/
void queue_push(void)
{
	struct node* p = NULL;
	p = Q_get_struct();
	if (Qhead == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		Qhead = p;
		Qlast = p;
	}
	else if (Qhead != NULL && p != NULL) // список уже есть, то вставляем в начало
	{
		p->next = Qhead;
		Qhead = p;
	}
	return;
}

/* Последовательное удаление из очереди (из конца)*/
void queue_pop() {
	struct node* sch = Qhead;

	if (Qhead == NULL) {
		printf("Очередь пуста...\n");
		system("pause");
		return;
	}

	if (sch != Qlast) {
		while (sch->next != Qlast) {
			sch = sch->next;
		}
		printf("Удаление : %s\n", Qlast->inf);
		free(Qlast);
		Qlast = sch;
		sch->next = NULL;
	}
	else {
		printf("Удаление : %s\n", Qhead->inf);
		free(Qhead);
		Qhead = NULL;
		Qlast = NULL;
	}
	system("pause");

	return;
}

/* Просмотр содержимого списка. */
void Qreview(void)
{
	struct node* struc = Qhead;
	if (Qhead == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		printf("Имя - %s, \n", struc->inf);
		struc = struc->next;
	}
	return;
}

/* Поиск элемента по содержимому. */
struct node* Q_find(char* name)
{
	struct node* struc = Qhead;
	if (Qhead == NULL)
	{
		printf("Список пуст\n");
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

void queue() {
	bool close = false;
	int c = -1;
	struct node* f = NULL;
	while (!close) {
		do {
			printf("[1]Добавить элемент\n[2]Просмотреть Очередь\n[3]Найти элемент\n[4]Удалить элемент из очереди\n\n\n[0]Назад.\n");
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
			printf("Введите название объекта, который хотите найти: \n");
			scanf("%s", Q_find_el);
			f = Q_find(Q_find_el);
			if (f)
				printf("\nНайдено: \nИмя - %s,\n", f->inf);
			else
				printf("Ничего не найдено\n");
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