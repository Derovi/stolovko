//
// Created by derovi on 9/16/2020.
//

#ifndef LAZYNEXTCLIENTVISITOR_H_
#define LAZYNEXTCLIENTVISITOR_H_

#include "NextClientVisitor.h"
class LazyNextClientVisitor : public NextClientVisitor {
 public:
  void visit(const Queue *queue) override;
};

bool operator<(const Client& first, const Client& second);

#endif   // LAZYNEXTCLIENTVISITOR_H_
