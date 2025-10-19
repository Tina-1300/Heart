#include "HeartShape.hpp"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Audio.hpp>

#include <windows.h>



int main(){

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Heart", sf::Style::Titlebar | sf::Style::Close);

    auto heart = HeartShape::create(400.f, 250.f, 10.f);

    //auto BreakHeart = BreakHeartShape::create(400.f, 250.f, 10.f);


    // start broken heart
    /*
    float cx = 400.f;
    float cy = 250.f;
    float scale = 10.94f;
    float pi = 3.141592f;

    float t_top = 0.f;
    float x0_top = 16 * std::pow(std::sin(t_top), 3);
    float y0_top = 13 * std::cos(t_top) - 5 * std::cos(2 * t_top) - 2 * std::cos(3 * t_top) - std::cos(4 * t_top);
    sf::Vector2f top(cx + x0_top * scale, cy - y0_top * scale);

    float t_bottom = pi;
    float x0_bottom = 16 * std::pow(std::sin(t_bottom), 3);
    float y0_bottom = 15.74f * std::cos(t_bottom) - 5 * std::cos(2 * t_bottom) - 2 * std::cos(3 * t_bottom) - std::cos(4 * t_bottom);
    sf::Vector2f bottom(cx + x0_bottom * scale, cy - y0_bottom * scale);

    float num_segments = 8.8f;  
    int num_points = num_segments + 1;
    std::vector<sf::Vector2f> crack_points;
    float zig_width = 8.f;  

    for (int i = 0; i < num_points; ++i){
        float fraction = static_cast<float>(i) / (num_points - 1);
        float curr_y = top.y + fraction * (bottom.y - top.y);
        float curr_dx = 0.f;
        if (i != 0 && i != num_points - 1){
            curr_dx = zig_width * ((i % 2 == 0) ? 1.f : -1.f);
        }
        crack_points.push_back({top.x + curr_dx, curr_y});
    }


    std::vector<sf::RectangleShape> crack_segments;
    float thickness = 3.6f; 

    for (size_t i = 0; i < crack_points.size() - 1; ++i){
        sf::Vector2f p1 = crack_points[i];
        sf::Vector2f p2 = crack_points[i + 1];
        sf::Vector2f dir = p2 - p1;
        float length = std::hypot(dir.x, dir.y);
        if (length == 0) continue;
        sf::RectangleShape seg(sf::Vector2f(length, thickness));
        seg.setOrigin(sf::Vector2f(0.f, thickness / 2.f));
        seg.setPosition(p1);
        seg.setFillColor(sf::Color::Black);
        float angle = std::atan2(dir.y, dir.x) * 180.f / pi;
        seg.setRotation(sf::degrees(angle));
        crack_segments.push_back(seg);
    }
    */
    // end broken heart





    sf::Font font;

    if (!font.openFromFile("C:\\Windows\\Fonts\\arial.ttf")){return -1;}

    sf::Text text(font, "I love you", 40);

    text.setFillColor(sf::Color::Black);

    sf::FloatRect bounds = text.getLocalBounds();

    text.setOrigin({ bounds.size.x / 2.f, bounds.size.y / 2.f }); 

    text.setPosition({ 400.f, 220.f });

    sf::Music music;

    if (!music.openFromFile("assets/sound/sad_rap.wav")){
        MessageBoxW(NULL, L"Error: Unable to load 'sad_rap.wav'. The program will continue without music.", L"Audio loading error", MB_OK | MB_ICONWARNING);   
    }

    music.play();

    while (window.isOpen()){

        while (auto eventOpt = window.pollEvent()){

            if (eventOpt.has_value()){

                const sf::Event& event = eventOpt.value();

                if (event.is<sf::Event::Closed>()){

                    window.close();

                }

            }

        }

        window.clear(sf::Color::Black);

        // start broken heart
        /*
        for (const auto& part : BreakHeart) {
            window.draw(part);
        }

        for (const auto& seg : crack_segments) {
            window.draw(seg);
        }
        */
        // end broken heart

        window.draw(heart);

        window.draw(text);

        window.display();

    }

    return 0;
}

/*

Compilation dynamique : 

g++ -o heart.exe heart.cpp -lsfml-graphics -lsfml-window -lsfml-system -mwindows & color

Compilation static :

g++ -DSFML_STATIC -o heart.exe heart.cpp -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lfreetype -lopengl32 -lgdi32 -lwinmm -limm32 -lshell32 -mwindows

avec music :

g++ -DSFML_STATIC -o heart.exe heart.cpp -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lflac -lvorbisfile -lvorbis -logg -lfreetype -lopengl32 -lgdi32 -lwinmm -limm32 -lshell32 -mwindows & color

*/