#include "pch.h"
#include "event.h"


 void game::movement(player& pl, mapp& m, sf::Event ev)
{
    if (ev.type == Event::KeyPressed) {
        if (ev.key.code == Keyboard::Key::LShift) {
            pl .set_run(1);
        }
    }
    if (ev.type == Event::KeyReleased) {
        if (ev.key.code == Keyboard::Key::LShift) {

            pl.set_run(0);
        }
    }
    
    if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
        pl.set_speed(0, -0.0005 * (pl.get_r() / 2.0 + 1));
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
        pl.set_speed(0, 0.0005 * (pl.get_r() / 2.0 + 1));
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
        pl.set_speed(-0.0005 * (pl.get_r() / 2.0 + 1), 0);
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
        pl.set_speed(0.0005 * (pl.get_r() / 2.0 + 1), 0);
    }
    react(pl, m);
   
}

void game::react(player& pl, mapp& m)
{
    for (int i = 0; i < m.get_num_y(); i++) {
        for (int j = 0; j < m.get_numx(); j++) {
            if (m.getTiles(i, j).get_type()) {
                if (abs(pl.getx() - m.getTiles(i, j).getx()) < 24 && abs(pl.gety() - m.getTiles(i, j).gety()) < 24) {
                    m.getTiles(i, j).set_inside(1);
                }
                else { m.getTiles(i, j).set_inside(0); }
            }
            else {
                collision(pl, m.getTiles(i, j),1);
                collision(pl, m.getTiles(i, j),0);
                
            }
            m.getTiles(i, j).react();
        }
    }
}

void game::collision(player& pl, tile& t, int k)
{
   
    if (abs(pl.getx() - t.getx()) <= 24 && abs(pl.gety() - t.gety()) <= 24) {
        std::cout << "got";
        if (pl.get_sy() > 0 && k == 1) pl.get_s().move(0,-24);
        if (pl.get_sx() > 0 && k == 0) pl.get_s().move( -24,0);
        if (pl.get_sy() < 0 && k == 1) pl.get_s().move(0, 24);
        if (pl.get_sx() < 0 && k == 0) pl.get_s().move(24,0);
    }
}


