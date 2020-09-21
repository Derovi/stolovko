cmake_minimum_required(VERSION 3.14)
project(labwp)

set(CMAKE_CXX_STANDARD 14)

add_executable(labwp
        main.cpp
        Context.cpp
        model/Model.cpp
        view/View.cpp
        model/Queue.cpp
        model/Client.cpp
        model/QueueIterator.cpp
        model/visitors/NextClientVisitor.cpp
        model/visitors/FairNextClientVisitor.cpp
        model/visitors/LazyNextClientVisitor.cpp
        presenter/Presenter.cpp
        Logger.cpp
        view/Visualization.cpp
        view/MessageHandler.cpp)
