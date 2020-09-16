//
// Created by derovi on 9/16/2020.
//

#include "Logger.h"
#include <iostream>

void Logger::presenter(const std::string& message) {
  std::cout << "Presenter << " <<  message;
}

void Logger::model(const std::string& message) {
  std::cout << "Model << " << message;
}

void Logger::view(const std::string& message) {
  std::cout << "View << " <<  message;
}
