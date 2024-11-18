#pragma once

#include <string>

/***
 * Struct to represent a coordinate as it is exported from Topcon Magnet Field.
 ***/

struct Coordinate
{
private:
    int unique_number;
    double northing, easting, elevation;
    std::string code;
public:

    // Constructors
    Coordinate (const int, const double, const double, const double, const std::string);
    Coordinate (const Coordinate&);
    Coordinate ();

    // Destructor
    ~Coordinate() = default;
    
    // Getters
    int get_unique_number() const;
    double get_northing() const;
    double get_easting() const;
    double get_elevation() const;
    std::string get_code() const;

    // Setters
    void set_unique_number(const int);
    void set_northing(const double);
    void set_easting(const double);
    void set_elevation(const double);
    void set_code(const std::string);

    // Is equal
    bool is_equal(const Coordinate&);

    // To string
    std::string to_string() const;

};