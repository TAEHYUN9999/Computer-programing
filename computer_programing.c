#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>

#define MAX_NODES 100 
#define MAX_LENGTH 100

typedef struct {
    char name[50];
} Place;

typedef struct {
    int vertex;//node
    int weight2;//가중치
} Node;

typedef struct {
    int numNodes;//vertex의 수
    int numEdges;//link의 수
    int adjacencyMatrix[MAX_NODES][MAX_NODES];//인접행렬은 정방행렬이다
    Place places[MAX_NODES];//장소의 배열
} Graph;
void printAdjacencyMatrix(Graph* graph) {//인접행렬을 시각화하여 그리는 함수
    printf("현재 교통상황 :\n");
    printf("         ");
    for (int i = 0; i < graph->numNodes; i++) {//graph의 노드수만큼 반복하여 이름을 출력한다
        printf("%s ", graph->places[i].name);
    }
    printf("\n");
    for (int i = 0; i < graph->numNodes; i++) {
        printf("%s ", graph->places[i].name);//graph의 노드수만큼 반복하여 이름을 출력한다
        for (int j = 0; j < graph->numNodes; j++) {
            printf("%d  ", graph->adjacencyMatrix[i][j]);//인접행렬에 있는 가중치를 출력한다
        }
        printf("\n");
    }
}

int minDistance(int dist[], int visited[], int numNodes) {//dijkstra알고리즘에서사용 방문하지 않은 노드중 최소거리를 갖는 노드의 인덱스 반환
    //,dist는 거리를,visited는 방문여부를 나타낸다
    int min = INT_MAX;                                    //min은 최소거리를 저장하는 변수이다      
    int minIndex = -1;                                    //minindex초기화,minIndex는 최소거리를 가지는 노드의인덱스를 저장

    for (int i = 0; i < numNodes; i++) { //0부터 i<numNodes까지 반복하여 방문하지않은 노드중 최소거리를 갖는 노드를 찾는다
        if (visited[i] == 0 && dist[i] <= min) {//만일 방문한적이 없고(==0), dist[i]의값이 현재의 min보다 작으면 dist[i]값을 min에할당
            min = dist[i];
            minIndex = i;//그 최솟값이 되는 i값을 minindex에 할당한다
        }
    }
    return minIndex;
}

void printPath(Graph* graph, int parent[], int j) {//dijkstra알고리즘에서 최단경로를 출력하는 함수,int parent는 부모의 배열을 나타낸다,rootnode
    if (parent[j] == -1)                           //int parent가 -1이라면 rootnode인것이므로 함수를 종료한다
        return;

    printPath(graph, parent, parent[j]);//함수를 재귀적으로 출력하여 최단경로를 출력한다
    printf("-> %s ", graph->places[j].name);//현재 노드의이름을 출력한다
}

void dijkstra(Graph* graph, int startNode, int endNode) {
    int dist[MAX_NODES];//거리배열
    int visited[MAX_NODES];//방문한 노드배열
    int parent[MAX_NODES];//부모노드 배열

    for (int i = 0; i < graph->numNodes; i++) {
        dist[i] = INT_MAX;//int_max는 초기값으로 사용할때 모든 거리값을 초기화한다.dist는 최단거리
        visited[i] = 0;//방문여부를 나타내는 배열.방문 안했으니 0으로 초기화
        parent[i] = -1;//최상단 노드 즉 root node의 index는 -1로 표시한다,이후 최단경로 갱신될때마다 부모노드 갱신 union find다
    }

    dist[startNode] = 0;//시작노드의 최단거리를 0으로 초기화한다

    for (int count = 0; count < graph->numNodes - 1; count++) {//count를 사용해서 각노드를 한번씩 모두 방문하는 반복문이다
        int u = minDistance(dist, visited, graph->numNodes);//아직 방문하지 않은 노드중에서 최단거리 노드를 선택한다
        visited[u] = 1;//방문한 노드는 1로 바꾼다

        for (int v = 0; v < graph->numNodes; v++) {
            if (visited[v] == 0 && graph->adjacencyMatrix[u][v] && dist[u] != INT_MAX &&// 방문하지 않은 노드인지 확인하고
                //graph가 해당 인접행렬에서 이어져있는지 확인
                //최단거리가 무한대가 아닌지 확인한다
                dist[u] + graph->adjacencyMatrix[u][v] < dist[v]) {//u를거쳐서 가는 최단거리+인접행렬의 가중치의합이 현재까지 최단거리보다 작다면 
                dist[v] = dist[u] + graph->adjacencyMatrix[u][v];  //최단거리를 u를 거쳐가도록 초기화시킨다
                parent[v] = u;//v의 이전노드를 기록한다
            }
        }
    }

    printf("최단 경로: %s ", graph->places[startNode].name);//시작노드의 이름을 출력한다
    printPath(graph, parent, endNode);//함수를 호출하여 시작노드부터 종료노드까지 최단경로를 출력,재귀적으로 이전노드를 출력한다
    printf("\n도로 혼잡도: %d\n", dist[endNode]);//가중치의 최소합을 출력해준다
}
//스택구현함수
typedef struct {
    char items[MAX_LENGTH];
    int top;
} Stack;//스택 구조체

