CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(TEST1)

SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb -pthread -Wall -Wextra")
SET(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb -pthread -Wall -Wextra")

SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -Wextra")
SET(CMAKE_C_FLAGS_RELEASE "-O3 -Wall -Wextra")

SET(CMAKE_CXX_STANDARD 17)

SET(APPLICATION_NAME "${PROJECT_NAME}" CACHE STRING "")
SET(VERSION_NUMBER "dev" CACHE STRING "")

MESSAGE("Application name ${APPLICATION_NAME}")
MESSAGE("Version number ${VERSION_NUMBER}")

CONFIGURE_FILE(Options.h.in ${PROJECT_SOURCE_DIR}/src/Options.h)

INCLUDE_DIRECTORIES( src/ )

SET(SRC 
    src/main.cpp
    src/BaseApplication/BaseApplication.cpp
    src/TestApplication/TestApplication.cpp

    src/Parser/Parser.cpp
    src/Parser/ParserCreator.cpp

    src/FileReader/FileReader.cpp    
    src/FileReader/FileReaderCreator.cpp

    src/ParseProcessor/ParseProcessor.cpp
    src/ParseProcessor/ParseProcessorCreator.cpp

    src/Report/Report.cpp
    src/Report/ReportCreator.cpp

)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC} )

TARGET_LINK_LIBRARIES(${PROJECT_NAME} pthread)
