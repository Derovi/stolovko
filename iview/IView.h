//
// Created by derovi on 9/15/2020.
//

#ifndef IVIEW_H_
#define IVIEW_H_

#include <memory>

class IPresenter;

class IView {
 public:
  virtual void start(std::unique_ptr<IPresenter> presenter) = 0;
};

#endif  // IVIEW_H_
