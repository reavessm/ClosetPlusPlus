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

/*const int kDummyBeltID = -1;
const string kDummyBeltName = "Fake Name";
const string kDummyBeltPrimColor = "Fake Primary Color";
const string kDummyBeltSecColor = "Fake Secondary Color";
const string kDummyBeltTertColor = "Fake Tertiary Color";
const string kDummyBeltMaterial = "Fake Material"; */

class Belt : public Clothes{
  public:
    //Constructors and Deconstructors
    Belt();
    Belt(int id, string name, string prim_color, string sec_color, 
          string tert_color, string material, string pattern); 
    virtual ~Belt();

    //General Functions
    int GetID();
    string GetName();
    string GetPrimColor();
    string GetSecColor();
    string GetTertColor();
    string GetMaterial();
    string GetPattern();

    void SetName(string name);
    void SetPrimColor(string color);
    void SetSecColor(string color);
    void SetTertColor(string color);
    void SetMaterial(string material);
    void SetPattern(string pattern);

    //bool IsDirty();

    string ToXML() const;
    string ToString() const;
  
  private:
    //Variables
    int id_ = kDummyBeltID;
    string name_ = kDummyBeltName;
    string primary_color_ = kDummyBeltPrimColor;
    string secondary_color_ = kDummyBeltSecColor;
    string tertiary_color_ = kDummyBeltTertColor;
    string material_ = kDummyBeltMaterial;
    string pattern_ = kDummyPattern;

    //Private Functions


};


#endif /* BELT_H */ 
