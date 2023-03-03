/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <rliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:18:42 by rliu              #+#    #+#             */
/*   Updated: 2023/03/03 19:01:50 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MESSAGE_HPP
#define MESSAGE_HPP

class Message{
    public:
        Message(std::string message);
        Message(void);
        ~Message(void);
        void setToken();
        std::string getNick();
        
        std::string        _message; 
        vector<string>     _tokens; 
        std::string        _nick; //tmp 
}
#endif