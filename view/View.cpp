//
// Created by derovi on 9/15/2020.
//

#include <chrono>
#include "View.h"
#include "../Context.h"
#include "../ipresenter/IPresenter.h"
#include "../Logger.h"

using namespace std::chrono;

class MultipleLinesPainter {
 public:
  MultipleLinesPainter() {
  }

  ~MultipleLinesPainter() {
  }

  LRESULT Handle(
      HWND window_handle, UINT message_code, WPARAM w_param, LPARAM l_param) {
    switch (message_code) {
      case WM_CREATE: {
        SetTimer(window_handle, TIMER_ID, 20 /* millis */, NULL);
        Context::GetPresenter()->start();
        lastUpdate = high_resolution_clock::now();
        break;
      }
      case WM_TIMER: {
        InvalidateRect(window_handle, nullptr, true);
        break;
      }
      case WM_LBUTTONDOWN: {
        POINT clickedPoint = {LOWORD(l_param), HIWORD(l_param)};
        break;
      }
      case WM_RBUTTONDOWN: {
        break;
      }
      case WM_KEYDOWN: {
        PAINTSTRUCT ps;

        HDC hdc = BeginPaint(window_handle, &ps);
        if (w_param == 107) {
          Context::GetPresenter()->cameDecent();
        } else if (w_param == 109) {
          Context::GetPresenter()->cameDisdecent();
        }
        break;
      }
      case WM_ERASEBKGND: {
        return (LRESULT) 1;
      }
      case WM_PAINT: {
        high_resolution_clock::time_point now = high_resolution_clock::now();

        duration<double, std::milli> time_span = now - lastUpdate;
        Context::GetPresenter()->update(time_span.count());

        lastUpdate = now;

        PAINTSTRUCT ps;

        HDC hdc = BeginPaint(window_handle, &ps);

        SelectObject(hdc, GetStockObject(HOLLOW_BRUSH));

        // draw text
        DWORD color = GetSysColor(COLOR_BTNFACE);
        SetBkColor(hdc, color);

        HFONT hFont = CreateFontW(15, 0, 0, 0, FW_MEDIUM, 0, 0, 0, 0,
                                  0, 0, 1, 0, L"Georgia");
        auto holdFont = static_cast<HFONT>(SelectObject(hdc, hFont));

        // draw status
        RECT rect;
        GetWindowRect(window_handle, &rect);

        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;

        std::wstring text;
        TextOutW(hdc, width / 2 - 3 * lstrlenW(text.c_str()), 50, text.c_str(),
                 lstrlenW(text.c_str()));

        // draw help

        text = L"Use left and right arrows to change drawing object";
        TextOutW(hdc, 100, height - 280, text.c_str(),
                 lstrlenW(text.c_str()));

        text = L"Use left mouse button to add a point to the drawing object";
        TextOutW(hdc, 100, height - 240, text.c_str(),
                 lstrlenW(text.c_str()));

        text = L"Use right mouse button to undo object drawing";
        TextOutW(hdc, 100, height - 200, text.c_str(),
                 lstrlenW(text.c_str()));

        text = L"Use ENTER to finish object drawing";
        TextOutW(hdc, 100, height - 160, text.c_str(),
                 lstrlenW(text.c_str()));

        text = L"Use ctrl + C to clear all objects from the screen";
        TextOutW(hdc, 100, height - 120, text.c_str(),
                 lstrlenW(text.c_str()));

        text = L"Use SPACE to start/ stop animation";
        TextOutW(hdc, 100, height - 80, text.c_str(),
                 lstrlenW(text.c_str()));

        text = L"Use R to restart animation";
        TextOutW(hdc, 100, height - 40, text.c_str(),
                 lstrlenW(text.c_str()));

        DeleteObject(hFont);
        EndPaint(window_handle, &ps);
        break;
      }
      case WM_SIZE: {
        InvalidateRect(window_handle, nullptr, true);
        break;
      }
      case WM_DESTROY: {
        PostQuitMessage(0);
        break;
      }
      default: {
        return DefWindowProc(window_handle, message_code, w_param, l_param);
      }
    }
    return 0;
  }

 private:
  int TIMER_ID;
  high_resolution_clock::time_point lastUpdate;
};

HDC View::hdcBackground = nullptr;

LRESULT View::MessagesHandler(
    HWND window_handle, UINT message_code, WPARAM w_param, LPARAM l_param) {
  static MultipleLinesPainter multiple_lines_painter;
  return multiple_lines_painter.Handle(
      window_handle, message_code, w_param, l_param);
}

int View::startView(HINSTANCE instance_handle_arg, int n_cmd_show) {
  instance_handle = instance_handle_arg;

  // Register the window class.
  const char kClassName[] = "msg_server_class";
  WNDCLASS window_class = {};
  window_class.lpfnWndProc = MessagesHandler;
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
}
void View::nextClientSelected(Client *client) {
  Logger::view("client selected: " + std::to_string(client->GetIndex()));
}
void View::progressUpdated(double progress) {
  Logger::view("progress updated: " + std::to_string(progress));
}
void View::clientServed(Client *client) {
  Logger::view("client served: " + std::to_string(client->GetIndex()));
}
