# Dice Game rules

- there a single die (cube with values from 1 to 6) - players throw it in turns, accumulating the points      
- in turn the player can throw the cube several times - the score for this turn is calculated as the sum of all throws, unless value 1 is thrown    
- player can stop voluntarily (then the score for this turn is added to his total) or he is stopped when 1 appears (in this case he scores nothing for the turn)    
- after the turn the die is transferred to another player - who plays in the same manner     
- the one who reaches 100 wins the game        

# Example

    player1 throws:  5 3 3 (stops, +11)
    player2 throws:  4 6 (stops, +10)
    player1 throws:  2 5 1 (bust, +0)
    player2 throws:  3 2 3 4 (stops, +12)
# How to run the program?  
You can run the program as       

    $ make
	$ ./dice_game
