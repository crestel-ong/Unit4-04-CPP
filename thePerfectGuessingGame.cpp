// Copyright (c) Crestel Ong All rights reserved
//
// Created by: Crestel
// Created on: October 2021
// This is the perfect guessing game program in C++

#include <iostream>
#include <random>
#include <string>

int main() {
    // declaring
    std::string guessNumberAsString;
    int guessNumber;
    int computerNumber;

    // input
    std::cout << "Enter a number between 0 - 10: ";
    std::cin >> guessNumberAsString;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int>idist(0, 10);
    computerNumber = idist(rgen);

    try {
        // convert string to integer
        guessNumber = std::stoi(guessNumberAsString);

        // process and output
        while (true)
            if (guessNumber == computerNumber) {
                std:: cout << "Great job, you guessed right!" << std::endl;
                break;
            } else if (guessNumber < computerNumber) {
                std:: cout << "Wrong, try guessing a higher number!"
                << std::endl;
                std:: cout << "" << std::endl;
                    std::cout << "Enter a number between 0 - 10: ";
                    std::cin >> guessNumberAsString;
                    guessNumber = std::stoi(guessNumberAsString);
            } else if (guessNumber > computerNumber) {
                std:: cout << "Wrong, try guessing a lower number!"
                << std::endl;
                std:: cout << "" << std::endl;
                    std::cout << "Enter a number between 0 - 10: ";
                    std::cin >> guessNumberAsString;
                    guessNumber = std::stoi(guessNumberAsString);
            }
    } catch (std::invalid_argument) {
        std::cout << guessNumberAsString << " is an invalid input."
        << std::endl;
    }
    std::cout << "\nDone." << std::endl;
}
