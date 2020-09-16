//
// Created by derovi on 9/16/2020.
//

#ifndef FAIRNEXTCLIENTVISITOR_H_
#define FAIRNEXTCLIENTVISITOR_H_

#include "NextClientVisitor.h"
class FairNextClientVisitor : public NextClientVisitor {
 public:
  void visit(Queue *queue) override;
};

#endif  // FAIRNEXTCLIENTVISITOR_H_
