//
// Created by derovi on 9/15/2020.
//

#include <memory>
#include "Context.h"
#include "presenter/Presenter.h"
#include "Logger.h"

void Context::initModel() {
  model_ = std::make_unique<Model>();
}

void Context::initView(std::unique_ptr<IView> view) {
  view_ = std::move(view);
}

void Context::initPresenter(std::unique_ptr<IPresenter> presenter) {
  presenter_ = std::move(presenter);
}

const std::unique_ptr<Model>& Context::GetModel() {
  return Context::model_;
}

const std::unique_ptr<IView>& Context::GetView() {
  return Context::view_;
}

const std::unique_ptr<IPresenter> &Context::GetPresenter() {
  return presenter_;
}

std::unique_ptr<Model> Context::model_ = nullptr;
std::unique_ptr<IView> Context::view_ = nullptr;
std::unique_ptr<IPresenter> Context::presenter_ = nullptr;
