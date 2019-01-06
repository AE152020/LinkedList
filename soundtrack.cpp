//Kevin Florio
//CSM20 Fall 2016
//ProjectA
#include "soundtrack.h"

soundtrack::soundtrack() {}

// Copy-Constructor
soundtrack::soundtrack(const soundtrack &rhs)
{
	this->setComposer(rhs.getComposer());
	this->setTitle(rhs.getTitle());
	this->setLabel(rhs.getLabel());
	this->setCatalogNumber(rhs.getCatalogNumber());
	this->setYearRecorded(rhs.getYearRecorded());
	this->setYearReleased(rhs.getYearReleased());

} // End constructor (soundtrack(const soundtrack &rhs))

  // Copy-Assignment
soundtrack& soundtrack::operator = (const soundtrack &rhs)
{
	this->setComposer(rhs.getComposer());
	this->setTitle(rhs.getTitle());
	this->setLabel(rhs.getLabel());
	this->setCatalogNumber(rhs.getCatalogNumber());
	this->setYearRecorded(rhs.getYearRecorded());
	this->setYearReleased(rhs.getYearReleased());

	return (*this);

} // End Copy-Assignment (operator = (const soundtrack &rhs))

  // Check if the soundtrack object is empty
bool soundtrack::empty() const
{
	if (this->getComposer().size() > 0) return false;
	if (this->getTitle().size() > 0) return false;
	if (this->getLabel().size() > 0) return false;
	if (this->getCatalogNumber().size() > 0) return false;
	if (this->getYearRecorded().size() > 0) return false;
	if (this->getYearReleased().size() > 0) return false;

	return true;
}

bool soundtrack::operator == (const soundtrack &rhs)
{
	// However, the comparing soundtrack must not be empty
	if (rhs.empty()) return false;

	if (rhs.getComposer().size() != 0)
		if (this->getComposer() != rhs.getComposer()) return false;

	if (rhs.getTitle().size() != 0)
		if (this->getTitle() != rhs.getTitle()) return false;

	if (rhs.getLabel().size() != 0)
		if (this->getLabel() != rhs.getLabel()) return false;

	if (rhs.getCatalogNumber().size() != 0)
		if (this->getCatalogNumber() != rhs.getCatalogNumber()) return false;

	if (rhs.getYearRecorded().size() != 0)
		if (this->getYearRecorded() != rhs.getYearRecorded()) return false;

	if (rhs.getYearReleased().size() != 0)
		if (this->getYearReleased() != rhs.getYearReleased()) return false;

	return true;

} 

std::string soundtrack::getComposer() const { return this->composer; }
std::string soundtrack::getTitle() const { return this->title; }
std::string soundtrack::getLabel() const { return this->label; }
std::string soundtrack::getCatalogNumber() const { return this->catalog_number; }
std::string soundtrack::getYearRecorded() const { return this->year_recorded; }
std::string soundtrack::getYearReleased() const { return this->year_released; }

void soundtrack::setComposer(const std::string &new_composer) {
	this->composer = new_composer;
}

// setTitle() function
void soundtrack::setTitle(const std::string &new_title) {
	this->title = new_title;
}

// setLabel() function
void soundtrack::setLabel(const std::string &new_label) {
	this->label = new_label;
}

// setCatalogNumber() function
void soundtrack::setCatalogNumber(const std::string &new_catalog_number) {
	this->catalog_number = new_catalog_number;
}

// setYearRecorded() function
void soundtrack::setYearRecorded(const std::string &new_year_recorded) {
	this->year_recorded = new_year_recorded;
}

// setYearReleased() function
void soundtrack::setYearReleased(const std::string &new_year_released) {
	this->year_released = new_year_released;
}

// Overloaded operator function for std::istream (soundtrack)
std::istream &operator >> (std::istream &is, soundtrack &obj)
{
	// Eliminate all the trailing whitespace characters
	is >> std::ws;

	std::string composer;
	std::string title;
	std::string label;
	std::string catalog_number;
	std::string year_recorded;
	std::string year_released;

	// Attempt to read every section. If any of these fails, force the function to return
	if (!std::getline(is, composer)) return is;
	if (!std::getline(is, title)) return is;
	if (!std::getline(is, label)) return is;
	if (!std::getline(is, catalog_number)) return is;
	if (!std::getline(is, year_recorded)) return is;
	if (!std::getline(is, year_released)) return is;

	obj.setComposer(composer);
	obj.setTitle(title);
	obj.setLabel(label);
	obj.setCatalogNumber(catalog_number);
	obj.setYearRecorded(year_recorded);
	obj.setYearReleased(year_released);

	return is;
} 

std::ostream &operator << (std::ostream &os, const soundtrack &obj)
{
	os << obj.getComposer() << "  ";
	os << obj.getTitle() << "  ";
	os << obj.getLabel() << "  ";
	os << obj.getCatalogNumber() << "  ";
	os << obj.getYearRecorded() << "  ";
	os << obj.getYearReleased() << std::endl;

	return os;
} 