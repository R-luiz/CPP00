/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:12:27 by rluiz             #+#    #+#             */
/*   Updated: 2024/05/08 18:05:35 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        static int contactCount;
        int contactnum;
    public:
        PhoneBook();
        void addContact(void);
        void displayContacts();
        void displayContact(int index);
        int getContactCount();
        void setContactCount(int count);
        ~PhoneBook();
        int getContactnum();
        void setContactnum(int contactnum);
};

#endif