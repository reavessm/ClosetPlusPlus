/******************************************************************************
 * File Name: shoes.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary: Header File for 'Shoes' class in the Closet++ program
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "clothes.h"

using namespace std;

#ifndef SHOES_H
#define SHOES_H

class Shoes : public Clothes {
  public:
    //Constructors and Deconstructors
    Shoes();
    Shoes(int id, string name, string prim_color, string sec_color, 
          string tert_color, string material, string style); 
    virtual ~Shoes();

    //General Functions

    //bool IsDirty();

    string ToXML() const;
    string ToString() const;
  
  private:
    //Variables

    //Private Functions

};


#endif /* SHOES_H */ 
