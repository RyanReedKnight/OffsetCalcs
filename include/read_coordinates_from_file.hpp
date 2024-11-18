#pragma once

#include "coordinate_map.hpp"

#include <fstream>
#include <sstream>
#include <vector>

std::map<std::string,Coordinate> load_coordinates_from_file(const std::string& file_path);