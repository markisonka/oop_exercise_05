#include <iostream>
#include <string>
#include <algorithm>

#include "Trapeze.h"
#include "Queue.h"

int main() {
    std::string command;
    Containers::Queue<Trapeze<int>> figures;
    while (std::cin >> command) {
        if (command == "add") {
            size_t position;
            std::cin >> position;
            auto it = figures.begin();
            try {
                it = std::next(it, position);
            } catch(std::exception& e) {
                std::cout << "Position is too big\n";
                continue;
            }
            Trapeze<int> new_figure;
            try {
                std::cin >> new_figure;
            } catch (std::exception& ex) {
                std::cout << ex.what() << "\n";
            }
            figures.Insert(it, new_figure);
            std::cout << new_figure << "\n";
        } else if (command == "erase") {
            size_t index;
            std::cin >> index;
            try {
                auto it = std::next(figures.begin(), index);
                figures.Erase(it);
            } catch (...) {
                std::cout << "Index is too big\n";
                continue;
            }
        } else if (command == "size") {
          std::cout << figures.Size() << "\n";
        } else if (command == "print") {
            std::for_each(figures.begin(), figures.end(), [] (const Trapeze<int>& fig) {
                std::cout << fig << " ";
            });
            std::cout << "\n";
        } else if (command == "count") {
            size_t required_area;
            std::cin >> required_area;
            std::cout << std::count_if(figures.begin(), figures.end(), [&required_area] (const Trapeze<int>& fig) {
                return fig.Area() < required_area;
            });
            std::cout << "\n";
        } else {
            std::cout << "Incorrect command" << "\n";
            std::cin.ignore(32767, '\n');
        }
    }
}