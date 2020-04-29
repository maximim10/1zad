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

  class VectorHori  : public Vector {
protected:

  public:
    using Vector::operator=;
    virtual void Output() const;// override;
    friend VectorHori operator+(Vector& first, Vector& second);
    friend VectorHori operator-(Vector& first, Vector& second);
    VectorHori(const std::string& filename, int N);
    VectorHori(const std::string& filename);
    VectorHori(const Vector& other);
    VectorHori(const VectorHori& other);
    ~VectorHori();
  };
}
