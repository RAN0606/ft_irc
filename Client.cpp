/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <rliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:12:21 by guillemette       #+#    #+#             */
/*   Updated: 2023/04/11 17:07:09 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Client::Client(void) : _isRegistered(false), _nickRegisted(false), _usrRegisted(false), _passRegisted(false) {
// TO DO: Change memset to a c++ method/func
	memset(this->_host, 0, NI_MAXHOST);
	this->_socklen = sizeof(this->_sockaddr);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Client::~Client(void) {}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- GETTERS ----------------------------------
*/

int			Client::getSocket(void) const{return (this->_socket);}

std::string	Client::getPass(void) const{return (this->_pass);}

std::string	Client::getNick(void) const{return (this->_nick);}

std::string	Client::getUser(void) const {return (this->_user);}

std::string Client::getIRCMode(void) const {return (this->_irc_mode);}

std::string Client::getHostName(void) const {return (this->_hostname);}

bool		Client::getRegistrationStatus(void) const {return (this->_isRegistered);}

std::string	Client::getPrefix(void) const {return (this->_prefix);}

std::string Client::getRealName(void) const {return (this->_realname);}

bool		Client::getNickStatus (void) const{return (this->_nickRegisted);}
bool		Client::getUsrStatus (void) const{return (this->_usrRegisted);}
bool		Client::getPassStatus (void) const{return (this->_passRegisted);}

/*
** --------------------------------- SETTERS ----------------------------------
*/

void Client::setSocket(int socket)
{
	this->_socket = socket;
}

void  Client::setPrefix(void)
{
		_prefix = _nick + "!" + _user + "@" + _hostname;
//      _msgWelcome = ":" + _prefix + " 001 " + _nick + " :Welcome to the IRC__ Network, " + _prefix + "\n";
	   std::cout << "test_setprefic: "<<_prefix << std::endl;
 }

void  Client::setNick(std::string &nickname)
{
	_nick = nickname;
}

void  Client::setAsRegistered(void){
    _isRegistered = true;
    this->setIRCMode("wi");
}

void		Client::setNickRegisted(void){
	_nickRegisted = true;
}

void		Client::setUsrRegisted(void){
	_usrRegisted = true;
}

void	Client::setPassRegisted(void){
		_passRegisted = true;
}

void  Client::setUsr(std::string &usrname)
{
	_user = usrname;
}

void  Client::setPass(std::string &pass)
{
	_pass = pass;
}

void  Client::setHostname(std::string &hostname)
{
	_hostname = hostname;
}

void    Client::setIRCMode(std::string mode) {

    this->_irc_mode = mode;
}

void	Client::setRealname(std::string &realname)
{
	_realname = realname;
}