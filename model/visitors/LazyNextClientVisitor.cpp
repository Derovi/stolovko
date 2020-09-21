//
// Created by derovi on 9/16/2020.
//

#include "LazyNextClientVisitor.h"
#include "../../Logger.h"
void LazyNextClientVisitor::visit(const Queue *queue) {
  if (queue->GetClients().empty()) {
    SetNextClient(nullptr);
    return;
  }
  Client* current = GetCurrentClient();
  /// todo optimize
  Client* next = nullptr;
  for (Client* client : queue->GetClients()) {
    if (client == current || (current != nullptr && *client < *current)) {
      continue;
    }
    if (next == nullptr || *client < *next) {
      next = client;
    }
  }
  SetNextClient(next);
}

bool operator<(const Client &first, const Client &second) {
  if (first.isDecent() && !second.isDecent()) {
    return true;
  } else
  if (!first.isDecent() && second.isDecent()) {
    return false;
  } else
  if (first.isDecent() && second.isDecent()) {
    return first.GetIndex() > second.GetIndex();
  } else {
    return first.GetIndex() < second.GetIndex();
  }
}
