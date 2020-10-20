/*
 * main.cpp
 *
 * Version Information
 * Author: Quinn Reilly
 * Date: 22 sept 2020
 *
 * Copyright notice
 */

// Include classes and headers
#include "../inc/common.h"

// Challenge Methods
void challenge1();      /* Gambler's ruin game */
void challenge2();      /* Problem of points game */

// Other methods
void gamblersRuin(int, int, int);           /* The coomputer gambles its money away in the hopes it can make a profit */
float randomNumberGenerator(float, float);  /* Creates a random float value between x and y */
int randomNumberGenerator(int, int);  /* Creates a random int value between x and y */
void displayGamblersScore(int, int, int);   /* Display the score for Gambler's Ruin game */
int playAgain();                            /* Ask the user to play again and return result */

// Main loop
int main() {
    //challenge1();
    challenge2();

    // End program
    return 0;
}

void challenge1() {
    // Initianize variables
    int playerPot, goalPot, stake;

    std::cout << "Welcome to Gambler's Ruin.\nChoose your starting pot: ";  /* User instruction */
    std::cin >> playerPot;                                                  /* User input */
    std::cout << std::endl;                                                 /* New line */

    std::cout << "\nChoose your goal pot: ";    /* User instruction */
    std::cin >> goalPot;                        /* User input */
    std::cout << std::endl;                     /* New line */

    std::cout << "\nChoose your stake: ";   /* User instruction */
    std::cin >> stake;                      /* User input */
    std::cout << std::endl;                 /* New line */

    // If statement to check that input is valid
    if(playerPot < goalPot && playerPot >= stake) {
        gamblersRuin(playerPot, goalPot, stake);
    } else {
        std::cout << "Goal pot must be larger than player pot and stake must be "
        "smaller than or equal to player pot." << std::endl; /* User warning */
    }
}

void challenge2() {
    int player1Score = 12, player2Score = 12;
    std::vector<int>die {0, 0, 0};

    while(player1Score != 0 && player2Score != 0) {
        // Roll the die.
        for(int i = 0; i < die.size(); i++) {
            die[i] = randomNumberGenerator(1, 6);
        }

        // Player 1 gains point.
        if(die[0] + die[1] + die[2] == 11) {
            player1Score ++;
            player2Score --;
        }

        // Roll the die.
        for(int i = 0; i < die.size(); i++) {
            die[i] = randomNumberGenerator(1, 6);
        }

        // Player 2 gains point.
        if(die[0] + die[1] + die[2] == 14) {
            player1Score --;
            player2Score ++;
        }

        std::cout << "Player 1 score: " << player1Score << std::endl;
        std::cout << "Player 2 score: " << player2Score << std::endl;
    }

    std::cout << std::endl;

    // End game.
    if(player1Score == 0) {
        std::cout << "Player 1 Loses." << std::endl;
    } else {
        std::cout << "Player 2 Loses." << std::endl;
    }

    std::cout << std::endl;
}

void gamblersRuin(int playerPot, int goalPot, int stake) {
    // Initialize variables
    int totalBets = 0;
    int totalWins = 0;
    int totalLoses = 0;
    int originalPot = playerPot;

    float randomNumber = 0.0;

    bool gameOver = 0;
    bool potDisplayed = 0;

    // Game loop
    while(gameOver == 0) {

        playerPot = originalPot;
        std::cout << "Your Pot: " << playerPot << std::endl; /* Player information */

        while(playerPot >= stake && playerPot < goalPot) {
            randomNumber = randomNumberGenerator(0.0f, 1.0f); /* Call randomNumberGenerator method */

            // Points if statement
            if(randomNumber >= 0.5) {   /* Win points condition */
                playerPot += stake;     /* Add points to player pot */
                std::cout << "Win!";
            } else {                    /* Lose points condition */
                playerPot -= stake;     /* Subtract points to player pot */
                std::cout << "Lose!";
            }

            // Print game information
            std::cout << '\t' << "Pot: " << playerPot  << '\t' << '\t';
            std::cout << "Outcome: " << '\t' << randomNumber << std::endl;

            totalBets++; /* Count bets */
        }

        // Game over if statement
        if(playerPot < stake) {             /* Lose game condition */
            std::cout << "Your pot is insufficient. Game over!" << std::endl;
            totalLoses++;                   /* Add points to total loses */
        } else if (playerPot >= goalPot) {  /* Win game condition */
            std::cout << "Your pot has reached the goal amount. Game over!" << std::endl;
            totalWins++;                    /* Add points to total wins */
        }

        displayGamblersScore(totalBets, totalWins, totalLoses); /* Display total wins, loses and bets */
        gameOver = playAgain();                                 /* Ask user if they want to play again */
    }
}

float randomNumberGenerator(float x, float y) {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_real_distribution<> distributor(x, y);

    return distributor(generator); /* Return final random number*/
}

int randomNumberGenerator(int x, int y) {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<> distributor(x, y);

    return distributor(generator); /* Return final random number*/
}

void displayGamblersScore(int totalBets, int totalWins, int totalLoses) {
    std::cout << std::endl << "Total Bets: " << totalBets << std::endl <<
        "Total Wins: " << totalWins << std::endl << "Total Loses: " <<
        totalLoses << std::endl << (float(totalWins) / (totalWins + totalLoses)) * 100 <<
        "% of games are wins." << std::endl; /* Final score of Gambler's ruin is displayed */
}

int playAgain() {
    // Declare variables
    std::string input;

    std::cout << "Play again? (y/n): "; /* User instruction */
    std::cin >> input;                  /* User input */
    std::cout << std::endl;             /* New line */

    // If statement to determine the users input
    if(input == "y") {
        return 0;
    } else {
        return 1;
    }
}
