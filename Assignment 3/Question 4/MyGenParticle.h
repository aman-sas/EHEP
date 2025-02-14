#ifndef _MYGENPARTICLE_
#define _MYGENPARTICLE_
#include <iostream>
#include <vector>
#include "TObject.h"


class MyGenParticle{
 public:
  MyGenParticle(){ px = 0; py = 0; pz = 0;};
  virtual ~MyGenParticle(){};

  void set_GP_Px(float x_){ px = x_;};
  void set_GP_Py(float y_){ py = y_;};
  void set_GP_Pz(float z_){ pz = z_;};

  float get_GP_Px(){return px;};
  float get_GP_Py(){return py;};
  float get_GP_Pz(){return pz;};

 private:
  float px;
  float py;
  float pz;
  ClassDef(MyGenParticle,1)
};

class GenP_Holder {
  std::vector<MyGenParticle> f1;
};

#endif


