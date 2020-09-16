//
// Created by derovi on 9/17/2020.
//

#ifndef VISUALIZATION_H_
#define VISUALIZATION_H_

#include "../model/Queue.h"
#include <windows.h>

class Visualization {
 public:
  Visualization();
  void update(HWND hwnd, HDC hdc, int msecDelta);
  void queueUpdated(Queue *queue);
  void nextClientSelected(Client *client);
  void progressUpdated(double progress);
  void clientServed(Client *client);

 private:
  Queue* queue_;
  Client* currentClient_;
  double progress_;
};

#endif  // VISUALIZATION_H_
