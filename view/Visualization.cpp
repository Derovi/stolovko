//
// Created by derovi on 9/17/2020.
//

#include <windef.h>
#include "Visualization.h"
#include <windows.h>

Visualization::Visualization() {

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
  DeleteObject(pen);
}

void Visualization::queueUpdated(Queue *queue) {
  queue_ = queue;
}

void Visualization::nextClientSelected(Client *client) {
  currentClient_ = client;
}

void Visualization::progressUpdated(double progress) {
  progress_ = progress;
}

void Visualization::clientServed(Client *client) {

}
