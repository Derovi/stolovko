//
// Created by derovi on 9/16/2020.
//

#ifndef QUEUE_ITERATOR_H_
#define QUEUE_ITERATOR_H_

#include <iterator>
#include "Client.h"
#include "Queue.h"
#include "visitors/NextClientVisitor.h"

struct QueueIterator : std::iterator<std::forward_iterator_tag, Client> {
  Queue* queue_;
  Client* cursor_;
  NextClientVisitor* next_client_visitor_;
  QueueIterator(Queue* queue, NextClientVisitor* next_client_visitor) :
          queue_(queue), cursor_(nullptr), next_client_visitor_(next_client_visitor) {
    next_client_visitor_->SetCurrentClient(cursor_);
    queue_->accept(next_client_visitor_);
    cursor_ = next_client_visitor_->GetNextClient();
  }

  QueueIterator() = default;
  QueueIterator(const QueueIterator&) = default;
  QueueIterator& operator=(const QueueIterator&) = default;
  ~QueueIterator() = default;
  reference operator*() const { return *cursor_; }
  QueueIterator& operator++() {
    next_client_visitor_->SetCurrentClient(cursor_);
    queue_->accept(next_client_visitor_);
    cursor_ = next_client_visitor_->GetNextClient();
    return *this;
  }
  QueueIterator operator++(int) { auto old = *this; ++(*this); return old; }
};

void swap(QueueIterator& a, QueueIterator& b) { std::swap(a.cursor_, b.cursor_); }

#endif  // QUEUE_ITERATOR_H_
