#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[100];
    char category[100];
    int available;
} Book;

Book library[MAX_BOOKS];
int numBooks = 0;

void addBook();
void searchBooks();
void searchByCategory();
void searchByAuthor();
void searchByTitle();
void borrowBook();
void returnBook();
void saveBooksToFile();
void loadBooksFromFile();

int main() {
     // 从文件加载图书信息
    loadBooksFromFile();
    int choice;

    do {
        printf("\n------ 图书管理系统 ------\n");
        printf("1. 录入书籍\n");
        printf("2. 查找书籍\n");
        printf("3. 借阅书籍\n");
        printf("4. 归还书籍\n");
        printf("0. 退出\n");
        printf("请输入你的选择：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 0:
                printf("感谢使用图书管理系统，再见！\n");
                break;
            default:
                printf("无效的选择，请重试。\n");
                break;
        }
    } while (choice != 0);
      
       // 保存图书信息到文件
    saveBooksToFile();

    return 0;
}

void addBook() {
    printf("\n------ 录入书籍 ------\n");

    printf("请输入书名：");
    scanf(" %[^\n]s", library[numBooks].title);

    printf("请输入作者名：");
    scanf(" %[^\n]s", library[numBooks].author);

    printf("请选择分类：\n");
    printf("1. 数学类\n");
    printf("2. 物理类\n");
    printf("3. 计算机类\n");
    printf("4. 工程类\n");
    printf("5. 经济类\n");
    printf("6. 生物类\n");
    printf("7. 化学类\n");
    printf("8. 文学类\n");
    printf("9. 语言类\n");
    printf("请输入你的选择（用空格分隔多个分类）：");

    int categoryChoice;
    char category[100] = "";
    do {
        scanf("%d", &categoryChoice);
        switch (categoryChoice) {
            case 1:
                strcat(category, "数学类 ");
                break;
            case 2:
                strcat(category, "物理类 ");
                break;
            case 3:
                strcat(category, "计算机类 ");
                break;
            case 4:
                strcat(category, "工程类 ");
                break;
            case 5:
                strcat(category, "经济类 ");
                break;
            case 6:
                strcat(category, "生物类 ");
                break;
            case 7:
                strcat(category, "化学类 ");
                break;
            case 8:
                strcat(category, "文学类 ");
                break;
            case 9:
                strcat(category, "语言类 ");
                break;
            default:
                printf("无效的选择，请重试。\n");
                break;
        }
    } while (categoryChoice < 1 || categoryChoice > 9);
    strcpy(library[numBooks].category, category);

    library[numBooks].available = 1;

    printf("书籍录入成功！\n");
    numBooks++;
}

void searchBooks() {
    int searchChoice;

    printf("\n------ 查找书籍 ------\n");
    printf("请选择查找方式：\n");
    printf("1. 按分类查找\n");
    printf("2. 按作者查找\n");
    printf("3. 按书名查找\n");
    printf("请输入你的选择：");
    scanf("%d", &searchChoice);

    switch (searchChoice) {
        case 1:
            searchByCategory();
            break;
        case 2:
            searchByAuthor();
            break;
        case 3:
            searchByTitle();
            break;
        default:
            printf("无效的选择，请重试。\n");
            break;
    }
}

void searchByCategory() {
    char searchCategory[100];
    int found = 0;
    printf("请选择分类：\n");
    printf(" 数学类\n");
    printf(" 物理类\n");
    printf(" 计算机类\n");
    printf(" 工程类\n");
    printf(" 经济类\n");
    printf(" 生物类\n");
    printf(" 化学类\n");
    printf(" 文学类\n");
    printf(" 语言类\n");
    printf("请输入要查找的分类：");
    scanf("%s", searchCategory);

    for (int i = 0; i < numBooks; i++) {
        if (strstr(library[i].category, searchCategory) != NULL) {
            printf("书名：%s\n", library[i].title);
            printf("作者：%s\n", library[i].author);
            printf("分类：%s\n", library[i].category);
            printf("可借阅：%s\n", library[i].available ? "是" : "否");
            found = 1;
        }
    }

    if (!found) {
        printf("未找到符合条件的书籍。\n");
    }
}

void searchByAuthor() {
    char searchAuthor[100];
    int found = 0;

    printf("请输入要查找的作者名：");
    scanf(" %[^\n]s", searchAuthor);

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].author, searchAuthor) == 0) {
            printf("书名：%s\n", library[i].title);
            printf("作者：%s\n", library[i].author);
            printf("分类：%s\n", library[i].category);
            printf("可借阅：%s\n", library[i].available ? "是" : "否");
            found = 1;
        }
    }

    if (!found) {
        printf("未找到符合条件的书籍。\n");
    }
}

void searchByTitle() {
    char searchTitle[100];
    int found = 0;

    printf("请输入要查找的书名：");
    scanf(" %[^\n]s", searchTitle);

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("书名：%s\n", library[i].title);
            printf("作者：%s\n", library[i].author);
            printf("分类：%s\n", library[i].category);
            printf("可借阅：%s\n", library[i].available ? "是" : "否");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("未找到符合条件的书籍。\n");
    }
}

void borrowBook() {
    printf("\n------ 借阅书籍 ------\n");

    char searchTitle[100];
    int found = 0;

    printf("请输入要借阅的书名：");
    scanf(" %[^\n]s", searchTitle);

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            if (library[i].available) {
                library[i].available = 0;
                printf("借阅成功！\n");
            } else {
                printf("抱歉，该书已被借出。\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("未找到要借阅的书籍。\n");
    }
}

   void returnBook() {
    printf("\n------ 归还书籍 ------\n");

    char searchTitle[100];
    int found = 0;

    printf("请输入要归还的书名：");
    scanf(" %[^\n]s", searchTitle);

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            if (!library[i].available) {
                library[i].available = 1;
                printf("归还成功！\n");
            } else {
                printf("该书未借出。\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("未找到要归还的书籍。\n");
    }
      void saveBooksToFile() {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("无法打开文件。\n");
        return;
    }

    for (int i = 0; i < numBooks; i++) {
        fprintf(file, "%s\n", library[i].title);
        fprintf(file, "%s\n", library[i].author);
        fprintf(file, "%s\n", library[i].category);
        fprintf(file, "%d\n", library[i].available);
    }

    fclose(file);
}

void loadBooksFromFile() {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("无法打开文件。\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        strcpy(library[numBooks].title, line);
        fgets(line, sizeof(line), file);
        strcpy(library[numBooks].author, line);
        fgets(line, sizeof(line), file);
        strcpy(library[numBooks].category, line);
        fgets(line, sizeof(line), file);
        library[numBooks].available = atoi(line);

        numBooks++;
    }

    fclose(file);
}
