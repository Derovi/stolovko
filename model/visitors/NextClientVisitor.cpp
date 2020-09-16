//
// Created by derovi on 9/16/2020.
//

#include "NextClientVisitor.h"

Client *NextClientVisitor::GetNextClient() const {
  return nextClient_;
}
Client *NextClientVisitor::GetCurrentClient() const {
  return currentClient_;
}
void NextClientVisitor::SetCurrentClient(Client *current_client) {
  currentClient_ = current_client;
}
void NextClientVisitor::SetNextClient(Client *next_client) {
  nextClient_ = next_client;
}