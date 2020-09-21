//
// Created by derovi on 9/16/2020.
//

#include "Presenter.h"
#include "../Logger.h"
#include "../model/visitors/FairNextClientVisitor.h"
#include "../Context.h"

void Presenter::start() {

}

void Presenter::update(int msecDelta) {
  if (current == nullptr) {
    chooseClient();
    return;
  }
  progress += msecDelta / 1000.0;
  if (progress > 1) {
    Context::GetView()->clientServed(current);
    queue_->removeClient(current);
    Context::GetView()->queueUpdated(queue_);
    chooseClient();
    progress = 0;
    return;
  }
  Context::GetView()->progressUpdated(progress);
  //Logger::presenter("update " + std::to_string(msecDelta));
}

void Presenter::chooseClient() {
  next_client_visitor_->SetCurrentClient(nullptr);
  queue_->accept(next_client_visitor_);
  current = next_client_visitor_->GetNextClient();
  if (current != nullptr) {
    Context::GetView()->nextClientSelected(current);
  }
}

void Presenter::changeNextClientVisitor(NextClientVisitor *visitor) {

}
Presenter::~Presenter() {
  delete next_client_visitor_;
  delete queue_;
}

Presenter::Presenter() {
  next_client_visitor_ = new FairNextClientVisitor();
  queue_ = new Queue();
  progress = 0;
  current = nullptr;
}
void Presenter::cameDecent() {
  queue_->addClient(true);
  Context::GetView()->queueUpdated(queue_);
  Logger::presenter("Came decent!");
}

void Presenter::cameDisdecent() {
  queue_->addClient(false);
  Context::GetView()->queueUpdated(queue_);
  Logger::presenter("Came disdecent!");
}
