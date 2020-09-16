//
// Created by derovi on 9/15/2020.
//

#ifndef VIEW_WAVIEW_H_
#define VIEW_WAVIEW_H_

#include "../iview/IView.h"
#include "Visualization.h"
#include <windows.h>
#include <windowsx.h>
#include <winbase.h>

class MessageHandler;

class View : public IView {
 public:
  int startView(HINSTANCE instance_handle_arg, int n_cmd_show);

  void queueUpdated(Queue *queue) override;
  void nextClientSelected(Client *client) override;
  void progressUpdated(double progress) override;
  void clientServed(Client *client) override;
  const std::unique_ptr<Visualization> &GetVisualization() const;
  static std::unique_ptr<MessageHandler> messageHandler;

 private:
  static LRESULT MessagesHandlerMethod(
      HWND window_handle, UINT message_code, WPARAM w_param, LPARAM l_param);
  HINSTANCE instance_handle;
};

#endif   // VIEW_WAVIEW_H_
