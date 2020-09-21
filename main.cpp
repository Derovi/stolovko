#include <iostream>
#include <memory>
#include "Context.h"
#include "view/View.h"
#include "presenter/Presenter.h"

int WinMain(HINSTANCE instance_handle_arg, HINSTANCE,
  LPSTR , int n_cmd_show) {

  Context::initModel();
  Context::initPresenter(std::unique_ptr<IPresenter>(new Presenter()));
  View* winApiView = new View();
  Context::initView(std::unique_ptr<IView>(winApiView));
  return winApiView->startView(instance_handle_arg, n_cmd_show);
}
