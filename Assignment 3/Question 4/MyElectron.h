#ifndef _MYELECTRON_
#define _MYELECTRON_
#include <iostream>
#include <vector>
#include "TObject.h"


class MyElectron{
 public:
  MyElectron(){ px = 0; py = 0; pz = 0;};
  virtual ~MyElectron(){};

  void set_e_Px(float x_){ px = x_;};
  void set_e_Py(float y_){ py = y_;};
  void set_e_Pz(float z_){ pz = z_;};

  float get_e_Px(){return px;};
  float get_e_Py(){return py;};
  float get_e_Pz(){return pz;};

 private:
  float px;
  float py;
  float pz;
  ClassDef(MyElectron,1)
};

class ElectronHolder {
  std::vector<MyElectron> f1;
};

#endif


