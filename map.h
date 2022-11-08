#pragma once
#include "cell.h"
#include "iobservable.h"
#include <vector>
#include <iostream>
class Map : public iobservable
{
private:
    std::vector<std::vector<cell>> cells;
    int numx;
    int numy;
    logoutinfo* info;
    std::pair <int, int> player_location;
public:
    Map(int x, int y, logoutinfo* info = nullptr);
    Map operator=(Map& m);
    int get_numx() const;
    int get_numy()  const;
    cell& get_cur_cell(int x, int y);
    void clear();
    void check();
    void creat_str();
    void creat_elem(int i, cell& c);
    void set_player_location(int x, int y);
};

