#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define N 100

//done
typedef struct {
    int num;
    char foodname[20];
    int money;
} caidan;
//done
typedef struct {
    int num;
    char name[20];
    char  sec[20];
    char VIP;
} customer;
//done
typedef struct {
    char name[20];
    long sec;
} master;
typedef struct {
    customer ID;
    int num;
    caidan food[20];
    double all_money;
} diandan;

int inputnum();

void hello();

void masterhello();

void master_doing();

void anlienhello();

void customerhello1();

void customer_doing();

void customer_doing_net();

void customercreate();

int customerchazhao(customer find);

void customer_write(customer inp);

caidan searchfood(int a);

void caidancreate();

void caidan_write(caidan inp);

void caidan_master();

void showcaidan();

void removefood(int q);

void customer_manage();

void showcustomer();

void removecustomer(char name1[]);

int customervipchazhao(customer find, customer root[]);

void customer_doing_diancan(customer inputname);

void customer_doing_diancan_add(customer inputname);

int searchfod(int a);

void food_write(caidan diandan[], int i);

void customer_doing_diancan_delete(customer inputname);

void customer_doing_diancan_delete_remove(int a);

void customer_doing_diancan_view();

void customer_doing1(customer inputname);

void customer_doing_jiezhang(customer inputname);

void master_doing_incomeview();

int main() {
    hello();
}

