#include "pch.h"
#include "mediator.h"
#include "key.h"

key* key::instance = nullptr;

int main()
{
    key::get_instance()->select_data();
    command_reader reader;
    reader.input_size_win();
    reader.set_output();
    reader.set_levels();
    reader.set_management();
    Texture t1;
    Texture t;
    logoutinfo* info = new logoutinfo(reader.get_outputs(), reader.get_levels());
    t.loadFromFile("pic.png");
    Texture t2;
    t2.loadFromFile("enemy.png");
    player* p = new player(info);
    player_view pv(p, t);
    Map* m = new Map(reader.get_w(), reader.get_h(), info);
    Map_view mv(m);
    enemies en;
    controller control(p,pv,m,mv,&en,info);
    control.set_enemies(reader.set_difficult(),t2);
	mediator med(control, reader);
    med.start();
    key::get_instance()->delete_key();
    return 0;
}
