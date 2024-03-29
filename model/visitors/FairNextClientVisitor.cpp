//
// Created by derovi on 9/16/2020.
//

#include "FairNextClientVisitor.h"

void FairNextClientVisitor::visit(const Queue *queue) {
  if (queue->GetClients().empty()) {
    SetNextClient(nullptr);
    return;
  }
  Client* current = GetCurrentClient();
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
