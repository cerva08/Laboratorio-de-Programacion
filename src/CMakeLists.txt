include_directories(${RBT_PROJECT_SOURCE_DIR}/include)
add_executable(RBT main.cpp)
target_sources(RBT PUBLIC RBTcreate RBTdelete RBTget RBTinsert RBTnode_add_fix RBTprint RBTrotations)

