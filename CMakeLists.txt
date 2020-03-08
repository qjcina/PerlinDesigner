cmake_minimum_required(VERSION 3.5)

project(PerlinDesigner LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_executable(PerlinDesigner
  src/main.cpp
  src/GUI/qml.qrc
  src/GUI/ImagePainter.cpp
  src/OctaveSettings/OctaveSettingsList.cpp
  src/OctaveSettings/OctaveSettingsEntry.cpp
  src/PerlinData.cpp
  src/PerlinOctave.cpp
  src/NoiseIterator.cpp
)

target_compile_definitions(PerlinDesigner
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(PerlinDesigner
  PRIVATE Qt5::Core Qt5::Quick)
