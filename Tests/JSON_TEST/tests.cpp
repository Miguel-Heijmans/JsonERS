#include <catch2/catch_all.hpp>

#include "4DSTests/Utility/Utility.h"


#include <memory>
#include <iostream>



TEST_CASE("Loading ODBC Manager") {
    std::unique_ptr<Ers::Script4D::Tests::Script4DLibrary> ODBCLibrary;
    auto executionType = ERSLIBRARYSECTIONTYPE;

    DYNAMIC_SECTION("Create new ODBC Document") {
        ODBCLibrary.reset();
        ODBCLibrary = std::make_unique<Ers::Script4D::Tests::Script4DLibrary>("JSON");


        void* output = ODBCLibrary->ExecuteFunction< void* (const char*, void*)>(executionType, "GetJsonString", "GetJsonString", "john.json").Get();
        std::cout << output << "\n";

        void* output2 = ODBCLibrary->ExecuteFunction< void* (const char*, void*)>(executionType, "GetJsonString", "GetJsonString", "cow.json").Get();
        std::cout << output2 << "\n";

        
        
        char* output3 = ODBCLibrary->ExecuteFunction< char* (void*, const char*, void*)>(executionType, "ValuePickerString", "ValuePickerString", output, "tiger").Get();
        std::cout << output3 << "\n";

        char* output4 = ODBCLibrary->ExecuteFunction< char* (void*, const char*, void*)>(executionType, "ValuePickerString", "ValuePickerString", output2, "bison").Get();
        std::cout << output4 << "\n"; 

        char* output5 = ODBCLibrary->ExecuteFunction< char* (void*, const char*, void*)>(executionType, "WriteJsonString", "WriteJsonString", output2, "merged.json").Get();
        std::cout << output5 << "\n";

    }
}

