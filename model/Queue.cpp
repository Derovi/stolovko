//
// Created by derovi on 9/15/2020.
//

#include "Queue.h"
#include "visitors/QueueVisitor.h"

const std::set<Client*> &Queue::GetClients() const {
  return clients_;
}

void Queue::accept(QueueVisitor *visitor) {
  visitor->visit(this);
}
void Queue::removeClient(Client *client) {
  clients_.erase(client);
  delete client;
}

Queue::~Queue() {
  for (Client* client : clients_) {
    delete client;
  }
}
void Queue::addClient(bool decent) {
  clients_.insert(new Client(decent, ++lastIndex_));
}
