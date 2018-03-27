add_library(Collision CollisionDetector.cpp Hit.cpp ../../include/BlobEngine/Reaction.hpp)
target_link_libraries(Collision Geometrie)
