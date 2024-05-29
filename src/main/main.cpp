#include "manager/manager.hpp"

int main()
{
    ard::Manager manager;

    ard::Polygon2D wall1({ {0, 0}, {0, .1}, {6, .1}, {6, 0} }, { 0, 0 });
    ard::Polygon2D wall2({ {0, 0}, {.1, 0}, {.1, 6}, {0, 6} }, { 0, 0 });
    ard::Polygon2D wall3({ {0, 0}, {0, .1}, {6, .1}, {6, 0} }, { 0, 6 });
    ard::Polygon2D wall4({ {0, 0}, {.1, 0}, {.1, 6}, {0, 6} }, { 6, 0 });

    ard::Polygon2D object1({ {1, 1}, {2.35, 1}, {1.5, 2} }, { 1, .1 });
    ard::Polygon2D object2({ {1, 1}, {2, 2}, {1, 3}, {1, 2} }, { 1, 1 });
    ard::Polygon2D object3({ {0, 0}, {.1, 0}, {.1, .1}, {0, .1} }, { 3.5, 1 });
    ard::Polygon2D object4({ {0, 0}, {.3, 0}, {.3, .3}, {0, .3} }, { 4, 3 });
    ard::Polygon2D object5({ {0, 0}, {.3, 0}, {.3, .3}, {0, .3} }, { 3, 4 });

    ard::Circle2D sphere1(.3, { 0, 0 });
    ard::Circle2D sphere2(.3, { 6, 0 });
    ard::Circle2D sphere3(.3, { 6, 6 });
    ard::Circle2D sphere4(.3, { 0, 6 });

    manager.add_object2D(wall1, "wall1");
    manager.add_object2D(wall2, "wall2");
    manager.add_object2D(wall3, "wall3");
    manager.add_object2D(wall4, "wall4");

    manager.add_object2D(object1, "object1");
    manager.add_object2D(object2, "object2");
    manager.add_object2D(object3, "object3");
    manager.add_object2D(object4, "object4");
    manager.add_object2D(object5, "object5");

    manager.add_object2D(sphere1, "sphere1");
    manager.add_object2D(sphere2, "sphere2");
    manager.add_object2D(sphere3, "sphere3");
    manager.add_object2D(sphere4, "sphere4");

    manager.run();

    return 0;
}