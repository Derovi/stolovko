//
// Created by derovi on 9/15/2020.
//

#ifndef IPRESENTER_H_
#define IPRESENTER_H_

class IView;

class IPresenter {
 public:
  virtual void start(std::unique_ptr<IView> view) = 0;
};

#endif  // IPRESENTER_H_
