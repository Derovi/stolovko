//
// Created by derovi on 9/15/2020.
//

#ifndef QUEUE_H_
#define QUEUE_H_

#include <vector>
#include "Client.h"

class QueueVisitor;

class Queue {
 public:
  void accept(QueueVisitor* visitor);

  const std::vector<Client*> &GetClients() const;

 private:
  std::vector<Client*> clients_;
};

#endif  // QUEUE_H_
