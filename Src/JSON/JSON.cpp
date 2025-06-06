#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <vector>


#include <memory>

class JSONContext {
public:
	std::vector<std::unique_ptr<nlohmann::json>> jsonVector;

};

#define Script4DContextClass JSONContext
#define ERS_API_CREATORNAME "JSON Library"
#define ERS_API_ENABLE
#define ERS_API_4DSCRIPT_LOGGING
#include "4DScriptLibrary/4DScriptLibrary.h"

constexpr const char* Category = "Miguel";

ERS_API void* GetJsonString(const char* inputstring, JSONContext* stateInstance)
{
	auto filepath = std::filesystem::current_path().string() + "\\" + std::string(inputstring);//sets the path to the json file

	std::ifstream file_input(filepath);//reads the contents of the json file

	stateInstance->jsonVector.push_back(std::make_unique<nlohmann::json>(nlohmann::json::parse(file_input)));

	


	return stateInstance->jsonVector.at(stateInstance->jsonVector.size() - 1).get(); //returns the amount of different groups in the json files
}



ERS_API_DEFINE4DSFUNCTIONLINK(
	GetJsonString,
	GetJsonString,
	Category, "retrieves json string"
);


ERS_API char* ValuePickerString(void* jsonPointer, const char* inputString, JSONContext* stateInstance)
{
	nlohmann::json* jsonFile = reinterpret_cast<nlohmann::json*>(jsonPointer);




	for (auto& element : jsonFile->items())
	{
		std::cout << element.key() << " " << element.value() << "\n";
	}


	return CopyString("hello");

}

ERS_API_DEFINE4DSFUNCTIONLINK(
	ValuePickerString,
	ValuePickerString,
	Category, "picks value"
);




ERS_API char* WriteJsonString(void* jsonPointer, const char* inputstring, JSONContext* stateInstance)
{

	nlohmann::json* jsonFile = reinterpret_cast<nlohmann::json*>(jsonPointer);

	for (auto& element : jsonFile->items())
	{
		std::ofstream o(inputstring, std::ios::app);
		o << std::setw(4) << element.key() << " " << element.value() << "\n";
	}

	//std::ofstream o(inputstring,std::ios::app);
	//o << std::setw(4) << *jsonFile << std::endl; 
	


	return CopyString("");


}

ERS_API_DEFINE4DSFUNCTIONLINK(
	WriteJsonString,
	WriteJsonString,
	Category, "writes json string"
);





