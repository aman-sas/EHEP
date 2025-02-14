#ifndef _MYMUON_
#define _MYMUON_
#include <iostream>
#include <vector>
#include "TObject.h"


class MyMuon{
 public:
  MyMuon(){ px = 0; py = 0; pz = 0;};
  virtual ~MyMuon(){};

  void set_m_Px(float x_){ px = x_;};
  void set_m_Py(float y_){ py = y_;};
  void set_m_Pz(float z_){ pz = z_;};

  float get_m_Px(){return px;};
  float get_m_Py(){return py;};
  float get_m_Pz(){return pz;};

 private:
  float px;
  float py;
  float pz;
  ClassDef(MyMuon,1)
};

class MuonHolder {
  std::vector<MyMuon> f1;
};

#endif


