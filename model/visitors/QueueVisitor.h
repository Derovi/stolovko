//
// Created by derovi on 9/16/2020.
//

#ifndef QUEUEVISITOR_H
#define QUEUEVISITOR_H

#include "../Queue.h"
class QueueVisitor {
 public:
  virtual void visit(const Queue* queue) = 0;
};

#endif  // QUEUEVISITOR_H
