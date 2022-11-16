#include "pch.h"
#include "fieldfactory.h"



fieldfactory::fieldfactory(Map*m, player* p)
{
	this->m = m;
	this->p = p;
}

void fieldfactory::creat_Map()
{
	m->check();
	cell_facrory* cf = new cell_facrory;
	if (m->get_numx() == 11) {
		for (int i = 0; i < m->get_numy(); i++) {
			m->creat_str();
			for (int j = 0; j < m->get_numx(); j++) {
				m->creat_elem(i,*cf->create_new(int(s1[i][j]) - 48, p));
			}
		}
	}
	else if (m->get_numx() == 16) {
		for (int i = 0; i < m->get_numy(); i++) {
			m->creat_str();
			for (int j = 0; j < m->get_numx(); j++) {
				m->creat_elem(i, *cf->create_new(int(s2[i][j]) - 48, p));
			}
		}
	}
	else if (m->get_numx() == 21) {
		for (int i = 0; i < m->get_numy(); i++) {
			m->creat_str();
			for (int j = 0; j < m->get_numx(); j++) {
				m->creat_elem(i, *cf->create_new(int(s3[i][j]) - 48, p));
				//std::cout << i<<" "<<j<<'\n';
			}
		}
	}
	delete cf;
}
