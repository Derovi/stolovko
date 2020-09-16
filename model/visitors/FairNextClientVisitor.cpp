//
// Created by derovi on 9/16/2020.
//

#include "FairNextClientVisitor.h"
void FairNextClientVisitor::visit(Queue *queue) {
  if (queue->GetClients().empty()) {
    return;
  }
  Client* current = GetCurrentClient();
  /// todo optimize
  Client* next = nullptr;
  for (Client* client : queue->GetClients()) {
    if (current != nullptr && client->GetIndex() <= current->GetIndex()) {
      continue;
    }
    if (next == nullptr || next->GetIndex() > client->GetIndex()) {
      next = client;
    }
  }
  SetNextClient(next);
}
