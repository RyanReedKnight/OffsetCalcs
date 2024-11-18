#include "../include/read_coordinates_from_file.hpp"
#include <iostream>

void echo(std::string message);
std::string get_input();
void echo(std::map<std::string,Coordinate> coordinate_map);

int main(void)
{

    echo("Please enter the path to the file containing the coordinates:");
    std::string file_path = get_input();
    echo("Reading coordinates from file: " + file_path);

    std::map<std::string,Coordinate> coordinate_map;

    try {
        coordinate_map = load_coordinates_from_file(file_path);
        echo("Coordinates loaded successfully");
    } catch (std::runtime_error& e) {
        echo(e.what());
    }

    echo(coordinate_map);

    return 0;
}

void echo(std::string message)
{
    std::cout << message << std::endl;
}


std::string get_input()
{
    std::string input;
    std::cin >> input;
    return input;
}

void echo(std::map<std::string,Coordinate> coordinate_map)
{
    for (auto& [key, val] : coordinate_map) {
        echo(val.to_string());
    }
}