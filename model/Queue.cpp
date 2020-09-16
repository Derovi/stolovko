//
// Created by derovi on 9/15/2020.
//

#include "Queue.h"
#include "visitors/QueueVisitor.h"

const std::vector<Client*> &Queue::GetClients() const {
  return clients_;
}
void Queue::accept(QueueVisitor *visitor) {
  visitor->visit(this);
}
