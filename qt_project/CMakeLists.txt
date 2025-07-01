cmake_minimum_required(VERSION 3.10)
project(QtLibraryGUI)

set(CMAKE_CXX_STANDARD 17)

# 🔧 Adjust this path if needed
set(CMAKE_PREFIX_PATH "C:/msys64/ucrt64")

# ✅ Find required Qt modules
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# ✅ Include headers + the build directory for generated files
include_directories(include ${CMAKE_CURRENT_BINARY_DIR})

# ✅ Process the .ui file (designed in Qt Designer)
qt6_wrap_ui(UI_HEADERS ui/MainWindow.ui)

# ✅ Add the executable and source files
add_executable(QtLibraryGUI
    main.cpp
    MainWindow.cpp
    src/Library.cpp
    ${UI_HEADERS}  # Generated from .ui file
)

# ✅ Link Qt libraries
target_link_libraries(QtLibraryGUI Qt6::Core Qt6::Gui Qt6::Widgets)

# ✅ Keep console window open (optional)
target_compile_definitions(QtLibraryGUI PRIVATE QT_DEBUG_CONSOLE)
