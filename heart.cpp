#include "HeartShape.hpp"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Audio.hpp>

#include <windows.h>



int main(){

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Heart", sf::Style::Titlebar | sf::Style::Close);

    //auto heart = HeartShape::create(400.f, 250.f, 10.f);

    auto BreakHeart = BreakHeartShape::create(400.f, 250.f, 10.f);

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
    }else{
        music.play();
    }

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

        window.draw(BreakHeart);

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