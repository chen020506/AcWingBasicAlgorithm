#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 50

typedef char VertexType[10];	//顶点数据的数据类型
typedef int EdgeType;	//边权值数据类型
typedef int Status;		//返回类型

typedef struct SqStack { //定义结构栈
    int data[MAXSIZE];
    int top;
}SqStack;

int Ve[MAXSIZE] = { 0 };//初始化最早发生时间数组
int Vl[MAXSIZE] = { 0 };	//最晚发生时间

void initSqStack(SqStack* stack) { //栈的初始化
    stack->top = 0;
    for (int i = 0; i < MAXSIZE; i++) {
        stack->data[i] = 0;
    }
}

Status Push(SqStack* stack, int e) {  //压栈
    if (stack->top >= MAXSIZE) return ERROR;
    stack->data[stack->top] = e;
    stack->top++;
    return OK;
}

Status Pop(SqStack* stack, int* e) {  //弹栈
    if (stack->top <= 0) return ERROR;
    --stack->top;
    *e = stack->data[stack->top];
    return OK;
}

int StackEmpty(SqStack Stack) {		//栈判空：空返回1，非空返回0
    if (Stack.top <= 0) return OK;
    else return ERROR;
}

typedef struct EdgeNode {    //边数据表
    int adjvex;
    EdgeType info;
    struct EdgeNode* next;
}EdgeNode;

typedef struct VertexNode {  //顶点数据表
    VertexType data;
    EdgeNode* firstedge;
}VertexNode, AdjList[MAXSIZE];

typedef struct GraphAdjList { //顶点图数据整合表
    AdjList adjList;
    int numNodes, numEdge;
}GraphAdjList;

void CreatALGraph(GraphAdjList* G) { //顶点图初始化
    VertexType former,later;
    int info = 0;
    EdgeNode* e;
    printf("请输入工程的顶点个数和边数，输入形式：顶点个数 边数\n");
    scanf("%d %d", &G->numNodes, &G->numEdge);
    printf("请依次输入顶点的数据值\n");
    for (int i = 0; i < (G->numNodes); i++) {
        scanf("%s", G->adjList[i].data);
        G->adjList[i].firstedge = NULL;
    }

    printf("请输入边数据，输入形式：vi vj info\n");
    for (int i = 0; i < (G->numEdge); i++) {    //i<(G->numEdge)判断形式！！！
        int fom = 0, lat = 0;
        scanf("%s %s %d", former, later, &info);
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        for (int j = 0; j < (G->numNodes); j++) {   //输入的数值指向和数值顶点对应下标进行转换
            if (!strcmp(G->adjList[j].data,former))fom = j;
            if (!strcmp(G->adjList[j].data,later))lat = j;
        }
        e->adjvex = lat; e->info = info;
        e->next = G->adjList[fom].firstedge;
        G->adjList[fom].firstedge = e;
    }
}

void FindInDegree(GraphAdjList G, int* InDegree) {	//计算每个顶点数据的入度信息
    for (int i = 0; i < (G.numNodes); i++) {
        for (EdgeNode* p = G.adjList[i].firstedge; p; p = p->next) {    //p=p->next记得递进赋值
            int k = p->adjvex;
            InDegree[k]++;
        }
    }
}

void FindOutDegree(GraphAdjList G, int* OutDegree) {	//计算每个顶点的出度信息
    for (int i = 0; i < (G.numNodes); i++) {
        for (EdgeNode* p = G.adjList[i].firstedge; p; p = p->next) {
            OutDegree[i]++;
        }
    }
}

Status TopologicalOder(GraphAdjList G) {		//拓扑排序，判断工程规划是否可行
    if (G.numNodes == 0) return ERROR;//判断顶点图是否为空
    SqStack Stack;
    int e = 0;//接弹出值
    initSqStack(&Stack);
    int InDegree[MAXSIZE] = { 0 };
    FindInDegree(G, InDegree);
    int count = 0;//判断顶点个数是否符合

    for (int i = 0; i < (G.numNodes); i++) {  //寻找第一个入度为0的数据，第一个入栈数据，多个工程图进行初入
        if (InDegree[i] == 0) {
            Push(&Stack, i);
        }
    }
    if (StackEmpty(Stack)) {
        printf("工程过程有不合理环\n");
        return ERROR;
    }
//    printf("拓扑排序： ");
    while (!StackEmpty(Stack)) {			//拓扑排序主算法
        Pop(&Stack, &e);
//        printf("%s->", G.adjList[e].data);   //弹出
        count++;
        for (EdgeNode* p = G.adjList[e].firstedge; p; p = p->next) {    //它所对应的出度的边都-1
            if ((--InDegree[p->adjvex]) == 0) {	//将入度为0的入栈，为下次判断做准备
                Push(&Stack, p->adjvex);
            }
            if (Ve[e] + (p->info) > Ve[p->adjvex]) {	//计算事件的最早发生时间
                Ve[p->adjvex] = Ve[e] + (p->info);//重复更新 找出最大值
            }
        }
    }
    printf("\b\b  \n");
    if (count < (G.numNodes)) {
        printf("工程过程有不合理环");
        return ERROR;
    }
    else return OK;

}
int MAX(int k) {	//寻找关键路径的最长发生时间
    int max = 0;
    for (int i = 0; i < k; i++) {
        if (max < Ve[i]) max = Ve[i];
    }
    return max;
}

