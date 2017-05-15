cmake_minimum_required (VERSION 3.1.0)
project (Qtic-Qtac-Qtoe)

# Invoke moc accordingly and handle Qt moc preprocessor automatically.
set (CMAKE_AUTOMOC ON)

# Invoke uic accordingly and handle Qt uic code generator automatically.
set (CMAKE_AUTOUIC ON)

# Find include in corresponding build directories.
set (CMAKE_INCLUDE_CURRENT_DIR ON)

# Find Qt libraries.
find_package (Qt5Widgets)

# Set C++ standard to C++11.
set (CMAKE_CXX_STANDARD 11)

# Set C++ flags.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${QtWidgets_EXECUTABLE_COMPILE_FLAGS}")

# Set path to executable output.
set (EXECUTABLE_OUTPUT_PATH ../bin)

# Create an executable "tictactoe".
add_executable (tictactoe
                ../src/main.cpp
                ../src/mainwindow.cpp
                ../src/tic-tac-toe.cpp)

# Link libraries to the executable.
target_link_libraries (tictactoe Qt5::Widgets)

