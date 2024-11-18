#include "../include/coordinate_map.hpp"

using std::string; using std::map;

map<string, Coordinate>& get_coordinate_map() 
{
    static std::map<std::string, Coordinate> coordinate_map;
    return coordinate_map;
}


bool coordinate_exists_in_map(map<string, Coordinate>& coordinate_map, const std::string& unique_number) 
{
    return coordinate_map.find(unique_number) != coordinate_map.end();
}

void add_coordinate_to_map(map<string, Coordinate>& coordinate_map,const Coordinate &coordinate)
{
    if (coordinate_exists_in_map(coordinate_map, std::to_string(coordinate.get_unique_number()))) {
        throw std::runtime_error("Duplicate unique number: " + std::to_string(coordinate.get_unique_number()));
    }
    coordinate_map[std::to_string(coordinate.get_unique_number())] = coordinate;
}

Coordinate get_coordinate_from_map(map<string, Coordinate>& coordinate_map, const std::string& unique_number) 
{
    return coordinate_map.at(unique_number);
}

void remove_coordinate_from_map(map<string,Coordinate>& coordinate_map,const std::string& unique_number) 
{
    coordinate_map.erase(unique_number);
}