char ans[MAXSIZE][10];
void dfs(GraphAdjList G,int n,int lev){
    strcpy(ans[lev],G.adjList[n].data);
    if(G.adjList[n].firstedge==NULL){
        for(int i=0;i<lev;i++)printf("%s->",ans[i]);
        printf("%s\n",ans[lev]);
        return;
    }
    for (EdgeNode* q = G.adjList[n].firstedge; q; q = q->next)
        {
            int k = q->adjvex;
            int dut = q->info;
            if (Ve[n] == Vl[k] - dut)
                dfs(G,k,lev+1);
        }
}

Status Show(GraphAdjList G) {
    int InDegree[MAXSIZE] = { 0 };
    FindInDegree(G, InDegree);
//    SqStack Stack;
//    int e = 0;//接弹出值
//    initSqStack(&Stack);
    printf("关键路径：\n");
    for (int i = 0; i < (G.numNodes); i++) {  //寻找第一个入度为0的数据，第一个入栈数据，多个工程图进行初入
        if (InDegree[i] == 0) {
//            Push(&Stack, i);
            dfs(G,i,0);
        }
    }
//    while (!StackEmpty(Stack)) {			//拓扑排序主算法
//        Pop(&Stack, &e);
//        for (EdgeNode* p = G.adjList[e].firstedge; p; p = p->next) {    //它所对应的出度的边都-1
//            if ((--InDegree[p->adjvex]) == 0) {    //将入度为0的入栈，为下次判断做准备
//                Push(&Stack, p->adjvex);
//            }
//        }
//        for (EdgeNode* q = G.adjList[e].firstedge; q; q = q->next)
//        {
//            int k = q->adjvex;
//            int dut = q->info;
//            if (Ve[e] == Vl[k] - dut)
//                printf("%s->", G.adjList[e].data);
//        }
//        if(G.adjList[e].firstedge==NULL){
//            printf("%s\n",G.adjList[e].data);
//        }
//    }

    printf("最早发生时间： ");
    for (int i = 0; i < (G.numNodes); i++)
        printf("[%s]=%d ", G.adjList[i].data, Ve[i]);
    printf("\n");
    printf("最迟发生时间： ");
    for (int i = 0; i < (G.numNodes); i++)
        printf("[%s]=%d ", G.adjList[i].data, Vl[i]);
    printf("\n");
    return OK;
}

Status CriticalPath(GraphAdjList G) {	//关键路径算法
    int k = G.numNodes;
    int max = MAX(k);//关键路径的最长发生时间
    for (int i = 0; i < k; i++) {
        Vl[i] = max;//初始化最晚发生时间的数组
    }

    SqStack Stack;
    int e = 0;
    initSqStack(&Stack);
    int OutDegree[MAXSIZE] = { 0 };//存储顶点的出度
    FindOutDegree(G, OutDegree);//计算出度

    for (int i = 0; i < (G.numNodes); i++) {  //寻找第一个出度为0的数据，第一个入栈数据，多个工程图进行初入
        if (OutDegree[i] == 0) {
            Push(&Stack, i);
        }
    }
    while (!StackEmpty(Stack)) {			//关键路径过程的主算法
        Pop(&Stack, &e);
        for (int i = 0; i < (G.numNodes); i++) {
            for (EdgeNode* p = G.adjList[i].firstedge; p; p = p->next) {	//寻找0出度顶点对应的前驱顶点
                if (p->adjvex == e) {
                    if ((--OutDegree[i]) == 0) {	//前驱顶点出度-1 ，判断是否为0
                        Push(&Stack, i);//为0则入栈做下次循环准备
                    }
                    if (Vl[e] - (p->info) < Vl[i]) {//计算事件的最晚发生时间
                        Vl[i] = Vl[e] - (p->info);//不断更新 找出最小值
                    }
                }
            }
        }
    }

//    Show(G);//关键路径结果输出

    return OK;
}


int main() {
    GraphAdjList graphAdjList;//创建顶点图变量
    CreatALGraph(&graphAdjList);//创建变量数值
    if (!TopologicalOder(graphAdjList)) return 0;///判断是否存在不合理环，不存在则继续执行
    CriticalPath(graphAdjList);//关键路径函数
    Show(graphAdjList);

    return 0;
}
