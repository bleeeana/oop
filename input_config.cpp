#include "pch.h"
#include "input_config.h"

input_config::input_config(configuration* cfg)
{
    this->cfg = cfg;
}

void input_config::set()
{
    ifstream file("file.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            string s;
            getline(file, s);
            string s1;
            getline(file, s1);
            if (s == "UP") {
                this->cfg->input( configuration::setting::UP,s1);
            }
            else if (s == "DOWN") {
                this->cfg->input(configuration::setting::DOWN, s1);
            }
            else if (s == "LEFT") {
                this->cfg->input(configuration::setting::LEFT, s1);
            }
            else if (s == "RIGHT") {
                this->cfg->input(configuration::setting::RIGHT, s1);
            }
            else if (s == "RUN") {
                this->cfg->input(configuration::setting::RUN, s1);
            }
            else if (s == "QUIT") {
                this->cfg->input(configuration::setting::QUIT, s1);
            }
        }
    }
    this->cfg->check();
}
