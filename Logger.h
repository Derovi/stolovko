//
// Created by derovi on 9/16/2020.
//

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>

class Logger {
 public:
  static const bool enabled = true;

  static void presenter(const std::string& message);
  static void model(const std::string& message);
  static void view(const std::string& message);
};

#endif  // LOGGER_H_
