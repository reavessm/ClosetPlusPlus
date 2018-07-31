/******************************************************************************
 * File Name: socks.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary: Header File for 'Socks' class in the Closet++ program
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "clothes.h"

using namespace std;

#ifndef SOCKS_H
#define SOCKS_H

class Socks : public Clothes {
 public:
  // Constructors and Deconstructors
  Socks();
  Socks(int id, string name, string prim_color, string sec_color,
        string tert_color, string pattern);
  virtual ~Socks();

  // General Functions

  // bool IsDirty();

  string ToXML() const;
  string ToString() const;

 private:
  // Variables

  // Private Functions
};

#endif /* SOCKS_H */
