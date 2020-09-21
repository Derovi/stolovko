//
// Created by derovi on 9/17/2020.
//

#include "MessageHandler.h"
LRESULT MessageHandler::Handle(HWND window_handle,
                               UINT message_code,
                               WPARAM w_param,
                               LPARAM l_param)  {
  switch (message_code) {
    case WM_CREATE: {
      SetTimer(window_handle, TIMER_ID, 20 /* millis */, NULL);
      Context::GetPresenter()->start();
      lastUpdate = std::chrono::high_resolution_clock::now();
      visualization_ = std::make_unique<Visualization>();
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
      InvalidateRect(window_handle, nullptr, true);
      std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();

      std::chrono::duration<double, std::milli> time_span = now - lastUpdate;
      Context::GetPresenter()->update(time_span.count());

      lastUpdate = now;

      PAINTSTRUCT ps;

      HDC hdc = BeginPaint(window_handle, &ps);

      SelectObject(hdc, GetStockObject(HOLLOW_BRUSH));

      visualization_->update(window_handle, hdc, time_span.count());

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

      std::wstring text = L"Обслуживает честный кассир!";
      TextOutW(hdc, width / 2 - 3 * lstrlenW(text.c_str()), 20, text.c_str(),
               lstrlenW(text.c_str()));

      // draw help

      text = L"Нажмите \"+\", чтобы добавить честного клиента!";
      TextOutW(hdc, 100, height - 140, text.c_str(),
               lstrlenW(text.c_str()));

      text = L"Нажмите \"-\", чтобы добавить голодного студента!";
      TextOutW(hdc, 100, height - 100, text.c_str(),
               lstrlenW(text.c_str()));

      text = L"Используйте стрелочки, чтобы выбрать кассира!";
      TextOutW(hdc, 100, height - 60, text.c_str(),
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