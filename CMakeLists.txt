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

# Trouvez OpenCV
find_package(OpenCV REQUIRED)

# Incluez les répertoires d'OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

# Créez l'exécutable
add_executable(${EXECUTABLE_NAME} ${SOURCES} ${MAIN_SOURCE})

# Liez OpenCV à votre exécutable
target_link_libraries(${EXECUTABLE_NAME} ${OpenCV_LIBS})

# Spécifiez le dossier de sortie pour le binaire
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
