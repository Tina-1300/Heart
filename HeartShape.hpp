#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

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


class BreakHeartShape{
    public:
        static std::vector<sf::ConvexShape> create(float x, float y, float scale){

            std::vector<sf::Vector2f> points(100);

            for (int i = 0; i < 100; ++i){

                float t = i * 2 * 3.141592f / 100;

                float x0 = 16 * std::pow(std::sin(t), 3);

                float y0 = 13 * std::cos(t) - 5 * std::cos(2 * t) - 2 * std::cos(3 * t) - std::cos(4 * t);

                points[i] = sf::Vector2f(x + x0 * scale, y - y0 * scale);
            }

            sf::ConvexShape right;
            right.setPointCount(51);
            for (int j = 0; j <= 50; ++j){
                right.setPoint(j, points[j]);
            }
            right.setFillColor(sf::Color::Red);

            sf::ConvexShape left;
            left.setPointCount(51);
            left.setPoint(0, points[50]);
            for (int j = 1; j < 50; ++j){
                left.setPoint(j, points[50 + j]);
            }
            left.setPoint(50, points[0]);
            left.setFillColor(sf::Color::Red);


            float offset = 0.f;  

            for (size_t i = 0; i < right.getPointCount(); ++i){
                auto p = right.getPoint(i);
                p.x += offset;
                right.setPoint(i, p);
            }
            for (size_t i = 0; i < left.getPointCount(); ++i){
                auto p = left.getPoint(i);
                p.x -= offset;
                left.setPoint(i, p);
            }

            return {left, right};
        }

};