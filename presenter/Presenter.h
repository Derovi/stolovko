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
  void cameDecent() override;
  void cameDisdecent() override;
  Presenter();
  virtual ~Presenter();

 private:
  NextClientVisitor* next_client_visitor_;
  Queue* queue_;
  double progress;
  Client* current;
};

#endif  // PRESENTER_H_
