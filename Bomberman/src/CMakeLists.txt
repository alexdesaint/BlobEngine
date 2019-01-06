add_subdirectory(BomberBlob)

add_executable(BomberMan
        main.cpp
#		GameMenu.cpp GameMenu.hpp
#		BomberBlob/BomberBlob.cpp
#		BomberBlob/Bomb.cpp
 #       BomberBlob/BombManager.cpp
  #      BomberBlob/Box.cpp
#        BomberBlob/ContactListener.cpp
#		BomberBlob/DynamicCircle.cpp
#		BomberBlob/Explosion.cpp
#		BomberBlob/IndestructibleBox.cpp
#		BomberBlob/Player.cpp
#		BomberBlob/StaticCircle.cpp
#		BomberBlob/StaticRect.cpp
#		BomberBlob/InfoBar.cpp
		)

target_link_libraries(BomberMan BlobGL Collision -static -static-libgcc -static-libstdc++ -lpthread)

add_executable(Server Server.cpp)
target_link_libraries(Server sfml-network)

add_executable(Client Client.cpp)
target_link_libraries(Client sfml-network)
