
include(${ers_engine_SOURCE_DIR}/ERS/Utility.cmake)

ERS_Add_Filters(${CMAKE_CURRENT_SOURCE_DIR} sourceFiles)

add_library(JSON SHARED ${sourceFiles})
set_property(TARGET JSON PROPERTY CXX_STANDARD 20)
target_include_directories(JSON PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(JSON PRIVATE nlohmann_json::nlohmann_json)



ERS_Link(JSON)
