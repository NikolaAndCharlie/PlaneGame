cmake_minimum_required(VERSION 3.5)
project(game)

set(CMAKE_CURRENT_INDCLUDE_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Multimedia REQUIRED)


file(GLOB SRC src/*.cc)
file(GLOB HDR src/*.h)

set(Qt_lib Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia)

qt5_add_resources(RC src/sound1.qrc)

add_executable(game WIN32 ${SRC} ${HDR} ${RC})
target_link_libraries(game ${Qt_lib})