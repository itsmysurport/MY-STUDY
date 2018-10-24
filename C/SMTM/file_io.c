// Compile on GCC

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_DEPARTMENT_LEN 20
#define MAX_ADDRESS_LEN 128

#define DEF_FNAME "data.cau"

typedef struct _Building {
	char name[MAX_NAME_LEN];
	char departmentName[2][MAX_DEPARTMENT_LEN];
	char address[MAX_ADDRESS_LEN];
} Building;

#define MAX_BUILDING 50
Building* building[MAX_BUILDING] = { NULL, };

void Init();
void Exit();
void Run();

void AddBuilding();
void AddDepartmentName();
void AddAddress();
void Rename();
void Delete();
void Search();
void ViewAll();

int SelectMenu();

int main() {
	Init();
	Run();
	Exit();
	return 0;
}

void Init() {
	FILE *fp = fopen(DEF_FNAME, "r");

	if (fp) {
		int i;

		while (1) {
			if (fread(&i, sizeof(int), 1, fp) < 1)
				break;

			building[i] = malloc(sizeof(Building));
			fread(building[i], sizeof(Building), 1, fp);
		}

		fclose(fp);
	}
}

void Exit() {
	FILE *fp = fopen(DEF_FNAME, "w");
	int i;

	for (i = 0; i < MAX_BUILDING; i++) {
		if (building[i]) {
			fwrite(&i, sizeof(int), 1, fp);
			fwrite(&building[i], sizeof(Building), 1, fp);

			free(building[i]);
			building[i] = NULL;
		}
	}
}

void Run() {
	int key;

	while ((key = SelectMenu()) != 8) {
		switch (key) {
		case 1: AddBuilding();        break;
		case 2: AddDepartmentName();  break;
		case 3: AddAddress();         break;
		case 4: Rename();             break;
		case 5: Delete();             break;
		case 6: Search();             break;
		case 7: ViewAll();            break;
		default: break;
		}
	}
}

void AddBuilding() {
	int num;
	char buf[MAX_NAME_LEN];

	printf("Building number to add(1~%d): ", MAX_BUILDING);
	scanf("%d", &num);

	printf("Name: ");
	scanf("%s", buf);

	building[num] = malloc(sizeof(Building));
	strcpy(building[num]->name, buf);
}

void AddDepartmentName() {
	char buf[MAX_DEPARTMENT_LEN];
	int index, i;

	printf("Building number to enter Department(1~%d): ", MAX_BUILDING);
	scanf("%d", &index);
	getchar();
	for (i = 0; i < 2; i++) {
		printf("Department Name : ");
		gets(buf);

		if (!i && !strcmp(buf, "")) {
			i--;
			continue;
		}

		strcpy(building[index]->departmentName[i], buf);
	}
}

void AddAddress() {
	char buf[MAX_ADDRESS_LEN];
	int index;

	printf("Building number to enter Address(1~%d): ", MAX_BUILDING);
	scanf("%d", &index);

	printf("Address Name : ");
	scanf("%s", buf);

	strcpy(building[index]->address, buf);
}

void Rename() {
	int index, i;

	printf("Building number to enter (1~%d): ", MAX_BUILDING);
	scanf("%d", &index);

	printf("If you want change department. 1, address. 2 ");
	scanf("%d", &i);

	if (i == 1) {
		char buf[MAX_DEPARTMENT_LEN];

		printf("Search Department Name : ");
		scanf("%s", buf);

		for (i = 0; i < 2; i++) {
			if (!strcmp(building[index]->departmentName[i], buf)) {
				printf("New department Name : ");
				scanf("%s", buf);

				strcpy(building[index]->departmentName[i], buf);
				return;
			}
		}
	}

	else {
		char buf[MAX_ADDRESS_LEN];

		printf("New Address Name : ");
		scanf("%s", buf);

		strcpy(building[index]->address, buf);
		return;
	}
}

void Delete() {
	int num;
	printf("Building number to delete(1~%d): ", MAX_BUILDING);
	scanf("%d", &num);

	building[num] = NULL;
	// strcpy(building[num], NULL);
}

void Search() {
	int i;
	char buf[MAX_DEPARTMENT_LEN];
	// printf("%s ", ((building[1])->departmentName[1]));
	printf("Input department to find Buliding ");
	scanf("%s", buf);
	for (i = 1; i < MAX_BUILDING + 1; i++) {
		if ((!strcmp(building[i]->departmentName[0], buf)) || (!strcmp(building[i]->departmentName[1], buf))) {
			printf("Building : %s\n", building[i]->name);
			return;
		}
	}
}

void ViewAll() {
	int temp = 0;

	for (int i = 0; i < MAX_BUILDING; i++) {
		if (!building[i]) continue;

		printf("num: %d\n", i);
		printf("name: %s\n", building[i]->name);

		for (temp = 0; temp < 2; temp++) {
			printf("departmentName: %s\n", building[i]->departmentName[temp]);
		}

		printf("address: %s\n", building[i]->address);
	}
}

int SelectMenu() {
	int i;
	printf("1. AddBuilding || 2. AddDepartmentName || 3. AddAddress || 4. Rename || 5. Delete || 6. Search || 7. ViewAll\n");
	scanf("%d", &i);
	return i;
}
