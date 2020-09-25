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

void introEnterName();  /* Get user to input name */
void challenge1();      /* Print out lower case and upper case ascii alphabet and corresponding ascii ID */
void challenge2();      /* FizzBuzz game */
int  MaximumCupCakes(); /* challenge3(); A calculator for cupcake purchases and promotional deals */
void challenge4();      /* Gambler's ruin game */

// Main loop
int main() {

    int input1 = 1;

    //introEnterName(); /* Call introEnterName */
    //challenge1(); /* Call challenge1 */
    //challenge2();
    //std::cout << MaximumCupCakes();
    challenge4();


    // End program
    return 0;
}

void introEnterName() {
    std::cout << "Hello" << std::endl;          /* Hello world message */

    std::string name = "";                      /* Name storage */
    std::cout << "Please put in your name: ";   /* Print instruction */
    std::cin >> name;                           /* Get user input */

    // Print final result
    std::cout << std::endl << "Your name: " + name << std::endl;
}

void challenge1() {
    char asciiUpperCase = 'A'; /* Store upper case character */
    char asciiLowerCase = 'a'; /* Store lower case character */

    // For loop
    for(int i = asciiLowerCase; i <= 'z'; i++) {                                /* Init i as 97 and iterate until 122 */
        std::cout << asciiUpperCase << '\t' << int(asciiUpperCase) << '\t';     /* Print the rest of lower case alphabet */
        asciiUpperCase++;                                                       /* Iterate char for output */

        std::cout << asciiLowerCase << '\t' << int(asciiLowerCase)  << std::endl;   /* Print the rest of lower case alphabet */
        asciiLowerCase++;                                                           /* Iterate char for output */
    }
}

void challenge2() {
    int input; /* Store user input */

    std::cout << "Welcome to FizzBuzz. Enter the maximum number to play: "; /* User instruction */
    std::cin >> input;                                                      /* User input */
    std::cout << std::endl;                                                 /* New line */

    // For loop
    for(int i = 1; i <= input; i++) {               /* Start at 1 and interate to user input */
        if(i % 3 == 0 && i % 5 == 0) {              /* Requirements for FizzBuzz */
            std::cout << "FizzBuzz" << std::endl;
        } else if(i % 3 == 0) {                     /* Requirements for Buzz */
            std::cout << "Buzz" << std::endl;
        } else if(i % 5 == 0) {                     /* Requirements for Fizz */
            std::cout << "Fizz" << std::endl;
        } else {                                    /* Requirements for generic number */
            std::cout << i << std::endl;
        }
    }
}

int MaximumCupCakes() {
    float money;
    float cost;
    int requiredWrappers;
    int cupcakes = 0;
    int wrappers = 0;

    std::cin >> money;
    std::cin >> cost;
    std::cin >> requiredWrappers;

    cupcakes = money / cost;
    wrappers = (cupcakes / requiredWrappers) + cupcakes;
    cupcakes = wrappers;

    return cupcakes;
}

void challenge4() {
     int playerPot = 10;
     int goalPot = 20;
     int stake = 1;
     int totalBets = 0;
     int totalWins = 0;
     int totalLoses = 0;
     float randomNumber = 0.0;
     bool gameOver = 0;

     std::string input;

     std::random_device rd;                          /* Will be used to obtain a seed for the random number engine */
     std::mt19937 gen(rd());                         /* Standard mersenne_twister_engine seeded with rd() */
     std::uniform_real_distribution<> dis(0.0, 1.0);

     // std::cout << randomNumber; /* Test Print */

     std::cout << "Your Pot: " << playerPot << std::endl;

     while(gameOver == 0) {
         randomNumber = dis(gen);

         if(randomNumber >= 0.5) {
             playerPot += stake;
             std::cout << "Win!" << '\t';
             std::cout << "Pot: " << playerPot << std::endl;
         } else {
             playerPot -= stake;
             std::cout << "Lose!" << '\t';
             std::cout << "Pot: " << playerPot << std::endl;
         }

         if(playerPot == 0) {
             std::cout << "Your pot is empty. Game over!" << std::endl;

             totalLoses++;
         } else if (playerPot == goalPot) {
             std::cout << "Your pot has reached the goal amount. Game over!" << std::endl;

             totalWins++;
         }

         totalBets++;
     }

     std::cout << std::endl << "Total Bets: " << totalBets << std::endl << "Total Wins: " << totalWins << std::endl << "Total Loses: " << totalLoses << std::endl;
     std::cout << "Play again? (y/n): ";
     std::cin >> input;
     std::cout << std::endl;

     if(input == "y") {
         gameOver = 0;
     } else {
         gameOver = 1;
     }
}
