/**
 * @class Clothes
 * @headerfile clothes.h ""
 * @author Stephen M. Reaves
 * @date July 14th, 2018
 *
 * @brief Clothes abstract class to be used by members of closet.
 *        Handles the light work.
 *
 * @detail These global variables are set for all clothes, but not all
 *         clothes use them.  For instance, pants will never need a 'collar'
 *         variable, but they do to make inheritence easier
 */

#ifndef CLOTHES_H
#define CLOTHES_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

static const int kDummyID = -1;
static const string kDummyName = "Fake Name";
static const string kDummyPrimColor = "Fake Primary Color";
static const string kDummySecColor = "Fake Secondary Color";
static const string kDummyTertColor = "Fake Tertiary Color";
static const string kDummyPattern = "Fake Pattern";
static const string kDummyMaterial = "Fake Material";
static const string kDummyStyle = "Fake Style";
static const string kDummyLength = "Fake Length";
static const string kDummyCut = "Fake Cut";
static const string kDummySleeveLength = "Fake Sleeve Length";
static const string kDummyCollar = "Fake Collar";

class Clothes {
 public:
  // Constructors and Deconstructors
  Clothes(){};
  virtual ~Clothes() {}

  // General Functions
  int GetID() { return id_; }

  virtual string ToString() const = 0;  ///< This is what makes this a purely
                                        ///< abstract class. The implementation
                                        ///< of these will be changed from one
                                        ///< article of clothing to the next.

 protected:
  int id_ = kDummyID;                          ///< Global unique identifier
  string name_ = kDummyName;                   ///< User readable name
  string primary_color_ = kDummyPrimColor;     ///< Primary color
  string secondary_color_ = kDummySecColor;    ///< Secondary color
  string tertiary_color_ = kDummyTertColor;    ///< Tertiary color
  string pattern_ = kDummyPattern;             ///< Design pattern
  string material_ = kDummyMaterial;           ///< Material
  string style_ = kDummyStyle;                 ///< Design style
  string length_ = kDummyLength;               ///< Length of the clothing
  string cut_ = kDummyCut;                     ///< Cut of the clothing
  string sleeve_length_ = kDummySleeveLength;  ///< Length of the sleeve
  string collar_ = kDummyCollar;               ///< Type of collar
};

#endif /* CLOTHES_H */
