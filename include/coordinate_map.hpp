#pragma once

#include "../include/coordinate.hpp"
#include <map>
#include <stdexcept>

std::map<std::string, Coordinate>& get_coordinate_map();

bool coordinate_exists_in_map(std::map<std::string, Coordinate>& coordinate_map, const std::string& unique_number);

void add_coordinate_to_map(std::map<std::string, Coordinate>& coordinate_map,const Coordinate &coordinate);

Coordinate get_coordinate_from_map(std::map<std::string, Coordinate>& coordinate_map, const std::string& unique_number);

void remove_coordinate_from_map(std::map<std::string, Coordinate>& coordinate_map, const std::string& unique_number);