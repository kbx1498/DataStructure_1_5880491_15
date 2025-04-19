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
        printf("전화번호부가 가득 찼습니다.\n");
        return;
    }

    printf("이름: ");
    scanf("%s", pb->contacts[pb->size].name);
    printf("전화번호: ");
    scanf("%s", pb->contacts[pb->size].phone);
    pb->size++;
    printf("연락처가 추가되었습니다.\n");
}

void deleteContact(PhoneBook* pb) {
    char name[30];
    printf("삭제할 이름: ");
    scanf("%s", name);
    int found = 0;

    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->size - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->size--;
            found = 1;
            printf("연락처가 삭제되었습니다.\n");
            break;
        }
    }
    if (!found)
        printf("연락처를 찾을 수 없습니다.\n");
}

void searchContact(PhoneBook* pb) {
    char name[30];
    printf("검색할 이름: ");
    scanf("%s", name);
    int found = 0;

    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("이름: %s, 전화번호: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            found = 1;
        }
    }
    if (!found)
        printf("연락처를 찾을 수 없습니다.\n");
}

void printAllContacts(PhoneBook* pb) {
    if (pb->size == 0) {
        printf("전화번호부가 비어 있습니다.\n");
        return;
    }

    printf("전체 연락처 목록:\n");
    for (int i = 0; i < pb->size; i++) {
        printf("%d. 이름: %s, 전화번호: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

int main() {
    PhoneBook pb;
    pb.size = 0;

    int choice;

    do {
        printf("\n1. 연락처 추가\n2. 연락처 삭제\n3. 연락처 검색\n4. 전체 연락처 출력\n0. 종료\n");
        printf("메뉴 선택: ");
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
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 입력입니다.\n");
        }
    } while (choice != 0);

    return 0;
}
