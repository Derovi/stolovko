//
// Created by derovi on 9/17/2020.
//

#ifndef MESSAGEHANDLER_H_
#define MESSAGEHANDLER_H_

#include <windows.h>
#include "../Context.h"
#include "View.h"
#include <chrono>
#include "../ipresenter/IPresenter.h"

class MessageHandler {
 public:
  MessageHandler() {
  }

  ~MessageHandler() {
  }

  LRESULT Handle(
      HWND window_handle, UINT message_code, WPARAM w_param, LPARAM l_param);

  const std::unique_ptr<Visualization> &GetVisualization() const {
    return visualization_;
  }

 private:
  int TIMER_ID;
  std::chrono::high_resolution_clock::time_point lastUpdate;
  std::unique_ptr<Visualization> visualization_;
  View* view_;
};

#endif  // MESSAGEHANDLER_H_
