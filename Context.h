#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <bits/unique_ptr.h>
#include "model/Model.h"
#include "iview/IView.h"

class Context {
 public:
  static void initialize(std::unique_ptr<IView> view);
  static std::unique_ptr<Model> &GetModel();
  static std::unique_ptr<IView> &GetView();

 private:
  static std::unique_ptr<Model> model_;
  static std::unique_ptr<IView> view_;
};

#endif  // CONTEXT_H_
