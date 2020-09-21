//
// Created by derovi on 9/17/2020.
//

#ifndef VISUALIZATION_H_
#define VISUALIZATION_H_

#include "../model/Queue.h"
#include "../model/visitors/NextClientVisitor.h"
#include <windows.h>

class Visualization {
 public:
  Visualization();
  void update(HWND hwnd, HDC hdc, int msecDelta);
  void queueUpdated(const Queue *queue);
  void nextClientSelected(const Client *client);
  void progressUpdated(double progress);
  void clientServed(const Client *client);

 private:
  const Queue* queue_;
  const Client* currentClient_;
  double progress_;
  NextClientVisitor* currentVisitor;
  int currentVisitorNumber;
};

#endif  // VISUALIZATION_H_
