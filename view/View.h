//
// Created by derovi on 9/15/2020.
//

#ifndef VIEW_WAVIEW_H_
#define VIEW_WAVIEW_H_

#include "../iview/IView.h"
#include <windows.h>
#include <windowsx.h>
#include <winbase.h>

class View : public IView {
 public:
  View(HINSTANCE instance_handle_arg, int n_cmd_show);

  void start(std::unique_ptr<IPresenter> presenter) override;
};

#endif   // VIEW_WAVIEW_H_
