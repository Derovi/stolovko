//
// Created by derovi on 9/15/2020.
//

#include "Client.h"

bool Client::isDecent() const {
  return decent_;
}
Client::Client(int index, bool decent) : index_(index), decent_(decent) {}

int Client::GetIndex() const {
  return index_;
}
