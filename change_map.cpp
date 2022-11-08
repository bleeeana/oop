#include "pch.h"
#include "change_Map.h"
#include "cell_facrory.h"
change_Map::change_Map(Map* m, player* p)
{
	this->m = m;
    this->p = p;
    this->add_observer(new iobserver());
}

void change_Map::execute(logoutinfo* info)
{
    cell_facrory fact;
    for (int i = 0; i < m->get_numx() * 1.50; ) {
        int j = rand() % (m->get_numx() - 2) + 1;
        int k = rand() % (m->get_numx() - 2) + 1;
        if (m->get_cur_cell(j, k).get_type() == 0) {
            m->get_cur_cell(j, k) = *(fact.create_new(3, p));
            i++;
        }
    }
    message msg(GAME, "Map changing event", info);
    notify(msg);
}


