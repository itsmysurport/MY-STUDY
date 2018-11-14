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
void VideoSearch();
void Rental();
void Re_turn();

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
			CustomerRegist();				break;
		case 2:
			CustomerSearch();				break;
		case 3:
			PrintALLCustomerInformation();	break;
		case 4:
			VideoRegist();					break;
		case 5:
			VideoSearch();					break;
		case 6:
			PrintALLVideoInformation();		break;
		case 7:
			Rental();						break;
		case 8:
			Re_turn();						break;
		default:
			break;
		}
	}
}

void PrintALLCustomerInformation()
{
	char ch;
	FILE *fp = fopen(CUSTOMER_FILE, "rt");
	rewind(fp);
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
	rewind(fp);
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
	fprintf(fp, "%d, %s, %s, %s, %s\n", count, name, number, phonenumber, statement);

	fclose(fp);
}

void VideoRegist()
{
	char name[32] = { NULL, }, genre[32] = { NULL, };
	char cost[16] = { NULL, };
	FILE *fp = fopen(VIDEO_FILE, "at");
	videocount++;
	printf("INPUT NAME >> ");			scanf("%s", name);
	printf("INPUT GENRE >> ");			scanf("%s", genre);
	printf("INPUT COST >> ");			scanf("%s", cost);
	fprintf(fp, "%d, %s, %s, %s, 0\n", videocount, name, genre, cost);

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
		if (str == EOF)	return;
		if ((strstr(str, search)) != NULL)
		{
			printf("%s", str);
			break;
		}
	}
}

void VideoSearch()
{
	FILE *fp = fopen(VIDEO_FILE, "rt");
	char str[1024];
	char search[32];
	printf("INPUT >> ");
	scanf("%s", search);
	while (1)
	{
		fgets(str, 1024, fp);
		if (str == EOF)	return;
		if ((strstr(str, search)) != NULL)
		{
			printf("%s", str);
			break;
		}
	}
}

void Rental()
{
	int nVideo, nCustomer, i=0, value;
	char name[32] = { NULL, }, genre[32] = { NULL, }, cost[16] = { NULL, }, buf[1024], *fon = "1";
	PrintALLVideoInformation();
	printf("Enter video number to Rent : ");
	scanf("%d", &nVideo);
	PrintALLCustomerInformation();
	printf("Please enter customer number : ");
	scanf("%d", &nCustomer);
	FILE *fp = fopen(VIDEO_FILE, "rt");
	rewind(fp);
	for (i = 0; i< nVideo; i++)
	{
		memset(buf, 0, 1024);
		fgets(buf, 1024, fp);
	}
	fseek(fp, -3000, SEEK_CUR);
	fwrite(fon, strlen(fon), 4, fp);

}

void Re_turn()
{
	int nVideo, nCustomer, i = 0, value;
	char name[32] = { NULL, }, genre[32] = { NULL, }, cost[16] = { NULL, }, buf[1024], *fon = "1";
	PrintALLVideoInformation();
	printf("Enter video number to Return : ");
	scanf("%d", &nVideo);
	PrintALLCustomerInformation();
	FILE *fp = fopen(VIDEO_FILE, "rt");
	rewind(fp);
	for (i = 0; i< nVideo; i++)
	{
		memset(buf, 0, 1024);
		fgets(buf, 1024, fp);
	}
	fseek(fp, -3000, SEEK_CUR);
	fwrite(fon, strlen(fon), 4, fp);
}
