#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char name[30];
    char phone[20];
} Contact;

typedef struct {
    Contact contacts[MAX];
    int size;
} PhoneBook;

void addContact(PhoneBook* pb) {
    if (pb->size >= MAX) {
        printf("��ȭ��ȣ�ΰ� ���� á���ϴ�.\n");
        return;
    }

    printf("�̸�: ");
    scanf("%s", pb->contacts[pb->size].name);
    printf("��ȭ��ȣ: ");
    scanf("%s", pb->contacts[pb->size].phone);
    pb->size++;
    printf("����ó�� �߰��Ǿ����ϴ�.\n");
}

void deleteContact(PhoneBook* pb) {
    char name[30];
    printf("������ �̸�: ");
    scanf("%s", name);
    int found = 0;

    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->size - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->size--;
            found = 1;
            printf("����ó�� �����Ǿ����ϴ�.\n");
            break;
        }
    }
    if (!found)
        printf("����ó�� ã�� �� �����ϴ�.\n");
}

void searchContact(PhoneBook* pb) {
    char name[30];
    printf("�˻��� �̸�: ");
    scanf("%s", name);
    int found = 0;

    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("�̸�: %s, ��ȭ��ȣ: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            found = 1;
        }
    }
    if (!found)
        printf("����ó�� ã�� �� �����ϴ�.\n");
}

void printAllContacts(PhoneBook* pb) {
    if (pb->size == 0) {
        printf("��ȭ��ȣ�ΰ� ��� �ֽ��ϴ�.\n");
        return;
    }

    printf("��ü ����ó ���:\n");
    for (int i = 0; i < pb->size; i++) {
        printf("%d. �̸�: %s, ��ȭ��ȣ: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

int main() {
    PhoneBook pb;
    pb.size = 0;

    int choice;

    do {
        printf("\n1. ����ó �߰�\n2. ����ó ����\n3. ����ó �˻�\n4. ��ü ����ó ���\n0. ����\n");
        printf("�޴� ����: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addContact(&pb);
            break;
        case 2:
            deleteContact(&pb);
            break;
        case 3:
            searchContact(&pb);
            break;
        case 4:
            printAllContacts(&pb);
            break;
        case 0:
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �Է��Դϴ�.\n");
        }
    } while (choice != 0);

    return 0;
}
