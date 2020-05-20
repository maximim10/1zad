#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include "Vector.hpp"
//#include "Vector.cpp"
#include "VectorHori.hpp"
//#include "VectorHori.cpp"
#include "VectorVert.hpp"
//#include "VectorVert.cpp"
#include "Factory.hpp"
#include "FactoryHori.hpp"
#include "FactoryVert.hpp"

using namespace VECTOR_HORI_VERT;
int autotest(){
    try
    {
    Vector* v1=new VectorHori("Test.txt",73);
    Vector* v2=new VectorHori("Test.txt",57);
    VectorHori v4=*v1-*v2;
    VectorHori v3=*v1+*v2;
    if ( (v3.vector_[0]==1) && (v3.vector_[1]==3) && (v3.vector_[2]==0) && (v3.L==3)
      && (v4.vector_[0]==1) && (v4.vector_[1]==6) && (v4.L==2) ){
        delete v2;
        delete v1;
        return 0;
    }else{
        v4.Output();
        delete v2;
        delete v1;
        return 1;
    }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}
int main() {
  try {
    int aut=autotest();
    if (aut!=0){
    std::cout<<"HMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<std::endl;
    return -1;
    }
    //factoryMap["Hori"] = std::make_unique<FactoryHori<EL_TYPE>>();    // unexpectedly make_unique() is C++14
    Factory* factoryMapH = new FactoryHori;
    //factoryMap["Vert"] = std::make_unique<FactoryVert<EL_TYPE>>();
    Factory* factoryMapV = new FactoryVert;

    /* smart pointer - shared_ptr */
    //std::vector< Vector* > vectorVector;
    Vector** vectorVector;
    Vector** tmpvctr;
    int ctr=0;
    const std::string inputFileName = "input.txt";

    /*
    * Format of input file is:
    * Hori file1.txt 1 2 3
    * Vert file2.txt 8 9 10
    */

    std::ifstream inputFile(inputFileName.c_str(), std::ios_base::in);
    if (!inputFile.is_open()) {
        throw std::invalid_argument("Error! Cannot open file " + inputFileName + "!\n");
    }

    std::string tmpString;
    Vector* curVect;

    while (std::getline(inputFile, tmpString)) {
      std::stringstream strStream;
      strStream << tmpString;

      std::string vectorType;
      strStream >> vectorType;
      //std::cout << vectorType << std::endl;
      std::string fileName;
      strStream >> fileName;
      int el;
      strStream >> el;

      if (vectorType=="Hori"){
        curVect = factoryMapH->Create(fileName, el);
      }else if (vectorType=="Vert"){
        curVect = factoryMapV->Create(fileName, el);
      }else{
        throw std::invalid_argument("Error! Wrong type of+ vector in file input.txt!\n");
      }
      tmpvctr=vectorVector;
      ++ctr;

      vectorVector=new Vector*[ctr];
      for(int b=0;b<ctr-1;++b){
        vectorVector[b]=tmpvctr[b];
      }
      delete [] tmpvctr;
      vectorVector[ctr-1]=curVect;
    }

    inputFile.close();

    /* range-based loop */
    for(int i=0;i<ctr;i++){
        vectorVector[i]->Output();
    }
    /*for (const auto& vect : vectorVector) {
      vect->Output();
    }*/

    return 0;
  }

  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