void init(Stack* stack) {//stack을 초기화시킨다
    stack->top = -1;
}

int isEmpty(const Stack* stack) {//stack이 공백이라면
    return stack->top == -1;
}

int isFull(const Stack* stack) {//stack이 가득찼다면
    return stack->top == MAX_LENGTH - 1;
}

void push(Stack* stack, char item) {//stack에 새로운 값을 넣어준다
    if (isFull(stack)) {
        printf("스택이 가득 찼습니다.\n");
        exit(EXIT_FAILURE);
    }

    stack->items[++stack->top] = item;//stack의 초기는 -1이므로 1증가시키고 item을 넣어준다
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어 있습니다.\n");
        exit(EXIT_FAILURE);
    }

    return stack->items[stack->top--];//top을 1감소시켜 stack에서 삭제시켜준다
}

char peek(const Stack* stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어 있습니다.\n");
        exit(EXIT_FAILURE);
    }

    return stack->items[stack->top];//stack에 최상단에 있는것을 확인한다
}

int isOperand(char ch) {
    return (ch >= '0' && ch <= '9');//이함수는 문자ch가 0부터 9면 참을 반환,반환값이 0이면 숫자가 아닌다른문자
}

int precedence(char operator) {//문자를 받는 함수 각 연산자들을 반환한다
    switch (operator) 
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    init(&stack);

    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        if (isOperand(token)) {
            postfix[j++] = token;
        }
        else if (token == '(') {
            push(&stack, token);
        }
        else if (token == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) != '(') {
                printf("잘못된 수식: 괄호 불일치\n");
                exit(EXIT_FAILURE);
            }
            pop(&stack);  // '(' 제거
        }
        else {
            while (!isEmpty(&stack) && precedence(token) <= precedence(peek(&stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    srand(time(NULL));

    Graph graph;
    graph.numNodes = 6;//vertex의 수
    graph.numEdges = 9;//link의 수

    for (int i = 0; i < graph.numNodes; i++) {//인접행렬의 값을 초기화
        for (int j = 0; j < graph.numNodes; j++) {
            graph.adjacencyMatrix[i][j] = 0;
        }
    }

    strcpy(graph.places[0].name, "현재위치");
    strcpy(graph.places[1].name, "강동대교");
    strcpy(graph.places[2].name, "양화대교");
    strcpy(graph.places[3].name, "테헤란로");
    strcpy(graph.places[4].name, "강변북로");
    strcpy(graph.places[5].name, "의류매장");

    // 무작위로 numEdges만큼의 간선을 생성 (자기 자신과 연결되지 않도록)
    int edges_added = 0;
    while (edges_added < graph.numEdges) {
        int u = rand() % graph.numNodes;
        int v = rand() % graph.numNodes;
        if (u == v) continue; // 자기 자신과 연결 방지
        if (graph.adjacencyMatrix[u][v] != 0) continue; // 이미 연결된 경우 방지
        int weight2 = rand() % 10 + 11;
        graph.adjacencyMatrix[u][v] = weight2;
        graph.adjacencyMatrix[v][u] = weight2;
        edges_added++;
    }

    double height, weight;
    printf("신장(cm)을 입력하세요: ");
    scanf("%lf", &height);
    printf("체중(kg)을 입력하세요: ");
    scanf("%lf", &weight);
    printf("BMI의 계산식은 몸무게/(키*키)입니다\n");
    printf("컴퓨터가 연산을할때 후위표식으로 계산하게됩니다\n");
    char infix[50];
    printf("본인의 BMI계산식을 중위 표기식으로 입력하세요: ");
    scanf("%s", infix);

    char postfix[50];
    infixToPostfix(infix, postfix);
    printf("후위 표기식 : %s\n", postfix);

    double heightMeter = height / 100.0;
    double bmi = weight / (heightMeter * heightMeter);
    printf("BMI: %.2f\n", bmi);

    if (bmi <= 18.5)
        printf("저체중입니다\n");
    else if (bmi > 18.5 && bmi < 22.9)
        printf("정상체중입니다\n");
    else if (bmi >= 23 && bmi < 24.9)
        printf("과체중입니다\n");
    else printf("비만입니다\n");

    if (height <= 160) {
        if (weight < 50)
            printf("옷 사이즈 추천: XS\n");
        else if (weight < 60)
            printf("옷 사이즈 추천: S\n");
        else if (weight < 70)
            printf("옷 사이즈 추천: L\n");
        else
            printf("옷 사이즈 추천: XL\n");
    }
    else if (height > 160 && height < 170) {
        if (weight < 60)
            printf("옷 사이즈 추천: M\n");
        else if (weight < 70)
            printf("옷 사이즈 추천: L\n");
        else if (weight < 80)
            printf("옷 사이즈 추천: XL\n");
        else
            printf("옷사이즈 추천:XXL");
    }
    else if (height >= 170 && height < 180) {
        if (weight < 60) {
            printf("옷 사이즈 추천: M\n");
        }
        else if (weight > 60 && weight < 80)
            printf("옷 사이즈 추천: XL\n");
        else if (weight > 80 && weight < 100)
            printf("옷 사이즈 추천: XXL\n");
        else
            printf("옷 사이즈 추천: XXL\n");
    }
    printf("해당 의류매장으로가는 최단경로를 계산해드리겠습니다\n");
    for (int i = 0; i < graph.numNodes; i++) {
        for (int j = 0; j < graph.numNodes; j++) {//link는 어디가 연결되고 어디가 연결안됐는지 고정이므로 해당 인접행렬을 직접선언해준다
            if (i != j)
            {
                graph.adjacencyMatrix[0][1] = rand() % 10 + 11;
                graph.adjacencyMatrix[0][2] = rand() % 10 + 11;
                graph.adjacencyMatrix[1][0] = rand() % 10 + 11;
                graph.adjacencyMatrix[1][3] = rand() % 10 + 11;
                graph.adjacencyMatrix[1][4] = rand() % 10 + 11;
                graph.adjacencyMatrix[1][5] = rand() % 10 + 11;
                graph.adjacencyMatrix[2][0] = rand() % 10 + 11;
                graph.adjacencyMatrix[2][3] = rand() % 10 + 11;
                graph.adjacencyMatrix[2][4] = rand() % 10 + 11;
                graph.adjacencyMatrix[3][1] = rand() % 10 + 11;
                graph.adjacencyMatrix[3][2] = rand() % 10 + 11;
                graph.adjacencyMatrix[3][5] = rand() % 10 + 11;
                graph.adjacencyMatrix[4][1] = rand() % 10 + 11;
                graph.adjacencyMatrix[4][2] = rand() % 10 + 11;
                graph.adjacencyMatrix[4][5] = rand() % 10 + 11;
                graph.adjacencyMatrix[5][1] = rand() % 10 + 11;
                graph.adjacencyMatrix[5][3] = rand() % 10 + 11;
                graph.adjacencyMatrix[5][4] = rand() % 10 + 11;
            }// 11이상부터 20까지의 무작위 가중치
            else
                graph.adjacencyMatrix[i][j] = 0;
        }//주대각행렬의 성분은 자기자신이므로 0이다
    }
    printAdjacencyMatrix(&graph);

    int startNode, endNode;
    printf("출발위치를 입력해주세요 (0부터 %d까지):\n", graph.numNodes - 1);
    for (int i = 0; i < graph.numNodes; i++) {
        printf("%d: %s\n", i, graph.places[i].name);
    }
    scanf("%d", &startNode);
    printf("도착위치를 입력해주세요 (0부터 %d까지):\n", graph.numNodes - 1);
    for (int i = 0; i < graph.numNodes; i++) {
        printf("%d: %s\n", i, graph.places[i].name);
    }
    scanf("%d", &endNode);

    dijkstra(&graph, startNode, endNode);

    return 0;
}
