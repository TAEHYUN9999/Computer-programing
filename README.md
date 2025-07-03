
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
