// sfmlPhysicstest.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "timeelapsed.h"

void renderingThread(sf::RenderWindow* window, std::vector<sf::Drawable*>& renderthings);
