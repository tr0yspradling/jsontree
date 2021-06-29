cmake_minimum_required(VERSION 3.2)

project(jsontree VERSION 1.0)

set(APPLICATION_ID "tr0y.me.jsontree")
string(REPLACE "." "/" APPLICATION_PREFIX "/${APPLICATION_ID}/")

list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
include(GlibUtils)
include(InstallScript)

set(GENERATED_FILES_DIR ${PROJECT_BINARY_DIR}/generated)
set(SOURCES_DIR ${GENERATED_FILES_DIR}/src)
set(DATA_DIR ${GENERATED_FILES_DIR}/data)
set(INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

configure_file(cmake/projectdefinitions.h.in ${SOURCES_DIR}/projectdefinitions.h)

find_package(GTKMM)

add_subdirectory(src)
add_subdirectory(data)
add_subdirectory(test)
add_subdirectory(include/rapidjson)

install(FILES cmake/uninstall.sh DESTINATION ${PROJECT_BINARY_DIR} PERMISSIONS OWNER_EXECUTE OWNER_READ OWNER_WRITE)
