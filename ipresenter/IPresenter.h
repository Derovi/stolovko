//
// Created by derovi on 9/15/2020.
//

#ifndef IPRESENTER_H_
#define IPRESENTER_H_

#include "../model/visitors/NextClientVisitor.h"
class IView;

class IPresenter {
 public:
  virtual void start() = 0;
  virtual void update(int msecDelta) = 0;

  virtual void changeNextClientVisitor(NextClientVisitor* visitor) = 0;
};

#endif  // IPRESENTER_H_
