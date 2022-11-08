#include "pch.h"
#include "command_reader.h"




void command_reader::set_settings()
{
    int n;
    std::cout << "Ќастроить игру через файл или через консоль?(1 или 2)\n";
    std::cin >> n;
    if (n == 1) this->cfg = new input_config();
    else this->cfg = new input_config_console();
    this->cfg->input();
    mng = new gui_management();
}

void command_reader::input_size_win()
{
	setlocale(LC_ALL, "ru");
	int n;
	std::cout << " ¬ыберите 1 из шаблонов игровой карты\n" << "1. 10x10\n" << "2. 15x15\n" << "3. 20x20\n";
	std::cin >> n;
    if (n == 1) height = width = 11;
    else if (n == 2) height = width = 16;
    else if (n == 3) height = width = 21;
    else { height = width = -100; }
    /*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
    */
}


int command_reader::input_event()
{
     return this->mng->input_commands(*cfg, event);
}

/*void command_reader::set_management()
{
    int n;
    std::cout << "¬ыберите вариант управлени€ персонажем(1 - через SFML, 2 - через консоль)\n";
    std::cin >> n;
    if (n == 1) mng = new gui_management();
    

}
*/

sf::Event& command_reader::get_event()
{
    return this->event;
}



int command_reader::get_w()
{
	return this->width;
}

int command_reader::get_h()
{
	return this->height;
}

void command_reader::win_screen(RenderWindow& win)
{
    win.close();
    sf::RenderWindow window(sf::VideoMode(500, 250), "WIN");
    sf::Text message;
    sf::Font font;
    font.loadFromFile("Beat My Guest.ttf");
    message.setFont(font);
    message.setString("W I N)");
    message.setCharacterSize(200);
    message.setFillColor(sf::Color::Red);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(message);
        window.display();
    }
}


void command_reader::lose_screen(RenderWindow& win)
{
    win.close();
    sf::RenderWindow window(sf::VideoMode(500, 200), "Game over");
    sf::Text message;
    sf::Font font;
    font.loadFromFile("Beat My Guest.ttf");
    message.setFont(font);
    message.setString("Game over(");
    message.setCharacterSize(100);
    message.setFillColor(sf::Color::Red);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(message);
        window.display();
    }
}

void command_reader::set_output()
{
    char res;
    std::cout << "Output to: \n";
    std::cout << "0 - File\n";
    std::cout << "1 - Console\n";
    std::cout << "2 - Console and file\n";
    std::cout << "3 - No log\n";
    std::cin >> res;
    switch (res) {
    case '0':
        this->outputs.push_back(OUTPUT::FILEOUT);
        break;
    case '1':
        this->outputs.push_back(OUTPUT::CONSOLE);
        break;
    case '2': {
        this->outputs.push_back(OUTPUT::FILEOUT);
        this->outputs.push_back(OUTPUT::CONSOLE);
    }
        break;
    default:
        break;
    }
}

void command_reader::set_levels()
{
    if (!this->outputs.empty()) {
       
            char res;
            std::cout << "Logging level: \n";
            std::cout << "0 - Game\n";
            std::cout << "1 - Status\n";
            std::cout << "2 - Errors\n";
            std::cout << "3 - Game and errors\n";
            std::cout << "4 - Status and errors\n";
            std::cout << "5 - Status and Game\n";
            std::cout << "6 - Everything\n";
            std::cin >> res;
            switch (res) {
            case '0':
                this->levels.push_back(LEVEL::GAME);
                break;
            case '1':
                this->levels.push_back(LEVEL::STATUS);
                break;
            case '2':
                this->levels.push_back(LEVEL::ERROR);
                break;
            case '3': {
                this->levels.push_back(LEVEL::GAME);
                this->levels.push_back(LEVEL::ERROR);
            }
                    break;
            case '4': {
                this->levels.push_back(LEVEL::STATUS);
                this->levels.push_back(LEVEL::ERROR);
            }
                    break;
            case '5':
                this->levels.push_back(LEVEL::STATUS);

            default: {
                this->levels.push_back(LEVEL::STATUS);
                this->levels.push_back(LEVEL::GAME);
                this->levels.push_back(LEVEL::ERROR);
            }
                   break;
            }
    }
}


    std::vector <OUTPUT> command_reader::get_outputs() {
        return this->outputs;
    }

    
    std::vector <LEVEL> command_reader::get_levels() {
        return this->levels;
    }