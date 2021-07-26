#include "../objects2D/circle2D.hpp"
#include "../objects2D/polygon2D.hpp"
#include "../world/world.hpp"

int main()
{
    // WINDOW
    sf::RenderWindow window(sf::VideoMode(ard::SCALE * ard::SCREEN_WIDTH, ard::SCALE * ard::SCREEN_HEIGHT), "Ardua Shooter");

    // WORLD
    ard::World world;

    // OBJECTS
    ard::Polygon2D wall1({ {0, 0}, {0, .1}, {6, .1}, {6, 0} }, { 0, 0 });
    ard::Polygon2D wall2({ {0, 0}, {.1, 0}, {.1, 6}, {0, 6} }, { 0, 0 });
    ard::Polygon2D wall3({ {0, 0}, {0, .1}, {6, .1}, {6, 0} }, { 0, 6 });
    ard::Polygon2D wall4({ {0, 0}, {.1, 0}, {.1, 6}, {0, 6} }, { 6, 0 });

    ard::Circle2D sphere1(.5, { 0, 0 });
    ard::Circle2D sphere2(.5, { 6, 0 });
    ard::Circle2D sphere3(.5, { 6, 5 });
    ard::Circle2D sphere4(.5, { 0, 6 });

    ard::Polygon2D object1({ {1, 1}, {2.35, 1}, {1.5, 2} }, { 1, .1 });
    ard::Polygon2D object2({ {1, 1}, {2, 2}, {1, 3}, {1, 2} }, { 1, 1 });
    ard::Polygon2D object3({ {0, 0}, {.1, 0}, {.1, .1}, {0, .1} }, { 3.5, 1 });
    ard::Polygon2D object4({ {0, 0}, {.3, 0}, {.3, .3}, {0, .3} }, { 4, 3 });
    ard::Polygon2D object5({ {0, 0}, {.3, 0}, {.3, .3}, {0, .3} }, { 3, 4 });

    world.add_object2D(wall1, "wall1");
    world.add_object2D(wall2, "wall2");
    world.add_object2D(wall3, "wall3");
    world.add_object2D(wall4, "wall4");

    world.add_object2D(sphere1, "zsphere1");
    world.add_object2D(sphere2, "zsphere2");
    world.add_object2D(sphere3, "zsphere3");
    world.add_object2D(sphere4, "zsphere4");

    world.add_object2D(object1, "object1");
    world.add_object2D(object2, "object2");
    world.add_object2D(object3, "object3");
    world.add_object2D(object4, "object4");
    world.add_object2D(object5, "object5");

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
        world.draw(window);
        window.display();
    }

    return 0;
}