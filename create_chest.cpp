#include "pch.h"
#include "create_chest.h"
#include <random>

create_chest::create_chest(Map* m, player* p)
{
    this->m = m;
    this->p = p;
    this->add_observer(new iobserver());
}

void create_chest::execute(logoutinfo* info)
{
    cell_facrory fact;
    std::random_device d1;
    std::random_device d2;
    while (1) {
        int j = d1() % (m->get_numx() - 2) + 1;
        int k = d2() % (m->get_numx() - 2) + 1;
        if (m->get_cur_cell(j, k).get_type() == 0) {
            m->get_cur_cell(j, k) = *(fact.create_new(4, p));
            break;
        }
    }
    message msg(GAME, "chest creating event", info);
    notify(msg);
}
