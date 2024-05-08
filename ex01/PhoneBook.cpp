
#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int PhoneBook::contactCount = 0;

PhoneBook::PhoneBook()
{
	this->contactnum = 0;
	return;
}

PhoneBook::~PhoneBook()
{
	return;
}

int	PhoneBook::getContactCount()
{
	return (this->contactCount);
}

void	PhoneBook::setContactCount(int count)
{
	this->contactCount = count;
	return;
}

void	PhoneBook::addContact(void)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	while (firstName.empty())
	{
		std::cout << "First name cannot be empty. Please enter a first name: ";
		std::getline(std::cin, firstName);
		if (std::cin.eof())
			return;
	}
	this->contacts[this->contactnum].setFirstName(firstName);

	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	while (lastName.empty())
	{
		std::cout << "Last name cannot be empty. Please enter a last name: ";
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			return;
	}
	this->contacts[this->contactnum].setLastName(lastName);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	while (nickname.empty())
	{
		std::cout << "Nickname cannot be empty. Please enter a nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			return;
	}
	this->contacts[this->contactnum].setNickname(nickname);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	while (phoneNumber.empty())
	{
		std::cout << "Phone number cannot be empty. Please enter a phone number: ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
			return;
	}
	this->contacts[this->contactnum].setPhoneNumber(phoneNumber);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	while (darkestSecret.empty())
	{
		std::cout << "Darkest secret cannot be empty. Please enter a darkestsecret: ";
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof())
			return;
	}
	this->contacts[this->contactnum].setDarkestSecret(darkestSecret);

	this->contactCount++;
	if (this->contactCount > 8)
		this->contactCount = 8;
	this->contactnum++;
	this->contactnum %= 8;
	return;
}

void	PhoneBook::displayContacts()
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < this->contactCount; i++)
	{
		std::cout << "         " << i << "|";
		std::cout.width(10);
		if (this->contacts[i].getFirstName().length() > 10)
		{
			std::cout.width(9);
			std::cout << this->contacts[i].getFirstName().substr(0, 9) << ".|";
		}
		else
		{
			std::cout.width(10);
			std::cout << this->contacts[i].getFirstName() << "|";
		}
		if (this->contacts[i].getLastName().length() > 10)
		{
			std::cout.width(9);
			std::cout << this->contacts[i].getLastName().substr(0, 9) << ".|";
		}
		else
		{
			std::cout.width(10);
			std::cout << this->contacts[i].getLastName() << "|";
		}
		if (this->contacts[i].getNickname().length() > 10)
		{
			std::cout.width(9);
			std::cout << this->contacts[i].getNickname().substr(0, 9) << "." << std::endl;
		}
		else {
			std::cout.width(10);
			std::cout << this->contacts[i].getNickname() << std::endl;	
		}
	}
	return;
}

void	PhoneBook::displayContact(int index)
{
	std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
	return;
}

bool	checkCommand(std::string command)
{
	if ((command != "ADD" && command != "SEARCH" && command != "EXIT") || command.empty() || std::cin.eof())
	{
		std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		return (true);
	}
	return (false);
}

int	main()
{
	PhoneBook phoneBook;
	std::string command;
	int i = 0;

	phoneBook = PhoneBook();
	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (checkCommand(command))
			break;
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
			std::cout << "Enter an index: ";
			std::getline(std::cin, command);
			i = (int)command[0] - '0';
			while (i < 0 || i > phoneBook.getContactCount() - 1 || command.length() != 1)
			{
				std::cout << "Invalid index. Please enter a number between 0 and " << phoneBook.getContactCount()-1 << ": ";
				std::getline(std::cin, command);
				i = (int)command[0] - '0';
			}
			phoneBook.displayContact(command[0] - '0');
		}
		else if (command == "EXIT")
			break;
	}
	return (0);
}