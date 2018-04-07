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

using namespace std;

#ifndef PANTS_H
#define PANTS_H

const int kDummyPantsID = -1;
const string kDummyPantsName = "Fake Name";
const string kDummyPantsPrimColor = "Fake Primary Color";
const string kDummyPantsSecColor = "Fake Secondary Color";
const string kDummyPantsTertColor = "Fake Tertiary Color";
const string kDummyPantsMaterial = "Fake Material";
const string kDummyPantsLength = "Fake Length";
const string kDummyPantsCut = "Fake Cut";

class Pants {
  public:
    //Constructors and Deconstructors
    Pants();
    Pants(int id, string name, string prim_color, string sec_color, 
          string tert_color, string material, string length, 
          string cut);
    virtual ~Pants();

    //General Functions
    int GetID();
    string GetName();
    string GetPrimColor();
    string GetSecColor();
    string GetTertColor();
    string GetMaterial();
    string GetLength();
    string GetCut();

    void SetName(string name);
    void SetPrimColor(string color);
    void SetSecColor(string color);
    void SetTertColor(string color);
    void SetMaterial(string material);
    void SetLength(string length);
    void SetCut(string cut);

    //bool IsDirty();

    string ToXML() const;
    string ToString() const;
  
  private:
    //Variables
    int id_ = kDummyPantsID;
    string name_ = kDummyPantsName;
    string primary_color_ = kDummyPantsPrimColor;
    string secondary_color_ = kDummyPantsSecColor;
    string tertiary_color_ = kDummyPantsTertColor;
    string material_ = kDummyPantsMaterial;
    string length_ = kDummyPantsLength;
    string cut_ = kDummyPantsCut;

    //Private Functions


};


#endif /* PANTS_H */ 
