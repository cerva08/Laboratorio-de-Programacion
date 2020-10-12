# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
# Link RBT RBTtest GTest and pthread library
include_directories(${RBT_PROJECT_SOURCE_DIR}/include)

# Add source files to executable
add_executable(RBTtest tests.cpp )
target_sources(RBTtest PUBLIC ${RBT_PROJECT_SOURCE_DIR}/src/RBTcreate.cpp
				${RBT_PROJECT_SOURCE_DIR}/src/RBTinsert.cpp
				${RBT_PROJECT_SOURCE_DIR}/src/RBTdelete.cpp
				${RBT_PROJECT_SOURCE_DIR}/src/RBTget.cpp
				${RBT_PROJECT_SOURCE_DIR}/src/RBTnode_add_fix.cpp
                ${RBT_PROJECT_SOURCE_DIR}/src/RBTprint.cpp
				${RBT_PROJECT_SOURCE_DIR}/src/RBTrotations.cpp)

target_link_libraries(RBTtest ${GTEST_LIBRARIES} pthread)
