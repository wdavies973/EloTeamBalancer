cmake_minimum_required(VERSION 3.10)
project(EloTeamBalancer)

set(CMAKE_CXX_STANDARD 17)

add_executable(EloTeamBalancer main.cpp code/BaseX.cpp code/BaseX.h code/MatchFinder.cpp code/MatchFinder.h models/Match.cpp models/Match.h models/Team.cpp models/Team.h)