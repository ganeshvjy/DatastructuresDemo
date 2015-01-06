#pragma once
#include"Interfaces03.h"

class RecordsSearch :public IRecordsSearch{
public:RecordsSearch();
	   ~RecordsSearch();
	   void bulkInsert(std::vector<Employee> records);
	   Employee searchFirstName(std::string first_name);
	   Employee searchLastName(std::string last_name);
	   Employee searchPassword(std::string password);

	   void quickFName(std::vector<Employee>& Vector, int front, int back);
	   void quickLName(std::vector<Employee>& Vector, int front, int back);
	   void quickPWord(std::vector<Employee>& Vector, int front, int back);

	   int binarySearchFName(std::vector<Employee>& Vector, std::string key);
	   int binarySearchLName(std::vector<Employee>& Vector, std::string key);
	   int binarySearchPWord(std::vector<Employee>& Vector, std::string key);

private:
	std::vector<Employee> RecordsFName;
	std::vector<Employee> RecordsLName;
	std::vector<Employee> RecordsPWord;
};