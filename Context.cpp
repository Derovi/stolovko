//
// Created by derovi on 9/15/2020.
//

#include <memory>
#include "Context.h"

void Context::initialize(std::unique_ptr<IView> view) {
  model_ = std::make_unique<Model>();
  view_ = std::move(view);
}

std::unique_ptr<Model>& Context::GetModel() {
  return Context::model_;
}

std::unique_ptr<IView>& Context::GetView() {
  return Context::view_;
}

std::unique_ptr<IView> Context::view_ = nullptr;
std::unique_ptr<Model> Context::model_ = nullptr;
