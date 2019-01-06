#ifndef soundtrack_H
#define soundtrack_H

#include <iostream>
#include <fstream>
#include <vector>
//Kevin Florio
//CSM20 Fall 2016
//ProjectA
#include <string>
#include <memory>
#include <stdexcept>

class soundtrack
{
	std::string composer;
	std::string title;
	std::string label;
	std::string catalog_number;
	std::string year_recorded;
	std::string year_released;

public:
	soundtrack();
	soundtrack(const soundtrack &rhs);
	soundtrack& operator = (const soundtrack &rhs);
	bool empty() const;
	bool operator == (const soundtrack &rhs);
	std::string getComposer() const;
	std::string getTitle() const;
	std::string getLabel() const;
	std::string getCatalogNumber() const;
	std::string getYearRecorded() const;
	std::string getYearReleased() const;
	void setComposer(const std::string &new_composer);
	void setTitle(const std::string &new_title);
	void setLabel(const std::string &new_label);
	void setCatalogNumber(const std::string &new_catalog_number);
	void setYearRecorded(const std::string &new_year_recorded);
	void setYearReleased(const std::string &new_year_released);

}; 

std::istream &operator >> (std::istream &is, soundtrack &obj);

std::ostream &operator << (std::ostream &os, const soundtrack &obj);

#endif