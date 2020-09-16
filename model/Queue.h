//
// Created by derovi on 9/15/2020.
//

#ifndef QUEUE_H_
#define QUEUE_H_

#include <set>
#include "Client.h"

class QueueVisitor;

class Queue {
 public:
  void accept(QueueVisitor* visitor);

  const std::set<Client*> &GetClients() const;
  void removeClient(Client* client);
  void addClient(bool decent);

  virtual ~Queue();

 private:
  std::set<Client*> clients_;
  int lastIndex_ = 0;
};

#endif  // QUEUE_H_
