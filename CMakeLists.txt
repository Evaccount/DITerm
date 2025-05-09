cmake_minimum_required(VERSION 3.10)

# Variables pour le nom du projet et de l'exécutable
set(PROJECT_NAME DITerm)
set(EXECUTABLE_NAME diterm)

# Nom du projet
project(${PROJECT_NAME})

# Spécifiez le standard C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajoutez le dossier include
include_directories(include)

# Ajoutez tous les fichiers .cpp dans le dossier src
file(GLOB SOURCES src/*.cpp)

# Ajoutez le fichier main.cpp
set(MAIN_SOURCE main.cpp)

# Créez l'exécutable
add_executable(${EXECUTABLE_NAME} ${SOURCES} ${MAIN_SOURCE})

# Spécifiez le dossier de sortie pour le binaire
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
