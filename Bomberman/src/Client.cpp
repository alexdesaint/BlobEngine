#include <array>
#include <SFML/Network.hpp>


int main() {
	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect("192.168.0.15", 53000);
	if (status != sf::Socket::Done)
	{
		// error...
	}

	char data[] = "123456789";

	if(socket.send(data, 10) != sf::Socket::Done) {
		// error...
	}
}