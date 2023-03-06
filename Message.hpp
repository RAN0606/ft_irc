/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <rliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:18:42 by rliu              #+#    #+#             */
/*   Updated: 2023/03/06 17:01:28 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MESSAGE_HPP
# define MESSAGE_HPP
# include "Client.hpp"
# include <vector>
# include <string>
#include <iostream>
# include <algorithm>

class Message{
    public:
        Message(std::string message);
        Message(void);
        ~Message(void);
        void setLines_tokens();
        //std::string getNick();
        std::string command_Nick();
        
        
        std::string                 _message;
        std::vector<std::string>     _lines;  
        std::string                 _nick; //tmp
        std::vector<std::string>     _tokens;
};
#endif