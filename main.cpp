/*#include <iostream>
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
*/

#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

int main(){
  for(int i = 0; i < 50; i++){

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    std::this_thread::sleep_for(std::chrono::milliseconds(5));

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration<double, std::milli> time_span = t2 - t1;

    std::cout << "It took me " << time_span.count() << " milliseconds.";
    std::cout << std::endl;
  }


}