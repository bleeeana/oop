#include "pch.h"
#include "cell_facrory.h"

cell* cell_facrory::create_new(int type, player* p)
{
    if (type == 0) {

        return new cell(type, nullptr);
    }
    else if (type == 1) {

        return new cell(type, nullptr);
    }
    else if (type == 2) {
        return new cell(type, new heal(p));
    }
    else if (type == 3) {
        
        return new cell(type, new give_dmg(p));
    }
    else if (type == 4) {

        return new cell(type, new get_treasure(p));
    }
}
