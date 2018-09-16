#include "main.h"
/**
 * @file main.cc
 * @author Stephen M. Reaves
 * @date July 14th, 2018
 */

int main(int argc, char** argv) {
  // if arg is Make, Build, Pick, do things

  fileFrontName = frontend_.GetClosetName();
  filename = fileFrontName + fileSurname;
  cloname = fileFrontName + cloSurname;

  myFile.open(filename.c_str());
  // myClo.open(cloname.c_str());

  frontend_.Init();
  frontend_.CreateCloset();

  output = frontend_.ToString();

  frontend_.Die();

  myFile << output;
  cout << output;
  // myClo << frontend_.StoreCloset();
  //  storeMyFile << closet.StoreCloset();

  myFile.close();
  // myClo.close();

  return 0;
}
