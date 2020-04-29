#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <map>

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

/*VectorHori operator-(Vector& first, Vector& other) {
    Vector* temp = new VectorHori(first.filename_, 1);
    temp->L=std::max(first.L,other.L);
    delete [] temp->vector_;
    temp->vector_=new int[std::max(first.L,other.L)];
    int mm=std::max(first.L,other.L)-std::min(first.L,other.L);
    if ((first.znak * other.znak) > 0){
        temp->znak=first.znak;
        if (first.L > other.L){
            temp->znak=first.znak;
        }else if (first.L < other.L){
            temp->znak=-first.znak;
        }else{
            for(int i=0; i<other.L; i++){
                if (first.vector_[i] < other.vector_[i]){
                    temp->znak=-first.znak;
                    break;
                }
            }
        }
        for (int i=std::max(first.L,other.L)-1; i>=0; i--) {

                temp->vector_[i] = ((temp->znak==first.znak ? first.vector_[i] : other.vector_[i]) -
                                (temp->znak==first.znak ? (i-mm>=0 ? other.vector_[i-mm] : 0) : (i-mm>=0 ? first.vector_[i-mm] : 0)));

        }


        for (int i=std::max(first.L,other.L)-1;i>0;i--) {
            if (temp->vector_[i]<0){
                temp->vector_[i-1]--;
                temp->vector_[i]+=10;
            }
        }
        temp->vector_[0]=std::abs(temp->vector_[0]);
        int j=0;
        for (int i=0; i<temp->L; i++){
            if (temp->vector_[i]>0){
                break;
            }else{
                j+=1;
            }
        }
        if (j>0){
            int* vtemp;
            vtemp=new int[temp->L-j];
            for (int i=0;i<temp->L-j;i++){
                vtemp[i]=temp->vector_[i+j];
            }
            delete [] temp->vector_;
            temp->vector_=vtemp;
            temp->L=temp->L-j;
        }
        return (*temp);
    }else{
        *temp=other;
        temp->znak=-(temp->znak);
        return ((first)+*temp);
    }
  }
  VectorHori operator+(Vector& first, Vector& other) {
    Vector* temp;                                                                                                                       \
    temp = new VectorHori(first.get_filename(),1);
    temp->L=std::max(first.L, other.L);
    delete [] temp->vector_;
    temp->vector_=new int[temp->L];
    int mm=std::max(first.L, other.L)-std::min(first.L, other.L);
    if ((first.znak * other.znak) > 0){
        temp->znak=other.znak;
        for(int i=std::max(first.L, other.L)-1;i>=0;i--){
            temp->vector_[i] = ((first.L > other.L ? first.vector_[i] : (i-mm>=0 ? first.vector_[i-mm] : 0)) +
                            (other.L > first.L ? other.vector_[i] : (i-mm>=0 ? other.vector_[i-mm] : 0)));
        }
        for(int i=std::max(first.L,other.L)-1;i>0;i--){
            if (temp->vector_[i]>9){
                temp->vector_[i-1]++;
                temp->vector_[i]-=10;
            }
        }
        if(temp->vector_[0]>9){
            int* vtemp;
            vtemp=new int[std::max(first.L, other.L)+1];
            for (int i=std::max(first.L, other.L);i>0;i--){
                vtemp[i]=temp->vector_[i-1];
            }
            vtemp[0]=1;
            vtemp[1]-=10;
            delete [] temp->vector_;
            temp->vector_=vtemp;
            temp->L=temp->L+1;
        }
        return (*temp);
    }else{
        (*temp)=other;
        temp->znak=-(temp->znak);
        return (first-(*temp));
     }
  }*/
int main() {
  try {

    /* smart pointer - unique_ptr */
    std::map < std::string, Factory* > factoryMap;
    //factoryMap["Hori"] = std::make_unique<FactoryHori<EL_TYPE>>();    // unexpectedly make_unique() is C++14
    factoryMap["Hori"] = new FactoryHori;
    //factoryMap["Vert"] = std::make_unique<FactoryVert<EL_TYPE>>();
    factoryMap["Vert"] = new FactoryVert;

    /* smart pointer - shared_ptr */
    std::vector< Vector* > vectorVector;
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
      std::map< std::string, Factory* >::iterator curFactory;
      curFactory = factoryMap.find(vectorType);
      if (curFactory == factoryMap.end()) {
        throw std::invalid_argument("Error! Wrong type of+ vector in file input.txt!\n");
      }

      Vector* curVect = curFactory->second->Create(fileName, el);
      vectorVector.push_back(curVect);
    }

    inputFile.close();

    /* range-based loop */
    for(int i=0;i<vectorVector.size();i++){
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
