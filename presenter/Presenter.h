//
// Created by derovi on 9/16/2020.
//

#ifndef PRESENTER_H_
#define PRESENTER_H_

#include "../ipresenter/IPresenter.h"
#include "../model/visitors/NextClientVisitor.h"

class Presenter : public IPresenter {
 public:
  void start() override;
  void update(int msecDelta) override;
  void changeNextClientVisitor(NextClientVisitor *visitor) override;
 private:

};

#endif  // PRESENTER_H_
