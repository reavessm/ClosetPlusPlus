/**
 * @class Shirt
 * @headerfile shirt.h ""
 * @author Stephen M. Reaves
 * @date
 */

#ifndef SHIRT_H
#define SHIRT_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "clothes.h"

using namespace std;

class Shirt : public Clothes {
 public:
  // Constructors and Deconstructors
  Shirt();
  Shirt(int id, string name, string prim_color, string sec_color,
        string tert_color, string pattern, string sleeve_length, string collar);
  virtual ~Shirt();

  // General Functions

  // bool IsDirty();

  string ToXML() const;
  string ToString() const;

 private:
  // Variables

  // Private Functions
};

#endif /* SHIRT_H */
