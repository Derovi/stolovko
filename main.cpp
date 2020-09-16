#include <iostream>
#include <memory>
#include "Context.h"
#include "view/View.h"

int WinMain(HINSTANCE instance_handle_arg, HINSTANCE,
  LPSTR /* command_line */, int n_cmd_show) {
  Context::initialize(std::unique_ptr<IView>(new View(
      instance_handle_arg, n_cmd_show)));
  return 0;
}