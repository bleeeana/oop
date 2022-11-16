#include "pch.h"
#include "mediator.h"






mediator::mediator(controller& control, command_reader& com)
{
    this->reader = & com;
    this->control = & control;
}


void mediator::start()
{

    this->control->add_observer(new iobserver());
    
    control->set_Map();
    RenderWindow win(VideoMode((control->get_field()->get_numx() - 1) * 48, (control->get_field()->get_numy() - 1) * 48), "moya igra - basta");
    win.setFramerateLimit(100);
    float currframe = 0;
    Texture t1;
    t1.loadFromFile("Gothic (3).png");
    Clock clk;
    while (win.isOpen()) {
        float time = clk.getElapsedTime().asMicroseconds();
        clk.restart();
        while (win.pollEvent(reader->get_event())) {
            if (reader->get_event().type == Event::Closed || reader->input_event() == 5) { win.close(); }
            control->movement(reader->input_event());
        }
        control->enemy_action();
        win.clear(Color::Black);
        control->draw(win, t1,time);
        win.display();
        if (control->win()) {
            reader->win_screen(win);
        }
        if (control->lose()) {
            reader->lose_screen(win);
        }
        
      
    }
}
