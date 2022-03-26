# RobotNavigationSearchAlgorithms
***********************************
PROGRAM: ROBOT NAVIGATION PROBLEM 
***********************************

CREATED BY: AREEB TARIQ



DESCRIPTION:
  
  
    This program implements following search algorithms to navigate the robot to the goal position:
      a. Breadth first Search 		
      b. Uniform cost search 		
      c. Depth first search 		
      d. Iterative deepening 		
      e. Greedy search 		
      f. A* search  	

    The size of the rectangular grid (space) is user defined NxN. 	
    The permission of diagonal movement in a grid is a choice of the user 	
    In case diagonal movement is allowed, user can choose the cost of diagonal movement either 1 or 1.5

  

PROCESS FLOW:
	
	1. The program sequentially asks for following initial information before proceeding with the search algorithm:
		a. Grid Size
		b. Grid (consisting of empty cells indicated by '.' and obstacles indicated by 'X')
		c. Robot Position (Rows: 1-N from bottom-to-top respectively. Colums: 1-N from left-to-right respectively)
		d. Goal Position (With same convention as robot position)
		e. Diagonal movement allowed: yes or no
		f. Cost of diagonal movement (if diagonal movment is allowed): 1 or 1.5
		g. Choice of search method from the list given in the description above
	
	
	2. After getting the information, program executes the respective search algorithm.
	
	3. At each step it shows the state of fringe, and list of expanded nodes.
	
	4. If successfully finds the path to goal position, the program provides the following output statistics:
		a. Cost from the robot initial position to the goal position 
		b. Total number of nodes generated in this process
		c. Total number of expanded nodes in this process
		f. Path consisting of initial node, intermediate node(s), and goal node 

	5. If there is no path possible, program will respond with no possible result.

	6. After this, program will offer three choices to the user:
		a. To provide the new grid
		b. Search again on the same grid 
		c. Exit
    
    Based on the response, program executes accordingly.
