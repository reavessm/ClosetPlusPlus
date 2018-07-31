#include "belt.h"
/**
 * @class Belt
 * @file belt.cc
 * @author Stephen M. Reaves
 * @brief This class represents a logical belt
 * @date July 14th, 2018
 */

/**
 * Default Constructor
 *
 * @returns Belt Object
 */
Belt::Belt() {}

/**
 * Parameterized Constructor
 *
 * @param id Integer uniquely identifying this object across the whole closet
 * @param name String used to inentify this object to the user
 * @param prim_color Primary color of this belt
 * @param sec_color Secondary color of this belt
 * @param tert_color Tertiary color of this belt
 * @param material Material this belt is made of
 * @param pattern Design pattern of this belt
 *
 * @returns Belt Object
 */
Belt::Belt(int id, string name, string prim_color, string sec_color,
           string tert_color, string material, string pattern) {
  this->id_ = id;
  this->name_ = name;
  this->primary_color_ = prim_color;
  this->secondary_color_ = sec_color;
  this->tertiary_color_ = tert_color;
  this->material_ = material;
  this->pattern_ = pattern;
}

/**
 * Deconstructor
 */
Belt::~Belt() {}

/**
 * ToXML
 * @deprecated
 * @returns XML representing the belt.
 */
string Belt::ToXML() const {
  string s = "";

  s += "  <Belt ID=" + to_string(this->id_) + ">\n";
  s += "    <Name>" + this->name_ + "</Name>\n";
  s += "    <Primary Color>" + this->primary_color_ + "</Primary Color>\n";
  s +=
      "    <Secondary Color>" + this->secondary_color_ + "</Secondary Color>\n";
  s += "    <Tertiary Color>" + this->tertiary_color_ + "</Tertiary Color>\n";
  s += "    <Material>" + this->material_ + "</Material>\n";
  s += "  </Belt>\n";

  return s;
}

/**
 * ToString
 * @returns 'string' representing the belt.
 */
string Belt::ToString() const {
  string s = "\n";

  s += "Name: " + this->name_ + "\n";
  s += "ID:   " + to_string(this->id_);
  s += "\n";
  s += "  -> Primary Color:   " + this->primary_color_ + "\n";
  s += "  -> Secondary Color: " + this->secondary_color_ + "\n";
  s += "  -> Tertiary Color:  " + this->tertiary_color_ + "\n";
  s += "  -> Material:        " + this->material_ + "\n";
  s += "  -> Pattern:         " + this->pattern_ + "\n";

  return s;
}
