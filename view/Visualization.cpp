//
// Created by derovi on 9/17/2020.
//

#include <windef.h>
#include "Visualization.h"
#include "../model/QueueIterator.h"
#include "../model/visitors/FairNextClientVisitor.h"
#include "../model/visitors/LazyNextClientVisitor.h"
#include "../Logger.h"
#include <windows.h>

Visualization::Visualization() {
  currentVisitor = new FairNextClientVisitor();
  currentVisitorNumber = 0;
  queue_ = nullptr;
}

void Visualization::update(HWND hwnd, HDC hdc, int msecDelta) {
  LOGBRUSH greenBrush;
  greenBrush.lbStyle = BS_SOLID;
  greenBrush.lbColor = RGB(0, 255, 0);
  greenBrush.lbHatch = 0;

  HPEN greenPen = ExtCreatePen(PS_SOLID | PS_GEOMETRIC, 8, &greenBrush, 0, NULL);

  LOGBRUSH redBrush;
  redBrush.lbStyle = BS_SOLID;
  redBrush.lbColor = RGB(255, 0, 0);
  redBrush.lbHatch = 0;
  HPEN redPen = ExtCreatePen(PS_SOLID | PS_GEOMETRIC, 8, &redBrush, 0, NULL);

  LOGBRUSH blueBrush;
  blueBrush.lbStyle = BS_SOLID;
  blueBrush.lbColor = RGB(0, 0, 255);
  blueBrush.lbHatch = 0;
  HPEN bluePen = ExtCreatePen(PS_SOLID | PS_GEOMETRIC, 8, &blueBrush, 0, NULL);

  SetDCBrushColor(hdc, RGB(0,0,255));
  MoveToEx(hdc, 50, 300, nullptr);
  LineTo(hdc, 950, 300);

  if (queue_ != nullptr) {
    LazyNextClientVisitor *visitor = new LazyNextClientVisitor();
    QueueIterator iterator(queue_, visitor);
    int index = 0;
    while (*iterator != nullptr) {
      const Client *client = *iterator;
      int y = 280;
      int x = 930 - index * 40;
      if (client->isDecent()) {
        SelectObject(hdc, greenPen);
      } else {
        SelectObject(hdc, redPen);
      }
      Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
      std::wstring text = std::to_wstring(client->GetIndex());
      TextOutW(hdc, x - 5 * text.size(), y - 7, text.c_str(), lstrlenW(text.c_str()));
      if (client == currentClient_) {
        SelectObject(hdc, bluePen);
        MoveToEx(hdc, x, y - 14, nullptr);
        AngleArc(hdc, x, y, 14, 90, 360 * progress_);
      }
      ++iterator;
      ++index;
    }
    delete visitor;
  }

  DeleteObject(redPen);
  DeleteObject(greenPen);
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
NextClientVisitor *Visualization::GetCurrentVisitor() const {
  return currentVisitor;
}
void Visualization::changeVisitor() {
  delete currentVisitor;
  if (currentVisitorNumber == 0) {
    currentVisitor = new LazyNextClientVisitor();
  } else {
    currentVisitor = new FairNextClientVisitor();
  }
  currentVisitorNumber ^= 1;
}

int Visualization::GetCurrentVisitorNumber() const {
  return currentVisitorNumber;
}
