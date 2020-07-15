#include <stdio.h>
#define MAX 100
#define typename int
typedef struct node {
    int  next;
    typename context;
}Node,List[MAX];
int InitStatic(List *l);
int get_Length(List *list);
int Insert(List *l,int i,typename x);
int delete(List *l,int k);
void print();
int main() {
    List *list;
    InitStatic(list);
    int h,i = 1;
    scanf("%d",&h);
    list[0]->next = h;
    while(i < h) {
        int f;
        scanf("%d",&f);
        list[i]->context = f;
        i++;
    }
    list[h-1]->next = 0;
    list[MAX - 1]->next = 1;
    printf("����Ϊ��%d\n",get_Length(list));
    print(list);
    delete(list,3);
    printf("����Ϊ��%d\n",get_Length(list));
    /*Insert(list,2,5);*/
    print(list);
    return 0;
}
//��ʼ������
int InitStatic(List *l) {
    for (int i = 0; i < MAX - 1; ++i) {
        l[i]->next = i + 1;
    }
    l[MAX - 1]->next = 0;
    return 1;
}
//��ò���ڵ�
int getLode(List *list) {
    int m = list[0]->next;
    if(m) {
        list[0]->next = list[m]->next;
    }
    return m;
}
//�����Ч����
int get_Length(List *list) {
    int lenth = 0,i = 0;
    for(i = 0;i < MAX ;i++) {
        if(list[i]->next) {
            lenth++;
        } else{
            break;
        }
    }
    return lenth;
}
//�������
int Insert(List *l,int i,typename x) {
    int m = getLode(l),j= 1;
    if(i < 1 || i > get_Length(l)) {
        printf("�������");
        return 0;
    }
    while(i - 1 > j) {
        if(l[j]->next) {
            j++;
        }
    }
    l[m]->context = x;
    l[m]->next = l[j]->next;
    l[j]->next = m;
    return 1;
}
//ɾ������
int delete(List *l,int k) {
    int j = 1;
    while(k - 1 > j) {
        if(l[j]->next) {
            j++;
        }
    }
    k = l[j]->next;
    l[j]->next = l[k]->next;
    l[k]->next = l[0]->next;
    l[0]->next = k;
    return 1;
}
//���ݵ�չʾ
void print(List list) {
    int i = 1,j = 1;
    while(j < list[0].next) {
        printf("����Ϊ��%d\n",list[i].context);
        i = list[i].next;
        j++;
    }
}
