#include "pch.h"
#include "menu.h"

void menu::win_init()
{
    setlocale(LC_ALL, "ru");
	int n;
	std::cout << " Выберите 1 из шаблонов игровой карты\n" << "1. 10x10\n" << "2. 15x15\n" << "3. 20x20\n";
	std::cin >> n;
	if (n == 1) start(10);
	else if (n == 2) start(15);
	else if (n == 3) start(20);
}

void menu::start(int x)
{
	RenderWindow win(VideoMode(x * 48, x * 48), "moya igra - basta");
	win.setFramerateLimit(200);
	float currframe = 0;
	Texture t;
	t.loadFromFile("pic.png");
	Clock clk;
	player p(t, (x - 2) * 10,(x-2)*10 + 48,100,100);
	mapp m(x+1, x+1);
	game g;
    while (win.isOpen()) {
        g.ifev.win(win,p);
        g.ifev.game_over(win, p);
        Event event;
        float time = clk.getElapsedTime().asMicroseconds();
        clk.restart();
        while (win.pollEvent(event)) {
            if (event.type == Event::Closed)
                win.close();
            g.movement(p, m, event);
        }
        RectangleShape h(sf::Vector2f(p.get_hp(), 20));
        RectangleShape s(sf::Vector2f(p.get_st(), 10));
        s.setPosition(0, 24);
        s.setFillColor(Color::Blue);
        h.setPosition(0, 0);
        h.setFillColor(Color::Red);
        p.update(time, x);
        win.clear(Color::Black);
        m.drawmap(win);
        win.draw(h);
        win.draw(s);
        win.draw(p.get_s());
        win.display();
    }
}

