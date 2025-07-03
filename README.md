
BMI-Based Clothing Size Recommendation and Shortest Path Finder
Overview
This project is a final assignment for the Advanced Computer Programming course. It implements a program that:
Calculates the user's BMI based on their height and weight input.
Recommends an appropriate clothing size based on the calculated BMI.
Finds the shortest path from the user's current location to a clothing store using Dijkstra's algorithm, considering dynamic road congestion.
The program processes the BMI formula using a stack-based algorithm to convert infix notation to postfix notation for evaluation and dynamically adjusts the recommended route based on traffic conditions.
Program Structure

1. BMI Calculation
Input: The user inputs their weight (A) and height (B).
Formula: BMI is calculated as A / (B * B) (infix notation).
Stack-Based Conversion:
The program converts the infix expression A / (B * B) to postfix notation A B B * / using a stack.
Operators are pushed onto the stack, and operands are sent to the output.
Example:
Input: A / (B * B)
Stack operations:
Process (B * B) → Output: B B *
Process / → Output: A B B * /
The postfix expression is evaluated to compute the BMI.
Output: Based on the BMI, the program recommends an appropriate clothing size.

2. Shortest Path to Clothing Store
Graph Representation:
The graph consists of 6 vertices:
index[0]: User's current location.
index[5]: Clothing store.
index[1-4]: Roads connecting the locations.
The graph is a directed graph to reflect varying traffic congestion depending on the direction of travel.
Weights: Each link's weight represents road congestion, generated dynamically using the rand() function to simulate real-time traffic conditions.
The adjacency matrix is asymmetric (e.g., [1][2] ≠ [2][1]) to model direction-specific congestion.
Dijkstra's Algorithm:
Calculates the shortest path from the user's location (index[0]) to the clothing store (index[5]).
Outputs the recommended path and the congestion level (weight) of each road.
Dynamic Routing:
The weights are randomized each time the program runs, ensuring varied route recommendations based on simulated traffic conditions.

3. Return Trip Option
After recommending the route to the store, the program prompts the user to choose:
1: Calculate the shortest path from the clothing store back to the user's location using Dijkstra's algorithm.
0: Terminate the program.
Implementation Details
Vertices: Fixed at 6, representing key locations and roads.
Links: 9 directed edges with dynamic weights to simulate traffic congestion.
Weight Interpretation:
Higher weight → Higher road congestion.
Lower weight → Less congested road, preferred for the shortest path.
Algorithm:
Stack-based infix-to-postfix conversion for BMI calculation.
Dijkstra's algorithm for shortest path computation.
Language: [Specify the programming language used, e.g., C++, Python, etc., if applicable].

Example Usage
Input:
Weight: 70 kg
Height: 1.75 m
Output:
BMI: 22.86
Recommended clothing size: Medium
Shortest path to store: Current Location -> Road 1 -> Road 3 -> Store (Congestion: 5)
Prompt: "Calculate return path? (1: Yes, 0: No)"
Return Path (if chosen):
Shortest path: Store -> Road 4 -> Current Location (Congestion: 3)
Future Improvements
Add real-time traffic data integration instead of simulated weights.
Expand clothing size recommendations with more detailed BMI ranges.
Implement a graphical user interface (GUI) for better user interaction.





BMI 기반 의류 사이즈 추천 및 최단 경로 탐색 프로그램
개요
이 프로젝트는 고급 컴퓨터 프로그래밍 기말 과제로 제작된 프로그램입니다. 주요 기능은 다음과 같습니다:
사용자의 키와 몸무게를 입력받아 BMI를 계산합니다.
계산된 BMI를 바탕으로 적합한 의류 사이즈를 추천합니다.
사용자의 현재 위치에서 의류 매장까지의 최단 경로를 다익스트라 알고리즘을 사용해 계산합니다.
BMI 계산은 스택 기반 알고리즘을 통해 중위 표기법을 후위 표기법으로 변환하여 처리하며, 경로 추천은 교통 상황에 따라 동적으로 변동됩니다.
프로그램 구성
1. BMI 계산
입력: 사용자가 몸무게(A)와 키(B)를 입력합니다.
공식: BMI는 A / (B * B) (중위 표기법)으로 계산됩니다.
스택 기반 변환:
중위 표기법 A / (B * B)를 후위 표기법 A B B * /로 변환합니다.
연산자는 스택에 저장되고, 피연산자는 출력으로 전달됩니다.
예시:
입력: A / (B * B)
스택 처리 과정:
(B * B) 처리 → 출력: B B *
/ 처리 → 출력: A B B * /

후위 표기법으로 변환된 식을 계산하여 BMI를 구합니다.
출력: BMI 값을 기반으로 적합한 의류 사이즈를 추천합니다.
2. 의류 매장까지의 최단 경로
그래프 구성:
정점(Vertex): 6개로 구성
index[0]: 사용자의 현재 위치
index[5]: 의류 매장
index[1-4]: 도로

방향 그래프: 도로의 방향에 따라 혼잡도가 다르므로 방향 그래프를 사용합니다.
가중치(Weight): 도로의 혼잡도를 나타내며, rand() 함수를 통해 동적으로 생성됩니다.
인접 행렬은 비대칭으로 설정됩니다 (예: [1][2] ≠ [2][1]).

다익스트라 알고리즘:
사용자의 현재 위치(index[0])에서 의류 매장(index[5])까지의 최단 경로를 계산합니다.
추천 경로와 각 도로의 혼잡도를 출력합니다.

동적 경로 추천:
가중치가 실행 시마다 무작위로 변경되어 교통 상황에 따라 다른 경로가 추천됩니다.

3. 귀가 경로 선택
매장까지의 경로를 추천한 후, 사용자에게 다음을 묻습니다:
1: 의류 매장에서 집(현재 위치)까지의 최단 경로를 계산.
0: 프로그램 종료.

귀가 경로를 선택하면 다익스트라 알고리즘을 다시 사용하여 경로를 출력합니다.
구현 세부사항
정점 수: 6개로 고정.
링크 수: 9개의 방향성 링크.
가중치 의미:
높은 가중치: 도로 혼잡도 높음.
낮은 가중치: 도로 혼잡도 낮음 (최단 경로로 선호).

알고리즘:
BMI 계산: 스택 기반 중위-후위 표기법 변환.
경로 계산: 다익스트라 알고리즘.


사용 예시
입력:
몸무게: 70kg
키: 1.75m

출력:
BMI: 22.86
추천 의류 사이즈: M
매장까지 최단 경로: 현재 위치 -> 도로 1 -> 도로 3 -> 매장 (혼잡도: 5)
질문: "귀가 경로를 계산하시겠습니까? (1: 예, 0: 아니오)"

귀가 경로 (선택 시):
최단 경로: 매장 -> 도로 4 -> 현재 위치 (혼잡도: 3)


