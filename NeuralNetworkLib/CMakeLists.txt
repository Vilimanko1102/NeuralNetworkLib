# CMakeList.txt : CMake project for NeuralNetworkLib, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (NeuralNetworkLib "main.c" "NeuralNetworkLib.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NeuralNetworkLib PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
