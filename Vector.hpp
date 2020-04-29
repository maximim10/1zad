#pragma once
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <map>

namespace VECTOR_HORI_VERT {

class Vector{
protected:
public:
    std::string filename_;
    int L;
    int znak;
    int* vector_;
    unsigned int get_length() const;
    std::string get_filename() const;
    virtual void Output() const = 0;
    Vector(const std::string& filename);
    Vector(const std::string& filename, int N);
    Vector(const Vector& other);
    void operator=(const Vector& other);
    //Vector(Vector<T>&& tmp);               // rvalue reference in move constructor
    //Vector& operator=(Vector<T>&& tmp);    // rvalue reference in move assignment operator

    virtual ~Vector();
  };

}
