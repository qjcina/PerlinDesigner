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
    src/GUI/ImagePainterManager.h
    src/GUI/ImagePainterAdapter.h

    src/NoiseGen/AverageValueNoiseData.h
    src/NoiseGen/Octave2D.h

    src/NoiseGen/IImageData.h
    src/NoiseGen/INoiseOctave.h
    src/NoiseGen/INoiseAlgorithm.h
    src/NoiseGen/INoiseCoordinate.h
    src/NoiseGen/NoiseIterator.h
    src/NoiseGen/NoiseCoordinate.h
    src/NoiseGen/NoiseAlgorithm.h
    src/NoiseGen/NoiseEngine.h
    src/NoiseGen/MathPD.h

    src/OctaveSettings/IOctaveSetting.h
    src/OctaveSettings/IDataFactory.h
    src/OctaveSettings/OctaveSettingsEntry.h
    src/OctaveSettings/PerlinDataFactory.h

    src/Models/OctavesModel.h
    src/Models/IOctavesModel.h

    src/Utils/QMLPointer.h
    src/Utils/AbstractSingleton.h

    src/CommonTypes.h
    src/CommonFunctions.h
)

set(SOURCE_FILES
    src/main.cpp

    src/GUI/qml.qrc
    src/GUI/ImagePainter.cpp
    src/GUI/ImagePainterManager.cpp
    src/GUI/ImagePainterAdapter.cpp

    src/NoiseGen/AverageValueNoiseData.cpp
    src/NoiseGen/Octave2D.cpp

    src/NoiseGen/NoiseIterator.cpp
    src/NoiseGen/NoiseCoordinate.cpp
    src/NoiseGen/NoiseAlgorithm.cpp
    src/NoiseGen/NoiseEngine.cpp
    src/NoiseGen/MathPD.cpp

    src/OctaveSettings/OctaveSettingsEntry.cpp
    src/OctaveSettings/PerlinDataFactory.cpp

    src/Models/OctavesModel.cpp
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
