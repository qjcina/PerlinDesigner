cmake_minimum_required(VERSION 3.5)

project(PerlinDesigner LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

set(HEADER_FILES
    src/GUI/IImagePainter.h
    src/GUI/ImagePainter.h

    src/NoiseGen/IImageData.h
    src/NoiseGen/INoiseOctave.h
    src/NoiseGen/NoiseIterator.h
    src/NoiseGen/PerlinData.h
    src/NoiseGen/PerlinOctave.h

    src/OctaveSettings/IOctaveSetting.h
    src/OctaveSettings/OctaveSettingsEntry.h
    src/OctaveSettings/OctavesManager.h
    src/OctaveSettings/PerlinDataFactory.h

    src/Models/OctavesModel.h

    src/Utils/QMLPointer.h

    src/CommonTypes.h

    src/EventEngine/EventEngine.h
    src/EventEngine/EventListener.h
    src/EventEngine/EventThread.h
    src/EventEngine/Event.h
)

set(SOURCE_FILES
    src/main.cpp

    src/GUI/qml.qrc
    src/GUI/ImagePainter.cpp

    src/NoiseGen/PerlinData.cpp
    src/NoiseGen/PerlinOctave.cpp
    src/NoiseGen/NoiseIterator.cpp

    src/OctaveSettings/OctavesManager.cpp
    src/OctaveSettings/OctaveSettingsEntry.cpp
    src/OctaveSettings/PerlinDataFactory.cpp

    src/Models/OctavesModel.cpp

    src/EventEngine/EventEngine.cpp
    src/EventEngine/EventListener.cpp
    src/EventEngine/EventThread.cpp
)

add_executable(PerlinDesigner
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

target_include_directories(PerlinDesigner PRIVATE
    src/
)

target_compile_definitions(PerlinDesigner
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(PerlinDesigner
  PRIVATE Qt5::Core Qt5::Quick)
