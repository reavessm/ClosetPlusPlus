#include "shirt.h"
/******************************************************************************
 * File Name: shirt.cc
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary:
 *
 */

using namespace std;

/******************************************************************************
 * Constructor
 */
Shirt::Shirt() {}

Shirt::Shirt(int id, string name, string prim_color, string sec_color, string tert_color, string pattern, string sleeve_length, string collar) {
  this->id_ = id;
  this->name_ = name;
  this->primary_color_ = prim_color;
  this->secondary_color_ = sec_color;
  this->tertiary_color_ = tert_color;
  this->pattern_ = pattern;
  this->sleeve_length_ = sleeve_length;
  this->collar_ = collar;
}

/******************************************************************************
 * Deconstructor
 */
Shirt::~Shirt() {}

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
 *    XML representing the shirt.
 */
string Shirt::ToXML() const{
  string s = "";
  
  s += "  <Shirt ID=" + to_string(this->id_) + ">\n";
  s += "    <Name>" + this->name_ + "</Name>\n";
  s += "    <Primary Color>" + this->primary_color_ + "</Primary Color>\n";
  s += "    <Secondary Color>" + this->secondary_color_ + "</Secondary Color>\n";
  s += "    <Tertiary Color>" + this->tertiary_color_ + "</Tertiary Color>\n";
  s += "    <Pattern>" + this->pattern_ + "</Pattern>\n";
  s += "    <Sleeve Length>" + this->sleeve_length_ + "</Sleeve Length>\n";
  s += "    <Collar>" + this->collar_ + "</Collar>\n";
  s += "  </Shirt>\n";

  return s;
}

/******************************************************************************
 * Function 'ToString'
 * Returns:
 *    'string' representing the shirt.
 */
string Shirt::ToString() const{
  string s = "\n";

  s += "Name: " + this->name_ + "\n";
  s += "ID:   " + to_string(this->id_);
  s += "\n";
  s += "  -> Primary Color:   " + this->primary_color_ + "\n";
  s += "  -> Secondary Color: " + this->secondary_color_ + "\n";
  s += "  -> Tertiary Color:  " + this->tertiary_color_ + "\n";
  s += "  -> Pattern:         " + this->pattern_ + "\n";
  s += "  -> Sleeve Length:   " + this->sleeve_length_ + "\n";
  s += "  -> Collar:          " + this->collar_ + "\n";

  return s;
}
