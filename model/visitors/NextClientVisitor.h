//
// Created by derovi on 9/16/2020.
//

#ifndef NEXT_CLIENT_VISITOR_H_
#define NEXT_CLIENT_VISITOR_H_

#include "QueueVisitor.h"
class NextClientVisitor : public QueueVisitor {
 public:
  virtual void visit(Queue *queue) = 0;

  Client *GetNextClient() const;
  void SetNextClient(Client *next_client);

  Client *GetCurrentClient() const;
  void SetCurrentClient(Client *current_client);

  virtual ~NextClientVisitor() = default;

 private:
  Client* currentClient_;
  Client* nextClient_;
};

#endif  // NEXT_CLIENT_VISITOR_H_
