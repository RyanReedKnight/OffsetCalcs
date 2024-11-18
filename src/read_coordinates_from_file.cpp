#include "../include/read_coordinates_from_file.hpp"


std::map<std::string,Coordinate> load_coordinates_from_file(const std::string& file_path)
{

    std::map<std::string,Coordinate> coordinate_map;;
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + file_path);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() != 5) {
            throw std::runtime_error("Invalid line format: " + line);
        }

        int unique_number = std::stoi(tokens[0]);
        double northing = std::stod(tokens[1]);
        double easting = std::stod(tokens[2]);
        double elevation = std::stod(tokens[3]);
        std::string code = tokens[4];

        Coordinate coordinate(unique_number, northing, easting, elevation, code);

        try {
            add_coordinate_to_map(coordinate_map,coordinate);
        } catch (const std::runtime_error& e) {
            // Just skip the duplicate coordinate
        }
    
    }

    file.close();

    return coordinate_map;
}