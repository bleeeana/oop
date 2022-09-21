#include "pch.h"
#include "event.h"

using  namespace sf;
int main()
{
    RenderWindow win(VideoMode(960, 960), "moya igra - basta");
    win.setFramerateLimit(200);
    float currframe = 0;
    Texture t;
    t.loadFromFile("pic.png");
    Clock clk;
    player p(t);
    mapp m;
    game g;
    while (win.isOpen()) {
        Event event;
        float time = clk.getElapsedTime().asMicroseconds();
        clk.restart();
        while (win.pollEvent(event)) {
            if (event.type == Event::Closed)
                win.close();
            g.movement(p,m,event);
            }
        RectangleShape h(sf::Vector2f(p.get_hp(), 20));
        RectangleShape s(sf::Vector2f(p.get_st(), 10));
        s.setPosition(0, 24);
        s.setFillColor(Color::Blue);
        h.setPosition(0, 0);
        h.setFillColor(Color::Red);
        p.update(time);
        win.clear(Color::Black);
        m.drawmap(win);
        win.draw(h);
        win.draw(s);
        win.draw(p.get_s());
        win.display();
    }
    return 0;
}
