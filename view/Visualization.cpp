//
// Created by derovi on 9/17/2020.
//

#include <windef.h>
#include "Visualization.h"
#include "../model/QueueIterator.h"
#include "../model/visitors/FairNextClientVisitor.h"
#include "../Logger.h"
#include <windows.h>

Visualization::Visualization() {
  currentVisitor = new FairNextClientVisitor();
  currentVisitorNumber = 0;
  queue_ = nullptr;
}

void Visualization::update(HWND hwnd, HDC hdc, int msecDelta) {
  LOGBRUSH brush;
  brush.lbStyle = BS_SOLID;
  brush.lbColor = RGB(0, 255, 0);
  brush.lbHatch = 0;

  HPEN pen = ExtCreatePen(PS_SOLID | PS_GEOMETRIC, 8, &brush, 0, NULL);
  SelectObject(hdc, pen);
  SetDCBrushColor(hdc, RGB(0,0,255));
  MoveToEx(hdc, 50, 300, nullptr);
  LineTo(hdc, 950, 300);

  if (queue_ != nullptr) {
    FairNextClientVisitor *visitor = new FairNextClientVisitor();
    QueueIterator iterator(queue_, visitor);
    int index = 0;
    while (*iterator != nullptr) {
      const Client *client = *iterator;
      int y = 280;
      int x = 930 - index * 40;
      Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
      ++iterator;
      ++index;
    }
    delete visitor;
  }
  DeleteObject(pen);
}

void Visualization::queueUpdated(const Queue *queue) {
  queue_ = queue;
}

void Visualization::nextClientSelected(const Client *client) {
  currentClient_ = client;
}

void Visualization::progressUpdated(double progress) {
  progress_ = progress;
}

void Visualization::clientServed(const Client *client) {

}
