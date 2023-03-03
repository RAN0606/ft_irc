/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <rliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:27:53 by rliu              #+#    #+#             */
/*   Updated: 2023/03/03 19:02:37 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"
#include <string>
#include <iostream>
#include <vector>

Message::Message(std::string message):_message(message){}
Message::Message(void){}
Message::Message(void){}
void Message::setToken(){
    vector<string>     lines;
    std::string delimiter = "\n";
    std::string parsed;
    std::stringstream input_stringstream(_message);
    while(getline(input_stringstream,parsed, '\n'))
        lines.push_back(parsed);
    for(std::vector<string>::iterator itb=lines.begin(); itb!=lines.end(); itb++)
        {
            input_stringstream.str(*itb);
            while(getline(input_stringstream,parsed, ' '))
                _tokens.push_back(parsed);
        }
}
    std::string Message::getNick(){
            std::vector<string> itf = find (_tokens.begin(), _tokens.end(), 30);
            if (itf != _tokens.end() && (itf+1)  != _tokens.end());
            _nick = *(itf+1);
            return (_nick);            
    }
        