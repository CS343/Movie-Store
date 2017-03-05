#include "nodedata.h"

/*
THIS APPROACH, the MOVIE class is an ABSTRACT NODE DATA class, each Movie type will inherit that NODE DATA methods,
 such as comparision and define how they are compared.

*/
//------------------- constructors/destructor  -------------------------------
NodeData::NodeData() { data = ""; }                         // default

NodeData::~NodeData() { }            // needed so strings are deleted properly

NodeData::NodeData(const NodeData& nd) { data = nd.data; }  // copy

NodeData::NodeData(const string& s) { data = s; }    // cast string to NodeData

//------------------------- operator= ----------------------------------------
NodeData& NodeData::operator=(const NodeData& rhs) {
	if (this != &rhs) {
		data = rhs.data;
	}
	return *this;
}

//------------------------- operator==,!= ------------------------------------
bool NodeData::operator==(const NodeData& rhs) const {
	return data == rhs.data;
}

bool NodeData::operator!=(const NodeData& rhs) const {
	return data != rhs.data;
}

//------------------------ operator<,>,<=,>= ---------------------------------
bool NodeData::operator<(const NodeData& rhs) const {
	return data < rhs.data;
}

bool NodeData::operator>(const NodeData& rhs) const {
	return data > rhs.data;
}

bool NodeData::operator<=(const NodeData& rhs) const {
	return data <= rhs.data;
}

bool NodeData::operator>=(const NodeData& rhs) const {
	return data >= rhs.data;
}

//------------------------------ setData -------------------------------------
// returns true if the data is set, false when bad data, i.e., is eof

bool NodeData::setData(istream& infile) {
	getline(infile, data);
	return !infile.eof();       // eof function is true when eof char is read
}

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, const NodeData& nd) {
	output << nd.data;
	return output;
}
