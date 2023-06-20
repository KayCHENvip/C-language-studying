#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PRODUCTS 100
#define MAX_CART_ITEMS 100

struct Product {
    char name[100];
    float price;
    int quantity;
};

struct User {
    char username[100];
    char password[100];
};

struct CartItem {
    struct Product product;
    int quantity;
};

struct Cart {
    struct CartItem items[MAX_CART_ITEMS];
    int count;
};

struct User users[MAX_USERS];
struct Product products[MAX_PRODUCTS];
struct Cart cart;

int userCount = 0;
int productCount = 0;

void registerUser() {
    printf("=== 注册 ===\n");
    char username[100];
    char password[100];
    
    // 输入用户名和密码
    printf("请输入用户名: ");
    scanf("%s", username);
    printf("请输入密码: ");
    scanf("%s", password);
    
    // 检查用户名是否已存在
    for (int i = 0; i < userCount; i++)  {
         if (strcmp(users[i].username, username) == 0) {
            printf("用户名已存在。注册失败。\n");
            return;
        }
    }
    
    // 将新用户添加到用户数组中
    if (userCount < MAX_USERS) {
        strcpy(users[userCount].username, username);
        strcpy(users[userCount].password, password);
        userCount++;
        printf("注册成功。\n");
    } else {
        printf("用户数量已达到上限。注册失败。\n");
    }
}

int loginUser() {
    printf("=== 登录 ===\n");
    char username[100];
    char password[100];
    
    // 输入用户名和密码
    printf("请输入用户名: ");
    scanf("%s", username);
    printf("请输入密码: ");
    scanf("%s", password);
    
    // 检查用户名和密码是否匹配
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("登录成功。\n");
            return i; // 返回登录用户的索引
        }
    }
    
    printf("无效的用户名或密码。请重新登录。\n");
    return -1; // 登录失败
}

void addProduct() {
    printf("=== 录入商品 ===\n");
    char name[100];
    float price;
	int quantity;
    
    // 输入商品信息
    printf("请输入商品名称: ");
    scanf("%s", name);
    printf("请输入商品价格: ");
    scanf("%f", &price);
	printf("请输入商品数目: ");
    scanf("%d", &quantity);
 
    
    // 将新商品添加到商品数组中
    if (productCount < MAX_PRODUCTS) {
        strcpy(products[productCount].name, name);
        products[productCount].price = price;
		products[productCount].quantity = quantity;
        productCount++;
        printf("商品添加成功。\n");
    } else {
        printf("商品数量已达到上限。无法添加商品。\n");
    }
}

void showProducts() {
    printf("=== 查看商品 ===\n");
    
    if (productCount == 0) {
        printf("暂无商品。\n");
    } else {
        printf("可用商品列表:\n");
        for (int i = 0; i < productCount; i++) {
          printf("%d. %s - ￥%.2f %d个\n", i + 1, products[i].name, products[i].price, products[i].quantity);

        }
    }
}

void showCartMenu() {
    printf("=== 购物车菜单 ===\n");
    printf("1. 添加商品到购物车\n");
    printf("2. 查看购物车\n");
    printf("3. 结账\n");
    printf("4. 返回上一级菜单\n");
    printf("请输入选项: ");
}

void addToCart(int productIndex, int quantity) {
    // 检查购物车是否已满
    if (cart.count >= MAX_CART_ITEMS) {
        printf("购物车已满。无法添加商品。\n");
        return;
    }
    
    // 检查商品索引是否有效
    if (productIndex < 0 || productIndex >= productCount) {
        printf("无效的商品索引。\n");
        return;
    }
    
    // 检查商品数量是否足够
    if (quantity <= 0) {
        printf("无效的商品数量。\n");
        return;
    }
    
    // 将商品添加到购物车
    struct Product product = products[productIndex];
    struct CartItem item;
    item.product = product;
    item.quantity = quantity;
    cart.items[cart.count] = item;
    cart.count++;
    
    printf("商品已添加到购物车。\n");
}

void viewCart() {
    printf("=== 查看购物车 ===\n");
    
    if (cart.count == 0) {
        printf("购物车为空。\n");
    } else {
        printf("购物车中的商品:\n");
        for (int i = 0; i < cart.count; i++) {
            struct CartItem item = cart.items[i];
            printf("%d. %s - ￥%.2f - 数量: %d\n", i + 1, item.product.name, item.product.price, item.quantity);
        }
    }
}

void checkout() {
    printf("=== 结账 ===\n");
    
    if (cart.count == 0) {
        printf("购物车为空。\n");
        return;
    }
    
    float total = 0;
    
    printf("购物车中的商品:\n");
    for (int i = 0; i < cart.count; i++) {
        struct CartItem item = cart.items[i];
        printf("%d. %s - ￥%.2f - 数量: %d\n", i + 1, item.product.name, item.product.price, item.quantity);
        total += item.product.price * item.quantity;
    }
    
    printf("总计金额: ￥%.2f\n", total);
    
    // 结账完成后清空购物车
    cart.count = 0;
}

