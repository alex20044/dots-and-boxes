# dots-and-boxes
The game dots and boxes
To solve the problem, 
firstly we create a class Player with private variables for their score and id and a constructor that takes as parameter the player ID.
The constructor initializes the starting values of score as zero and sets the player ID.
We have also created public member functions to either get or set different values of score.
The getter is constant, because it does not change the values. We create two players as p1 and p2.
The user interface is a 2 dimensional vector with “+” representing the dots (because it looks a bit better and aligns with the lines) and strings containing a space to keep the dots from moving when we insert a line.
We are using a global Boolean to save the turns.
The main function starts by calling the display() function which simply prints the vector.
We create a boolean won to check if some player has won with the function hasWon(), if the value is false we keep repeating the turns() function that toggles the player turns.
Then we call the play() function(with the player id as argument) which takes the 2 coordinates of the dots from the standard input and removes any spaces or commas that the user might have included (by using sstream library).
It also checks if the selected line is not already placed and determines what character to use by comparing the first coordinate of the first dot with the first coordinate of the second dot.
After the line has been created, we check if any squares have been formed by first making sure the square hasn’t been counted, if a new square has been formed we give the player one more turn and their score increases.
We display the updated vector with a number of the player that has completed the square in the middle of it.
When all 4 squares have been created the game ends and prints the score of each player and who has won.