//这是第一个欢迎界面,done
void hello() {
    int i;
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    printf("                   欢迎进入bingo餐厅！                 \n");
    printf("                    请问您是什么身份                     \n");
    printf("                      1 MASTER\n");
    printf("                      2 顾客\n");
    printf("                      3 外星人\n");
    printf("                      0 退出\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    while (1)
    {
        i = inputnum();
        switch (i) {
            case 1: {
                masterhello();
                break;
            }
            case 2: {
                customerhello1();
                break;
            }
            case 3: {
                anlienhello();
                break;
            }
            case 0:
            {
                exit(0);
            }
            default:
            {
                printf("error");
            }
        }
    }
}

//这是管理员欢迎界面,done
void masterhello() {
    int i;
    int flag = 0;
    master Name[2] = {
            {"bingoner", 123456},
            {"admin",    000000}
    };
    master inputname;
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    A:
    printf("               尊敬的master，请输入您的账号                 \n");
    scanf("%s", inputname.name);
    printf("                      请输入密码                     \n");
    scanf("%ld", &inputname.sec);
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    for (i = 0; i < 2; i++) {
        if ((inputname.sec == Name[i].sec) && (strcmp(inputname.name, Name[i].name) == 0)) {
            printf("登陆成功！\n");
            master_doing();
            break;
        } else if (i == 1 && ((inputname.sec != Name[i].sec) || (strcmp(inputname.name, Name[i].name) != 0))) {
            printf("账号密码错误，请重新登陆！\n");
            flag++;
            if (flag == 3) {
                printf("您已经3次输错");
                exit(0);
            }
            goto A;
        }
    }
}

//这是管理员执行命令界面
void master_doing() {
    int i;

    while (1)
    {
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
        printf("                    您要执行什么操作                \n");
        printf("               1 查找、浏览和更新用户信息                   \n");
        printf("               2 输入、查询、浏览更新菜单信息 \n");
//    printf("               3 外卖统计分析功能                \n");
        printf("               4 收入浏览               \n");
        printf("               0 退出               \n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
        i = inputnum();
        switch (i) {
            case 1: {
                customer_manage();
                break;
            }
            case 2: {
                caidan_master();
                break;
            }
            case 3: {
            }
            case 4: {
                master_doing_incomeview();
                break;
            }
            case 0: {
                exit(0);
            }
            default:
            {
                printf("您输入存在错误！");
            }
        }
    }
}

//这是顾客欢迎界面,done
void customerhello1() {
    char a;
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    printf("尊敬的顾客您想来点什么吗？我们有最新的菜品如果想看的话请输入【y】，不想请输入其他字符   \n");
    scanf(" %c", &a);
    if (a == 'y' || a == 'Y') {
        printf("               1 佛跳墙\n");
        printf("               2 大肠刺身\n");
        printf("               3 东北大骨\n");
        printf("               4 皇家东坡肉\n");
        goto B;
    } else {
        B:
        customer_doing();
    }
}

//这是顾客操作界面
void customer_doing() {
    static int i = 1;
    char ch, sh;
    int sucess, flag = 0;
    customer inputname;
    C:
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    printf("                    您有账户吗：\n");
    printf("              如果没有账户请输入回车创建，如果有请输入y或Y：\n");
    sh = getchar();
    ch = getchar();
    if (ch == '\n') {
        customercreate();
        goto D;
    }
    D:
    printf("                     请输入您的账户名：\n");
    scanf("%s", inputname.name);
    printf("                      请输入您的密码：\n");
    scanf("%s", inputname.sec);
    sucess = customerchazhao(inputname);
    if (sucess == 1) {
        customer_doing1(inputname);
    } else {
        printf("您输入错误，请重新输入\n");
        goto C;
    }
}

//这是网上点餐界面
void customer_doing_net() {
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    printf("                 您好这里是网上点餐服务              \n");
    printf("                 请您输入您想要点的菜品                  \n");
    printf("                  请留下您的电话号码\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
}

//这是数字输入函数,done
int inputnum() {
    int i;
    scanf("%d", &i);
    return i;
}

//这是彩蛋,done
void anlienhello() {
    printf("对不起，暂不提供服务.\n");
    exit(0);
}

//这是账户创建,done
void customercreate() {
    customer inputname;
    int i, n;
    char seccheak[20];
    customer root[N];
    FILE *fp;
    if ((fp = fopen("/home/bingoner/桌面/homework/customer.txt", "r")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%d", &root[i].num);
        fscanf(fp, "%s", root[i].name);
        fscanf(fp, "%s", root[i].sec);
        fscanf(fp, "%c", &root[i].VIP);
    }
    fclose(fp);
    n = i;
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    printf("               您好，欢迎来到账户创建界面                \n");
    printf("               您是我们第%d位创建账户者               \n", n);
    printf("                首先请您输入您的账户名                 \n");
    scanf("%s", inputname.name);
    printf("                 请您输入您的密码\n");
    scanf("%s", inputname.sec);
    printf("                 请再次输入您的密码               \n");
    scanf("%s", seccheak);
    printf("                 您是否想加入VIP               \n");
    scanf(" %c", &inputname.VIP);
    if (strcmp(inputname.sec,seccheak)==0) {
        printf("创建成功！             \n");
        inputname.num = i;
        customer_write(inputname);
    } else {
        printf("创建失败！             \n");
    }
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
}

//这是查找登陆账户,done
int customerchazhao(customer find) {
    int flag = 0;
    customer root[N];
    FILE *fp;
    int i, n;
    if ((fp = fopen("/home/bingoner/桌面/homework/customer.txt", "r")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%d", &root[i].num);
        fscanf(fp, "%s", root[i].name);
        fscanf(fp, "%s", root[i].sec);
        fscanf(fp, " %c", &root[i].VIP);
    }
    fclose(fp);
    for (n = 0; n < i - 1; n++) {
        if ((strcmp(find.name, root[n].name) == 0) && (strcmp(find.sec,root[n].sec))==0) {
            flag++;
            return 1;
        }
    }
    if (flag == 0) {
        return -1;
    }
}

//这是录入信息,done
void customer_write(customer inp) {
    FILE *fp;
    if ((fp = fopen("/home/bingoner/桌面/homework/customer.txt", "a")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    fprintf(fp, "%3d   %s               %s", inp.num,
            inp.name, inp.sec);
    fprintf(fp, "         %c", inp.VIP);
    fprintf(fp, "\n");
    fclose(fp);
}

//这是检索食物价格,done
caidan searchfood(int a) {
    caidan root[N];
    caidan guke;
    FILE *fp;
    int i, n;
    if ((fp = fopen("/home/bingoner/桌面/homework/food.txt", "r")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%d", &root[i].num);
        fscanf(fp, "%s", root[i].foodname);
        fscanf(fp, "%d", &root[i].money);
    }
    fclose(fp);
    for (n = 0; n < i; n++) {
        if (a == root[n].num) {
            guke.num = root[n].num;
            strcpy(guke.foodname, root[n].foodname);
            guke.money = root[n].money;
            return guke;
        }
    }
}

//这是创建菜单,done
void caidancreate() {
    caidan inputname;
    char ch;
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    printf("            master您好，欢迎来到菜单创建界面                \n");
    printf("                您可以查看当前菜单,如果查看请输入【y】\n");
    scanf(" %c", &ch);
    if (ch == 'y') {
        showcaidan();
    }
    printf("                 首先请您输入菜名号：                 \n");
    scanf("%d", &inputname.num);
    printf("                   请您输入菜名：\n");
    scanf("%s", inputname.foodname);
    printf("                    请输入价格：               \n");
    scanf("%d", &inputname.money);
    caidan_write(inputname);
    printf("创建成功！             \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    caidan_master();
}

//这是写菜单,done
void caidan_write(caidan inp) {
    FILE *fp;
    if ((fp = fopen("/home/bingoner/桌面/homework/food.txt", "a")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    fprintf(fp, "\n%14d%s%14d", inp.num,
            inp.foodname, inp.money);
    fclose(fp);
}

//这是管理菜单界面,done
void caidan_master() {
    int i, n;
    A:printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    printf("                    您要执行什么操作                \n");
    printf("               1 输入菜单信息                 \n");
    printf("               2 查询菜单信息 \n");
    printf("               3 更新菜单信息               \n");
    printf("               0 退出                \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    i = inputnum();
    switch (i) {
        case 1: {
            caidancreate();
            break;
        }
        case 2: {
            showcaidan();
            caidan_master();
            break;
        }
        case 3: {
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
            printf("                    请输入您要删除的菜品号                \n");
            n = inputnum();
            removefood(n);
            caidan_master();
            break;
        }
        case 0: {
            master_doing();
        }
        default:
        {
            printf("error");
            goto A;
        }
    }
}

//这是展示菜单,done
void showcaidan() {
    caidan root[N];
    FILE *fp;
    int i, n;
    if ((fp = fopen("/home/bingoner/桌面/homework/food.txt", "r")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%d", &root[i].num);
        fscanf(fp, "%s", root[i].foodname);
        fscanf(fp, "%d", &root[i].money);
    }
    printf("菜号          菜名           单价\n");
    for (n = 0; n < i; n++) {
        printf("%d          %s%14d", root[n].num, root[n].foodname, root[n].money);
        printf("\n");
    }
    fclose(fp);
}

//这是删除菜品,仅限管理,done
void removefood(int q) {
    int i, f = -1;
    int num;
    caidan root[N];
    FILE *fp, *fn;
    if ((fp = fopen("/home/bingoner/桌面/homework/food.txt", "r")) == NULL) {
        printf("can not open file\n");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%d", &root[i].num);
        fscanf(fp, "%s", root[i].foodname);
        fscanf(fp, "%d", &root[i].money);
    }
    fclose(fp);
    for (num = 0; num < i; num++) {
        if (q == root[num].num) {
            if (num < i - 1) {
                for (f = num; f < i; f++) {
                    root[num].num = root[num + 1].num;
                    strcpy(root[num].foodname, root[num + 1].foodname);
                    root[num].money = root[num + 1].money;
                }
            }
            if ((fn = fopen("/home/bingoner/桌面/homework/food.txt", "w")) == NULL) {
                printf("文件打不开！\n");
                printf("\npress enter to return menu\n");
                exit(0);
            }
            for (num = 0; num < i - 1; num++) {
                fprintf(fn, "\n%14d%s%14d", root[num].num, root[num].foodname, root[num].money);
            }
            fclose(fn);
            printf("\n删除成功！\n");
            printf("\npress enter to return menu\n");
            getchar();
            getchar();
            caidan_master();
        }
    }
    if (f < 0) {
        printf("\n您所查找的信息不存在！\n");
        printf("\npress enter to return menu\n");
        getchar();
        getchar();
        caidan_master();
    }
}

//这部分管理用户信息,done
void customer_manage() {
    int i, n;
    char name1[20];
    A:printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    printf("                    您要执行什么操作                \n");
    printf("               1 添加用户信息 \n");
    printf("               2 查询用户信息 \n");
    printf("               3 更新用户信息               \n");
    printf("               0 退出                \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    i = inputnum();
    switch (i) {
        case 1: {
            customercreate();
            customer_manage();
            break;
        }
        case 2: {
            showcustomer();
            customer_manage();
            break;
        }
        case 3: {
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
            printf("                    请输入您要删除的用户名                \n");
            scanf("%s", name1);
            removecustomer(name1);
            customer_manage();
            break;
        }
        case 0: {
            master_doing();
            break;
        }
        default:
        {
            printf("error");
            goto A;
        }
    }
}

//这部分显示customer信息,done
void showcustomer() {
    customer root[N];
    FILE *fp;
    int i, n;
    if ((fp = fopen("/home/bingoner/桌面/homework/customer.txt", "r")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%d", &root[i].num);
        fscanf(fp, "%s", root[i].name);
        fscanf(fp, "%s", root[i].sec);
        fscanf(fp, " %c", &root[i].VIP);
    }
    printf("单号          用户名          密码           VIP\n");
    for (n = 0; n < i - 1; n++) {
        printf("%d\t\t%s\t\t%s\t\t", root[n].num, root[n].name, root[n].sec);
        printf(" %c", root[n].VIP);
        printf("\n");
    }
    fclose(fp);
}

//这部分移除用户信息,done
void removecustomer(char name1[]) {
    int i, f = -1;
    int num;
    customer root[N];
    FILE *fp, *fn;
    if ((fp = fopen("/home/bingoner/桌面/homework/customer.txt", "r")) == NULL) {
        printf("can not open file\n");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%3d", &root[i].num);
        fscanf(fp, "%s", root[i].name);
        fscanf(fp, "%s", root[i].sec);
        fscanf(fp, " %c", &root[i].VIP);
    }
    fclose(fp);
    for (num = 0; num < i; num++) {
        if (strcmp(name1, root[num].name) == 0) {
            if (num < i - 1) {
                for (f = num; f < i; f++) {
                    root[f].num = root[f + 1].num;
                    strcpy(root[f].name, root[f + 1].name);
                    strcpy(root[f].sec,root[f + 1].sec);
                    root[f].VIP = root[f + 1].VIP;
                }
            }
            if ((fn = fopen("/home/bingoner/桌面/homework/customer.txt", "w")) == NULL) {
                printf("文件打不开！\n");
                printf("\npress enter to return menu\n");
                exit(0);
            }
            for (num = 0; num < i - 2; num++) {
                fprintf(fn, "%3d %s    %s   %c\n", root[num].num, root[num].name, root[num].sec, root[num].VIP);

            }
            fclose(fn);
            printf("\n删除成功！\n");
            printf("\npress enter to return menu\n");
            getchar();
            getchar();
            customer_manage();
        }
    }
    if (f < 0) {
        printf("\n您所查找的信息不存在！\n");
        printf("\npress enter to return menu\n");
        getchar();
        getchar();
        customer_manage();
    }
}

int customervipchazhao(customer find, customer root[]) {
    int flag = 0;
    FILE *fp;
    int i, n;
    if ((fp = fopen("/home/bingoner/桌面/homework/customer.txt", "r")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%3d", &root[i].num);
        fscanf(fp, "%s", root[i].name);
        fscanf(fp, "%s", root[i].sec);
        fscanf(fp, " %c", &root[i].VIP);
    }
    fclose(fp);
    for (n = 0; n < i; i++) {
        if (find.VIP == root[n].VIP) {
            flag++;
            return 0.8;
        }
    }
    if (flag == 0) {
        return 1;
    }
}

void customer_doing_diancan(customer inputname) {
    int i;
    A:
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    printf("            顾客您好，现在请选择您要进行的操作                \n");
    printf("                    1 查看菜单                  \n");
    printf("                    2 点餐                  \n");
    printf("                    3 减餐             \n");
    printf("                    4 查看点菜             \n");
    printf("                    0 退出             \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    i = inputnum();
    switch (i) {
        case 1: {
            showcaidan();
            goto A;
            break;
        }
        case 2: {
            customer_doing_diancan_add(inputname);
            break;
        }
        case 3: {
            customer_doing_diancan_delete(inputname);
            break;
        }
        case 4: {
            customer_doing_diancan_view();
            goto A;
            break;
        }
        case 0: {
            customer_doing1(inputname);
            break;
        }
        default:
        {
            printf("error");
            goto A;
        }
    }
}

void customer_doing_diancan_add(customer inputname) {
    caidan diandan[N];
    int i = 0, a;
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    A:
    printf("            顾客您好，现在请选择您要点的菜，输入菜单号输入0结束               \n");
    a = inputnum();
    if (a != 0) {
        if (searchfod(a) == 1) {
            diandan[i] = searchfood(a);
            i++;
            goto A;
        } else if (searchfod(a) == 0) {
            printf("点餐失败！");
            goto A;
        }
    } else if (a == 0) {
        printf("点餐完成！");
        food_write(diandan, i);
        customer_doing_diancan(inputname);
    }
}

int searchfod(int a) {
    caidan root[N];
    int flag = 0;
    FILE *fp;
    int i, n;
    if ((fp = fopen("/home/bingoner/桌面/homework/food.txt", "r")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%d", &root[i].num);
        fscanf(fp, "%s", root[i].foodname);
        fscanf(fp, "%d", &root[i].money);
    }
    fclose(fp);
    for (n = 0; n < i; n++) {
        if (a == root[n].num) {
            return 1;
        }
    }
    if (flag == 0) {
        return 0;
    }
}

void food_write(caidan diandan[], int i) {
    FILE *fp;
    int n;
    if ((fp = fopen("/home/bingoner/桌面/homework/moneyedit.txt", "a")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    for (n = 0; n < i; n++) {
        fprintf(fp, "%3d%s      %5d", diandan[n].num, diandan[n].foodname, diandan[n].money);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void customer_doing_diancan_delete(customer inputname) {
    caidan diandan[N];
    int i = 0, a;
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    A:
    printf("            顾客您好，现在请选择您要删除的菜，输入菜单号输入0结束               \n");
    a = inputnum();
    if (a != 0) {
        if (searchfod(a) == 1) {
            customer_doing_diancan_delete_remove(a);
            goto A;
        } else if (searchfod(a) == 0) {
            printf("减餐失败！");
            goto A;
        }
    } else if (a == 0) {
        printf("减餐完成！");
        customer_doing_diancan(inputname);
    }
}

void customer_doing_diancan_delete_remove(int a) {
    int i, f = -1,k;
    int num;
    caidan root[N];
    FILE *fp, *fn;
    if ((fp = fopen("/home/bingoner/桌面/homework/moneyedit.txt", "r")) == NULL) {
        printf("can not open file\n");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%d", &root[i].num);
        fscanf(fp, "%s", root[i].foodname);
        fscanf(fp, "%d", &root[i].money);
    }
    fclose(fp);
    for (num = 0; num < i; num++) {
        if (a == root[num].num) {
            if (num < i - 1) {
                for (f = num; f < i-1; f++) {
                    root[f].num = root[f + 1].num;
                    strcpy(root[f].foodname, root[f + 1].foodname);
                    root[f].money = root[f + 1].money;
                }
            }
            if ((fn = fopen("/home/bingoner/桌面/homework/moneyedit.txt", "w")) == NULL) {
                printf("文件打不开！\n");
                printf("\npress enter to return menu\n");
                exit(0);
            }
            for (k = 0; k < i - 2; k++) {
                fprintf(fn, "%3d%s      %5d\n", root[k].num, root[k].foodname, root[k].money);
            }
            fclose(fn);
            printf("\n删除成功！\n");
            break;
        }
    }
}

void customer_doing_diancan_view() {
    caidan root[N];
    FILE *fp;
    int i, n;
    if ((fp = fopen("/home/bingoner/桌面/homework/moneyedit.txt", "r")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%d", &root[i].num);
        fscanf(fp, "%s", root[i].foodname);
        fscanf(fp, "%d", &root[i].money);
    }
    printf("菜号          菜名           单价\n");
    for (n = 0; n < i - 1; n++) {
        printf("%d          %s%14d", root[n].num, root[n].foodname, root[n].money);
        printf("\n");
    }
    fclose(fp);
}

void customer_doing1(customer inputname) {
    int i;
    A:printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    printf("            顾客您好，现在请选择您要进行的操作                \n");
    printf("                    1 点餐                  \n");
//    printf("                    2 外卖订购             \n");
    printf("                    3 结帐             \n");
    printf("                    0 退出             \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
    i = inputnum();
    switch (i) {
        case 1: {
            customer_doing_diancan(inputname);
            break;
        }
        case 2: {
            customer_doing_net();
            break;
        }
        case 3: {
            customer_doing_jiezhang(inputname);
            break;
        }
        case 0: {
            exit(0);
        }
        default:
        {
            printf("error");
            goto A;
        }
    }
}
void customer_doing_jiezhang(customer inputname)
{
    diandan cus;
    caidan jiezhang[N];
    customer root[N];
    int flag = 0;
    char ch;
    FILE *fp,*fn,*fm;
    int i, n, p,k;
    double all_money = 0;
    if ((fp = fopen("/home/bingoner/桌面/homework/customer.txt", "r")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%3d", &root[i].num);
        fscanf(fp, "%s", root[i].name);
        fscanf(fp, "%s", root[i].sec);
        fscanf(fp, " %c", &root[i].VIP);
    }
    fclose(fp);
    for (n = 0; n < i; n++) {
        if (strcmp(inputname.name, root[n].name) == 0) {
            inputname.num = root[n].num;
            strcpy(inputname.name,root[n].name);
            inputname.VIP = root[n].VIP;
            if ((fn = fopen("/home/bingoner/桌面/homework/moneyedit.txt", "r")) == NULL) {
                printf("FAILURE OPEN FILE!");
                exit(0);
            }
            for (i = 0; !feof(fn); i++) {
                fscanf(fp, "%d", &jiezhang[i].num);
                fscanf(fp, "%s", jiezhang[i].foodname);
                fscanf(fp, "%d", &jiezhang[i].money);
            }
            for (p = 0;p<i;p++)
            {
                all_money += jiezhang[p].money;
            }
            fclose(fn);
            if ((inputname.VIP == 'y')||(inputname.VIP == 'Y'))
            {
                all_money = all_money*0.8;
                printf("您是我们的VIP客户,本次共消费%lf元.",all_money);
                break;
            }
            else if((inputname.VIP == 'n')||(inputname.VIP == 'N'))
            {
                printf("您本次共消费%lf元.",all_money);
                break;
            }
        }
    }
    if ((fm = fopen("/home/bingoner/桌面/homework/kehumingxi.txt", "a")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    cus.ID.num = inputname.num;
    strcpy(cus.ID.name,inputname.name);
    cus.ID.VIP = inputname.VIP;
    cus.num = i;
    for (k = 0;k<i;k++)
    {
        cus.food[k].num = jiezhang[k].num;
        strcpy(cus.food[k].foodname,jiezhang[k].foodname);
        cus.food[k].money = jiezhang[k].money;
    }
    cus.all_money = all_money;
    fprintf(fm,"%3d  %s        %c\n",cus.ID.num,cus.ID.name,cus.ID.VIP);
    fprintf(fm,"%d\n",cus.num);
    for (k = 0;k<i-1;k++)
    {
        fprintf(fm,"%3d  %s       %d\n",cus.food[k].num,cus.food[k].foodname,cus.food[k].money);
    }
    fprintf(fm,"%.2lf\n",cus.all_money);
    fclose(fm);
    if ((fn = fopen("/home/bingoner/桌面/homework/moneyedit.txt", "w")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    fclose(fn);
    printf("请按任意键结束...........");
    ch = getchar();
    exit(0);
}

void master_doing_incomeview()
{
    diandan root[N];
    FILE *fp;
    int i, n,k,p;
    if ((fp = fopen("/home/bingoner/桌面/homework/kehumingxi.txt", "r")) == NULL) {
        printf("FAILURE OPEN FILE!");
        exit(0);
    }
    for (i = 0; !feof(fp); i++) {
        fscanf(fp, "%d", &root[i].ID.num);
        fscanf(fp, "%s", root[i].ID.name);
        fscanf(fp, " %c", &root[i].ID.VIP);
        fscanf(fp,"%d",&root[i].num);
        for (k = 0;k<root[i].num-1;k++)
        {
            fscanf(fp,"%d",&root[i].food[k].num);
            fscanf(fp,"%s",root[i].food[k].foodname);
            fscanf(fp,"%d",&root[i].food[k].money);
        }
        fscanf(fp,"%lf",&root[i].all_money);
    }
    for (p = 0;p<i-1;p++)
    {
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
        printf("num          顾客名           是否VIP\n");
        printf("%3d       %s              %c\n",root[p].ID.num,root[p].ID.name,root[p].ID.VIP);
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
        printf("编号        菜名             价格\n");
        for (n = 0; n < root[p].num; n++) {
            printf("%d          %s%14d", root[p].food[n].num, root[p].food[n].foodname, root[p].food[n].money);
            printf("\n");
        }
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
        printf("总价为\n");
        printf("%lf\n",root[p].all_money);
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
        printf("\n");
    }
    fclose(fp);
}



















