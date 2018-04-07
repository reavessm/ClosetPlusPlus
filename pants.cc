#include "pants.h"
/******************************************************************************
 * File Name: pants.cc
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary:
 *
 */


/******************************************************************************
 * Constructor
 */
Pants::Pants() {}

Pants::Pants(int id, string name, string prim_color, string sec_color, string tert_color, string material, string length, string cut) {
  this->id_ = id;
  this->name_ = name;
  this->primary_color_ = prim_color;
  this->secondary_color_ = sec_color;
  this->tertiary_color_ = tert_color;
  this->material_ = material;
  this->length_ = length;
  this->cut_ = cut;
}

/******************************************************************************
 * Deconstructor
 */
Pants::~Pants() {}

/******************************************************************************
 * Accessors and Mutators
 */

int Pants::GetID() { return this->id_; }
string Pants::GetName() { return this->name_; }
string Pants::GetPrimColor() { return this->primary_color_; }
string Pants::GetSecColor() { return this->secondary_color_; }
string Pants::GetTertColor() { return this->tertiary_color_; }
string Pants::GetMaterial() { return this->material_; }
string Pants::GetCut() { return this->cut_; }

void Pants::SetName(string name) { this->name_ = name; }
void Pants::SetPrimColor(string color) { this->primary_color_ = color; }
void Pants::SetSecColor(string color) { this->secondary_color_ = color; }
void Pants::SetTertColor(string color) { this->tertiary_color_ = color; }
void Pants::SetMaterial(string material) { this->material_ = material; }
void Pants::SetCut(string cut) { this->cut_ = cut; }

/******************************************************************************
 * General Functions
 */

/*****************************************************************************
 * Function 'ToXML'
 * Returns:
 *    XML representation of the shirt
 */
string Pants::ToXML() const {
  string s = "";

  s += "  <Pants ID=" + to_string(this->id_) + ">\n";
  s += "    <Name>" + this->name_ + "</Name>\n";
  s += "    <Primary Color>" + this->primary_color_ + "</Primary Color>\n";
  s += "    <Secondary Color>" + this->secondary_color_ + "</Secondary Color>\n";
  s += "    <Tertiary Color>" + this->tertiary_color_ + "</Tertiary Color>\n";
  s += "    <Material>" + this->material_ + "</Material>\n";
  s += "    <Length>" + this->length_ + "</Length>\n";
  s += "  </Pants>\n";
  
  return s;
}

/******************************************************************************
 * Function 'ToString'
 * Returns:
 *    'string' representing the pants.
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
