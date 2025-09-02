#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>


class HeartShape {
    public:
        static sf::ConvexShape create(float x, float y, float scale){

            sf::ConvexShape heart;

            heart.setPointCount(100);

            for (int i = 0; i < 100; ++i){

                float t = i * 2 * 3.141592f / 100;

                float x0 = 16 * std::pow(std::sin(t), 3);

                float y0 = 13 * std::cos(t) - 5 * std::cos(2 * t) - 2 * std::cos(3 * t) - std::cos(4 * t);

                heart.setPoint(i, sf::Vector2f(x + x0 * scale, y - y0 * scale));
            }

            heart.setFillColor(sf::Color::Red);

            return heart;
        }

};

// to do : heart break
class BreakHeartShape{
    public:
        static sf::ConvexShape create(float x, float y, float scale){

            sf::ConvexShape heart;
            

            heart.setPointCount(100);

            for (int i = 0; i < 100; ++i){

                float t = i * 2 * 3.141592f / 100;

                float x0 = 16 * std::pow(std::sin(t), 3);

                float y0 = 13 * std::cos(t) - 5 * std::cos(2 * t) - 2 * std::cos(3 * t) - std::cos(4 * t);

                heart.setPoint(i, sf::Vector2f(x + x0 * scale, y - y0 * scale));
            }

            heart.setFillColor(sf::Color::Red);

            

            return heart;
        }

};