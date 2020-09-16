//
// Created by derovi on 9/15/2020.
//

#include <chrono>
#include "View.h"
#include "../Context.h"
#include "../ipresenter/IPresenter.h"
#include "../Logger.h"
#include "MessageHandler.h"

using namespace std::chrono;

std::unique_ptr<MessageHandler> View::messageHandler = std::make_unique<MessageHandler>();

LRESULT View::MessagesHandlerMethod(
    HWND window_handle, UINT message_code, WPARAM w_param, LPARAM l_param) {
  return View::messageHandler->Handle(
      window_handle, message_code, w_param, l_param);
}

int View::startView(HINSTANCE instance_handle_arg, int n_cmd_show) {
  instance_handle = instance_handle_arg;

  // Register the window class.
  const char kClassName[] = "msg_server_class";
  WNDCLASS window_class = {};
  window_class.lpfnWndProc = View::MessagesHandlerMethod;
  window_class.hInstance = instance_handle;
  window_class.lpszClassName = kClassName;
  window_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
  window_class.hbrBackground = GetStockBrush(WHITE_BRUSH);
  RegisterClass(&window_class);

  // Create the window.
  HWND handle_of_window = CreateWindowEx(
      /* dwExStyle =    */ 0,
      /* lpClassName =  */ kClassName,
      /* lpWindowName = */ "Stolovka",
      /* dwStyle =      */ WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
      /* X =            */ CW_USEDEFAULT,
      /* Y =            */ CW_USEDEFAULT,
      /* nWidth =       */ 1000,
      /* nHeight =      */ 600,
      /* hWndParent =   */ nullptr,
      /* hMenu =        */ nullptr,
      /* hInstance =    */ instance_handle,
      /* lpParam =      */ nullptr
  );
  if (handle_of_window == nullptr) {
    return -1;
  }

  // Show the window.
  ShowWindow(handle_of_window, n_cmd_show);

  // Run the message loop.
  MSG message = {};
  while (GetMessage(&message, nullptr, 0, 0)) {
    TranslateMessage(&message);
    DispatchMessage(&message);
  }
  return 0;
}

void View::queueUpdated(Queue *queue) {
  Logger::view("queue updated");
  messageHandler->GetVisualization()->queueUpdated(queue);
}
void View::nextClientSelected(Client *client) {
  Logger::view("client selected: " + std::to_string(client->GetIndex()));
  messageHandler->GetVisualization()->nextClientSelected(client);
}
void View::progressUpdated(double progress) {
  Logger::view("progress updated: " + std::to_string(progress));
  messageHandler->GetVisualization()->progressUpdated(progress);
}
void View::clientServed(Client *client) {
  Logger::view("client served: " + std::to_string(client->GetIndex()));
  messageHandler->GetVisualization()->clientServed(client);
}
