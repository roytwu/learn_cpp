#ifndef READCSV_H_
#define READCSV_H_

#include <boost/algorithm/string.hpp>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::ifstream;
using std::getline;

class CSVReader{
public:
	CSVReader(string filename, string delim = ","): fileName(filename), delimeter(delim) {}

	//function to fetch data from a CSV file
	vector< vector<string> > getData(); 
	
private:	
	string fileName;
	string delimeter;
};


// Parses through csv file line by line and returns the data in vector of vector of strings  
vector< vector<string> > CSVReader::getData(){
	ifstream o_input;
	o_input.open(fileName);
	
	vector< vector<string> > dataList;
	
	string line;
	while(getline(o_input, line)){
		vector<string> v_foo;
		boost::algorithm::split(v_foo, line, boost::algorithm::is_any_of(delimeter));
		dataList.push_back(v_foo);
	}
	o_input.close();

	return dataList;
}


#endif  //READCSV_H_