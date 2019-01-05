#include <SFML/Network.hpp>
#include <iostream>

int main() {
	sf::TcpListener listener;
	sf::TcpSocket socket;
	bool connected = false;

	if (listener.listen(53000) != sf::Socket::Done) {

	}

	while(!connected){
		if(listener.accept(socket) == sf::Socket::Done)
			connected = true;
	}

	while(1){
		char data[100];
		std::size_t received;

		socket.receive(data, 100, received);

		if (received > 0) {
			std::cout << "Received " << received << " bytes : " << data << std::endl;
		}

	}
}