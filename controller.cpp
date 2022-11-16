#include "pch.h"
#include "controller.h"


void controller::movement(int k)
{
	if (k == -2 && this->pl->get_run() == 1) {
		this->pl->set_run(0);
	}
	else if (k == -1) {
		this->pl->set_run(1);
	}
	else if (k == 0) {
		this->pl->set_speed(0, -0.0007 * long double((pl->get_run() + 1)));
	}
	else if (k == 1) {
		this->pl->set_speed(0, 0.0007 * long double((pl->get_run() + 1)));
	}
	else if (k == 2) {
		this->pl->set_speed(-0.0007 * long double((pl->get_run() + 1)), 0);
	}
	else if (k == 3) {
		this->pl->set_speed(0.0007 * long double((pl->get_run() + 1)), 0);
	}
	else this->pl->set_speed(0, 0);
	react();
	
}



void controller::react()
{
	for (int i = 0; i < field->get_numy(); i++) {
		for (int j = 0; j < field->get_numx(); j++) {
			if (this->field->get_cur_cell(i, j).get_type() != 1) {
				if (abs(this->p->get_s().getPosition().x - j * 48) < 24 && abs(this->p->get_s().getPosition().y - i * 48) < 24) {
					this->field->get_cur_cell(i, j).get_event(info);
					this->field->get_cur_cell(i, j).set_type(5);
					this->field->set_player_location(j, i);
				}
				else if (this->field->get_cur_cell(i, j).get_type() == 5) this->field->get_cur_cell(i, j).set_type(0);
			}
			else {
				colission(i, j, 1);
				colission(i, j, 0);
			}
		}
	}
}

void controller::draw(sf::RenderWindow& win, sf::Texture &t, float time)
{
	change();
	this->p->update(time, this->field->get_numx());
	this->field_view->drawMap(win,t);
	this->p->draw(win);
	enemy->update(time, this->field->get_numx());
	enemy->draw(win);
}

controller::controller(player* p, player_view& pv, Map* m, Map_view& mv, enemies* enemies, logoutinfo* info) : pl(p), p(&pv), field(m), field_view(&mv), enemy(enemies)
{
	this->info = info;
	this->field->add_observer(new iobserver);
	this->pl->add_observer(new iobserver);
}



Map* controller::get_field()
{
	return this->field;
}

void controller::colission(int i, int j, int k)
{
	if (abs(p->get_s().getPosition().x - j*48) < 24 && abs(p->get_s().getPosition().y - i*48) < 24) {
		
		if (pl->get_speedy() > 0 && p->get_s().getPosition().y < i * 48 && k == 1) {
			p->get_s().move(0, -15);
		}
		if (pl->get_speedx() > 0 && p->get_s().getPosition().x < j * 48 && k == 0) { 
			p->get_s().move(-15, 0); 
		}
		if (pl->get_speedy() < 0 && p->get_s().getPosition().y > i*48 && k == 1) p->get_s().move(0, 15);
		if (pl->get_speedx() < 0 && p->get_s().getPosition().x > j*48 && k == 0) p->get_s().move(15, 0);
		message col(ERROR, "player is trying to get into unavailable cell", info);
		this->field->notify(col);
	}
}

void controller::set_enemies(int k, Texture & t)
{
	switch (k)
	{
	case(1):
		this->enemy->push_back_new(new enemy1_view(new enemy1(this->info), t, 0, this->field->get_numx() * 24));
		break;
	case(2):
		this->enemy->push_back_new(new enemy1_view(new enemy1(this->info), t, 0, this->field->get_numx() * 24));
		this->enemy->push_back_new(new enemy2_view(new enemy2(this->info), t, 0, 0));
		break;
	case(3):
		this->enemy->push_back_new(new enemy1_view(new enemy1(this->info), t, 0, this->field->get_numx() *24));
		this->enemy->push_back_new(new enemy2_view(new enemy2(this->info), t, 0, 0));
		this->enemy->push_back_new(new enemy3_view(new enemy3(this->info), t, 0, this->field->get_numx()*36));
		break;
	default:
		this->enemy->push_back_new(new enemy1_view(new enemy1(this->info), t, 0, this->field->get_numx() * 24));
		break;
	}
}


void controller::enemy_action()
{
	this->enemy->movement(this->field->get_numx(), this->p);
	this->enemy->attack(this->p);
}

void controller::set_Map()
{
	message w(STATUS, "Game started", info);
	notify(w);
	fieldfactory fact(field, pl);
	fact.creat_Map();
	create_chest *c = new create_chest(field, pl);
	c->execute(info);
	delete c;
}

void controller::change()
{
	
	if (this->pl->get_counter()!= this->progress) {
		change_Map e(field, pl);
		create_chest c(field, pl);
		for (int i = 0; i < this->pl->get_counter() - this->progress; i++) {
			e.execute(info);
			c.execute(info);
		}
	}
	this->progress = this->pl->get_counter();
}

bool controller::win() {
	if (this->progress == 3) {
		message w(STATUS, "WIN", info);
		notify(w);
		return 1;
	}
	else return 0;
}

bool controller::lose() {
	if ((this->pl->get_hp() <= 0)) {
		message l(STATUS, "LOSE", info);
		notify(l);
		return 1;
	}
	else return 0;
}

