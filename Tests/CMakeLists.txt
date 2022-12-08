include(${ers_engine_SOURCE_DIR}/ERS/Utility.cmake)

ERS_Add_Filters(${CMAKE_CURRENT_SOURCE_DIR} sourceFiles)

add_executable(JSON_TEST ${sourceFiles})
set_property(TARGET JSON_TEST PROPERTY CXX_STANDARD 20)
target_include_directories(JSON_TEST PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(JSON_TEST PUBLIC JSON)
ERS_add_Test(JSON_TEST)