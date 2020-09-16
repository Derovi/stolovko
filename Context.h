#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <bits/unique_ptr.h>
#include "model/Model.h"
#include "iview/IView.h"

class Context {
 public:
  static void initModel();
  static void initView(std::unique_ptr<IView> view);
  static void initPresenter(std::unique_ptr<IPresenter> presenter);
  static const std::unique_ptr<Model> &GetModel();
  static const std::unique_ptr<IView> &GetView();
  static const std::unique_ptr<IPresenter> &GetPresenter();

 private:
  static std::unique_ptr<Model> model_;
  static std::unique_ptr<IView> view_;
  static std::unique_ptr<IPresenter> presenter_;
};

#endif  // CONTEXT_H_
