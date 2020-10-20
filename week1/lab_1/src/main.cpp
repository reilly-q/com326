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

// Other methods
void introEnterName();                      /* Get user to input name */
int  MaximumCupCakes(int, int, int);        /* A calculator for cupcake purchases and promotional deals */
void gamblersRuin(int, int, int);           /* The coomputer gambles its money away in the hopes it can make a profit */


// Main loop
int main() {
    //introEnterName();

    //challenge1();
    //challenge2();
    challenge3();

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
