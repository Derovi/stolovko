//
// Created by derovi on 9/15/2020.
//

#ifndef IVIEW_H_
#define IVIEW_H_

#include <memory>
#include "../model/Queue.h"

class IPresenter;

class IView {
 public:
  virtual void queueUpdated(Queue* queue) = 0;
  virtual void nextClientSelected(Client* client) = 0;
  virtual void progressUpdated(double progress) = 0;
  virtual void clientServed(Client* client) = 0;
};

#endif  // IVIEW_H_
