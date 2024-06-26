# Project description

We initialized a random city with any desired number of intersections, filling it with the marker ('-'). We then printed the city using the `p_city` function. Initially, we used the `srand()` function to randomly assign intersections ('#') in the city. We employed the `validmove` function to check the correctness of the vehicle's movement in a given direction, considering the city's constraints and intersections. After confirming a valid move, we used the `movecar` function to randomly relocate the vehicle to a new valid direction, placing it in the new location with the marker ('*') and removing the vehicle's previous markers from the old locations. We used the `printcity` function to print the city at each stage of the simulation. The `main` function takes input, creates vehicles at random locations in the city, and moves them in each step using the `movecar` function. We also utilized the `clearscreen` function to clear the screen before printing the city in each stage, and the `sleep` function was used to pause the program for a short period to better observe the vehicle movements.


# Description of different parts of the code

 * define constants are defined with `values of 20`. These constants are used to define the dimensions of the city array.

><img src="./img/1.png" width="349" height="200">

 * The `ClearScreen()` function is one that clears the console screen.

><img src="./img/2.png" width="349" height="110">

 * The city_p() function initializes the city array with dashes ('-') and randomly places a specified number of intersections, denoted by '#', in the city array
 
><img src="./img/3.png" width="349" height="230">

 * The validmove() function checks whether a movement is valid for a car, considering its current position, direction, and the city array. It verifies if the movement is within the city limits and not blocked by an intersection (denoted by '#').
 
><img src="./img/4.png" width="349" height="700">

 * The movecar() function moves a car within the city array. It generates a random direction and continues to generate new directions until a valid movement is found. Then, it updates the car's position in the city array.
 
><img src="./img/5.png" width="390" height="700">

 * The printcity() function prints the current state of the city array.
 
><img src="./img/6.png" width="349" height="190">

 * "In the main() function, the program asks the user to enter the number of cars, taghato, and iterations. It then initializes the city array and places the taghato using the citytaghato_p() function. It also dynamically allocates a two-dimensional array, negah_car, to store the positions of the cars. In the loop, each car is moved using the movecar() function, and its position in the negah_car array is updated. Then, it prints the current state of the city using printcity(), clears the screen, and repeats for a specified number of iterations. Finally, it frees the memory dynamically allocated for the negah_car array before returning from the program."

><img src="./img/7.png" width="349" height="700">
