#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SFML Lesson2";
const float FPS = 70.f;

const float BALL_RADIUS = 25.f;

const float BAT_WIDTH = 20.f;
const float BAT_HEIGHT = 80.f;
const float BAT_OFFSET = 50.f;
const sf::Vector2f ballPosition((WINDOW_WIDTH - 2 * BALL_RADIUS) / 2, (WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2);
const sf::Vector2f batSize(20.f, 80.f);
const sf::Color leftBatColor{ 158,20,37 };
const sf::Color rightBatColor{ 20,158,49 };
const float batSpeed = 3.f;
const sf::Vector2f leftBatStartPos{ BAT_OFFSET, (WINDOW_HEIGHT - BAT_HEIGHT) / 2 };
const sf::Vector2f rightBatStartPos{ WINDOW_WIDTH - BAT_OFFSET, (WINDOW_HEIGHT - BAT_HEIGHT) / 2 };
const float  batDy = 5.f;
const float batDx = 5.f;

const int charSize = 64.f;
const sf::Vector2f lefttextStartPos(200.f, 10.f);
const sf::Vector2f righttextStartPos(550.f, 10.f);

const int TextSize = 64.f; 
const sf::Vector2f TextStartPos(100.f, 10.f); 

const int rightCharacterSize = 64.f;


const sf::Color ballColor{ sf::Color::Yellow };