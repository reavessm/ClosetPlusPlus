#include "pants.h"
/**
 * @class Pants
 * @file pants.cc
 * @author Stephen M. Reaves
 * @date July 14th, 2018
 */

/**
 * Default Constructor
 */
Pants::Pants() {}

/**
 * Parameterized Constructor
 * @param id Integer to identify this pants uniquely across the closet
 * @param name String to identify this pants to the user
 * @param prim_color Primary color
 * @param sec_color Secondary color
 * @tert_color Tertiary color
 * @material Material of these pants
 * @length Length of the pants' legs
 * @cut Cut of the pants' legs
 * @returns Pants object
 */
Pants::Pants(int id, string name, string prim_color, string sec_color,
             string tert_color, string material, string length, string cut) {
  this->id_ = id;
  this->name_ = name;
  this->primary_color_ = prim_color;
  this->secondary_color_ = sec_color;
  this->tertiary_color_ = tert_color;
  this->material_ = material;
  this->length_ = length;
  this->cut_ = cut;
}

/**
 * Deconstructor
 */
Pants::~Pants() {}

/******************************************************************************
 * Accessors and Mutators
 */

/******************************************************************************
 * General Functions
 */

/**
 * ToXML
 * @deprecated
 *
 * @returns XML representation of the shirt
 */
string Pants::ToXML() const {
  string s = "";

  s += "  <Pants ID=" + to_string(this->id_) + ">\n";
  s += "    <Name>" + this->name_ + "</Name>\n";
  s += "    <Primary Color>" + this->primary_color_ + "</Primary Color>\n";
  s +=
      "    <Secondary Color>" + this->secondary_color_ + "</Secondary Color>\n";
  s += "    <Tertiary Color>" + this->tertiary_color_ + "</Tertiary Color>\n";
  s += "    <Material>" + this->material_ + "</Material>\n";
  s += "    <Length>" + this->length_ + "</Length>\n";
  s += "  </Pants>\n";

  return s;
}

/**
 * ToString
 * @returns 'string' representing the pants.
 */
string Pants::ToString() const {
  string s = "\n";

  s += "Name: " + this->name_ + "\n";
  s += "ID:   " + to_string(this->id_);
  s += "\n";
  s += "  -> Primary Color:   " + this->primary_color_ + "\n";
  s += "  -> Secondary Color: " + this->secondary_color_ + "\n";
  s += "  -> Tertiary Color:  " + this->tertiary_color_ + "\n";
  s += "  -> Material:        " + this->material_ + "\n";
  s += "  -> Length:          " + this->length_ + "\n";

  return s;
}
