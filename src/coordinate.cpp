#include "../include/coordinate.hpp"


using std::string;

// Constructors
Coordinate::Coordinate(const int unique_number, const double northing, const double easting, const double elevation, const string code)
{
    this->unique_number = unique_number;
    this->northing = northing;
    this->easting = easting;
    this->elevation = elevation;
    this->code = code;
}
Coordinate::Coordinate(const Coordinate& other)
{
    this->unique_number = other.unique_number;
    this->northing = other.northing;
    this->easting = other.easting;
    this->elevation = other.elevation;
    this->code = other.code;
}
Coordinate::Coordinate()
{
    this->unique_number = 0;
    this->northing = 0;
    this->easting = 0;
    this->elevation = 0;
    this->code = "";
}

// Getters
int Coordinate::get_unique_number() const
{
    return this->unique_number;
}

double Coordinate::get_northing() const
{
    return this->northing;
}

double Coordinate::get_easting() const
{
    return this->easting;
}

double Coordinate::get_elevation() const
{
    return this->elevation;
}

std::string Coordinate::get_code() const
{
    return this->code;
}

// Setters
void Coordinate::set_unique_number(const int new_number)
{
    this->unique_number = new_number;
}

void Coordinate::set_northing(const double new_northing)
{
    this->northing = new_northing;
}

void Coordinate::set_easting(const double new_easting)
{
    this->easting = new_easting;
}

void Coordinate::set_elevation(const double new_elevation)
{
    this->elevation = new_elevation;
}

void Coordinate::set_code(const string new_code)
{
    this->code = new_code;
}

// Is equal
bool Coordinate::is_equal(const Coordinate& other)
{
    return this->unique_number == other.unique_number && this->northing == other.northing 
    && this->easting == other.get_easting() && 
    this->elevation == other.get_elevation() && this->code.compare(other.get_code()) == 0;
}

// To string
std::string Coordinate::to_string() const
{
    return std::to_string(this->unique_number) + "," + std::to_string(this->northing) + "," + std::to_string(this->easting) + "," + std::to_string(this->elevation) + "," + this->code;
}