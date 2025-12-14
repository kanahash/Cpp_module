#include "PhoneBook.hpp"

PhoneBook::PhoneBook():
	index(-1),
	num_contacts(0)
{
}

PhoneBook::~PhoneBook()
{
}

//printContact
std::string resize_str(const std::string& str)
{
	if(str.length() > 10)
		return(str.substr(0, 9) + ".");
	return(str);
} 

void PhoneBook::printContactlist()
{
	int i;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << std::right << "Index";
	std::cout << "|" << std::setw(10) << std::right << "First Name";
	std::cout << "|" << std::setw(10) << std::right << "Last Name";
	std::cout << "|" << std::setw(10) << std::right <<"NickName";
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	i = 0;
	while(i < num_contacts)
	{
		std::cout << "|" << std::setw(10) << std::right << i + 1;
		std::cout << "|" <<std::setw(10) << std::right << resize_str(contact_lists[i].getFirstName());
		std::cout << "|" << std::setw(10) << std::right << resize_str(contact_lists[i].getLastName());
		std::cout << "|" << std::setw(10) << std::right << resize_str(contact_lists[i].getNickName());
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::printContact(int index)
{
		std::cout << "[ " << index + 1 << " ]" << std::endl;
		std::cout << "First Name : " << contact_lists[index].getFirstName() << std::endl;
		std::cout << "Last Name : " << contact_lists[index].getLastName() << std::endl;
		std::cout << "Nick Name : " << contact_lists[index].getNickName() << std::endl;
		std::cout << "Phone Number : " << contact_lists[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret : " << contact_lists[index].getDarkestSecret() << std::endl;
}

//searchContact
bool PhoneBook::getIndexFromUser(int& selected_index)
{
	std::string input;
	int internal_index;
	int user_input_index;

	while(true)
	{
		std::cout << "please input the index of the contact you want to view : ";
		if(!std::getline(std::cin, input))
		{
			std::cout << "Error reading input. Exiting search." <<std::endl;
			if(std::cin.eof())
				std::cin.clear();
			return(false);
		}
		if(input.empty())
		{
			std::cout << "Input cannot be empty. Please enter an index." << std::endl;
			continue;
		}
		std::stringstream ss(input);
		if(ss >> user_input_index && ss.eof())
		{
			internal_index = user_input_index - 1;
			if(internal_index >= 0 && internal_index < num_contacts)
			{
				selected_index = internal_index;
				return(true);
			}
		}
		std::cout << "Invalid index. Please enter a number between 1 and " << num_contacts << "." << std::endl;
	}
}

bool PhoneBook::searchContact()
{
	if(num_contacts == 0)
	{
	std::cout << "No contacts to display." << std::endl;
	return(true);
	}
	printContactlist();
	int selected_index;
	if(!getIndexFromUser(selected_index))
		return(false);
	printContact(selected_index);
	return(true);	
}

//addContact
void PhoneBook::incrementIndex()
{
	index++;
	if(index > 7)
		index = 0;
}

std::string getInfo(std::string str)
{
	std::string input;

	while(true)
	{
		std::cout << str << ": ";
		if(!std::getline(std::cin, input))
		{
			if(std::cin.eof())
				std::cerr << "End of input detected." << std::endl;
			else
			{
				std::cerr << "Input error occured. Clearing stream." << std::endl;
				std::cin.clear();
			}
			return("");
		}
		if(!input.empty())
			return(input);
		else
			std::cout << "empty" << std::endl;
	}
}


bool PhoneBook::getContactDetails(Contact& contact)
{
	std::string input;

		input = getInfo("First Name");
	if(input == "")
		return(false);
	contact.setFirstName(input);

	input = getInfo("Last Name");
	if(input == "")
		return(false);
	contact.setLastName(input);

	input = getInfo("Nick Name");
	if(input == "")
		return(false);
	contact.setNickName(input);

	input = getInfo("Phone Number");
	if(input == "")
		return(false);
	contact.setPhoneNumber(input);

	input = getInfo("Darkest Secret");
	if(input == "")
		return(false);
	contact.setDarkestSecret(input);

	return(true);
}


bool PhoneBook::addContact()
{
		Contact temp_Contact;

	if(!getContactDetails(temp_Contact))
		return(false);

	if(num_contacts < 8)
	{
		contact_lists[num_contacts] = temp_Contact;
		index = num_contacts;
		num_contacts++;
	}
	else
	{
		incrementIndex();
		contact_lists[index] = temp_Contact;
	}
	return(true);
}
