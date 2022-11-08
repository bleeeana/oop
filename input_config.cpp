#include "pch.h"
#include "input_config.h"

void input_config::input()
{
	ifstream file("file.txt");
    if (file.is_open()) {
        this->config.clear();
        while (!file.eof()) {
            string s;
            getline(file, s);
            string s1;
            getline(file, s1);
            if (s == "UP") {
                this->config.insert({ UP, key::get_instance()->get_keys()->at(s1) });
            }
            else if (s == "DOWN") {
                this->config.insert({ DOWN,key::get_instance()->get_keys()->at(s1) });
            }
            else if (s == "LEFT") {
                this->config.insert({ LEFT, key::get_instance()->get_keys()->at(s1) });
            }
            else if (s == "RIGHT") {
                this->config.insert({ RIGHT, key::get_instance()->get_keys()->at(s1) });
            }
            else if (s == "RUN") {
                this->config.insert({ RUN, key::get_instance()->get_keys()->at(s1) });
            }
        }
    }
}
