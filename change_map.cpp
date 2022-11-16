#include "pch.h"
#include "change_Map.h"
#include "cell_facrory.h"
#include <random>
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
        std::random_device d1;
        std::random_device d2;
        int j = d1() % (m->get_numx() - 2) + 1;
        int k = d2() % (m->get_numx() - 2) + 1;
        if (m->get_cur_cell(j, k).get_type() == 0) {
            m->get_cur_cell(j, k) = *(fact.create_new(3, p));
            i++;
        }
    }
    message msg(GAME, "Map changing event", info);
    notify(msg);
}


