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
  virtual void queueUpdated(const Queue* queue) = 0;
  virtual void nextClientSelected(const Client* client) = 0;
  virtual void progressUpdated(double progress) = 0;
  virtual void clientServed(const Client* client) = 0;
};

#endif  // IVIEW_H_
