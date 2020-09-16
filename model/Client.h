//
// Created by derovi on 9/15/2020.
//

#ifndef CLIENT_H_
#define CLIENT_H_


class Client {
 public:
  Client(int index, bool decent);
  int GetIndex() const;
  bool isDecent();

 private:
  int index_;
  bool decent_;
};

#endif  // CLIENT_H_
