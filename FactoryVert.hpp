#pragma once

#include "Factory.hpp"
#include "Vector.hpp"
#include "VectorHori.hpp"
namespace VECTOR_HORI_VERT {
class FactoryVert : public Factory{
public:
    virtual Vector* Create (const std::string& filename, int N){
        return new VectorVert (filename, N);
    }
};
}
