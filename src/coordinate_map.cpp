#include "../include/coordinate_map.hpp"

using std::string; using std::map;

/***
 * Check if a coordinate exists in a map
 * @param coordinate_map: The map to check for the coordinate
 * @param unique_number: The unique number of the coordinate to check for
 * @returns: True if the coordinate exists in the map, false otherwise 
 * */
bool coordinate_exists_in_map(map<string, Coordinate>& coordinate_map, const std::string& unique_number) 
{
    return coordinate_map.find(unique_number) != coordinate_map.end();
}

/***
 * Add a coordinate to a map
 * @param coordinate_map: The map to add the coordinate to
 * @param coordinate: The coordinate to add to the map
 * @throws: std::runtime_error if the coordinate already exists in the map
 * */
void add_coordinate_to_map(map<string, Coordinate>& coordinate_map,const Coordinate &coordinate)
{
    if (coordinate_exists_in_map(coordinate_map, std::to_string(coordinate.get_unique_number()))) {
        throw std::runtime_error("Duplicate unique number: " + std::to_string(coordinate.get_unique_number()));
    }
    coordinate_map[std::to_string(coordinate.get_unique_number())] = coordinate;
}

/***
 * Get a coordinate from a map
 * @param coordinate_map: The map to get the coordinate from
 * @param unique_number: The unique number of the coordinate to get
 * @returns: The coordinate mapped to by the unique number
 * */
Coordinate get_coordinate_from_map(map<string, Coordinate>& coordinate_map, const std::string& unique_number) 
{
    return coordinate_map.at(unique_number);
}

/***
 * Remove a coordinate from a map
 * @param coordinate_map: The map to remove the coordinate from
 * @param unique_number: The unique number of the coordinate to remove
 * */
void remove_coordinate_from_map(map<string,Coordinate>& coordinate_map,const std::string& unique_number) 
{
    coordinate_map.erase(unique_number);
}