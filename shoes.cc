#include "shoes.h"
/******************************************************************************
 * File Name: shoes.cc
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary:
 *
 */

/******************************************************************************
 * Constructor
 */
Shoes::Shoes() {}

Shoes::Shoes(int id, string name, string prim_color, string sec_color,
             string tert_color, string material, string style) {
  this->id_ = id;
  this->name_ = name;
  this->primary_color_ = prim_color;
  this->secondary_color_ = sec_color;
  this->tertiary_color_ = tert_color;
  this->material_ = material;
  this->style_ = style;
}

/******************************************************************************
 * Deconstructor
 */
Shoes::~Shoes() {}

/******************************************************************************
 * Accessors and Mutators
 */

/******************************************************************************
 * General Functions
 */

/******************************************************************************
 * DEPRECATED
 *
 * Function 'ToXML'
 * Returns:
 *    XML representing the shoes.
 */
string Shoes::ToXML() const {
  string s = "";

  s += "  <Shoes ID=" + to_string(this->id_) + ">\n";
  s += "    <Name>" + this->name_ + "</Name>\n";
  s += "    <Primary Color>" + this->primary_color_ + "</Primary Color>\n";
  s +=
      "    <Secondary Color>" + this->secondary_color_ + "</Secondary Color>\n";
  s += "    <Tertiary Color>" + this->tertiary_color_ + "</Tertiary Color>\n";
  s += "    <Material>" + this->material_ + "</Material>\n";
  s += "    <Style>" + this->style_ + "</Style>\n";
  s += "  </Shoes>\n";

  return s;
}

/******************************************************************************
 * Function 'ToString'
 * Returns:
 *    'string' representing the shoes.
 */
string Shoes::ToString() const {
  string s = "\n";

  s += "Name: " + this->name_ + "\n";
  s += "ID:   " + to_string(this->id_);
  s += "\n";
  s += "  -> Primary Color:   " + this->primary_color_ + "\n";
  s += "  -> Secondary Color: " + this->secondary_color_ + "\n";
  s += "  -> Tertiary Color:  " + this->tertiary_color_ + "\n";
  s += "  -> Material:        " + this->material_ + "\n";
  s += "  -> Style:           " + this->style_ + "\n";

  return s;
}
