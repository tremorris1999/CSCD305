// src/grade_tester.cpp

/**
 * @file grade_tester.cpp
 * @author Trevor Morris (00876703) (tmorris17@ewu.edu)
 * 
 * I am personally running clang++ for my compiler, but I'm using CMake for
 * building the project, so it should work with g++ or MSVC no problem.
 * 
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main(void)
{
    auto prompt = [](std::string message)
    {
        int error = 0;
        float out = 0.0f;
        std::string str;
        std::stringstream stream;
        do
        {
            if(error)
            {
                std::cerr << "Invalid input, please try again!" << std::endl;
            }

            error = 1;
            std::cout << message;
            std::cin >> str;
            std::cout << std::endl;
            stream = std::stringstream(str);
        } while(!((stream >> out) && !(stream >> str)));

        return out;
    };

    auto promptInt = [prompt](std::string message)
    {
        float f = prompt(message);
        int i = (int)f;
        while((float)i != f)
        {
            std::cerr << "Input must not be floating-point." << std::endl;
            f = prompt(message);
            i = (int)f;
        }

        return i;
    };

    std::string str;
    int numStudents = promptInt("Enter the number of students: ");
    while(numStudents < 1)
    {
        std::cerr << "Number of students must be greater than zero. Please try again." << std::endl;
        numStudents = promptInt("Enter the number of students: ");
    }

    std::vector<double> scores;
    double sum = 0, lowest, highest;
    for(int i = 0; i < numStudents; i++)
    {
        std::string prompt_text = "Enter score #" + std::to_string(i + 1) + ": ";
        double score = prompt(prompt_text);
        while(score < 0.0f || score > 100.f)
        {
            std::cerr << "Value out of range (0 - 100), please try again." << std::endl;
            score = prompt(prompt_text);
        }

        if(score < lowest || i == 0)
            lowest = score;

        if(score > highest || i == 0)
            highest = score;

        sum += score;
        scores.push_back(score);
    }

    std::cout << "Lowest score: " << lowest << std::endl;
    std::cout << "Highest score: " << highest << std::endl;
    std::cout << "Average score: " << sum / scores.size() << std::endl;
}