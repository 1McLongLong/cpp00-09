/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:51:19 by touahman          #+#    #+#             */
/*   Updated: 2024/09/16 08:56:48 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact {
  std::string m_first_name;
  std::string m_last_name;
  std::string m_nick_name;
  std::string m_phone_number;
  std::string m_darkest_secret;
  int         m_contact_index;
public:
  void        set_first_name();
  void        set_last_name();
  void        set_nick_name();
  void        set_darkest_secret();
  void        set_phone_number();
  void        set_contact_index(int index);
  void        get_contact();
  int         get_index();
  std::string get_first_name();
  std::string get_last_name();
  std::string get_nick_name();
};

#endif
