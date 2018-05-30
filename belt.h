/******************************************************************************
 * File Name: belt.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary: Header File for 'Belt' class in the Closet++ program
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "clothes.h"

using namespace std;

#ifndef BELT_H
#define BELT_H

class Belt : public Clothes{
  public:
    //Constructors and Deconstructors
    Belt();
    Belt(int id, string name, string prim_color, string sec_color, 
          string tert_color, string material, string pattern); 
    virtual ~Belt();

    //General Functions

    //bool IsDirty();

    string ToXML() const;
    string ToString() const;
  
  private:
    //Variables

    //Private Functions

};


#endif /* BELT_H */ 
