/******************************************************************************
 * File Name: pants.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary: Header File for 'Pants' class in the Closet++ program
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "clothes.h"

using namespace std;

#ifndef PANTS_H
#define PANTS_H

class Pants : public Clothes {
  public:
    //Constructors and Deconstructors
    Pants();
    Pants(int id, string name, string prim_color, string sec_color, 
          string tert_color, string material, string length, 
          string cut);
    virtual ~Pants();

    //General Functions

    //bool IsDirty();

    string ToXML() const;
    string ToString() const;
  
  private:
    //Variables

    //Private Functions

};


#endif /* PANTS_H */ 
