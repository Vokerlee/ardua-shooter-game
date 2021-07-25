#include "../objects2D/circle2D.hpp"
#include "../objects2D/polygon2D.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(ard::SCREEN_WIDTH, ard::SCREEN_HEIGHT), "Ardua Shooter");

    ard::Polygon2D wall1({ {0, 0}, {0, .1}, {6, .1}, {6, 0} }, { 0, 0 });
    ard::Polygon2D wall2({ {0, 0}, {.1, 0}, {.1, 6}, {0, 6} }, { 0, 0 });
    ard::Polygon2D wall3({ {0, 0}, {0, .1}, {6, .1}, {6, 0} }, { 0, 6 });
    ard::Polygon2D wall4({ {0, 0}, {.1, 0}, {.1, 6}, {0, 6} }, { 6, 0 });

    ard::Circle2D sphere1(.5, { 0, 0 });
    ard::Circle2D sphere2(.5, { 5, 0 });
    ard::Circle2D sphere3(.5, { 5, 5 });
    ard::Circle2D sphere4(.5, { 0, 5 });

    // RENDERING
    auto previous_time = std::chrono::system_clock::now();
    auto current_time  = std::chrono::system_clock::now();

    while (window.isOpen())
    {
        current_time = std::chrono::system_clock::now();
        std::chrono::duration <double> elapsed_time = current_time - previous_time;
        previous_time = current_time;

        double d_elapsed_time = elapsed_time.count();

        std::string title = "Ardua Shooter (" + std::to_string((double) (1 / d_elapsed_time)) + " fps)";
        window.setTitle(title);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        wall1.draw(window);
        wall2.draw(window);
        wall3.draw(window);
        wall4.draw(window);
        sphere1.draw(window);
        sphere2.draw(window);
        sphere3.draw(window);
        sphere4.draw(window);

        window.display();
    }

    return 0;
}