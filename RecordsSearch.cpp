#include"RecordsSearch.h"


RecordsSearch::RecordsSearch(){

}
RecordsSearch::~RecordsSearch(){

}

void RecordsSearch::bulkInsert(std::vector<Employee> records){
	for (int i = 0; i<records.size(); i++)
	{
		RecordsFName.push_back(records[i]);
		RecordsLName.push_back(records[i]);
		RecordsPWord.push_back(records[i]);
	}
	quickFName(RecordsFName, 0, RecordsFName.size() - 1);
	quickLName(RecordsLName, 0, RecordsLName.size() - 1);
	quickPWord(RecordsPWord, 0, RecordsPWord.size() - 1);
}

void RecordsSearch::quickFName(std::vector<Employee>& Vector, int front, int back){
	int start = front;
	int end = back;
	std::string pivot = Vector[(front + back) / 2].first_name;
	while (start <= end){
		while (Vector[start].first_name < pivot){ start++; }
		while (Vector[end].first_name > pivot){ end--; }
		if (start <= end){
			Employee temp = Vector[start];
			Vector[start] = Vector[end];
			Vector[end] = temp;start++;end--;
		}
	}
	if (front < end)
		quickFName(Vector, front, end);
	if (start < back)
		quickFName(Vector, start, back);
}

void RecordsSearch::quickLName(std::vector<Employee>& Vector, int front, int back){
	int start = front;
	int end = back;
	std::string pivot = Vector[(front + back) / 2].last_name;
	while (start <= end){
		while (Vector[start].last_name < pivot){ start++; }
		while (Vector[end].last_name > pivot){ end--; }
		if (start <= end){
			Employee temp = Vector[start];
			Vector[start] = Vector[end];
			Vector[end] = temp;start++;end--;
		}
	}
	if (front < end)
		quickLName(Vector, front, end);
	if (start < back)
		quickLName(Vector, start, back);
}

void RecordsSearch::quickPWord(std::vector<Employee>& Vector, int front, int back){
	int start = front;
	int end = back;
	std::string pivot = Vector[(front + back) / 2].password;
	while (start <= end){
		while (Vector[start].password < pivot){ start++; }
		while (Vector[end].password > pivot){ end--; }
		if (start <= end){
			Employee temp = Vector[start];
			Vector[start] = Vector[end];
			Vector[end] = temp;start++;end--;
		}
	}
	if (front < end)
		quickPWord(Vector, front, end);
	if (start < back)
		quickPWord(Vector, start, back);
}


int RecordsSearch::binarySearchFName(std::vector<Employee>& Vector, std::string key){
	int low = 0;
	int mid;
	int high = Vector.size() - 1;

	while (low <= high){
		mid = (low + high) / 2;
		if (key < Vector[mid].first_name){
			high = mid - 1;
		}
		else if (Vector[mid].first_name < key){
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
int RecordsSearch::binarySearchLName(std::vector<Employee>& Vector, std::string key){
	int low = 0;
	int mid;
	int high = Vector.size() - 1;
	while (low <= high){
		mid = (low + high) / 2;
		if (key < Vector[mid].last_name){
			high = mid - 1;
		}
		else if (Vector[mid].last_name < key){
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int RecordsSearch::binarySearchPWord(std::vector<Employee>& Vector, std::string key){
	int low = 0;
	int mid;
	int high = Vector.size() - 1;

	while (low <= high){
		mid = (low + high) / 2;
		if (key < Vector[mid].password){
			high = mid - 1;
		}
		else if (Vector[mid].password < key){
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}




Employee RecordsSearch::searchFirstName(std::string first_name){
	int index = binarySearchFName(RecordsFName, first_name);
	return RecordsFName[index];
}

Employee RecordsSearch::searchLastName(std::string last_name){
	int index = binarySearchLName(RecordsLName, last_name);
	return RecordsLName[index];
}

Employee RecordsSearch::searchPassword(std::string password){
	int index = binarySearchPWord(RecordsPWord, password);
	return RecordsPWord[index];

}