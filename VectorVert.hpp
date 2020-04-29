#pragma once
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <map>
#include "Vector.hpp"

namespace VECTOR_HORI_VERT {

  class VectorVert : public Vector {
  public:
    using Vector::operator=;
    virtual void Output() const;
    VectorVert(const std::string& filename);
    VectorVert(const std::string& filename, int N);
    VectorVert(const Vector& other);
    ~VectorVert();
  };

}
