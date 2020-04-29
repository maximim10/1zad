project(VectorHoriVert)

set(VECTOR_SRC main.cpp Vector.cpp VectorHori.cpp VectorVert.cpp)
set(VECTOR_HDR Vector.hpp VectorHori.hpp VectorVert.hpp Factory.hpp FactoryHori.hpp FactoryVert.hpp)

#add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_library(vector STATIC ${VECTOR_SRC} ${VECTOR_HDR})
add_executable(${PROJECT_NAME} ${VECTOR_SRC} ${VECTOR_HDR})