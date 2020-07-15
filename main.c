#include <stdio.h>
#define MAX 100
#define typename int
typedef struct node {
    int  next;
    typename context;
}Node,List[MAX];
int InitStatic(Node *l);
int get_Length(Node *list);
int Insert(Node *l,int i,typename x);
int delete(Node *l,int k);
void print();
int main() {
    List list;
    InitStatic(list);
    int h,i = 1;
    scanf("%d",&h);
    list[0].next = h;
    while(i < h) {
        int f;
        scanf("%d",&f);
        list[i].context = f;
        i++;
    }
    list[h-1].next = 0;
    list[MAX - 1].next = 1;
    printf("长度为：%d\n",get_Length(list));
    print(list);
    printf("-------------------------------------\n");
    delete(list,3);
    printf("长度为：%d\n",get_Length(list));
    /*Insert(list,5,5);
    printf("长度为：%d\n",get_Length(list));*/
    print(list);
    return 0;
}
//初始化操作
int InitStatic(Node *l) {
    for (int i = 0; i < MAX - 1; ++i) {
        l[i].context = 0;
        l[i].next = i + 1;
    }
    l[MAX - 1].next = 0;
    return 1;
}
//获得插入节点
int getLode(Node *list) {
    int m = list[0].next;
    if(m) {
        list[0].next = list[m].next;
    }
    return m;
}
//获得有效长度
int get_Length(Node *list) {
    int length = 0,i = 1;
    while(i != 0) {
        i = list[i].next;
        length++;
    }
    return length;
}
//插入操作
int Insert(Node *l,int i,typename x) {
    int m = getLode(l),j = 1, k = 1;
    if(i < 1 || i > get_Length(l) + 1) {
        printf("插入错误！");
        return 0;
    }
    for (;j < i - 1;j++)  k = l[k].next;
    l[m].context = x;
    l[m].next = l[k].next;
    l[k].next = m;
    return 1;
}
//删除操作
int delete(Node *l,int k) {
    int j = 1,m = 1;
    for (;j < k - 1;j++) m = l[m].next;
    k = l[m].next;
    l[m].next = l[k].next;
    l[k].next = l[0].next;
    l[0].next = k;
    return 1;
}
//数据的展示
void print(Node *list) {
    int i = 1;
    while(list[i].next) {
        printf("数据为：%d\n",list[i].context);
        i = list[i].next;
    }
    printf("数据为：%d\n",list[i].context);
}
