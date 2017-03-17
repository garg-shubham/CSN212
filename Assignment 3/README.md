# Assignment 3 ( Bellman Ford Algorithm Implementation )

## Input Format
    First line should contain T: No. of test cases.
    First line of each test case should have two integers: v : Number of vertices and e : Number of edges.
	Next line contains single integer which specify the souce vertex: source
	Next e lines specifies each edge of the graph with three integers each: a b c
    It defines directed edge from vertex a to b with weight/cost c

## Output Format: 
    For each test case:
    If graph contains a negative weight cycle, then program outputs error statement.
    Otherwise program outputs two integers in next v lines : node number and minimum distance from source node.
    Last line of test case contains time taken by the test case to run.
