#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define CUSTOMER_FILE "customer_information.txt"
#define VIDEO_FILE "video_information.txt"

int count = 0;
int videocount = 0;
int SelectMenu();
void Run();
void PrintALLCustomerInformation();
void PrintALLVideoInformation();
void CustomerRegist();
void VideoRegist();
void CustomerSearch();

int main(void)
{
	Run();
	return 0;
}

int SelectMenu()
{
	int i;
	printf("<Video rental management program>\n");
	printf("1. New Customer regisration\n");
	printf("2. Customer information inquiry\n");
	printf("3. View all customer information\n");
	printf("4. New Video registration\n");
	printf("5. View video information\n");
	printf("6. View full video information\n");
	printf("7. Rental\n");
	printf("8. Return\n");
	printf("0. Exit\n");

	scanf("%d", &i);

	return i;
}

void Run()
{
	int key;

	while ((key = SelectMenu()) != 0)
	{
		switch (key)
		{
		case 1:
			CustomerRegist();	break;
		case 2:
			CustomerSearch();	break;
		case 3:
			PrintALLCustomerInformation();	break;
		case 4:
			VideoRegist();					break;
		case 6:
			PrintALLVideoInformation();	break;
		default:
			break;
		}
	}
}

void PrintALLCustomerInformation()
{
	char ch;
	FILE *fp = fopen(CUSTOMER_FILE, "rt");
	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)	break;
		putchar(ch);
	}
	putchar('\n');
	fclose(fp);
}

void PrintALLVideoInformation()
{
	char ch;
	FILE *fp = fopen(VIDEO_FILE, "rt");
	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)	break;
		putchar(ch);
	}
	putchar('\n');
	fclose(fp);
}

void CustomerRegist()
{
	char name[32] = { NULL, }, statement[32] = {NULL, };
	char number[16] = { NULL, }, phonenumber[16] = { NULL, };
	FILE *fp = fopen(CUSTOMER_FILE, "at");
	count++;
	printf("INPUT NAME >> ");			scanf("%s", name);
	printf("INPUT STATEMENT >> ");		scanf("%s", statement);
	printf("INPUT NUMBER >> ");			scanf("%s", number);
	printf("INPUT PHONENUMBER >> ");	scanf("%s", phonenumber);
	fprintf(fp, "%d, %s, %s, %s, %s", count, name, number, phonenumber, statement);

	fclose(fp);
}

void VideoRegist()
{
	char name[32] = { NULL, }, genre[32] = { NULL, };
	char cost[16] = { NULL, };
	FILE *fp = fopen(CUSTOMER_FILE, "at");
	count++;
	printf("INPUT NAME >> ");			scanf("%s", name);
	printf("INPUT STATEMENT >> ");		scanf("%s", genre);
	printf("INPUT COST >> ");			scanf("%s", cost);
	fprintf(fp, "%d, %s, %s, 0", count, genre, cost);

	fclose(fp);
}

void CustomerSearch()
{
	FILE *fp = fopen(CUSTOMER_FILE, "rt");
	char str[1024];
	char search[32];
	printf("INPUT >> ");
	scanf("%s", search);
	while (1)
	{
		fgets(str, 1024, fp);
		if (str != EOF)	return;
		if ((strstr(str, search)) != NULL)
		{
			printf("%s", str);
			break;
		}
}
