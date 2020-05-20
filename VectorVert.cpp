#include "VectorVert.hpp"

namespace VECTOR_HORI_VERT {
  void VectorVert::Output() const {
    std::ofstream fil;
    fil.open(this->get_filename().c_str(), std::ios_base::app);
    if (!fil.is_open()) {
      throw std::invalid_argument("Error! Cannot open file " + this->get_filename() + "!\n");
    }
    fil << this-> znak << '*';
    for (unsigned int i = 0; i < this->L; i++) {
      fil << this->vector_[i] << "\n  ";
    }
    fil << std::endl;
    fil.close();
  }
  VectorVert::VectorVert(const std::string& filename, int N)
    : Vector(filename, N)
  {
  }
  VectorVert::VectorVert(const std::string& filename)
    : Vector(filename)
  {
  }
  VectorVert::VectorVert(const Vector& other)
    : Vector(other)
  {
  }
  VectorVert::~VectorVert() {
  }

}