void mainMenu() {
    int loggedInUserIndex = -1; // 当前登录用户的索引
    
    while (1) {
        printf("\n=== 主菜单 ===\n");
        printf("1. 注册\n");
        printf("2. 登录\n");
        printf("3. 退出\n");
        printf("请输入选项: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loggedInUserIndex = loginUser();
                if (loggedInUserIndex == -1) {
                    continue; // 登录失败，回到主菜单
                }
                break;
            case 3:
                printf("感谢使用，再见！\n");
                return; // 退出程序
            default:
                printf("无效的选项，请重新输入。\n");
                break;
        }
        
        while (loggedInUserIndex != -1) {
            printf("\n=== 商品菜单 ===\n");
            printf("1. 查看商品\n");
            printf("2. 录入商品\n");
            printf("3. 购物车\n");
            printf("4. 退出登录\n");
            printf("请输入选项: ");
            
            scanf("%d", &choice);
            
            switch (choice) {
                case 1:
                    showProducts();
                    break;
                case 2:
                    if (loggedInUserIndex != -1) {
                        addProduct();
                    } else {
                        printf("请先登录。\n");
                    }
                    break;
                case 3:
                    while (1) {
                        showCartMenu();
                        scanf("%d", &choice);
                        
                        switch (choice) {
                            case 1: {
                                if (loggedInUserIndex != -1) {
                                    int productIndex, quantity;
                                    printf("请输入要添加到购物车的商品索引: ");
                                    scanf("%d", &productIndex);
                                    printf("请输入要添加到购物车的商品数量: ");
                                    scanf("%d", &quantity);
                                    addToCart(productIndex - 1, quantity);
                                } else {
                                    printf("请先登录。\n");
                                }
                                break;
                            }
                            case 2:
                                viewCart();
                                break;
                            case 3:
                                checkout();
                                break;
                            case 4:
                                break;
                            default:
                                printf("无效的选项，请重新输入。\n");
                                break;
                        }
                        
                        if (choice == 4) {
                            break;
                        }
                    }
                    break;
                case 4:
                    printf("已退出登录。\n");
                    loggedInUserIndex = -1; // 重置登录用户的索引
                    break;
                default:
                    printf("无效的选项，请重新输入。\n");
                    break;
            }
        }
    }
}


void loadProductQuantities() {
    FILE* quantitiesFile = fopen("E:\\Files\\vscproject\\3\\quantities.txt", "r");
    if (quantitiesFile != NULL) {
        for (int i = 0; i < productCount; i++) {
            fscanf(quantitiesFile, "%d", &products[i].quantity);
        }
        fclose(quantitiesFile);
    }
}

void saveProductQuantities() {
    FILE* quantitiesFile = fopen("E:\\Files\\vscproject\\3\\quantities.txt", "w");
    if (quantitiesFile != NULL) {
        for (int i = 0; i < productCount; i++) {
            fprintf(quantitiesFile, "%d\n", products[i].quantity);
        }
        fclose(quantitiesFile);
    }
}


int main() {
    // 从文件中加载用户数据和商品数据
    FILE* usersFile = fopen("E:\\Files\\vscproject\\3\\users.txt", "r");
    FILE* productsFile = fopen("E:\\Files\\vscproject\\3\\products.txt", "r");
    
    if (usersFile != NULL && productsFile != NULL) {
        // 读取用户数据
        fscanf(usersFile, "%d", &userCount);
        for (int i = 0; i < userCount; i++) {
            fscanf(usersFile, "%s %s", users[i].username, users[i].password);
        }
        
        // 读取商品数据
        fscanf(productsFile, "%d", &productCount);
        for (int j = 0; j < productCount; j++) {
            fscanf(productsFile, "%s %f", products[j].name, &products[j].price);
        }
        
        // 关闭文件
        fclose(usersFile);
        fclose(productsFile);
    }
    
    // 加载商品数量
    loadProductQuantities();
    
    mainMenu();
    
    // 将用户数据和商品数据保存到文件
    usersFile = fopen("E:\\Files\\vscproject\\3\\users.txt", "w");
    productsFile = fopen("E:\\Files\\vscproject\\3\\products.txt", "w");
    
    if (usersFile != NULL && productsFile != NULL) {
        // 保存用户数据
        fprintf(usersFile, "%d\n", userCount);
        for (int i = 0; i < userCount; i++) {
            fprintf(usersFile, "%s %s\n", users[i].username, users[i].password);
        }
        
        // 保存商品数据
        fprintf(productsFile, "%d\n", productCount);
        for (int j = 0; j < productCount; j++) {
            fprintf(productsFile, "%s %.2f\n", products[j].name, products[j].price);
        }
        
        // 关闭文件
        fclose(usersFile);
        fclose(productsFile);
    }
    
    // 保存商品数量
    saveProductQuantities();
    
    return 0;
}
