/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <rliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:27:53 by rliu              #+#    #+#             */
/*   Updated: 2023/03/06 17:15:09 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"


//save recv message
Message::Message(void){}

Message::Message(std::string message):_message(message){
    setLines_tokens();
}

Message::~Message(void){}

//getline save in the lines;
// void setMessage(std::stirng message){
//     _message = message;
// }
void Message::setLines_tokens(){
    
    
    // Takes only space separated C++ strings.
    std::stringstream ss(_message);  
    std::string word;
    while (ss >> word) { // Extract word from the stream.
       _tokens.push_back(word);
    }
}

std::string Message::command_Nick(){
            std::vector<std::string>::iterator itf = find(_tokens.begin(),_tokens.end(), "NICK");
            if (itf != _tokens.end() && (itf+1)  != _tokens.end())
            _nick = *(itf+1);
            return (_nick);            
    }
    
        