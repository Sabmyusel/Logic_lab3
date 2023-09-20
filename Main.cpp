#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <windows.h>
#include "dop.h"

char find_el[256];

struct node *head = NULL, *last = NULL, *first = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;

struct node
{
	char inf[256];  // полезная информация
	int prior; // приоритет
	struct node* next; // ссылка на следующий элемент 
};


struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];
	int pr = 0;
	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
	scanf("%s", s);
	printf("Введите приоритет объекта: \n");   // вводим приоритет
	scanf("%d", &pr);
	if (*s == 0 || pr == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);
	p->prior = pr;
	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в список элемента (в конец)*/
void spstore(void)
{
	struct node* p = NULL, *srch = NULL, *prev = NULL;
	p = get_struct();
	dlinna++;
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // список уже есть
	{
		srch = head;
		while (p->prior > srch->prior && srch->next != NULL) {// поиск элемента с приоритетом, меньшим указанного
			prev = srch;
			srch = srch->next;
		}
		if (head == srch && p->prior <= srch->prior) {// если нужно добавить в начало списка
			p->next = head;
			head = p;
		}
		else if (p->prior > last->prior) {// если в конец
			last->next = p;
			last = p;
		}
		else {// если в середину
			prev->next = p;
			p->next = srch;
		}
	}
	return;
}


/* Просмотр содержимого списка. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
		return;
	}
	printf("Всего %d элементов:\n", dlinna);
	while (struc){
		printf("Имя - %s, приоритет - %d,\n", struc->inf, struc->prior);
		struc = struc->next;
	}
	return;
}

/* Поиск элемента по содержимому. */
struct node* find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
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

/* Удаление элемента по содержимому. */
void del(char* name)
{
	struct node* struc = head; // указатель, проходящий по списку установлен на начало списка
	struct node* prev;// указатель на предшествующий удаляемому элемент
	int flag = 0;      // индикатор отсутствия удаляемого элемента в списке

	if (head == NULL) // если голова списка равна NULL, то список пуст
	{
		printf("Список пуст\n");
		return;
	}

	if (strcmp(name, struc->inf) == 0) // если удаляемый элемент - первый
	{
		flag = 1;
		head = struc->next; // установливаем голову на следующий элемент
		free(struc);  // удаляем первый элемент
		struc = head; // устанавливаем указатель для продолжения поиска
		prev = NULL;
		dlinna--;
	}
	else
	{
		dlinna--;
		prev = struc;
		struc = struc->next;
	}

	while (struc) // проход по списку и поиск удаляемого элемента
	{
		if (strcmp(name, struc->inf) == 0) // если нашли, то
		{
			flag = 1;         // выставляем индикатор
			if (struc->next)  // если найденный элемент не последний в списке
			{
				prev->next = struc->next; // меняем указатели
				free(struc);		    // удаляем  элемент
				struc = prev->next; // устанавливаем указатель для продолжения поиска
			}
			else			// если найденный элемент последний в списке
			{
				last = prev;
				prev->next = NULL; // обнуляем указатель предшествующего элемента
				free(struc);	// удаляем  элемент
				return;
			}
		}
		else // если не нашли, то
		{
			prev = struc; // устанавливаем указатели для продолжения поиска
			struc = struc->next;
		}
	}

	if (flag == 0)				// если флаг = 0, значит нужный элемент не найден
	{
		printf("Элемент не найден\n");
		return;
	}	
}
void start() {
	bool close = false;
	int c = -1;
	struct node *f = NULL;
	while (!close) {
		do {
			printf("[1]Добавить элемент.\n[2]Просмотреть список.\n[3]Найти элемент.\n[4]Удалить элемент.\n\n\n[0]Назад.\n");
			scanf("%d", &c);
			system("cls");
		} while (c < 0 || c > 4);

		switch (c) {
		case 1:
			spstore();
			system("cls");
			break;
		case 2:
			review();
			system("pause");
			system("cls");
			break;
		case 3:
			printf("Введите название объекта, который хотите найти: \n");
			scanf("%s", find_el);
			f = find(find_el);
			if (f)
				printf("\nНайдено: \nИмя - %s, Приоритет - %d\n", f->inf, f->prior);
			else
				printf("Ничего не найдено\n");
			system("pause");
			system("cls");
			break;
		case 4:
			printf("Введите название объекта, который хотите удалить: \n");
			scanf("%s", find_el);
			del(find_el);
			printf("Объект удалён\n");
			system("pause");
			system("cls");
			break;
		case 0:
			close = true;
			break;
		}
	}
}
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int a = -1;
	bool stop = false;
	while (!stop) {
		do {
			printf("[1]Задание 1 - Очередь с приоритетом\n[2]Задание 2 - Очередь\n[3]Задание 3 - Стек\n\n\n[0]Выход.\n");
			scanf("%d", &a);
			system("cls");
		} while (a < 0 || a > 3);

		switch (a) {
		case 0:
			stop = true;
			break;
		case 1:
			start();
			break;
		case 2:
			queue();
			break;
		case 3:
			stack();
			break;
		}
	}

	return 0;
}
