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
void challenge1();      /* Print ascii characters and ascii IDs */
void challenge2();      /* FizzBuzz game */
void challenge3();      /* Cupcake calculatr */
void challenge4();      /* Gambler's ruin game */

// Other methods
void introEnterName();                      /* Get user to input name */
int  MaximumCupCakes(int, int, int);        /* A calculator for cupcake purchases and promotional deals */
void gamblersRuin(int, int, int);           /* The coomputer gambles its money away in the hopes it can make a profit */
float randomNumberGenerator(float, float);  /* Creates a random float value between x and y */
void displayGamblersScore(int, int, int);   /* Display the score for Gambler's Ruin game */
int playAgain();                            /* Ask the user to play again and return result */

// Main loop
int main() {
    //introEnterName();

    //challenge1();
    //challenge2();
    //challenge3();
    challenge4();

    // End program
    return 0;
}

void challenge1() {
    char asciiUpperCase = 'A'; /* Store upper case character */
    char asciiLowerCase = 'a'; /* Store lower case character */

    // For loop
    for(int i = asciiLowerCase; i <= 'z'; i++) {    /* Init i as 97 and iterate until 122 */
        std::cout << asciiUpperCase << '\t' <<
            int(asciiUpperCase) << '\t';            /* Print the rest of lower case alphabet */
        asciiUpperCase++;                           /* Iterate char for output */

        std::cout << asciiLowerCase << '\t' <<
            int(asciiLowerCase)  << std::endl;      /* Print the rest of lower case alphabet */
        asciiLowerCase++;                           /* Iterate char for output */
    }
}

void challenge2() {
    int input; /* Store user input */

    std::cout << "Welcome to FizzBuzz. Enter the maximum number to play: "; /* User instruction */
    std::cin >> input;                                                      /* User input */
    std::cout << std::endl;                                                 /* New line */

    // For loop
    for(int i = 1; i <= input; i++) {               /* Start at 1 and iterate to user input */
        if(i % 3 == 0 && i % 5 == 0) {              /* Requirements for FizzBuzz */
            std::cout << "FizzBuzz" << std::endl;
        } else if(i % 3 == 0) {                     /* Requirements for Buzz */
            std::cout << "Buzz" << std::endl;
        } else if(i % 5 == 0) {                     /* Requirements for Fizz */
            std::cout << "Fizz" << std::endl;
        } else {                                    /* Requirements for number */
            std::cout << i << std::endl;
        }
    }
}

void challenge3() {
    int n = 0, c = 0, m = 0; /* Store user input */

    std::cout << "Welcome to the cupcake calculator. \nPlease enter your budget: "; /* User instruction */
    std::cin >> n;                                                                  /* User input */
    std::cout << std::endl;                                                         /* New line */

    std::cout << "Please enter the cost of a cupcake: ";    /* User instruction */
std::cin >> c;                                              /* User input */
    std::cout << std::endl;                                 /* New line */

    std::cout << "Please enter the number of cupcake wrappers"
        " you need for a free cupcake: ";                       /* User instruction */
    std::cin >> m;                                              /* User input */
    std::cout << std::endl;                                     /* New line */

    // If statement to check that input is valid
    if(m > 1 && c < n) {    /* Input is valid */
        std::cout << "You can eat " << MaximumCupCakes(n, c, m) << " cupcakes." << std::endl;
    } else {                /* Input is invalid */
        std::cout <<
            "Oops! The program cannot run if the required wrappers is less"
            " than 2 or if the price of a cupcake is greater than your budget."
            << std::endl;                                                       /* User warning */
    }
}

void challenge4() {
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

void introEnterName() {
    std::cout << "Hello" << std::endl;          /* Hello world message */

    std::string name;                           /* Name storage */
    std::cout << "Please put in your name: ";   /* Print instruction */
    std::cin >> name;                           /* Get user input */

    // Print final result
    std::cout << std::endl << "Your name: " + name << std::endl;
}

int MaximumCupCakes(int n, int c, int m) {
    int cupcakes = n / c;
    int wrappers = cupcakes / m;
    cupcakes += wrappers;

    while(wrappers > 1) {
        wrappers /= m;
        cupcakes += wrappers;
    }

    return cupcakes;
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
            randomNumber = randomNumberGenerator(0.0, 1.0); /* Call randomNumberGenerator method */

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
