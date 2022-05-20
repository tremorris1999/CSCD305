# CSCD305/Assignment4

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Terrain.obj
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(Assignment4
    "bin/graph_tester.cpp.o"
    "src/Point3D.cpp"
    "src/Graph.cpp"
)