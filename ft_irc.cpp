#include <poll.h>
#include <vector>
#include "Client.hpp"
#include "Server.hpp"
#include "Message.hpp"
#include <string>

void    ft_loop(Client client, Server server, int fd_size) {

    int     fd_count = 1;
    char    buf[256];

    while (true)
    {
        int poll_count = client._poll();

        if (poll_count == -1) {
            perror("poll");
            exit(1);
        }
        // Run through the existing connections looking for data to read
        for(int i = 0; i < fd_count; i++) {

            // Check if someone's ready to read
            if (client.getPfd(i).revents == POLLIN) { // We got one!!

                if (client.getPfd(i).fd == server.getSocket())
                    client._accept(&server, &fd_count, &fd_size);
                else
                {
                    // If not the listener, we're just a regular client
                    memset(buf, 0 , 256);// @rliu
                    int nbytes = recv(client.getPfd(i).fd, buf, sizeof(buf), 0);
                    
                    while(cin.getline(buf, 100)){
                    std::string ss(s);
                    Message mes(sbuf);//@rliu
                    //std::string nickname = mes.command_Nick(); //@rliu
                    // if (!nickname.empty())
                    //     std::cout << nickname << std::endl;
    }
           
                    int sender_fd = client.getPfd(i).fd;

                    if (nbytes <= 0)
                    {
                        // Got error or connection closed by client
                        if (nbytes == 0)
                            std::cout << "pollserver: socket " << sender_fd << " hung up" << std::endl;
                        else
                            perror("recv");
                        close(client.getPfd(i).fd); // Bye!
                        client.del_from_pfds(i, &fd_count);
                    }
                    else
                    {
                        // We got some good data from a client

                        for(int j = 0; j < fd_count; j++) {
                            // Send to everyone!
                            int dest_fd = client.getPfd(j).fd;

                            // Except the listener and ourselves
                            if (dest_fd != server.getSocket() && dest_fd != sender_fd)
                            {
                                if (send(dest_fd, buf, nbytes, 0) == -1)
                                    perror("send");
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char **argv) {

    if (argc != 2)
    {
        std::cout << "Port number needed." << std::endl;
        return (-1);
    }

    int     fd_size = 5;

    Client  client(fd_size);
    Server  server(argv[0]);

    server.setSocket();
    server.fillSockAddr(htons(std::strtol(argv[1], NULL, 10)));
    server._bind();
    server._listen();
    client.fillpfds(&server);

    ft_loop(client, server, fd_size);

    return (0);
}