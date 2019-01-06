//Kevin Florio
//CSM20 Fall 2016
//ProjectA
#pragma warning(disable : 4786)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

#include "LinkedList.h"
#include "LinkedListValue.h"
#include "SoundTrack.h"
int main()
{
	int i;

	std::cout << "Create int LinkedListValue llv1 using default constructor" << std::endl << std::endl;
	LinkedListValue<int> llv1;

	std::cout << "Insert items into llv1" << std::endl << std::endl;

	llv1.insert_back(-34);
	llv1.insert_back(2);
	llv1.insert_back(17);
	llv1.insert_back(63);
	llv1.insert_back(225);
	llv1.insert_back(-2345);

	std::cout << "Display llv1 : " << std::endl << std::endl;

	std::cout << "There are " << llv1.getLength() << " values in the list : " << std::endl;
	for (i = 0; i < llv1.getLength(); i++)
	{
		std::cout << llv1.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Create Linked List ll1 which is a copy of llv1" << std::endl << std::endl;

	LinkedList<int> ll1(llv1);

	std::cout << "Display ll1 : " << std::endl << std::endl;
	std::cout << "There are " << ll1.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < ll1.getLength(); i++)
	{
		std::cout << ll1.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Change the fifth value of ll1 to 2015" << std::endl << std::endl;

	ll1.setEntry(4, 2015);

	std::cout << "Change the tenth value of ll1 to 2016" << std::endl << std::endl;

	ll1.setEntry(9, 2016);

	std::cout << std::endl;
	std::cout << "Display ll1 : " << std::endl << std::endl;
	std::cout << "There are " << ll1.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < ll1.getLength(); i++)
	{
		std::cout << ll1.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Create LinkedListValue llv2 which is a copy of llv1" << std::endl << std::endl;

	LinkedListValue<int> llv2(llv1);

	std::cout << "Display llv2 : " << std::endl << std::endl;
	std::cout << "There are " << llv2.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < llv2.getLength(); i++)
	{
		std::cout << llv2.getEntry(i) << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Remove 63 from llv2" << std::endl << std::endl;

	if (llv2.removeItem(63))
	{
		std::cout << "63 was removed from llv2" << std::endl << std::endl;
	} 
	else
	{
		std::cout << "63 was NOT removed from llv2" << std::endl << std::endl;
	} 

	std::cout << "Attempt to remove 63 from llv2 again" << std::endl << std::endl;

	if (llv2.removeItem(63))
	{
		std::cout << "63 was removed from llv2" << std::endl << std::endl;
	} 
	else
	{
		std::cout << "63 was NOT removed from llv2" << std::endl << std::endl;
	}

	std::cout << "Display llv2 : " << std::endl << std::endl;
	std::cout << "There are " << llv2.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < llv2.getLength(); i++)
	{
		std::cout << llv2.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Create LinkedListValue llv3 from llv2" << std::endl << std::endl;

	LinkedListValue<int> llv3(llv2);

	std::cout << "Display llv3 : " << std::endl << std::endl;
	std::cout << "There are " << llv3.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < llv3.getLength(); i++)
	{
		std::cout << llv3.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Assign llv3 the values from llv1" << std::endl << std::endl;

	llv3.assign(llv1);

	std::cout << "Display llv3 : " << std::endl << std::endl;
	std::cout << "There are " << llv3.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < llv3.getLength(); i++)
	{
		std::cout << llv3.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Assign ll1 the values from llv3" << std::endl << std::endl;

	ll1.assign(llv3);

	std::cout << "Display ll1 : " << std::endl << std::endl;
	std::cout << "There are " << ll1.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < ll1.getLength(); i++)
	{
		std::cout << ll1.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Create string LinkedListValue llv4 using default constructor" << std::endl << std::endl;

	LinkedListValue<std::string> llv4;

	std::cout << "Insert items into llv4" << std::endl << std::endl;

	llv4.insert_back("CS");
	llv4.insert_back("M");
	llv4.insert_back("20");
	llv4.insert_back("Data Structures");
	llv4.insert_back("Using");
	llv4.insert_back("C++");

	std::cout << "Display llv4 : " << std::endl << std::endl;
	std::cout << "There are " << llv4.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < llv4.getLength(); i++)
	{
		std::cout << llv4.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Create llv5 from llv4" << std::endl << std::endl;

	LinkedListValue<std::string> llv5(llv4);

	std::cout << "Display llv5 : " << std::endl << std::endl;
	std::cout << "There are " << llv5.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < llv5.getLength(); i++)
	{
		std::cout << llv5.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Delete \"Data\" from llv5" << std::endl << std::endl;

	if (llv5.removeItem("Data"))
	{
		std::cout << "\"Data\" deleted from llv5" << std::endl << std::endl;
	} 
	else
	{
		std::cout << "\"Data\" NOT deleted from llv5" << std::endl << std::endl;
	} 

	std::cout << "Delete \"Data Structures\" from llv5" << std::endl << std::endl;

	if (llv5.removeItem("Data Structures"))
	{
		std::cout << "\"Data Structures\" deleted from llv5" << std::endl << std::endl;
	} 
	else
	{
		std::cout << "\"Data Structures\" NOT deleted from llv5" << std::endl << std::endl;
	} 

	std::cout << "Display llv5 : " << std::endl << std::endl;
	std::cout << "There are " << llv5.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < llv5.getLength(); i++)
	{
		std::cout << llv5.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Assign llv5 to llv4" << std::endl << std::endl;

	llv4.assign(llv5);

	std::cout << "Display llv4 : " << std::endl << std::endl;
	std::cout << "There are " << llv4.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < llv4.getLength(); i++)
	{
		std::cout << llv4.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Create soundtrack LinkedListValue llv6" << std::endl << std::endl;

	LinkedListValue<soundtrack> llv6;

	std::ifstream inFile("Topic A Soundtrack List.txt");

	if (!inFile.is_open())
	{
		std::cerr << "The file 'the_file.txt' cannot be opened. Program cannot continue..." << std::endl;
		return 0;
	} 

	std::vector<soundtrack> vec_llv6;

	while (inFile)
	{
		// Appends an empty soundtrack element
		vec_llv6.push_back(soundtrack());

		// Attempt to load data from the file. If the operation fails, remove the element
		if (!(inFile >> vec_llv6.back())) vec_llv6.pop_back();
	} 

	std::cout << "Insert values from file" << std::endl << std::endl;

	for (i = 0; i < vec_llv6.size(); i++)
	{
		llv6.insert_back(vec_llv6[i]);
	} 

	std::cout << "Display llv6 : " << std::endl << std::endl;
	std::cout << "There are " << llv6.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < llv6.getLength(); i++)
	{
		std::cout << llv6.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Create a new POINTER to a LinkedListValue pllv7, a copy of llv6" << std::endl << std::endl;

	std::unique_ptr<LinkedListValue<soundtrack> > pllv7(new LinkedListValue<soundtrack>(llv6));

	std::cout << "Display pllv7 : " << std::endl << std::endl;
	std::cout << "There are " << pllv7->getLength() << " values in the list : " << std::endl;

	for (i = 0; i < pllv7->getLength(); i++)
	{
		std::cout << pllv7->getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Delete \"Henry V\" from pllv7" << std::endl << std::endl;

	soundtrack item_6C25;
	item_6C25.setTitle("Henry V");

	if (pllv7->removeItem(item_6C25))
	{
		std::cout << "\"Henry V\" removed from pllv7" << std::endl << std::endl;
	} 
	else
	{
		std::cout << "\"Henry V\" NOT removed from pllv7" << std::endl << std::endl;
	} 

	std::cout << "Display pllv7 : " << std::endl << std::endl;
	std::cout << "There are " << pllv7->getLength() << " values in the list : " << std::endl;

	for (i = 0; i < pllv7->getLength(); i++)
	{
		std::cout << pllv7->getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Delete \"Henry V\" AGAIN from pllv7" << std::endl << std::endl;

	soundtrack item_71A6;
	item_71A6.setTitle("Henry V");

	if (pllv7->removeItem(item_71A6))
	{
		std::cout << "\"Henry V\" removed from pllv7" << std::endl << std::endl;
	} 
	else
	{
		std::cout << "\"Henry V\" NOT removed from pllv7" << std::endl << std::endl;
	} 

	std::cout << "Display pllv7 : " << std::endl << std::endl;
	std::cout << "There are " << pllv7->getLength() << " values in the list : " << std::endl;

	for (i = 0; i < pllv7->getLength(); i++)
	{
		std::cout << pllv7->getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Assign pllv7 to llv6" << std::endl << std::endl;

	llv6.assign(*pllv7);

	std::cout << "Display llv6 " << std::endl << std::endl;
	std::cout << "There are " << llv6.getLength() << " values in the list : " << std::endl;

	for (i = 0; i < llv6.getLength(); i++)
	{
		std::cout << llv6.getEntry(i) << std::endl;
	} 

	std::cout << std::endl;
	std::cout << "Find the soundtrack recorded in 1947 in pllv7" << std::endl << std::endl;

	soundtrack item_6D26;
	item_6D26.setYearRecorded("1947");

	int i_1C34;
	try
	{
		i_1C34 = pllv7->findItem(item_6D26, true);
	}
	catch (PrecondViolatedExcept &)
	{
		std::cerr << "Cannot find the soundtrack recorded in 1947 in pllv7. Program cannot continue..." << std::endl << std::endl;
		return 0;
	} 

	std::cout << "The soundtrack recorded in 1947 is in position " << i_1C34 + 1 << " and is the following : " << std::endl;
	std::cout << pllv7->getEntry(i_1C34) << std::endl;
	std::cout << "Program Ending Successfully" << std::endl << std::endl;
	std::cout << "Press Enter to end" << std::endl << std::endl;
	std::cin.get();

	return 0;

} 