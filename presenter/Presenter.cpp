//
// Created by derovi on 9/16/2020.
//

#include "Presenter.h"
#include "../Logger.h"
#include "../model/visitors/FairNextClientVisitor.h"
#include "../Context.h"

void Presenter::start() {
  Logger::presenter("started");
}

void Presenter::update(int msecDelta) {
  //Logger::presenter("update " + std::to_string(msecDelta));
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
}

void Presenter::cameDisdecent() {
  queue_->addClient(false);
  Context::GetView()->queueUpdated(queue_);
}
